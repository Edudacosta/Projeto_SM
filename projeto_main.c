#include <msp430.h>
#include <conversion.h>
#include <configurations.h>
#include <lcd.h>

/**
 * main.c
 */
int main(void){
//    __delay_cycles(400000);
    // Configurar
    volatile int linha = 1;
    char carac = 0x0;
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    config_I2C();
    init_lcd();
    write_byte(0xF,0);
    volatile int i;

    position = 0;
    w_size = 0;
    int z =0;
    for(;z<5; z++){
        morse[z] = '0';
    }
    config_timers();
    config_sw();

    while(1){
        if((P2IN&BIT1) == 0){
        teste = def_morse();
        form_morse(teste);
        srch_char();
        if(w_size == 5){
            form_string(caractere);
//            write_byte(caractere, 1);
        }
        __delay_cycles(30000);
        }
        }
//    return 0;
}

