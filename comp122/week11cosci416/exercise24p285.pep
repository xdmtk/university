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
;           int num1       
;           int num2
;
;           int main()
;            {
;                scanf("$d $d", &num1, &num2);
;                printf("%d\n%d\n", num2, num1);
;
;                return 0;
;            }
;
;
;
;

	 
         BR main
num1:    .BLOCK 2           
num2:    .BLOCK 2


main:    DECI num1,d              ; Input num1
         DECI num2,d              ; Input num2
         DECO num2,d              ; Output num2
         LDBA '\n',i              ; Output newline
         STBA charOut,d           ; 
         DECO num1,d              ; Output num1
         LDBA '\n',i              ; Output newline
         STBA charOut,d
         STOP

         .END    