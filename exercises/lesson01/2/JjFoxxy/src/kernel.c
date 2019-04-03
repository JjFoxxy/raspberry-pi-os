#include "uart.h"
#include "gpio.h"
#include "utils.h"

void kernel_main()
{
    uart_init();
    while(1) {
        uart_send_string("Hi, I am a single-core application for RPi3!");
        delay(100000000);
    }
}