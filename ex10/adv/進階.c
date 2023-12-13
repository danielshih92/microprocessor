#include <regx51.h>
void print_msg(char *);
void write(char, int);
void delay(unsigned int);

void main()
{
write(0x38, 0);
write(0x0F, 0);
write(0x06, 0);
write(0x01, 0);
write(0x80, 0); //DD line1
print_msg("E14104064");


write(0x40, 0);//row1 , get the address
write(0x00, 1);//write the designed pattern into CGRAM for first row
write(0x41, 0);//row2
write(0x0a, 1);
write(0x42, 0);//3
write(0x1f, 1);
write(0x43, 0);//4
write(0x1f, 1);
write(0x44, 0);//5
write(0x0e, 1);
write(0x45, 0);//6
write(0x04, 1);
write(0x46, 0);//7
write(0x00, 1);
write(0x47, 0);//cursor
write(0x00, 1);

write(0xC0, 0);//line2
write(0x00, 1);

while (1);
}

void print_msg(char *msg)
{
	for(;*msg!='\0';msg++)
	     write(*msg,1);
}

void write(char cmd,int rs_value)
{
	P1=cmd; //D0 to D7
	P3_0=rs_value; // determine whether write command to LCD <0> or to DDRAM,CGRAM <1>
	P3_1=1;  // TXD enable
	delay(100);
	P3_1=0;
}

void delay(unsigned int i)
{
	while(i--);
}