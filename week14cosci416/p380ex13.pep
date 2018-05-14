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
;	
;
;	int main()
;	{
;		char ch;
;		scanf("%c", &ch")
;		if ((ch >= 'A') && (ch <= 'Z'))
;		{	
;			printf("A");
;		}
;                      else if  ((ch >= 'a') && (ch <= 'z'))
;	           {
;                            printf("a");
;                      }
;                      else
;                      {
;                            printf("$");
;                      }
;		return 0;
;	}


	 
         BR main

ch: .BLOCK 1



main:    LDBA charIn ,d       ; Input number from terminal 
if1:     CPBA 'A',i







         .END