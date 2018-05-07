;Nick Martinez
;COSCI 416 - Rettke
;May 6th 2018
;
;
;        Mystery Program: Comments
;
         BR      main        
n1:      .BLOCK  2           ;#2d
n2:      .BLOCK  2           ;#2d
n3:      .BLOCK  2           ;#2d
;
main:    DECI    n2,d             ; Input the first two numbers in the input window      
         DECI    n3,d             ; Equivalent to scanf("%d %d", &n2, &n3)

         LDWA    n2,d             ; Load n2 into accumulator
         CPWA    n3,d             ; Compare n2 against n3
         BRLT    L1               ; Jump (branch) to L1 label if n2 is less than n3

         DECI    n1,d             ; Only enters this code section if n2 greater than n3        
         LDWA    n1,d             ; In which it inputs the next number in the input into n1
         CPWA    n3,d             ; Loads it into the accumulator, and compares it against n3
         BRLT    L7               ; Jump to L7 label if n1 is less than n3
         BR      L6               ; If n1 is greater than n3, jump unconditionally to L6


         STWA    n3,d             ; This line of code never gets executed following an unconditional jump        


L1:      DECI    n1,d             ; Input another number from the terminal
         LDWA    n2,d             ; Load n2 into the accumulator
         CPWA    n1,d             ; Compare n2 to n1
         BRLT    L5               ; If n2 is greater than n1, jump to L5 
         DECO    n1,d             ; Otherwise print out n1 and n2
         DECO    n2,d        


L2:      DECO    n3,d             ; Prints n3
         STOP                     ; Ends program


L3:      DECO    n2,d             ; Prints n2 and n3 then jumps to L9
         DECO    n3,d        
         BR      L9          


L4:      DECO    n1,d             ; Prints out n1 and n2 
         DECO    n2,d             ; then ends the program
         STOP                
         STWA    n1,d             ; This line of code never gets executed


L5:      LDWA    n3,d             ; Loads n3 into accumulator        
         CPWA    n1,d             ; Compares to n1
         BRLT    L3               ; Jumps to L3 if n3 is less than n1


         DECO    n2,d             ; Otheriwse print out n2 and then n1      
         DECO    n1,d             
         BR      L2               ; Then jump to L2

      
L6:      DECO    n3,d             ; Print n3
         LDWA    n1,d             ; Load n1 into accumulator
         CPWA    n2,d             ; Compare to n2
         BRLT    L4               ; Jump to L4 if n1 is less than n2
         BR      L8               ; Otherwise jump to L8 



L7:      DECO    n1,d             ; Print out n1 n2 and n3 then stop     
         DECO    n3,d        
         DECO    n2,d        
         STOP                

L8:      DECO    n2,d             ; Print n2, then fall through to L9
L9:      DECO    n1,d             ; Print n1, then stop execution
         STOP                
         .END                  
