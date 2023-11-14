/*		 ORG 0 ; start from0000H ex3
		 MOV DPTR, #TABLE ; DPTR point to TABLE
		 MOV R5, #2 ; 2 numbers
		 
		 
START:   MOV R0, #1 ; initialize typed signal
		 MOV R1, #4 ; set 4 row
		 MOV R2, #11110111B ; set first row
		   
SCAN:    MOV A, R2 ; move R2 to A
		 MOV P2, A ; input scanned signal
		 JNB P2.7, NUMBERIN ; scan column 1
		 INC R0 ; add #01 into R0
		 JNB P2.6, NUMBERIN ; scan column 2
		 INC R0 ; add #01 into R0
		 JNB P2.5, NUMBERIN ; scan column 3
		 INC R0 ; add #01 into R0
		 JNB P2.4, KEYIN  
		 RR A ; nextrow
		 MOV R2, A ; move A to R2
		 DJNZ R1, SCAN ; scan 3 rows
		 SJMP START ; jump to scan keypad again
		 
		 
		 
		 
KEYIN:   CALL DEBOUNCE ; call debounce function
		 MOV A, R0 ; get typed signal
		 JNB P2.3,DO_ADD
		 JNB P2.2,DO_SUB
		 JNB P2.1,DO_MUL
		 JNB P2.0,DO_DIV
		 SJMP START; jump to scan keypad again

		 
NUMBERIN:  CALL DEBOUNCE
		   MOV A, R0
		   DJNZ R5,NUMBER_ONE
		   MOV B, A
		   MOV R5,#2
		   SJMP START
NUMBER_ONE: MOV R6, A
			SJMP START
			
DEBOUNCE:  MOV R4, #50 ; move 50 times intoR4
DE_500_us: MOV R3, #250 ; move 250 times intoR3
           DJNZ R3, $ ; jump to itself R3 times
		   DJNZ R4, DE_500_us ; delay 25ms
           RET ; return to main code

		
DO_ADD: CALL DEBOUNCE
		MOV A,R6
		ADD A,B
		MOV B,#10
		DIV AB
		MOVC A, @A+DPTR
		CALL DEBOUNCE
		MOV P1, A
		CALL DEBOUNCE
		CALL DEBOUNCE
		CALL DEBOUNCE
		CALL DEBOUNCE
		CALL DEBOUNCE
		CALL DEBOUNCE
		MOV A,B
		MOVC A , @A+DPTR
		MOV P1, A
		SJMP START

DO_SUB: CALL DEBOUNCE
	   MOV A, R6
	   SUBB A,B
	   MOVC A, @A+DPTR
	   MOV P1, A
	   SJMP START
	   
DO_MUL:CALL DEBOUNCE
	   MOV A, R6
	   MUL AB
	   CALL DEBOUNCE
	   MOV B,#10
	   DIV AB
	   MOVC A, @A+DPTR
	   MOV P1, A
	   CALL DEBOUNCE
	   CALL DEBOUNCE
	   CALL DEBOUNCE
		CALL DEBOUNCE
		CALL DEBOUNCE
		CALL DEBOUNCE
	   MOV A,B
	   MOVC A, @A+DPTR
	   MOV P1, A
	   LJMP START
DO_DIV:CALL DEBOUNCE
	   DIV AB
	   CALL DEBOUNCE
	   MOVC A, @A+DPTR
	   MOV P1, A
	   CALL DEBOUNCE
	   CALL DEBOUNCE
	   CALL DEBOUNCE
	   CALL DEBOUNCE
	   CALL DEBOUNCE
	   CALL DEBOUNCE
	   MOV A,B
	   MOVC A, @A+DPTR
	   MOV P1, A
	   LJMP START
	   
TABLE: DB 00000011B ; display 0
       DB 10011111B; 1
       DB 00100101B; 2
       DB 00001101B; 3 
       DB 10011001B; 4
       DB 01001001B; 5
       DB 01000001B; 6   
       DB 00011011B; 7
       DB 00000001B; 8
       DB 00001001B; 9 
       END */
	   
	   
	   /*ex4_hard*/
	   /*
	   ORG 0 ; start from 0000H
			MOV DPTR, #TABLE ; DPTR point to TABLE
			MOV R5, #2 ; run two times
			
START: 		MOV R0, #1 ; R0 current at which number
			MOV R1, #4 ; total 4 row(R1)
			MOV R2, #11110111B ; set first row
			
SCAN: 		MOV A, R2 ;R2 current at which row
			MOV P2, A
			
			JNB P2.7, NUMBERIN ; scan column 1
			INC R0
			JNB P2.6, NUMBERIN ; scan column 2
			INC R0 
			JNB P2.5, NUMBERIN ; scan column 3
			INC R0
			
			JNB P2.4, KEYIN    ; scan column 4*****
			
			RR A               ; next row
			MOV R2, A          ; change R2 (to next row)
			
			DJNZ R1, SCAN      ; run above four times (scan 4 rows)
			
			SJMP START ; 
			
			
NUMBERIN:	CALL DEBOUNCE ; call debounce function
			MOV A, R0 ; (R0) at which number?
			
			DJNZ R5,NUM_ONE
			MOV R6,A                ;R6 = number 2
			MOV R5,#2
			SJMP START 
NUM_ONE:	MOV B,A					;B = number 1
			SJMP START 
			
KEYIN: 		CALL DEBOUNCE 
			JNB P2.3, PLUS
			JNB P2.2, MINUS
			JNB P2.1, MULTIPUL
			JNB P2.0, DIVIDE


PLUS:		MOV  A,R6
			ADD	 A,B
			
			MOV	 B,#10 ;solve ten 
			DIV AB     ;solve ten
			
			
			MOVC A, @A+DPTR
			MOV P1, A 
			CALL delay
			CALL delay
			CALL delay
			MOV  A,B
			MOVC A, @A+DPTR
			MOV P1, A 
			
			
			CALL delay;
			MOV R5,#2
			SJMP START
MINUS:		MOV  A,R6
			SUBB A,B
			CALL delay
			
			
			MOVC A, @A+DPTR 
			MOV P1, A 
			
			
			MOV R5,#2
			SJMP START
MULTIPUL: 	MOV  A,R6
			MUL  AB
			CALL delay
			
			MOV	 B,#10
			DIV AB
			
			MOVC A, @A+DPTR ;
			MOV P1, A
			CALL delay
			CALL delay
			CALL delay
			
			MOV  A,B
			MOVC A, @A+DPTR 
			MOV P1, A     
			CALL delay
			SJMP START
DIVIDE:		MOV  A,R6
			DIV  AB
			;CALL delay------
			MOVC A, @A+DPTR
			MOV P1, A 
			CALL delay
			CALL delay;+++++
			CALL delay
			MOV  A,B
			MOVC A, @A+DPTR 
			MOV P1, A 
			;----CALL delay
			MOV R5,#2
			LJMP START			
			
DEBOUNCE: 	MOV R4, #50 ; move 50 times into R4
DE_500_us: 	MOV R3, #250 ; move 250 times into R3
			DJNZ R3, $ ; jump to itself R3 times
			DJNZ R4, DE_500_us ; delay 25ms
			RET
			
delay: 		MOV R4, #250 ; move 50 times into R4
delayloop: 	MOV R3, #250 ; move 250 times into R3
			DJNZ R3, $ ; jump to itself R3 times
			DJNZ R4, delayloop ; delay 25ms
			RET
			
TABLE: 		DB 00000011B ; display 0
			DB 10011111B ; display 1
			DB 00100101B ; display 2
			DB 00001101B ; display 3
			DB 10011001B ; display 4
			DB 01001001B ; display 5
			DB 01000001B ; display 6
			DB 00011011B ; display 7
			DB 00000001B ; display 8
			DB 00001001B ; display 9
			END
	   */
	   
ORG 0000h
JMP LOOP ;jump into loop
ORG 0030h
LOOP: MOV SP, #32h ;SP = #32H
MOV A, #0xFE ;A = #0xfe
MOV P2, A ;P2 = A
SETB P1.0 ;set p1.0 to high
MOV R0, #8D ;set the execution times of marquee
JNB P1.0, MARQUEE ;jump into marquee when p1.0 is low
JMP LOOP ;infinite loop
MARQUEE: PUSH 00h ;push the value of R0 into stack
MOV R0, #250D ;set the execution times of DELAY1
CALL DELAY1 ;call DELAY1
POP 00h ;pop out the value of R0 which is pushed in line11
RL A ;left rotate
MOV P2, A ;set the value of A into P2
DJNZ R0, MARQUEE ;loop back until MARQUEE execute 8 times
JMP LOOP ;end of MARQUEE, back to LOOP
DELAY1: PUSH 00h ;push the remain times of DELAY1 into stack
MOV R0, #250D ;set the execution times of DELAY2
CALL DELAY2 ;call DELAY2
POP 00h ;pop the remain times of DELAY1 back to R0
DJNZ R0, DELAY1 ;loop until R0 is 0
RET ;return to MARQUEE
DELAY2: DJNZ R0, DELAY2 ;loop until R0 is 0
RET ;return to DELAY1
END
