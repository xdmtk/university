;        Nicholas Martinez
;        COSCI 416 - M 5:45pm - 10:00pm
;        M. Rettke
;        5/14/18
;
;	Convert the following C program to Pep/9
;	assembly language
;
;	#include<stdio.h>
;
;	const int limit = 5;
;
;	int main()
;	{
;		int number;
;		scanf("%d", &number")
;		while (number < limit)
;		{	
;			number++;
;			printf("%d", number);
;		}
;	
;
;
;		return 0;
;	}


	 
         BR main

number: .BLOCK 2
limit: .EQUATE 5


main:    DECI number,d       ; Input number from terminal
while:   LDWA number,d       ; Load into accumulator
         CPWA limit,i        ; Compare number to constant
         BRGE done            ; If (number < 5) do not branch 
         ADDA 1,i            ; Add 1 to number
         STWA number,d       ; Store number
         DECO number,d       ; Output number
         LDBA ' ',i          ; Print space
         STBA charOut,d
         BR while            ; Go back to loop condition
done:    STOP
         
         .END