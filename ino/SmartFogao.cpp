#include "SmartFogao.h"

void SmartFogao::iniciarFogao(
    uint8_t portFaisca,
    uint8_t portSensorDeFogo,
    uint8_t portControleTemperatura,
    uint8_t portSensorDeTemperatura)
{
    this->boca.iniciarBocaDoFogao(
        portFaisca,
        portSensorDeFogo,
        portControleTemperatura,
        portSensorDeTemperatura
    );
    this->lcd = new LcdFogao();
    this->esp = new ComunicacaoESP();
}

void SmartFogao::work() {
    
    // Tratando do ESP
    if (this->esp->hasSomethingToSay()) {
        
        this->esp->captureCod();
        

        if ((this->esp->getStatusBoca()) && (!this->boca.getFireIsUp())){
            this->boca.lightUp();
            this->boca.setExpectedTemp( this->esp->getNewTemp() );
            this->boca.setNewTime( this->esp->getNewTime() * 60000 );
        }
        else if((this->esp->getStatusBoca()) && (this->boca.getFireIsUp())){
            this->boca.setExpectedTemp( this->esp->getNewTemp() );
            this->boca.setNewTime( this->esp->getNewTime() * 60000 );
        }

        this->boca.switchToAutoMode();
    } 

    // Tratando dos botões no LCD Shield
    uint8_t pressedBtnOnLcd = this->lcd->getPressedButton();
    if (pressedBtnOnLcd != 0) {
        switch (pressedBtnOnLcd) {
            case 3:
                this->boca.decreaseTemp();
                break;
            case 4:
                this->boca.increaseTemp();
                break;
        }
        delay(200);
        this->boca.switchToManualMode();
    }

    // Atualizando view do LCD
    this->lcd->displayStatusScreen(
        this->boca.getManualModeOn() ? 1 : 2,
        this->boca.getPower(),
        this->boca.getExpectedTemp()
    );

    this->boca.keepEverythingTogether();
}
