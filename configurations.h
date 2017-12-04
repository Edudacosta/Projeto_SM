/*
 * configurations.h
 *
 *  Created on: 1 de dez de 2017
 *      Author: eduardo
 */

#ifndef CONFIGURATIONS_H_
#define CONFIGURATIONS_H_

#include <msp430.h>


void config_timers(void);       // Configurar timers
void config_sw(void);           // Configurar chaves
void config_dma(void);          // configura dma
void delay(int);                // função de delay usando timers

#endif /* CONFIGURATIONS_H_ */
