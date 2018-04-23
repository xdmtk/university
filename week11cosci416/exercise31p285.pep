;Nick Martinez
;COSCI 416 - M 5:45-10:00PM
;Mari Rettke
;4/22/18
;
; Exercise 31 p285
         BR      main        
num1:   .BLOCK 2          ; Integer Variable
num2:   .BLOCK 2          ; 
;

main:    DECI num1,d               ; Input number into num1
         LDWA num1,d               ; Load into accum
         ANDA 15,i                 ; AND with 15 to get modulus
         STWA num2,d               ; Since 15 == 00001111
         DECO num1,d               ; Which would only produce numbers
         STRO msg1,d               ; 0 -15 meaning all the numbers of the given
         DECO num2,d               ; inputted number that arent dividable by 16
                                   ; i.e. the remainder
         STOP 
         
         


msg1: .ASCII " Modulus 16  = \x00"

.END