#include <regx52.h>
#include <string.h>

void print_msg(char[]);
void write(char, int); 
void delay(unsigned int);
int itr0 = 0; // interrupt 0 counter
int itr1 = 0; // interrupt 1 counter
int counter = 0; // timer counter
char roll_msg[] = "Final exam      ";

void main() {
    TMOD = 0x02;
    PX1=1; // INT1 is highest priority
    ET0=1; // open TF0
    TL0=0x00;
    TH0=0x00;

    IT0=0; //interrup t 0
    IT1=0; //interrup t 1
    EX0=1; // open INT0
    EX1=1; //open INT1
    EA=1;
    write(0x38, 0); // use 2 lines and 5x7 matrix
    write(0x0F, 0); // LCD ON, cursor ON, cursor blinking ON
    write(0x06, 0); // increment cursor
    write(0x01, 0); // clear screen
    while(itr0==0 && itr1==0){
        write(0x01, 0); // clear screen
        write(0x80, 0); // DDRAM 1st row 1st column (00H)
        if(P0 < 81){
            print_msg("LOW");
        }
        else if(P0 < 171){
            print_msg("MIDDLE");
        }
        else if(P0 < 256){
            print_msg("HIGH");
        }
        write(0xC0, 0); // DDRAM 2nd row 1st column (40H)
        if(P0 < 20){
            print_msg("=");
        }
        else if(P0 < 40){
            print_msg("==");
        }
        else if(P0 < 60){
            print_msg("===");
        }
        else if(P0 < 80){
            print_msg("====");
        }
        else if(P0 < 120){
            print_msg("=====");
        }
        else if(P0 < 140){
            print_msg("======");
        }
        else if(P0 < 160){
            print_msg("=======");
        }
        else if(P0 < 180){
            print_msg("========");
        }
        else if(P0 < 200){
            print_msg("=========");
        }
        else if(P0 < 220){
            print_msg("==========");
        }
        else if(P0 < 240){
            print_msg("===========");
        }
        else if(P0 < 256){
            print_msg("============");
        }
        delay(16383);
    }
    while(1);
}

void int_0(void) interrupt 0 {
    if(itr0 == 0){
        write(0x08, 0);
        P2_0=0;
    }
    else if(itr0 == 1){
        write(0x0F, 0);
        write(0x01, 0);
        write(0x80, 0);
        print_msg("E14104064");

        //skull
        write(0x40,0); //RAM POSITION
        write(0x00,1);
        write(0x0E,1);
        write(0x1F,1);
        write(0x15,1);
        write(0x0E,1);
        write(0x0E,1);
        write(0x00,1);
        write(0x00,1); //CURSOR
        //smile------------------------------------
        write(0x48,0); //RAM POSITION
        write(0x00,1);
        write(0x0A,1);
        write(0x0A,1);
        write(0x00,1);
        write(0x11,1);
        write(0x0E,1);
        write(0x00,1);	
        write(0x00,1);	//CURSOR

        write(0x8F,0);//PRINT POSITION
        write(0x00,1);
        write(0xCF,0);//PRINT POSITION
        write(0x01,1);

        P2_1=0;
    }
    else if(itr0 == 2){
        P2_2=0;
        write(0x01, 0);
        write(0x80, 0);
        print_msg("Best1");
        write(0xC0, 0);
        print_msg("Worst2");
    }

    itr0++;
    delay(65535);
}

void int_1(void) interrupt 2 {
    if(itr1 == 0){
        write(0x01, 0);
        write(0x80, 0);
        print_msg("Final exam      ");
    }
    else if(itr1 == 1){
        TR0=1;
        P2_0=0;
    }
    else if(itr1 == 2){
        TR0=0; // close timer 0
				TF0=0; // set the flag to 0
    }

    itr1++;
    delay(65535);
}


void timer_0(void) interrupt 1 {
    int k;
    char temp;
    P2_1=0;
    P2_2=0;
    write(0x01, 0);
    write(0x80, 0);
    print_msg(roll_msg);
    temp = roll_msg[15];
    for(k=15; k>0; k--){
        roll_msg[k] = roll_msg[k-1];
    }
    roll_msg[0] = temp;
    delay(65535);
}

void print_msg(char msg[]) {
    int i;
    for (i=0; i<strlen(msg); i++) // for every character
        write(msg[i], 1); // monitor displays character
}

void write(char cmd, int rs_value) {
    P1 = cmd; // P1=cmd
    P3_6 = rs_value; // RS=rs (1or0)
    P3_7 = 1; // ENABLE high
    delay(100);
    P3_7 = 0; // ENABLE low
}

void delay(unsigned int i) {
    while (i--); 
}
