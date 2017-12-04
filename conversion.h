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
// INPUT void:- OUTPUT: char('0', '1' ou '2')
// Essa função é chamada sempre que o sw1 é pressionado.
// Ela calcula (usando o timer) o tempo em que o sw1 ficou apertado
// Se o tempo for menor que 180 ms, retorna um '0', se estiver entre
// 180 ms e 1 s retorna '1' e se for maior que 1 segundo, retorna '2'
// -- -- --


void form_morse(char);
// INPUT: char - OUTPUT: void
// REcebe um caractere que corresponde a um '0' ou '1' do cógigo morse, e insere em um array(char morse[5] GLOBAL), que corresponde ao
// código morse de uma letra ou número
// -- -- --

void srch_char(void);
//  INPUT:void- OUTPUT:void
// Procura o caractere que corresponde ao código da variável char morse[5], e atribui esse caractere a variável global 'char caractere'
// -- -- --

void form_string(void);
// INPUT: void - OUTPUT : void
// Insere o que está na variável global 'char caractere' em um array, também global, 'char phrase[32]'.
// char phrase[32] corresponde a mensagem que será enviada
// -- -- --

void clear_morse(void);
// I: void  O: void
// 'limpa' o array de código morse 'char morse[5]', fazendo morse = "00000"
// -- -- --

void clear_phrase(void);
// I: void  O: void
// Apaga todos os caracteres do array phrase[32], preenchendo todos os elementos com 0x0
// -- -- --

void clear_all(void);
// Simplesmente chama as duas funções para limpar morse e limpar phrase, zera a variável global de controle 'int position', e
// outra variável global 'int w_size'
// [ vou explicar o que são essas variáveis logo abaixo]
// -- -- --

void insert_sw2(void);
// I: void  O: void
// Função chamada caso SW2 seja pressionado.
// Calcula tempo pressionado, e a partir desse tempo realiza três possíveis ações:
//  - Pula para próximo caractere para inserção ou escreve um espaço
//  - Enviar a mensagem escrita
// -- -- --

int char_to_morse(char);
// I: char  O: int
// Essa função possui uma 'tabela' que relaciona o carctere de entrada a um número inteiro
// Essa função é usada para codificar o código morse
// A lógica funciona da seguinte forma:
//  - 1 simboliza o traço, o 0 simboliza o ponto, e o 2 simboliza espaço em branco
// -- -- --

void form_morse_rcv(void);
// Utiliza a função acima (char_to_morse) e insere os inteiros correspondentes no array morse_rcv

void m_rcvd_buzzer(void);
// I: void  O: void
// Controla a saída do buzzer de acordo com os inteiros no array
// global morse_rsv (que foi codificado com a função acima)
//-- -- --

void morse_buzzer(int);
// I: recebe um inteiro que corresponde ao código morse de um caractere
// e controla a saída do buzzer utilizando a funçao buzzer() abaixo

void buzzer(int);
// I: um inteiro que pode ser 1, 0 ou 2
// O: void
// A partir do inteiro de entrada, decide o tempo de saída do buzzer,
// se a entrada for 0, o buzzer toca por 200 ms,
// se for 1, o buzzer toca por 600 ns
// se for 2 o buzze não toca
// -- -- --


// ============================================
//          VARIÁVEIS GLOBAIS
// ===========================================
unsigned int w_size, position, space;
//  w_size => utilizada como controle do tamanho do código morse de um caractere, pois como a variável morse[5] tem sempre tamanho 5, é
//            preciso diferenciar alguns caracteres que podem ser iguais, se espaços em branços são considerados como 0

// position => a toddo momento o array com a menagem a ser enviada está sendo modificado. Essa variável aponta para o caractere atual
// que está sendo modificado, utilizando para o controle do array, e para mostrar no LCD

// space => usada para diferenciar entra 1 ou +2 clques no sw2. Caso space = 0. Quer dizer que não pressionado anteriormente
//          Assim, se for pressionado, quer dizer que o usuário que ir para a próxima letra
//          Porém se já foi pressionado uma segunda vez, quer dizer que se quer escrever um espaço
// -- -- --

char caractere, p_or_t;
//  caractere => guarda o último caractere decodificado de acordo com a entrada morse no SW1
//  p_or_t => é sempre 0, 1 ou 2. Correspondente a pontos, traços ou o comando para apagar. Usando somente na inserção de morse, mas não na recepção

char morse[5];
// morse[5] => guarda o úlitmo morse inserido, tem tamanho fixo 5, pois é o máximo possível para código morse

char phrase[32], rcvd_phrase[32];
//  phrase[32] => array que guarda a mensagem escrita até o momento. Por conveniência (LCD) foi escolhido o tamanho fixo de 32 bytes

long int morse_rcv[32];
// array com os códigos morser(em forma de ints).
// os códigos desse array são diferentes da variável morse[5], pois a finalidade de morse_src[32] é somente para apitar o buzzer

#endif /* CONVERSION_H_ */
