;Nick Martinez
;COSCI 416 - M 5:45-10:00PM
;Mari Rettke
;4/22/18
         BR      main        
perim:   .BLOCK 2          ; Integer variables
width:   .BLOCK  2         ; int perim, width, length         
length:   .BLOCK  2           
;

main:    DECI width,d        ; Get both width and length from input
         DECI length,d
         LDWA width,d        ; Load width into accumulator
         ADDA length,d       ; Add length to accumulator
         ASLA                ; Left bit shift == multiplying by two, since bit position represent 2^n
         STWA perim,d        ; Store contents of accumulator into perim
         STRO msg,d          ; Output message
         DECO perim,d        ; Output perimeter
         STOP


msg: .ASCII "Perimeter = \x00"
     .END
         