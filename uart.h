void uart_tx(unsigned char x);
uart_rx(void);
void uart_init(void);
void uart_string_rx(void);
unsigned char v[15];

void uart_init(void)
{
	SCON  = 0x50;		        /* SCON: mode 1, 8-bit UART, enable rcvr      */
    TMOD |= 0x20;               /* TMOD: timer 1, mode 2, 8-bit reload        */
    TH1   = 0XFD;                /* TH1:  reload value for 1200 baud @ 16MHz   */
    TR1   = 1;                  /* TR1:  timer 1 run                          */
    TI    = 1;
}


void uart_tx(unsigned char x)
{
	SBUF=x;
	while(TI==0);
	TI=0;
}

void uart_num(unsigned int m)
{
	
	uart_tx(m+48);
}
uart_rx(void)
{
	unsigned char w;
	while (RI==0);
		w=SBUF;
		RI=0;
	return w;
}


void uart_string_rx(void)
{
	unsigned char i;
	for(i=0;v[i]!='&';i++)
	{
		while (RI==0);
		v[i]=SBUF;
		RI=0;
		if(v[i]=='&')
		{
			break;
		}
		SBUF=v[i];
	while(TI==0);
	TI=0;
	}
}