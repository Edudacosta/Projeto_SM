/*
 * serial.c
 *
 *  Created on: 1 de dez de 2017
 *      Author: eduardo
 */

// Configurar Pinos I2C - UCSB0
// P3.0 --> SDA
// P3.1 --> SCL

#include<serial.h>

void config_I2C(void){
    SDA_SEL |=  SDA_BIT;    //  Usar módulo dedicado
    SDA_REN |=  SDA_BIT;    //  Habilitar resistor
    SDA_OUT |=  SDA_BIT;    //  Pull-up
    SCL_SEL |=  SCL_BIT;    //  Usar módulo dedicado
    SCL_REN |=  SCL_BIT;    //  Habilitar resistor
    SCL_OUT |=  SCL_BIT;    //  Pull-up
    UCB0CTL1 |= UCSWRST;    //  UCSI B0 em ressete
    UCB0CTL0 = UCSYNC |     //  Síncrono
               UCMODE_3 |   //  Modo I2C
               UCMST;       //  Mestre
    UCB0BRW = BR100K;       //  100 kbps
    UCB0CTL1 = UCSSEL_2;    //  SMCLK e remove ressete
}

// Escrever dado na porta
void PCF_write(char dado){
    UCB0I2CSA = PCF;                            //Endereço do Escravo
    UCB0CTL1 |= UCTR    |                       //Mestre transmissor
                UCTXSTT;                        //Gerar START e envia endereço
    while ( (UCB0IFG & UCTXIFG) == 0);          //Esperar TXIFG (completar transm.)
    if ( (UCB0IFG & UCNACKIFG) == UCNACKIFG){   //NACK?
//        LED1_OUT |= LED1;                       //Acender LED Vermelho
        while(1);                               //Se NACK, prender
    }
    UCB0TXBUF = dado;                           //Dado a ser escrito
    while ((UCB0IFG & UCTXIFG) == 0);          //Esperar Transmitir
    UCB0CTL1 |= UCTXSTP;                        //Gerar STOP
    while ( (UCB0CTL1 & UCTXSTP) == UCTXSTP);   //Esperar STOP
    __delay_cycles(1000);                                  //Atraso p/ escravo perceber stop
}
