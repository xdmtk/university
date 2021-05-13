; Nicholas Martinez
; COSCI 416 - M 5:45 - 10:00PM
; M. Rettke
; May 28th 2018
; Final Exam
;
;File: fig0648.pep
;Computer Systems, Fifth edition
;Figure 6.48
;
         BR      main        
data:    .EQUATE 0           ;struct field #2d
next:    .EQUATE 2           ;struct field #2h
p2check: .BLOCK 2
;
;******* main ()
p2:      .EQUATE 8           ; local #2h
first2:  .EQUATE 6           ; local #2h
first:   .EQUATE 4           ;local variable #2h
p:       .EQUATE 2           ;local variable #2h
value:   .EQUATE 0           ;local variable #2d

rmsg:    .ASCII "In reverse:\n\x00"

;; Original Program
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

main:    SUBSP   10,i         ;push #p2 #first2 #first #p #value
         LDWA    0,i         ;first = 0
         STWA    first,s     
         DECI    value,s     ;scanf("%d", &value);




while:   LDWA    value,s     ;while (value != -9999)
         CPWA    -9999,i     
         BREQ    endWh  
     
         LDWA    first,s     ;p = first
         STWA    p,s         

         LDWA    4,i         ;first = (struct node *) malloc(sizeof(struct node))
         CALL    malloc      ;allocate #data #next 
         STWX    first,s     

         LDWA    value,s     ;first->data = value
         LDWX    data,i      
         STWA    first,sfx   

         LDWA    p,s         ;first->next = p
         LDWX    next,i      
         STWA    first,sfx   

         DECI    value,s     ;scanf("%d", &value)
         BR      while       



endWh:   LDWA    first,s     ;for (p = first
         STWA    p,s         




for:     LDWA    p,s         ;p != 0
         CPWA    0,i         
         BREQ    endFor      
         LDWX    data,i      ;printf("%d ", p->data)
         DECO    p,sfx       
         LDBA    ' ',i       
         STBA    charOut,d   
         LDWX    next,i      ;p = p->next)
         LDWA    p,sfx       
         STWA    p,s         
         BR      for         



endFor:  BR      reverse

         STOP     

;; Original Program End
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;




;; Addition for Final
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

reverse: LDWA 0,i             ; Begin reverse sequence 
         STWA first2,s        ; Set first2 = 0
         LDWA first,s         ; p = first
         STWA p,s            

for2:    LDWA p,s             ; Check address of p for null (next member)
         ADDA 2,i             ; Adding 2 to heap pointer location for next member
         STWA p2check,d       ; Store this value in global as to not change the 
         LDWA p2check,n       ; actual p pointer, load the next value into accumulator
         CPWA 0,i             ; Determine if were at end of list, p->next == 0

         BREQ lastrun        ; If so, jump to last iteration, since we need to get the last data
         LDWA first2,s       ; p2 = first2
         STWA p2,s           ; 
         
         LDWA 4,i            ; first2 = malloc()
         CALL malloc         ; allocate #data #next
         STWX first2,s

         LDWA    p,sf         ;first->next = p
         STWA    first2,sf    ;Store value of first list to second list  
         LDWA    p2,s         ; Set first2->next to p2
         LDWX    first2,s     ; Access first2 next member by increment it by 2
         ADDX    2,i          ; 

         STWX    first2,s     ; Store address back to first2
         LDWA    p2,s         ; Load value of p2 to accumulator
         STWA    first2,sf    ; Store at first2->next

         LDWA    p,s          ; Traverse the heap in reverse
         SUBA    4,i          ; By moving directly to next data item
         STWA    p,s

         BR      for2



lastrun: LDWA first2,s       ; p2 = first2
         STWA p2,s
         
         LDWA 4,i            ; first2 = malloc()
         CALL malloc         ; allocate #data #next
         STWX first2,s

         LDWA    p,sf         ;first->next = p
         STWA    first2,sf    ;Store value of first list to second list  
         LDWA    p2,s         ; Set first2->next to p2
         LDWX    first2,s     ; Access first2 next member by increment it by 2
         ADDX    2,i          ; 

         STWX    first2,s     ; Store address back to first2
         LDWA    p2,s         ; Load value of p2 to accumulator
         STWA    first2,sf    ; Store at first2->next

         LDWA    p,s          ; Traverse the heap in reverse
         SUBA    4,i          ; By moving directly to next data item
         STWA    p,s
         LDBA    '\n',i
         STBA charOut,d
         LDBA    '\n',i
         STBA charOut,d
         STRO rmsg,d 



prntrvrs:LDWA    first2,s    ; Load first2 which should be pointing to last next member
         SUBA    2,i         ; Subtract 2 to get to data member
         STWA    first2,s    ; Store data member address back to stack
         DECO    first2,sf   ; Output the contents of data member address
         LDBA    ' ',i       ; Print space
         STBA    charOut,d 
         LDWA    first2,s    ; Reload first2 (data member address)
         ADDA    2,i         ; Add 2 to get back to next member
         STWA    first2,s    ; Store next member address of stack
         LDWX    first2,sf   ; Load the contents ofaddress of the next member into index
         STWX    first2,s    ; Store that back on to stack
         LDWA    first2,s    ; Check to see if its the last member (0000 next address)
         CPWA    0,i         ; If it is, end the program
         BREQ    endfor2     ;
         BR prntrvrs         ; Otherwise start loop again
         



endfor2: STOP


;; End Addition for Final
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

                         


;
;******* malloc()
;        Precondition: A contains number of bytes
;        Postcondition: X contains pointer to bytes
malloc:  LDWX    hpPtr,d     ;returned pointer
         ADDA    hpPtr,d     ;allocate from heap
         STWA    hpPtr,d     ;update hpPtr
         RET                 
hpPtr:   .ADDRSS heap        ;address of next free byte
heap:    .BLOCK  1           ;first byte in the heap
         .END                      
