;	Convert the following C program to Pep/9 
;	assembly language
;
;	#include<stdio.h>
;	int main()
;	{
;		int number;
;		scanf("%d", &number")
;		if (number % 2 == 0) 
;		{
;			printf("Even\n");
;		}
;		else
;		{
;			printf("Odd\n");
;		}
;		return 0;
;	}
         BR main

number: .BLOCK 2
msgodd: .ASCII   "Odd\n\x00"
msgeven:.ASCII   "Even\n\x00" 

main:    DECI number,d       ; Input number from terminal
         LDWA number,d       ; Load into accumulator
if:      ANDA 0x1,i          ; AND with 0000 0001 
         CPWA 1,i            ; If 1 bit is set, then number must be odd
         BRNE even           ; So if the AND'd variable is odd, then CPWA will 
odd:     STRO msgodd,d       ; Produce equal result, therefore print odd msg
         STOP                ; and stop
even:    STRO msgeven,d      ; Otherwise jump to even 
         STOP                ; and stop
         .END