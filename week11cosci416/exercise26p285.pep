;        Nicholas Martinez
;        COSCI 416 - M 5:45pm - 10:00pm
;        M. Rettke
;        4/22/18
;
;	Convert the following C program to Pep/9
;	assembly language
;
;	#include<stdio.h>
;                
;           const int amount = 20000;
;           int num      
;           int sum
;
;           int main()
;            {
;                scanf("%d", &num);
;                sum = num + amount;
;                printf("Sum = %d\n", sum);
;
;                return 0;
;            }
;
;
;
;

	 
         BR main
amount: .WORD 20000
num:    .BLOCK 2           
sum:    .BLOCK 2
msg:    .ASCII "Sum = \x00"

main:    DECI num,d               ; Input number 
         LDWA num,d               ; Load it into accumulator 
         ADDA amount,d            ; Add amount constnat
         STWA sum,d               ; Store it back into sum
         STRO msg,d               ; Print sum
         DECO sum,d               ; with message


         STOP

         .END    