#ifndef UART_H
#define UART_H

void uart_init ( void );
void uart_send_string(char* str);
char uart_recv ( void );
void uart_send ( char c );
void waitUartReady ( void );

#endif // UART_H
