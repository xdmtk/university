; In class Assignments 
; Nick Martinez
; COSCI 416 - Rettke
; May 7th 2018
;
; if (N < 0)
; output (t)


         LDWA n,d            ; Load 'n' into accumulator
         CPWA 0,i            ; Compare 'n' with 0
         BRLT L1             ; If n is less than 0, jump to L1
         STOP                ; If not, end execution
L1:      LDBA 't',i          ; Load 't' into accumulator
         STBA charOut,d      ; Output 't'
         STOP



; if (count >= 39)
; output(1)
; else output(2)

         LDWA count,d         ; Load 'count' into accumulator
         CPWA 38,i            ; Compare 'count' with 38, optimized for greater or equal than 39
         BRGT L1              ; If count greater than or equal to 39 jump to L1
         LDBA '2',i           ; Otherwise print 2
         STBA charOut,d 
         STOP
                              
L1:      LDBA '1',i          ; Load '1' into accumulator
         STBA charOut,d      ; Output '1'
         STOP





; if (A>B)
; output(A)
; else
; output(B)



         LDWA A,d                     ; Load 'A' into accumulator
         CPWA B,d                     ; Compare 'A' with 'B'
         BRGT L1                      ; If 'A' greater than 'B' jump to L1
         LDWA B,d                     ; Otherwise print B
         STWA charOut,d 
         STOP
                              
L1:      LDWA A,d                     ; Load 'A' into accumulator
         STWA charOut,d               ; Output 'A'
         STOP




; input(N)
; while(N < 99)
; {
; 	output(N)
;	input(N)
; }
	
	DECI N,d	; Input n
L1:	CPWA 99,i	; Compare to 99
	BRGT L2		; If greater than 99, do not enter loop
	DECO N,d	; Otherwise output N
	DECI N,d	; Then input N
	BR L1		; Jump unconditonally to L1, to compare N again with 99
L2:	STOP		; Jump location when N is finally greater 99 causing stop execution




; input(N)
; while(N > 6 && N <= 10)
; {
; 	sum += N
;	input(N)
; }

sum: .BLOCK 2


	DECI N,d	; Input n
L1:	CPWA 99,i	; Compare to 6
	BRLT L2		; If less than 6, test already failed do not enter loop
	CPWA 11,i	; Optimized test for <= 10
	BRGT L2		; If second test fails, also do not enter loop
	LDWA sum,d	; Load sum into accumulator
	ADDA N,d	; Add N to sum
	STWA sum,d	; Store back into sum
	DECI, N		; Input N again
	BR L1		; Jump unconditonally to L1, start test over again
L2:	STOP	





; For (i =0; i <3 ; i++)
; {
;	For (j = 0; j < 5; j++)
;	{
;		Output('*')
;	}
;	Output('\n')
; }
	




L1:	LDWA i,d	; Start outer for loops
	CPWA 3,i	; Check condition i < 3
	BRGT L2		; If condition fails, break loop to end execution at L2
	ADDA 1,i	; If not, increment counter and execute loop body
	STWA i,d	; Store the increment back into i
L3:	LDWA j,d	; Second for loop start
	CPWA 5,i	; Check condition j < 5
	BRGT L4		; If fails, break loop to end of nested for loop at L4
	ADDA 1,i	; Otherwise increment counter
	STWA j,d	; Store increment
	LDBA '*',i	; Output '*'
	STBA charOut,d	; Using output trap
	BR L3		; Loop back to nested for loop beginning
L4:	LDBA '\n', i	; This is the rest of the loop body of the remaining for loop
	STBA charOut,d
	BR L1		; Loops back to condition check for first for loop
L2: 	STOP		; When that finally fails execution stops by a jump to L2








