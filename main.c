#include <8052.h> //include the required file based on your compiler and microprocessor 
#include "include/uart.h"

void main(void)
{
	UART_Init();
	while(1) //super loop
	{
		const char* output = UART_read();
		UART_print(output);
	}
}