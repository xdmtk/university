#lang racket
; Nicholas Martinez
; Comp 333
; Homework #3
; Due Date: Feb 20

(displayln "Nicholas Martinez")

;Convert the following arithmetic expressions into Scheme expressions.
;Use Java operator precedence rules.
;Enter your expressions into the DR Racket Edit Window Run to confirm the results.
;a.( 300 + 5) / ( 7.0 *12 – 70) * (1001)
(* (/ ( + 300 5 ) (- (* 7.0 12) 70)) 1001)

;b. 12 + sqrt( 12*12 - 4*2*5) /( 2*2)
(+ 12 ( / (sqrt (* (* 12 12) (* 4 2 5))) (* 2 2)))


;Write a single expression to find the difference between the smallest and largest of numbers a,b,c,d.
;Hint: Use min and max. To test use define to set values for a,b,c,d in the edit file.
;Your expression should work for any 4 numbers in any order.
;Test on the values  1  2  3  4;   7  50  3  4;  -4   -5  -7  9.
(- (max 1 2 3 4) (min 1 2 3 4))
(- (max 7 50 3 4) (min 7 50 3 4))
(- (max -4 -5 -7 9) (min -4 -5 -7 9))


;Write an expression the determines if x lies between  200 and 500 or if x equals -1.
;Do not use an if. Use an or.
;Test on x  300, -1  10
(define x 300)
(or (and (< x 500) (> x 200)) (= x -1))
(set! x -1)
(or (and (< x 500) (> x 200)) (= x -1))
(set! x 10)
(or (and (< x 500) (> x 200)) (= x -1))


