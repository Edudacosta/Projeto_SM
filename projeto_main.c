#include <msp430.h> 
#include <configurations.h>

char def_morse(void);
void form_word(char);
void srch_char(void);

char teste;
unsigned int w_size;
char caractere;
char morse[5];

/**
 * main.c
 */
int main(void){
//    __delay_cycles(400000);
    // Configurar
    w_size = 0;
    config_timers();
    config_sw();
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
//    __enable_interrupt();
    __delay_cycles(400000);
    while(1){
        if((P2IN&BIT1) == 0){
        teste = def_morse();
        form_word(teste);
        srch_char();
        if(w_size == 6) w_size = 0;
        __delay_cycles(30000);
        if(w_size == 6) w_size = 0;
        if(w_size == 6) w_size = 0;
        }
        }
//    return 0;
}

char def_morse(void){
    unsigned char signal;           // Ponto ou traço
    unsigned int count;            // Contagem com SW pressionado
    TA0R = 0;
    P8OUT |= BIT1;
    while((P2IN&BIT1) == 0);
    count = TA0R;
    P8OUT &= ~BIT1;
    if(count > 700) signal = '1';
    else signal ='0';
    return signal;
}

void form_word(char signal){
    if(w_size == 5) w_size = 0;
    w_size ++;
    morse[w_size-1] = signal;
}

void srch_char(void){
    int i = 0, ct=0;
    for(i; i<5; i++){
        if(morse[i] == '1') ct++;
    }

    if(w_size == 1){
        if(ct == 0) caractere = 'E';
        if(ct == 1) caractere = 'T';

    }
//    if(w_size == 2){
//        if(morse[0] == '0' && morse[1] == '0') caractere = 'I';
//        if(morse[0] == '0' && morse[1] == '1') caractere = 'I';
//    }
//    if(w_size == 3){
//
//    }
//    if(w_size == 4){
//
//    }
//    if(w_size == 5){
//
//    }
}
