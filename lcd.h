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


void init_lcd(void);;
void write_nibble(char nibble);
void write_byte(char byte, int rs);
void LCD_BL_on(void);
void write_string(char*);

#endif /* LCD_H_ */
