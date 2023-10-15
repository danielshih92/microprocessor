ORG 0000h
JMP LOOP ;jump into loop
ORG 0030h
LOOP: MOV SP, #32h ;SP = #32H
      MOV A, #0xFC ;A = #0xfc
	  MOV R0,#0;
      MOV P2, A ;P2 = A
      SETB P1.0 ;set push to high
      SETB P1.2 ;set pop to high 
//MOV R0, #8D ;set the execution times of marquee
JMP MARQUEE ;jump into marquee when p1.0 is low
JMP LOOP ;infinite loop
MARQUEE: //PUSH 00h ;push the value of R0 into stack
        MOV R1, #250D ;set the execution times of DELAY1
       CALL DELAY ;call DELAY1
       //POP 00h ;pop out the value of R0 which is pushed in line11
        RL A ;left rotate
        MOV P2, A ;set the value of A into P2
		JNB P1
        DJNZ R1, MARQUEE ;loop back until MARQUEE execute 8 times
        JMP LOOP ;end of MARQUEE, back to LOOP

DELAY:


END