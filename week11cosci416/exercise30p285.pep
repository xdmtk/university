;Nick Martinez
;COSCI 416 - M 5:45-10:00PM
;Mari Rettke
;4/22/18
;
; Exercise 30 p285
         BR      main        
num1:   .BLOCK 2          ; Integer Variable
num2:   .BLOCK 2          ; 
;

main:    DECI num1,d         ; Input number into num1
         LDWA num1,d         ; Load into accum
         ASRA                ; Shift right 4 times, since 2^4 = 16
         ASRA                
         ASRA
         ASRA
         STWA num2,d         ; Store back into num1
         DECO num1,d         ; Print out original number
         STRO msg1,d         ; Print out message
         DECO num2,d         ; Print out number divided by 16
         STOP 
         
         


msg1: .ASCII " Divided by 16  = \x00"

.END