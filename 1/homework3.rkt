#lang racket
; Nicholas Martinez
; Comp 333
; Homework #3
; Due Feb 20 2020

(displayln "Nicholas Martinez")


;Problem 1
;Convert the following arithmetic expressions into Scheme expressions.
;Use Java operator precedence rules.
;Enter your expressions into the DR Racket Edit Window Run to confirm the results.
;a.( 300 + 5) / ( 7.0 *12 – 70) * (1001)
(displayln "Problem 1")
(* (/ ( + 300 5 ) (- (* 7.0 12) 70)) 1001)

;b. 12 + sqrt( 12*12 - 4*2*5) /( 2*2)
(+ 12 ( / (sqrt (* (* 12 12) (* 4 2 5))) (* 2 2)))


;Write a single expression to find the difference between the smallest and largest of numbers a,b,c,d.
;Hint: Use min and max. To test use define to set values for a,b,c,d in the edit file.
;Your expression should work for any 4 numbers in any order.
;Test on the values  1  2  3  4;   7  50  3  4;  -4   -5  -7  9.
(displayln "Problem 2")
(define small_large_distance
  (lambda (a b c d)
    (- (max a b c d) (min a b c d))
  )
)
(small_large_distance 1 2 3 4)
(small_large_distance 7 50 3 4)
(small_large_distance -3 -5 -7 9)


;Problem 3
;Write an expression the determines if x lies between  200 and 500 or if x equals -1.
;Do not use an if. Use an or.
;Test on x  300, -1  10
(displayln "Problem 3")
(define two_five_one 
  (lambda (x) 
    (or (and (< x 500) (> x 200)) (= x -1))
  )
)
(two_five_one 300)
(two_five_one -1)
(two_five_one 10)


;Problem 4
;Define a lambda expression that returns the product of 3 arguments.  
;Test on 20 30 11
(displayln "Problem 4")
(define p3
  (lambda (a b c)
    ( * a b c )
    )
  )
(p3 20 30 11)


;Problem 5
;Define a Scheme function average that returns the average of 3 arguments.
;( average  4 7 4 )  => 5  Test on the numbers 6 4 8;  9 10 12;  -4 8 -2
(displayln "Problem 5")
(define average
  (lambda (x y z)
    (/ (+ x y z) 3)
  )
)
(average 6 4 8)
(average 9 10 12)
(average -4 8 -2)


;Problem 6
;Define a Scheme function evalPoly to evaluate the expression 
;ax2 +bx + c where a, b, c and x are arguments.
;( evalPoly   1  2  3  5  ) => eval x2 + 2x + 3 at x =5  => 38  . 
;Test on 5 8 4 10;   -2  -3  17 13

(displayln "Problem 6")
(define polynomial
  (lambda (a b c x)
   ( + ( * a (* x x) ) (* b x) c)
))
(polynomial 5 8 4 10)
(polynomial -2 -3 17 13)


;Problem 7
;Write a Scheme function that returns the middle value from a 
;list of 3 numbers. For example,
; (middle  ‘ (7  2  4) ) returns 4 . Use cond. 
;Do not use sort. Test on numbers  3 4 5;   5 3 8; 3 10 7

(displayln "Problem 7")
(define mid
  (lambda (a b c) 
    (cond [(not (member a (list (max a b c) (min a b c)))) (displayln a)]
          [(not (member b (list (max a b c) (min a b c)))) (displayln b)]
          [(not (member c (list (max a b c) (min a b c)))) (displayln c)])                                                 
))
(mid 3 4 5)
(mid 5 3 8)
(mid 3 10 7)


;Problem 8
;Write a Scheme function  (greater?  point1  point2) that
;returns true if point1 is further from the origin than point2
; otherwise returns false.  Here point1 and points2 are lists of 2 numbers.
;For example ( greater ‘(10  6)  ‘( 2  3) )
;returns true since the point ( 10  6) is further from the origin than point ( 2  3).
;Test on points  ( 5 6)  ( 7 8) ;  ( 10 9) ( -1  -2) ;   ( 3 2)  ( -3  2)
;[Hint: first write a Scheme function (distOrigin  point) that computes the distance
;of a point from the origin. Define it as a nested function using let.]


(displayln "Problem 8")
(define greater? 
  (lambda (point1 point2)
    (let 
      ([
          distOrigin (lambda (point)
            (sqrt (+ (* (car point) (car point)) (* (cadr point) (cadr point))))
          )
        ])
      (> (distOrigin point1) (distOrigin point2) )
    )
  )
)
(greater? (list 5 6) (list 7 8))
(greater? (list 10 9) (list -1 -2))
(greater? (list 3 2) (list -3 2))


;Problem 9
;Exercise . Define recursive Scheme function  gcd to find the greatest common 
;divisor of two non-negative  integers.Use the following recursive definition. 
;The is pseudo code. You need to translate this into Scheme. Use cond.  Test on the 
;numbers    24  36;   315 30 ;  763  19835 ;   2001  179 ; 112  792

;if (  a == 0  and b == 0)   
;    “No greatest common divisor of 0 0 “
;else if ( b == 0)
;    a
;else if ( a == 0)       
;    b
;else if ( a >= b)    
;    gcd( a – b, b) 
;else     
;    gcd ( a, b-a)


(displayln "Problem 9")

