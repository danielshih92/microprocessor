#include <regx51.h> // include header file for 8051
//#define TH0_init 0x06 //TH0_init= 256 - 250
//#define TL0_init 0x06 //TL0_init = 256 - 250
#define Timer0_int_exe_time 10 //the parameter can be changed
void delay(int t);
int counter;
unsigned char a=0xfe;
void main(){
TMOD = 0x09; //set timer0 to mode 1(8-bits and auto-reload)
IP = 0x02; //timer0 interrupt has high priority
IE = 0x82; //enable timer0 interrupt
P2 = 0xfe;	
TL0 = (65536-50000)%256;
TH0 = (65536-50000)/256; //set TH0 & TL0
TCON = 0x10; //enable timer0
while(1){
P2=a;
}
}
void timer0_interrupt(void) interrupt 1 // ‘interrupt 1’ is int vector of INT0
{
counter++;
if (counter == Timer0_int_exe_time) //250clock cycle * 2000 = 0.5 second
{
if(P2!=0x7f){
a =a<<1; //inverse P2.0	
a =a+1;
}
else{
a =a<<1;
}
counter = 0;
}
}
