#include <reg51.h>
#include <stdio.h>
#include "uart.h"

unsigned char i,j,k;
int ir_data[3];
void uart_ir_init();
int main()
{
	while(1)
	{
			uart_ir_init();
			for(i=0;i<3;i++)
			{
				ir_data[i]=uart_rx();
			}
			uart_init();
			printf("\n\n\n\n\n\n\n\n\n\n\n\n__||__||__||__||__||__||__||__||__||__||__||__||__||__||__\n**\t\t\t\t\t\t\t**\n**\t\t\t\t\t\t\t**\n");
			printf("**\t\t   ir status     %x                     **\n",ir_data[0]);
			printf("**\t\t   ir command    %x                     **\n",ir_data[1]);
			printf("**\t\t   ir data       %x                     **\n**\t\t\t\t\t\t\t**\n**\t\t\t\t\t\t\t**\n\0",ir_data[2]);
			printf("__||__||__||__||__||__||__||__||__||__||__||__||__||__||__ \0");
			if(ir_data[2]==0xfa)
				P1=~P1;
			for(j=0;j<100;j++);
			P0=ir_data[2];
	}
}

void uart_ir_init()
{
		 TMOD=0X22;
		 TH1=0xE8;
		 SCON=0X50;
		 TR1=1;
}