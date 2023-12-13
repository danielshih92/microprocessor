#include <regx51.h>

void main( )
{
IT0 = 0; //enable a low-level signal on external interrupt
EX0 = 1; //enable INT0
EA = 1; //enable interrupt
P3_4 = 0; //WR=0,clean the data
P3_4 = 1; //WR=1,analog convert to digital
while(1); //infinite loop
}

void int_0(void)interrupt 0 //INT0 interrupt function
{
 P3_5 = 0; //RD=0,read the digital data
 if (P1>=0 &&P1 <25) 
 {
	 P2 = 255;//LED off
 }
 else if (P1 >=25 && P1 <50)//1
 {
   P2 = 254;
 }
 else if (P1 >=50 && P1 <75)//2
 {
   P2 = 252;
 } 
 else if (P1 >=75 && P1 <100)//3
 {
   P2 = 248;
 }  
 else if (P1 >=100 && P1 <125)//4
 {
   P2 = 240;
 }
 else if (P1 >=125 && P1 <150)//5
 {
   P2 = 224;
 }
 else if (P1 >=150 && P1 <175)//6
 {
   P2 = 192;
 }
 else if (P1 >=175 && P1 <200)//7
 {
   P2 = 128;
 }
 else if(P1>=200)//8 
 {
   P2 = 0;
 }  

 P3_5 = 1; //RD=1
 P3_4 = 0; //WR=0,clean the data
 P3_4 = 1; //WR=1,analog convert to digital
}