;Nick Martinez
;COSCI 416 - M 5:45-10:00PM
;Mari Rettke
;4/22/18
;
; Exercise 29 p285
         BR      main        
num1:   .BLOCK 2          ; Integer Variable
num2:   .BLOCK 2          ; 
;

main:    DECI num1,d         ; Input number into num1
         LDWA num1,d         ; Load num1 into accum
         NEGA                ; Negative on accum
         STWA num2,d         ; Store result in num2
         STRO msg1,d         ; Print msg1
         DECO num1,d         ; Print num1
         LDBA '\n', i        ; Prelude for newline output
         STBA charOut,d      ; Output newline
         STRO msg2,d         ; Print msg2
         DECO num2,d         ; Print num2
         LDBA '\n',i         ; Prelude for newline
         STBA charOut,d      ; Output newline
         STOP
 

msg1: .ASCII "Num 1  = \x00"
msg2: .ASCII "Num 2 = \x00"

.END