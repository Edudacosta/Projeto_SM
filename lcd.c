/*
 * lcd.c
 *
 *  Created on: 1 de dez de 2017
 *      Author: eduardo
 */
#include <lcd.h>

void write_nibble(char nibble){         // Enviar 8 bits
    PCF_write(nibble);                  // Escreve sem enable
    PCF_write(nibble | BIT_E);          // Pulso enable
    __delay_cycles(10);                 // Espera...
    PCF_write(nibble );                 // Desativa enable
    return;
}

void write_byte(char byte, int rs){
    volatile char lsb_byte = byte << 4;
    write_nibble((byte&0xf0) | rs | BIT_BL);
    write_nibble((lsb_byte&0xf0) | rs | BIT_BL);
}

// inicialização do LCD
void init_lcd(void){
    __delay_cycles(300000);           // Esperar mais de 15 ms

    write_nibble(BIT5 | BIT4);       // Instrução : 0011 - Definir condições(8bits)
    __delay_cycles(90000);            // Espera mais de 4,1 ms

    write_nibble(BIT5 | BIT4);       // Instrução: 0011 - Definir condições(8bits)
    __delay_cycles(20000);            // Esperar mais de 100 us

    write_nibble(BIT5 | BIT4);       // Instrução: 0011 - Definir condições (8bit)
    __delay_cycles(100);

    write_nibble(BIT5);              // Instrução: 0010 - Definir condições (4bits)
    __delay_cycles(100);

    write_byte((BIT5|BIT3),0);       // Instrução: 0010 NF00 [0010 1000]     - Definir condições (4bits) N e F (N = 1 e F = 0) (4 bits e 5x8)
    __delay_cycles(100);

    write_byte(BIT3,0);              // Mostrador desativado     - Instrução: 0000 1000
    __delay_cycles(100);

    write_byte(BIT0, 0);                 // Limpar mostrador         - Instrução: 0000 0001
    __delay_cycles(100);                 // 0000 0110

    write_byte((BIT2|BIT1), 0);         // Definir modo de entrada(I/D e S) - Instrução: 0000 01IS [0000 0110]
    __delay_cycles(10);                 // (display parado cursor anda)
}


void clear_lcd(void){
    write_byte(1, 0);
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

