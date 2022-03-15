/* date = January 19th 2022 11:38 am */

#ifndef UART_H
#define UART_H

//Low Level Implementation For UART

void UART_Init()
{
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = 0xFD;
	TR1 = 1;
}

void UART_tx(unsigned char x)
{
	SBUF = x;
	while(TI == 0);
	TI = 0;
}

unsigned char UART_rx(void)
{
	unsigned char inp;
	while(!RI);
	inp = SBUF;
	RI = 0;
	return inp;
}


//Higher Level Functions For Users

void UART_print(const char* str)
{
	for(int i = 0; str[i] != 0; i++)
	{
		UART_tx(str[i]);
	}
}

void UART_println(const char* str)
{
	for(int i = 0; str[i] != 0; i++)
	{
		UART_tx(str[i]);
	}
	UART_tx('\r');
	UART_tx('\n');
}

const char* UART_read(void)
{
	unsigned int i = 0;
	unsigned char inp;
	char output[] = "";
	while(1)
	{
		inp = UART_rx();
		if(inp == '\r')
		{
			break;
		}
		output[i] = inp;
		i++;
	}
	output[i + 1] = '\0';
	return output;
}






#endif //UART_H
