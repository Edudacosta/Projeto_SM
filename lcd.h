/*
 * lcd.h
 *
 *  Created on: 1 de dez de 2017
 *      Author: eduardo
 */

#ifndef LCD_H_
#define LCD_H_

#include <serial.h>

#define BIT_RS   BIT0
#define BIT_RW   BIT1
#define BIT_E    BIT2
#define BIT_BL   BIT3
#define BIT_D4   BIT4
#define BIT_D5   BIT5
#define BIT_D6   BIT6
#define BIT_D7   BIT7



void init_lcd(void);                    // Inicializa o LCD
void write_nibble(char nibble);         // Envia um nibble
void write_byte(char byte, int rs);     // Utiliza a função write_nibble duas vezes para enviar um byte. rs = 1 corresponde a escrita no LCD, se rs = 0, corresponde uma instrução
void clear_lcd(void);                   // Limpa o mostrador, e volta para a posição 0
void print_string(char*);               // Receve uma string e escreve nos 32 espaços do LCD

#endif /* LCD_H_ */
