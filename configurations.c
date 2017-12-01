/*
 * configurations.c
 *
 *  Created on: 1 de dez de 2017
 *      Author: eduardo
 */
#include <configurations.h>

// Configurar chaves
void config_sw(void){
    P2DIR &= ~ BIT1;
    P2REN |= BIT1;
    P2OUT |= BIT1;
//    P2IE |= BIT1;
//    P2IES |= BIT1;

    // LED verde
    P4DIR |= BIT7;
    P4OUT |- BIT7;

    // buzzer
    P8DIR |= BIT1;
    P8OUT &=~ BIT1;
}

// Configurar timers
void config_timers(void){
    TA0EX0 |= TAIDEX_0;
    TA0CTL = (TASSEL_1 | TACLR | ID_3 | MC_2); // ACLK dividido por 8, clock = 4096Hz
 }
