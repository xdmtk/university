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
;           const char chConst = 'a'
;           char ch1       
;           char ch2
;
;           int main()
;            {
;                scanf("%c %c", &ch1, &ch2);
;                printf("%c\n%c\n%c\n", c1, chConst, ch2);
;
;                return 0;
;            }
;
;
;
;

	 
         BR main
chConst: .BYTE 'a'
ch1:    .BLOCK 1           
ch2:    .BLOCK 1


main:    LDBA charIn,d            ; Get char 
         STBA ch1,d               ; Store into ch1
         LDBA charIn,d            ; Get char 
         STBA ch2,d               ; Store into ch2
         LDBA ch1,d               ; Output ch1
         STBA charOut,d
         LDBA '\n',i              ; Output newline
         STBA charOut,d
         LDBA chConst,d           ; Output constant
         STBA charOut,d
         LDBA '\n',i              ; Output new line
         STBA charOut,d           
         LDBA ch2,d               ; Output ch2
         STBA charOut,d
         LDBA '\n',i              ; Output newline
         STBA charOut,d

         STOP

         .END    