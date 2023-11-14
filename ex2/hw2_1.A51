 /*    ORG 0 ; start from0000H ex3
     MOV DPTR, #TABLE ; DPTR point to TABLE
START:     MOV R0, #0 ; initialize typed signal
     MOV R1, #4 ; set 4 row
     MOV R2, #11110111B ; set first row
SCAN:      MOV A, R2 ; move R2 to A
     MOV P2, A ; input scanned signal
     JNB P2.7, KEYIN ; scan column 1
     INC R0 ; add #01 into R0
     JNB P2.6, KEYIN ; scan column 2
     INC R0 ; add #01 into R0
     JNB P2.5, KEYIN ; scan column 3
     INC R0 ; add #01 into R0
     JNB P2.4, KEYIN  
     INC R0 ; add #01 into R0
     RR A ; nextrow
     MOV R2, A ; move A to R2
     DJNZ R1, SCAN ; scan 3 rows
     SJMP START ; jump to scan keypad again
KEYIN:     CALL DEBOUNCE ; call debounce function
     MOV A, R0 ; get typed signal
     MOVC A, @A+DPTR ; accordingA, getsignal fromTABLE
     MOV P1, A ; output displayed signal
     SJMP START ; jump to scan keypad again
DEBOUNCE:  MOV R4, #50 ; move 50 times intoR4
DE_500_us: MOV R3, #250 ; move 250 times intoR3
           DJNZ R3, $ ; jump to itself R3 times
		   DJNZ R4, DE_500_us ; delay 25ms
           RET ; return to main code
TABLE: DB 10011111B; 1
       DB 00100101B; 2
       DB 00001101B; 3
       DB 00010001B;A 
       DB 10011001B; 4
       DB 01001001B; 5
       DB 01000001B; 6
       DB 11000001B; B   
       DB 00011011B; 7
       DB 00000001B; 8
       DB 00001001B; 9  
       DB 11100101B;C  
       DB 01110001B ;F
       DB 00000011B ;0
       DB 01100001B;E     
       DB 10000101B;D
    
       END */
	   ORG 0 ; start from0000H ex3
		 MOV DPTR, #TABLE ; DPTR point to TABLE
		 MOV R5, #2 ; 2 numbers
		 MOV A,#11100101B
		 MOV P1, A
		 MOV A,#0
		 MOV P2.6,A
		 
		 
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
		 MOV R6,#0
		 MOV R7,#0
		 SJMP START; jump to scan keypad again

		 
NUMBERIN:  CALL DEBOUNCE
		   MOV A, R0
		   DJNZ R5,NUMBER_ONE
		   MOV R7, A
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
		MOV B,R7
		ADD A,B
		MOV B,#00AH
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
		MOVC A , @A+DPTR
		MOV P1, A
		SJMP START

DO_SUB: CALL DEBOUNCE
	   MOV A, R6
	   MOV B, R7
	   SUBB A,B
	   MOVC A, @A+DPTR
	   MOV P1, A
	   SJMP START
TABLE: 
       DB 10011111B; 1
       DB 00100101B; 2
       DB 00001101B; 3 
       DB 10011001B; 4
       DB 01001001B; 5
       DB 01000001B; 6   
       DB 00011011B; 7
       DB 00000001B; 8
       DB 00001001B; 9 
       END


