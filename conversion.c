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
        else if(strcmp(morse, "10100") == 0) caractere = 'C';
        else if(strcmp(morse, "00100") == 0) caractere = 'F';
        else if(strcmp(morse, "00000") == 0) caractere = 'H';
        else if(strcmp(morse, "01110") == 0) caractere = 'J';
        else if(strcmp(morse, "01000") == 0) caractere = 'L';
        else if(strcmp(morse, "01100") == 0) caractere = 'P';
        else if(strcmp(morse, "11010") == 0) caractere = 'Q';
        else if(strcmp(morse, "00010") == 0) caractere = 'V';
        else if(strcmp(morse, "10010") == 0) caractere = 'X';
        else if(strcmp(morse, "10110") == 0) caractere = 'Y';
        else if(strcmp(morse, "11000") == 0) caractere = 'Z';
        else caractere = '?';
    }
    if(w_size == 5){
        if(strcmp(morse, "11111") == 0) caractere = '0';
        else if(strcmp(morse, "01111") == 0) caractere = '1';
        else if(strcmp(morse, "00111") == 0) caractere = '2';
        else if(strcmp(morse, "00011") == 0) caractere = '3';
        else if(strcmp(morse, "00001") == 0) caractere = '4';
        else if(strcmp(morse, "00000") == 0) caractere = '5';
        else if(strcmp(morse, "10000") == 0) caractere = '6';
        else if(strcmp(morse, "11000") == 0) caractere = '7';
        else if(strcmp(morse, "11100") == 0) caractere = '8';
        else if(strcmp(morse, "11110") == 0) caractere = '9';
        else caractere = '?';
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
    delay(10);
//    __delay_cycles(30000);
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
    caractere = ' ';
    w_size = 0;
    position = 0;
}

// 0 - ponto; 1- traço;
int char_to_morse(char caract){
    unsigned int n_morse;
    if(caract == ' ') n_morse = 22222;
    if(caract == 0) n_morse = 22222;
    if(caract == 'A' || caract == 'a') n_morse = 22210;
    if(caract == 'B' || caract == 'b') n_morse = 20001;
    if(caract == 'C' || caract == 'c') n_morse = 20101;
    if(caract == 'D' || caract == 'd') n_morse = 22001;
    if(caract == 'E' || caract == 'e') n_morse = 22220;
    if(caract == 'F' || caract == 'f') n_morse = 20100;
    if(caract == 'G' || caract == 'g') n_morse = 22011;
    if(caract == 'H' || caract == 'h') n_morse = 20000;
    if(caract == 'I' || caract == 'i') n_morse = 22200;
    if(caract == 'J' || caract == 'j') n_morse = 21110;
    if(caract == 'K' || caract == 'k') n_morse = 22101;
    if(caract == 'L' || caract == 'l') n_morse = 20010;
    if(caract == 'M' || caract == 'm') n_morse = 22211;
    if(caract == 'N' || caract == 'n') n_morse = 22201;
    if(caract == 'O' || caract == 'o') n_morse = 22111;
    if(caract == 'P' || caract == 'p') n_morse = 20110;
    if(caract == 'Q' || caract == 'q') n_morse = 21011;
    if(caract == 'R' || caract == 'r') n_morse = 22010;
    if(caract == 'S' || caract == 's') n_morse = 22000;
    if(caract == 'T' || caract == 't') n_morse = 22221;
    if(caract == 'U' || caract == 'u') n_morse = 22100;
    if(caract == 'V' || caract == 'v') n_morse = 21000;
    if(caract == 'W' || caract == 'w') n_morse = 22110;
    if(caract == 'X' || caract == 'x') n_morse = 21001;
    if(caract == 'Y' || caract == 'y') n_morse = 21101;
    if(caract == 'Z' || caract == 'z') n_morse = 20011;
    if(caract == '0') n_morse = 11111;
    if(caract == '1') n_morse = 11110;
    if(caract == '2') n_morse = 11100;
    if(caract == '3') n_morse = 11000;
    if(caract == '4') n_morse = 10000;
    if(caract == '5') n_morse = 00000;
    if(caract == '6') n_morse = 00001;
    if(caract == '7') n_morse = 00011;
    if(caract == '8') n_morse = 00111;
    if(caract == '9') n_morse = 01111;

    return n_morse;
}

void insert_sw2(void){
    unsigned long int counter = 0;
    TA0R = 0;
    while((P1IN&BIT1) == 0);
    counter = TA0R;

    if(counter > 1300) {
        clear_lcd();
        print_string("Enviando        mensagem...");
        send_string();
        delay(3000);
        clear_lcd();
        print_string("Enviado!");
        delay(3000);
        clear_lcd();
        print_string(phrase);
    }
    else{
        if(caractere == 0) caractere = ' ';
        if(space > 0){
            form_string();
            print_string(phrase);
        }
        space++;
        position++;
        clear_morse();
        caractere = ' ';
        w_size = 0;
    }
}

void form_morse_rcv(void){
    int t =0;
    for(;t<32;t++){
        morse_rcv[t] = char_to_morse(rcvd_phrase[t]);
    }
}

void buzzer(int type){
    unsigned int limit;
    if(type != 2){
        if (type == 0){
            limit = 200;
        }
        if(type == 1){
            limit = 600;
        }
//        TA1R = 0;
//        TA1CCTL2 &=~CCIFG;
        P8OUT |= BIT1;
//        while((TA1CCTL2&CCIFG)==0);
        delay(limit);
        P8OUT &=~BIT1;
//        TA1CCTL2 &=~CCIFG;
        delay(300);
    }
}

void morse_buzzer(int m_code){
    unsigned int tm;
    for(tm = 0; tm < 5; tm++){
        buzzer(m_code%10);
        m_code = m_code/10;
    }
}

void m_rcvd_buzzer(void){
    unsigned int at = 0;
    form_morse_rcv();
    for(;at<32;at++){
        morse_buzzer(morse_rcv[at]);
    }
}
