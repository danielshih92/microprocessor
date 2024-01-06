#include <regx51.h>
void print_msg(char *);
void write(char, int);
void delay(unsigned int);
int i;

void main()
{
write(0x38, 0);  //mode set first
write(0x0E, 0);  //control on/off
write(0x06, 0);  //mode
write(0x01, 0);  //clear
write(0x80, 0); //DD line1
//print_msg("final exam");




while (1){
	for(i=0;i<16;i++)
	{

	if(i==0)
	{
		write(0x80, 0);
		print_msg("final exam      ");
		delay(25000);
	}
	else if(i==1)
	{
		write(0x80, 0);
		print_msg(" final exam     ");
		delay(25000);
	}
	else if(i==2)
	{
		write(0x80, 0);
		print_msg("  final exam    ");
		delay(25000);
	}
	else if(i==3)
	{
		write(0x80, 0);
		print_msg("   final exam   ");
		delay(25000);
	}
	else if(i==4)
	{
		write(0x80, 0);
		print_msg("    final exam  ");
		delay(25000);
	}
	else if(i==5)
	{
		write(0x80, 0);
		print_msg("     final exam ");
		delay(25000);
	}
	else if(i==6)
	{
		write(0x80, 0);
		print_msg("      final exam");
		delay(25000);
	}
	else if(i==7)
	{
		write(0x80, 0);
		print_msg("m      final exa");
		delay(25000);
	}
	else if(i==8)
	{
		write(0x80, 0);
		print_msg("am      final ex");
		delay(25000);
	}
	else if(i==9)
	{
		write(0x80, 0);
		print_msg("xam      final e");
		delay(25000);
	}
	else if(i==10)
	{
		write(0x80, 0);
		print_msg("exam      final ");
		delay(25000);
	}
	else if(i==11)
	{
		write(0x80, 0);
		print_msg(" exam      final");
		delay(25000);
	}
	else if(i==12)
	{
		write(0x80, 0);
		print_msg("l exam      fina");
		delay(25000);
	}
	else if(i==13)
	{
		write(0x80, 0);
		print_msg("al exam      fin");
		delay(25000);
	}
	else if(i==14)
	{
		write(0x80, 0);
		print_msg("nal exam      fi");
		delay(25000);
	}
	else if(i==15)
	{
		write(0x80, 0);
		print_msg("inal exam      f");
		delay(25000);
	}
	}
	
	write(0x80, 0);
	write(0xC0, 0);
	print_msg("0");
	delay(50000);
}
}

void print_msg(char *msg)
{
	for(;*msg!='\0';msg++)
	     write(*msg,1);
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

