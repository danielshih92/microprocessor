#include <regx51.h>
void print_msg(char *);
void write(char, int);
void delay(unsigned int);
int c;
int a[3];
char b[3];

void main( )
{
write(0x38, 0);  //mode set first
write(0x0F, 0);  //control on/off
write(0x06, 0);  //mode
write(0x01, 0);  //clear
//write(0x80, 0); //DD line1

 while(1)
 {
	 c=P1;
	 a[2]=c%10;//digits
	 c=c/10;
	 a[1]=c%10;//ten
	 c=c/10;
	 a[0]=c%10;//hundred
	 write(0x01, 0);  //clear
	 write(0x80, 0); //DD line1
	 b[2]=a[2]+48;
	 b[1]=a[1]+48;
	 b[0]=a[0]+48;
   print_msg(b);
	 delay(5000);
	 
	 
   if(P1 >=0 && P1<16) //if P1 greater than 256/2
	 {
		  write(0x01, 0);  //clear
		  write(0x80, 0); //DD line1
		  write(0xC0, 0); //line2
      print_msg("=");
		  delay(5000);
	 }
   else if( P1>=16 && P1<32)
   {
		  write(0x01, 0);
		  write(0x80, 0); //DD line1
		  write(0xC0, 0);
		  print_msg("==");
		  delay(5000);
	 }
	 else if( P1>=32 && P1<48)
	 {
		  write(0x01, 0);
		  write(0x80, 0); //DD line1
		  write(0xC0, 0);
		  print_msg("===");
		  delay(5000);
	 }
	 else if( P1>=48 && P1<64)
	 {
		  write(0x01, 0);
		  write(0x80, 0); //DD line1
		  write(0xC0, 0);
		  print_msg("====");
		  delay(5000);
	 }
	 else if( P1>=64 && P1<80)
	 {
		  write(0x01, 0);
		  write(0x80, 0); //DD line1
		  write(0xC0, 0);
		  print_msg("=====");
		  delay(5000);
	 }
	 else if( P1>=80 && P1<96)
	 {
		  write(0x01, 0);
		  write(0x80, 0); //DD line1
		  write(0xC0, 0);
		  print_msg("======");
		  delay(5000);
	 }
	 else if( P1>=96 && P1<112) //7
	 {
		  write(0x01, 0);
		  write(0x80, 0); //DD line1
		  write(0xC0, 0);
		  print_msg("=======");
		  delay(5000);
	 }
	 else if( P1>=112 && P1<128) //8
	 {
		  write(0x01, 0);
		  write(0x80, 0); //DD line1
		  write(0xC0, 0);
		  print_msg("========");
		  delay(5000);
	 }
	 else if( P1>=128 && P1<144) //9
	 {
		  write(0x01, 0);
		  write(0x80, 0); //DD line1
		  write(0xC0, 0);
		  print_msg("=========");
		  delay(5000);
	 }
	 else if( P1>=144 && P1<160) //10
	 {
		  write(0x01, 0);
		  write(0x80, 0); //DD line1
		  write(0xC0, 0);
		  print_msg("==========");
		  delay(5000);
	 }
	 else if( P1>=160 && P1<176) //11
	 {
		  write(0x01, 0);
		  write(0x80, 0); //DD line1
		  write(0xC0, 0);
		  print_msg("===========");
		  delay(5000);
	 }
	 else if( P1>=176 && P1<192) //12
	 {
		  write(0x01, 0);
		  write(0x80, 0); //DD line1
		  write(0xC0, 0);
		  print_msg("============");
		  delay(5000);
	 }
	 else if( P1>=192 && P1<208) //13
	 {
		  write(0x01, 0);
		  write(0x80, 0); //DD line1
		  write(0xC0, 0);
		  print_msg("=============");
		  delay(5000);
	 }
	 else if( P1>=208 && P1<224) //14
	 {
		  write(0x01, 0);
		  write(0x80, 0); //DD line1
		  write(0xC0, 0);
		  print_msg("==============");
		  delay(5000);
	 }
	 else if( P1>=224 && P1<240) //15
	 {
		  write(0x01, 0);
		  write(0x80, 0); //DD line1
		  write(0xC0, 0);
		  print_msg("===============");
		  delay(5000);
	 }
	 else if( P1>=240 && P1<256) //16
	 {
		  write(0x01, 0);
		  write(0x80, 0); //DD line1
		  write(0xC0, 0);
		  print_msg("================");
		  delay(5000);
	 }
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