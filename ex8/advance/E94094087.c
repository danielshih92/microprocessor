#include <regx51.h>
#include <stdio.h>
#define LED P2
 void init_uart();
 
 bit receive_full=1;
 bit transmit_flag=1;
 char cbindex = 0;
 char rxbuf[9];
 int n;
 char stnum[]="e14104064";
 char correct[]="\r\nCorrect";
 char wrong[]="\r\nWrong";
 int rn[]={0x0d,0x0a};
 
 void main( )
 {
	init_uart();
	while(1)
	{
		if(receive_full==1)
	  {
			bit check_flag = 0;
			receive_full = 0;
			for(n=0;n<9;n++)
			{
					if(stnum[n]!=rxbuf[n])
					{
						check_flag=1;
						break;
					}
			}
			if(check_flag==0)
			{
					for(n=0;n<9;n++)
					{
							while(!transmit_flag);
					
							transmit_flag=0;
							SBUF=correct[n];
					}
					for(n=0;n<2;n++)
					{
							while(!transmit_flag);
					
							transmit_flag=0;
							SBUF=rn[n];
					}
			}
			else
			{
				for(n=0;n<7;n++)
					{
							while(!transmit_flag);
					
							transmit_flag=0;
							SBUF=wrong[n];
					}
					for(n=0;n<2;n++)
					{
							while(!transmit_flag);
					
							transmit_flag=0;
							SBUF=rn[n];
					}
			}
	  }
  }
 }
 void init_uart(void)
 { 
	SCON=0x50; 
	TMOD=0x20; 
	TH1=0xe6; 
	TR1=1; 
	IE=0x90;
 }
 void UART_Isr(void) interrupt 4
 {
		if(RI==1)
		{
			RI=0;
			rxbuf[cbindex++]=SBUF;
			LED=rxbuf[cbindex-1];
			cbindex=cbindex%0x09;
			if(cbindex==0)
			{
					receive_full=1;
			}
		}
		else
		{
				TI=0;
				transmit_flag=1;
		}
	}