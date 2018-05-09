; Nicholas Martinez
; COSCI 416 - Rettke
; May 6th 2018
;
;
;
; Write and test a Pep 9 assembly language program that inputs the total number of
; bottles, that the farmer needs to ship and ouputs the cost of mailing them
;
; A box can hold 8 bottles and cost 16$ to mail
; Partially filled boxes cost $3 for each bottle




         BR      main        
bottles:          .BLOCK  2                 ; Bottles variable
fboxnum:          .BLOCK  2                 ; How many full boxes 
fboxcost:         .BLOCK  2             ; Cost of full boxes
pboxnum:          .BLOCK 2                  ; How many partial boxes
pboxcost:         .BLOCK 2               ; Variable for partial cost 
total:            .BLOCK 2                  ; Variable for finalcost = cost+partial 
dsign:            .EQUATE    '$'
;


; Summary of main function:
;        
;        We begin by getting the input for amount of bottles
;        Next we divide that by 8 and store the result in another variable
;
;        We use that variable and multiply it by 16 to get the cost for our
;        full boxes to mail.
;
;        Next we reuse the amount of bottles to find the number of bottles 
;        in the partial box, if any
;
;        This is done by ANDing the remaining bits behind the 8 bit
;        and multiplying them by 3 to get the cost
;
;        Finally we can total the cost for both partial and full
;        into another variable and display the output




main:    STRO prompt,d
         DECI bottles,d

         LDWA bottles,d                   ; Load bottles into accumulator
         ASRA                             ; Shift 3 times so 8 bit is 1 bit
         ASRA                             ; This gives the result of bottles divided by 8
         ASRA                             ; Which is how many full boxes to mail
         STWA fboxcost,d                  ; Store this in the cost and also save the number in additonal
         STWA fboxnum,d                   ; variable to display later

        
         LDWA fboxcost,d                  ; Load cost back into accumulator and multiply by 16 to get actual cost
         ASLA                             ; 4 Left shits multiplies by 16
         ASLA
         ASLA
         ASLA
         STWA fboxcost,d                  ; Store result back into cost

         
 


         LDWA bottles,d                   ; Get the modulus 8 of entered amount
         ANDA 0x7,i                       ; By ANDing it with the digits not divisible
         STWA pboxnum,d                   ; by 8, store it in partial




         LDWA total,d                     ; Load final cost into accumulator
         ADDA pboxnum,d                   ; ADD pboxnum 3 times into the accumulator,
         ADDA pboxnum,d                   ; To emulate a multiply by 3 operation
         ADDA pboxnum,d                   ;   
         STWA total,d                     ; Store back into toal cost
         STWA pboxcost, d                 ; Also store it in a variable




         LDWA total,d                      ; Load final fboxcost variable into accumulator
         ADDA fboxcost,d                   ; Add the cost from full boxes to it
         STWA total,d                      ; Store it back into final cost from accumulator






         STRO fullb,d                      ; Begin output sequence

         DECO fboxnum,d                    ; Amount of full boxes to mail : %d
         
         STRO costb,d                      ; The cost of full boxes: $%d     
         LDBA '$',i
         STBA charOut,d
         DECO fboxcost,d

         STRO partialb, d                  ; The cost of a partial box: $%d
         LDBA '$',i
         STBA charOut,d
         DECO pboxcost, d

         LDBA '\n',i                      ; Spacing for output clarity
         STBA charOut,d
         LDBA '\n',i
         STBA charOut,d

         STRO finalb1,d                    ; The total cost to mail $%d bottles: $%d
         DECO bottles,d
         STRO finalb2,d
         LDBA '$',i
         STBA charOut,d
         DECO total,d
  
         

         STOP              


; List of ASCII messages to display

prompt: .ASCII "Enter amount of bottles to mail: \x00"
fullb: .ASCII "\nThe amount of full boxes to mail: \x00"
costb: .ASCII "\nThe cost of the full boxes: \x00"
partialb: .ASCII "\nThe cost of a partial box: \x00"
finalb1: .ASCII "\nThe total cost to mail \x00"
finalb2: .ASCII " bottles: \x00"

.END