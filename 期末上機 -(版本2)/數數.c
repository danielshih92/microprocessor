#include <regx51.h>
void print_msg(char *);
void write(char, int);
void delay(unsigned int);
int a[3];
char b[3];
int i,j,k;

void main()
{
write(0x38, 0);  //mode set first
write(0x0F, 0);  //control on/off
write(0x06, 0);  //mode
write(0x01, 0);  //clear
write(0x80, 0); //DD line1

	for(k=0;k<10;k++)
	{
		for(j=0;j<10;j++)
		{
			for(i=0;i<10;i++)
			{
				a[2]=i;//int to char
				b[2]=a[2]+48;
				a[1]=j;
				b[1]=a[1]+48;
				a[0]=k;
				b[0]=a[0]+48;
				write(0x01, 0);  //clear
				write(0x80, 0);
				print_msg(b);
				delay(20000);
			}
		}
	}
}
	
void write(char cmd,int rs_value)
{
	P0=cmd;
	P3_0=rs_value;
	P3_1=1;
	delay(100);
	P3_1=0;
}

void delay(unsigned int i)
{
	while(i--);
}

void print_msg(char *msg)
{
	for(;*msg!='\0';msg++)
	     write(*msg,1);
}
