#include <regx51.h>
void print_msg(char *);
void write(char, int);
void delay(unsigned int);
int of;//on off
int count;
int j;
int enter;

void main()
{
of=0;
count=0;
j=0;
enter=0;

IT0 = 0; //enable a low-level signal on external interrupt
IT1 = 0;
EX0 = 1; //enable INT0
EX1 = 1; //enable INT1
EA = 1; //enable interrupt
	
write(0x38, 0);
write(0x0F, 0);
write(0x06, 0);
write(0x01, 0);
write(0x80, 0); //DD line1
print_msg("e94094087");


write(0x40, 0);//row1
write(0x00, 1);
write(0x41, 0);
write(0x0a, 1);
write(0x42, 0);
write(0x1f, 1);
write(0x43, 0);
write(0x1f, 1);
write(0x44, 0);
write(0x0e, 1);
write(0x45, 0);
write(0x04, 1);
write(0x46, 0);
write(0x00, 1);
write(0x47, 0);
write(0x00, 1);

write(0xC0, 0);//line2
write(0x00, 1);

while (1)
{

if(enter==1)
{
	 if(of==0)
   {
		  write(0x08 ,0);
	 }
	 else
	 {
		  write(0x0F, 0);
	 }
}

if(enter==2)
{
	 if(count==1)
	 {
		 write(0x01, 0); //clean
		 write(0x80, 0); //DD line1
     print_msg("pass"); 
	 }
	 else if(count==2)
	 {
	   
		   //write(0x80+j, 0); //DD line1
       write(0x1C, 0);
		   delay(10000);
	 }
	 else if(count==3)
	 {
		  
		  //write(0x80+j, 0); //DD line1
		  write(0x1C, 0);
		  delay(1000);		 
	 }
	 delay(15000);
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

void int_0(void)interrupt 0 //INT0 interrupt function
{
	enter=1;
 if(of==0)
 {
	 of=1;
 }
 else
 {
	 of=0;
	 
 }
}

void int_1(void)interrupt 2 //INT1 interrupt function
{
 enter=2;
 delay(20000);
 if(count==0)
 { 
	 count=1;
 }
 else if(count==1)
 {
	 count=2;
 }
 else if(count==2)
 {
	 count=3;
 }
 else if(count==3)
 {
	 count=0;
 }
}
 
