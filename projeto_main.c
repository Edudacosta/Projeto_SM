#include <msp430.h>
#include <conversion.h>
#include <configurations.h>
#include <lcd.h>

void print_string(char *);
/**
 * main.c
 */
int main(void){
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    space = 0;
    config_I2C();
    init_lcd();
    write_byte(0xF,0);
    config_timers();
    config_sw();
    clear_all();
//    __enable_interrupt();
    while(1){
        if((P2IN&BIT1) == 0){
            space = 0;
            p_or_t = def_morse();
            if(p_or_t != '2'){
                form_morse(p_or_t);
                srch_char();
                form_string();
                print_string(phrase);
            }
            else{
                  clear_all();
                  clear_lcd();
                  print_string(phrase);
            }

        }
        if((P1IN&BIT1) == 0){
            next_char();
        }
    }
}

void print_string(char *string){
    unsigned int i = 0;
    write_byte(0x80,0);
    while(string[i] != 0 && i < 16){
        write_byte(string[i], 1);
        i++;
    }
    if(i == 16){
        write_byte(0xC0, 0);
        while(string[i] != 0 && i < 32){
            write_byte(string[i], 1);
            i++;
        }
    }
}

void next_char(void){
    if(space > 0){
        form_string();
        print_string(phrase);
    }
    space++;
    position++;
    clear_morse();
    caractere = ' ';
    w_size = 0;
    while((P1IN&BIT1) == 0);
    __delay_cycles(100000);
}
