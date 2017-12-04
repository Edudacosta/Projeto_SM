/*
 * serial.h
 *
 *  Created on: 1 de dez de 2017
 *      Author: eduardo
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#include<msp430.h>
#include<conversion.h>

// I2C pins
#define SDA_SEL     P3SEL
#define SDA_BIT     BIT0
#define SDA_REN     P3REN
#define SDA_OUT     P3OUT

#define SCL_SEL     P3SEL
#define SCL_BIT     BIT1
#define SCL_REN     P3REN
#define SCL_OUT     P3OUT

#define BR100K      10      //100 kbps
#define BR50K       20      // 50 kbps
#define BR10K       100     // 10 kbps

/////////////////////////////////////////////
#define PCF 0x3F    //Endereço PCF8574AT
////////////////////////////////////////////

void config_I2C(void);          // Configura pinos p/ I2C
void PCF_write(char dado);      // Escreve na porta PCF
void config_uart(void);         // Configura UART para tranferencia de dados
void send_string(void);         // Envia mensagem pela porta serial UART

#endif /* SERIAL_H_ */
