/*
 * conversion.h
 *
 *  Created on: 1 de dez de 2017
 *      Author: eduardo
 */

#ifndef CONVERSION_H_
#define CONVERSION_H_

#include <msp430.h>
#include <string.h>

char def_morse(void);
void form_morse(char);
void srch_char(void);
void form_string(char);

char teste;
unsigned int w_size, position;
char caractere;
char morse[5];
char phrase[32];

#endif /* CONVERSION_H_ */
