/* date = January 14th 2022 7:39 pm */

#ifndef TIMING_H
#define TIMING_H

void delay(long long ms)
{
	while(ms--)
	{
		TMOD = 0x01;
		TH0 = 0xFC;
		TL0 = 0x66;
		TR0 = 1;
		while(!TF0)
		{
			TR0 = 0;
			TF0 = 0;
		}
	}
}


#endif //TIMING_H
