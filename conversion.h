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
void form_string(void);
void clear_morse(void);
void clear_phrase(void);
void clear_all(void);
void next_char(void);


unsigned int w_size, position, space;
char caractere, p_or_t;
char morse[5];
char phrase[32];

#endif /* CONVERSION_H_ */
