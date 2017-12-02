/*
 * conversion.c
 *
 *  Created on: 1 de dez de 2017
 *      Author: eduardo
 */
#include <conversion.h>
#include <configurations.h>
#include <lcd.h>

// Converte código morse para um caractere
void srch_char(void){
    if(w_size == 1){
        if(strcmp(morse, "00000") == 0) caractere = 'E';
        if(strcmp(morse, "10000") == 0) caractere = 'T';
    }
    if(w_size == 2){
        if(strcmp(morse, "01000") == 0) caractere = 'A';
        if(strcmp(morse, "00000") == 0) caractere = 'I';
        if(strcmp(morse, "11000") == 0) caractere = 'M';
        if(strcmp(morse, "10000") == 0) caractere = 'N';
    }
    if(w_size == 3){
        if(strcmp(morse, "10000") == 0) caractere = 'D';
        if(strcmp(morse, "11000") == 0) caractere = 'G';
        if(strcmp(morse, "10100") == 0) caractere = 'K';
        if(strcmp(morse, "11100") == 0) caractere = 'O';
        if(strcmp(morse, "01000") == 0) caractere = 'R';
        if(strcmp(morse, "00000") == 0) caractere = 'S';
        if(strcmp(morse, "00100") == 0) caractere = 'U';
        if(strcmp(morse, "01100") == 0) caractere = 'W';
    }
    if(w_size == 4){
        if(strcmp(morse, "10000") == 0) caractere = 'B';
        if(strcmp(morse, "10100") == 0) caractere = 'C';
        if(strcmp(morse, "00100") == 0) caractere = 'F';
        if(strcmp(morse, "00000") == 0) caractere = 'H';
        if(strcmp(morse, "01110") == 0) caractere = 'J';
        if(strcmp(morse, "01000") == 0) caractere = 'L';
        if(strcmp(morse, "10010") == 0) caractere = 'P';
        if(strcmp(morse, "11010") == 0) caractere = 'Q';
        if(strcmp(morse, "00010") == 0) caractere = 'V';
        if(strcmp(morse, "10010") == 0) caractere = 'X';
        if(strcmp(morse, "10110") == 0) caractere = 'Y';
        if(strcmp(morse, "11000") == 0) caractere = 'Z';
//        else caractere = '?';
    }
    if(w_size == 5){
        if(strcmp(morse, "11111") == 0) caractere = '0';
        if(strcmp(morse, "01111") == 0) caractere = '1';
        if(strcmp(morse, "00111") == 0) caractere = '2';
        if(strcmp(morse, "00011") == 0) caractere = '3';
        if(strcmp(morse, "00001") == 0) caractere = '4';
        if(strcmp(morse, "00000") == 0) caractere = '5';
        if(strcmp(morse, "10000") == 0) caractere = '6';
        if(strcmp(morse, "11000") == 0) caractere = '7';
        if(strcmp(morse, "11100") == 0) caractere = '8';
        if(strcmp(morse, "11110") == 0) caractere = '9';
//        else caractere = '?';
    }

}

// Define se usuário inseriu um ponto ou um traço
char def_morse(void){
    unsigned char signal;           // Ponto ou traço
    unsigned int count;            // Contagem com SW pressionado
    TA0R = 0;
    P8OUT |= BIT1;
    while((P2IN&BIT1) == 0);
    count = TA0R;
    P8OUT &= ~BIT1;
    if(count > 700 && count < 4000) signal = '1';
    else if(count > 4000){
        signal = '2';
    }
    else signal ='0';
    __delay_cycles(10000);
    return signal;
}

// Junta os pontos e traços
void form_morse(char signal){
    morse[w_size] = signal;
    w_size ++;
}

// Quardar string
void form_string(void){
    if(position < 33) phrase[position] = caractere;
}

//// Interrupção da porta P1
//#pragma vector = 47
//__interrupt void P1(void){
//    unsigned int a = __even_in_range(P1IV, 0x4);
//    switch(a){
//    case 0: break;
//    case 2: break;
//    case 4:
//        position ++;
//        clear_morse();
//        caractere = ' ';
//        w_size = 0;
//        while((P1IN&BIT1) == 0);
//        __delay_cycles(1000000);
//        break;
//    default: break;
//    }
//}

void clear_morse(void){
    unsigned int z =0;
    for(;z<5; z++){
        morse[z] = '0';
    }
}

void clear_phrase(void){
    unsigned int z = 0;
    for(;z < 32; z++){
        phrase[z] = 0x0;
    }
}

void clear_all(void){
    clear_morse();
    clear_phrase();
    caractere = 0x0;
    w_size = 0;
    position = 0;
}
