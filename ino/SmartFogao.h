#ifndef SMARTFOGAO_H
#define SMARTFOGAO_H

#include "LcdFogao.h"
#include "BocaDoFogao.h"
#include "ComunicaoESP.h"
#include <Arduino.h>

class SmartFogao {
    public:
        void iniciarFogao(uint8_t, uint8_t, uint8_t, uint8_t);
        void work();
        LcdFogao *lcd;
        BocaDoFogao boca;
        ComunicacaoESP *esp;

    private:
       
};


#endif // SMARTFOGAO_H
