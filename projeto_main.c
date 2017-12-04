#include <msp430.h>
#include <conversion.h>
#include <configurations.h>
#include <lcd.h>
#include <serial.h>

#define RXBUFMEMO (__SFR_FARPTR)0x05CC

void init_system(void);
void insert_sw1(void);
void delay(int);

/**
 * main.c
 */
int main(void){
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    init_system();
    __enable_interrupt();
    while(1){
        if((P2IN&BIT1) == 0){
           insert_sw1();
        }
        if((P1IN&BIT1) == 0){
            insert_sw2();
        }
    }
}

// Função que configura o DMA
// INPUT: void - outr
void config_dma(void){
    DMACTL0 = DMA0TSEL_16;   // Trigger pelo URXBUF
    DMA0CTL = DMAEN |        // Habilitar DAM0
              DMADT_4 |      // Modo simples repetido
              DMASRCINCR_1 | // source address is incremented
              DMADSTINCR_3 |
              DMASRCBYTE   |
              DMADSTBYTE   |
              DMAIE;
    DMA0SA = RXBUFMEMO; //Endereço ADC MEM0
    DMA0DA = &rcvd_phrase[0];
    DMA0SZ = 32;
}

// Inicializa o programa, setandos as configurações de TIMER, GPIO, UART, I2C, DMA, etc;
void init_system(void){
    space = 1;
    config_uart();
    config_I2C();
    init_lcd();
    write_byte(0xF,0);
    config_timers();
    config_sw();
    clear_all();
    config_dma();
}

// Função que define se o usuário quer inserir um caractere ou apagar o que inseriu
void insert_sw1(void){
    space = 0;
    p_or_t = def_morse();
    if(p_or_t != '2'){
        form_morse(p_or_t);
        srch_char();
        form_string();
        print_string(phrase);
        if(caractere == 0) caractere = ' ';
        if(w_size == 5){
            space++;
            position++;
            clear_morse();
            caractere = ' ';
            w_size = 0;
            print_string(phrase);
        }
    }
    else{
          space = 1;
          clear_all();
          clear_lcd();
          print_string(phrase);

    }
}

// Interrupção do DMA
// Ocorre após receber 32 bytes pelar porta UART. 32 bytes que correspondem a mensagem enviada pela outra placa
#pragma vector = 50
__interrupt void DMA0(void){
    switch(__even_in_range(DMAIV, 0x02)){
    case 0x00: break;
    case 0x02:
        clear_lcd();
        delay(10);
        print_string("Nova mensagem...");
        delay(5000);
        clear_lcd();
        print_string(rcvd_phrase);
        m_rcvd_buzzer();
        delay(10000);
        clear_lcd();
        print_string(phrase);
        break;
    default: break;
    }
}

