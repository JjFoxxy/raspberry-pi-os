#include "gpio.h"
#include "utils.h"
#include "peripherals/gpio.h"

void setPin(int pin_number, int value)
{
    if(pin_number > 32) return;
    
    value &= 0x1;
    
    if(value == 0) put32(GPCLR0, 1 << pin_number);
    else           put32(GPSET0, 1 << pin_number);
}