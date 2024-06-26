/*
 * configurations.c
 *
 *  Created on: 1 de dez de 2017
 *      Author: eduardo
 */
#include <configurations.h>

// Configurar chaves
void config_sw(void){
    // SW1 - inserir morse
    P2DIR &= ~ BIT1;
    P2REN |= BIT1;
    P2OUT |= BIT1;
//    P2IE |= BIT1;
//    P2IES |= BIT1;

    // SW2 - Espaço ou Enviar
    P1DIR &= BIT1;
    P1REN |= BIT1;
    P1OUT |= BIT1;
//    P1IE |= BIT1;
//    P1IES |= BIT1;

    // LED verde
    P4DIR |= BIT7;
    P4OUT |= BIT7;

    //LED vermelho
    P1DIR |= BIT0;
    P1OUT &= ~BIT0;

    // buzzer
    P8DIR |= BIT1;
    P8OUT &=~ BIT1;
}

// Configurar timers
void config_timers(void){
    TA0EX0 |= TAIDEX_0;
    TA0CTL = (TASSEL_1 | TACLR | ID_3 | MC_2); // ACLK dividido por 8, clock = 4096Hz

    TA1EX0 |= TAIDEX_0;
    TA1CTL = (TASSEL_1 | TACLR | ID_3 | MC_1); // ACLK dividido por 8, clock = 4096Hz
    TA1CCR0 = 3000;
 }

void delay(int time){
    int count_d = (time * 4);
    TA0CCR3 = count_d;
    TA0R = 0;
    TA0CCTL3 &= ~CCIFG;
    while((TA0CCTL3&CCIFG) == 0);
    return;
}
