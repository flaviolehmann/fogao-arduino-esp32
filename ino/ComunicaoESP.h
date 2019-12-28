#ifndef COMUNICACAOESP_H
#define COMUNICACAOESP_H

#include <Arduino.h>

class ComunicacaoESP {
    public:
        ComunicacaoESP();
        bool hasSomethingToSay();
        String captureCod();
        bool getStatusBoca();
        uint8_t getNewTemp();
        uint8_t getNewTime();

        String codigo;
        bool status;
        String temperatura;
        String tempo;

    private:
        
};

#endif
