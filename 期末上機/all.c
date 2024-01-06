#include <regx52.h>
#include <string.h>

void print_msg(char[]);
void write(char, int); 
void delay(unsigned int);
void num2();
void num3();
void num4();
int itr0 = 0; // interrupt 0 counter
int itr1 = 0; // interrupt 1 counter
int counter = 0; // timer counter
char roll_msg[] = "I love embedded system.";

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
    write(0x08, 0); // display off
    delay(60000);
    delay(60000);
    write(0x38, 0); // use 2 lines and 5x7 matrix
    write(0x0F, 0); // LCD ON, cursor ON, cursor blinking ON
    write(0x06, 0); // increment cursor
    write(0x01, 0); // clear screen
    while(1){
        if(P0 <= 70){
            write(0x01, 0); // clear screen
            P2_0 = 0;
            P2_1 = 1;
            P2_2 = 1;
            num2();
        }
        else if(P0 <= 165){
            write(0x01, 0); // clear screen
            P2_0 = 1;
            P2_1 = 0;
            P2_2 = 1;
            num3();
        }
        else if(P0 <= 255){
            write(0x01, 0); // clear screen
            P2_0 = 1;
            P2_1 = 1;
            P2_2 = 0;
            num4();
        }
		delay(16383);
    }
}

void int_0(void) interrupt 0 {
    delay(65535);
}

void int_1(void) interrupt 2 {
    write(0x01, 0);
    write(0x80, 0);
    print_msg("Best1");
    write(0xC0, 0);
    print_msg("Worst2");
    delay(65535);
		delay(65535);
		delay(65535);
}


void timer_0(void) interrupt 1 {
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

void num2(){
        write(0x80, 0);//print position
        print_msg("0%");
		write(0xC0, 0);//print position
        print_msg("=>");
        delay(65535);
        write(0xC0, 0);//print position
        print_msg("==>");
        delay(65535);
        write(0xC0, 0);//print position
        print_msg("===>");
        delay(65535);
        write(0xC0, 0);//print position
        print_msg("====>");
        delay(65535);
        write(0xC0, 0);//print position
        print_msg("=====>");
        delay(65535);
        write(0xC0, 0);//print position
        print_msg("======>");
        delay(65535);
        write(0xC0, 0);//print position
        print_msg("=======>");
        delay(65535);
        write(0xC0, 0);//print position
        print_msg("========>");
        delay(65535);
}
void num3(){
        write(0x80, 0);//print position
        print_msg("E14104064");
        write(0xC0, 0);//print position
        print_msg("Final exam");
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
}

void num4(){
    write(0x80, 0);//print position
    print_msg("I love embedded ");
    delay(65535);
    write(0x80, 0);//print position
    print_msg(" love embedded s"); 
    delay(65535);
    write(0x80, 0);//print position
    print_msg("love embedded sy");
    delay(65535);
    write(0x80, 0);//print position
    print_msg("ove embedded sys");
    delay(65535);
    write(0x80, 0);//print position
    print_msg("ve embedded syst");
    delay(65535);
    write(0x80, 0);//print position
    print_msg("e embedded syste");
    delay(65535);
    write(0x80, 0);//print position
    print_msg(" embedded system");
    delay(65535);
    write(0x80, 0);//print position
    print_msg("embedded system.");
    delay(65535);
    write(0x80, 0);//print position
    print_msg("mbedded system. ");
    delay(65535);
    write(0x80, 0);//print position
    print_msg("bedded system. I");
    delay(65535);
    write(0x80, 0);//print position
    print_msg("edded system. I ");
    delay(65535);
    write(0x80, 0);//print position
    print_msg("dded system. I l");
    delay(65535);
    write(0x80, 0);//print position
    print_msg("ded system. I lo");
    delay(65535);
    write(0x80, 0);//print position
    print_msg("ed system. I lov");
    delay(65535);
    write(0x80, 0);//print position
    print_msg("d system. I love");
    delay(65535);
    write(0x80, 0);//print position
    print_msg(" system. I love ");
    delay(65535);
    write(0x80, 0);//print position
    print_msg("system. I love e");
    delay(65535);
    write(0x80, 0);//print position
    print_msg("ystem. I love em");
    delay(65535);
    write(0x80, 0);//print position
    print_msg("stem. I love emb");
    delay(65535);
    write(0x80, 0);//print position
    print_msg("tem. I love embe");
    delay(65535);
    write(0x80, 0);//print position
    print_msg("em. I love embed");
    delay(65535);
    write(0x80, 0);//print position
    print_msg("m. I love embedd");
    delay(65535);
    write(0x80, 0);//print position
    print_msg(". I love embedde");
    delay(65535);
    write(0x80, 0);//print position
    print_msg(" I love embedded");
    delay(65535);
}