
#include <stdint.h>
#include "tm4c123gh6pm.h"

void Systick_Init (void);

void Systick_wait10ms(uint32_t delay);

void systick_delay (uint32_t delay);

void Systick_wait1ms ();

void UART_Init(void);
