#include "utils.h"
#include "peripherals/uart.h"
#include "peripherals/gpio.h"

#include "gpio.h"
#include "uart.h"

void uart_init ( void )
{
	unsigned int selector;

	selector = get32(GPFSEL1);
	selector &= ~(7<<12);                   // clean gpio14
	selector |= 4<<12;                      // set alt5 for gpio14
	selector &= ~(7<<15);                   // clean gpio15
	selector |= 4<<15;                      // set alt5 for gpio15
	put32(GPFSEL1,selector);

	put32(GPPUD,0);
	delay(150);
	put32(GPPUDCLK0,(1<<14)|(1<<15));
	delay(150);
	put32(GPPUDCLK0,0);

    put32(UART_IBRD, 26);                   // Baudrate integer = 137
    put32(UART_FBRD, 3);                    // Baudrate fractional = 41 (0.3368 * 64 + 0.5)
    put32(UART_LCRH, 0x70);                 // Enable 8 bit mode, 1 stop bit, no parity, no fifo
    put32(UART_CR, 0x301);                  // Enable TX,RX, UART and RTS
}

void uart_send ( char c )
{
    while(1)
    {
		if(!(get32(UART_FR) & 0x20)) 
			break;
	}
	put32(UART_DR,c);
}

char uart_recv ( void )
{
    while(1)
    {
        if(get32(UART_FR) & 0x10) 
        {
            break;
        }
    }
    return(get32(UART_DR) & 0xFF);
}

void uart_send_string(char* str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        uart_send((char)str[i]);
    }
}
