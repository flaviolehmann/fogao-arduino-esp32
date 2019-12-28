#include "ComunicaoESP.h"

ComunicacaoESP::ComunicacaoESP() {
    String codigo = "";
    String temperatura = "";
    String tempo = "";
}

bool ComunicacaoESP::hasSomethingToSay() {
    return Serial.available();
}

String ComunicacaoESP::captureCod(){
    char num;
    codigo = "";
    while(Serial.available()){
        num = Serial.read();
        if(num != '\n'){
            codigo.concat(num);
        }
        delay(10);
    }
    return codigo;
}

bool ComunicacaoESP::getStatusBoca(){
    return codigo[0];
}

uint8_t ComunicacaoESP::getNewTemp() {
    temperatura = "";
    temperatura += codigo[4];
    temperatura += codigo[5];
    temperatura += codigo[6];
    
    return (uint8_t) atoi(temperatura.c_str());
}

uint8_t ComunicacaoESP::getNewTime() {
    tempo = "";
    tempo += codigo[1];    
    tempo += codigo[2];
    tempo += codigo[3];
    
    return (uint8_t) atoi(tempo.c_str());
}
