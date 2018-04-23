;Nick Martinez
;COSCI 416 - M 5:45-10:00PM
;Mari Rettke
;4/22/18
;
; Exercise 28 p285
         BR      main        
ch:   .BLOCK 1          ; Char Variable
;

main:    LDBA charIn,d       ; Input character
         STBA ch,d           ; Store character into ch
         LDBA ch,d           ; Load back into accum
         SUBA 1,i            ; Decrement by 1
         STBA charOut,d      ; Print contents of accum
         LDBA '\n',i         ; Load '\n' into accum
         STBA charOut,d      ; Print 'n'
         STOP
         .END
         