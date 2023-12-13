#include<regx52.h>

code char two_phase[] = {0x0c,0x06,0x03,0x09};
int delay_time;

void delay(int);
void turn();

void main() {

    while(1) {
        if(P2 < 50){
            delay_time=4800;
        } else if(P2 < 100) {
            delay_time=2400;
        } else if(P2 < 150) {
            delay_time=1200;
        } else if(P2 < 200) {
            delay_time=600;
        } else if(P2 < 250){
            delay_time=300;
        }
        turn();
    }
}

void turn() {
				int x;
        for(x=0;x<4;x++) {
            P1=two_phase[x];
            delay(delay_time);
        }
}

void delay(int t) {
    while(t--);
}
