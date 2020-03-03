#lang racket
; Nicholas Martinez
; Comp 333
; Homework #4
; Due Mar 10 2020

(displayln "Nicholas Martinez")


;Problem 1
;Write a recursive Scheme function ( countZeros  lst) that returns the number of 
;zeros at the top level in a given list.
;
;Example:  (countZeros   ‘( a  b  0   4 6  0  q  3   “red” 0  0 ) ) => 4

(define countZeros
  (lambda ( lst )
    (cond [ (= 0 (length lst) ) 0 ]
          [ (and (number? (car lst)) (= 0 (car lst))) (+ (countZeros (cdr lst)) 1)] 
          [ (and (number? (car lst)) (not (= 0 (car lst)))) (+ (countZeros (cdr lst)) 0)] 
          [ (not (number? (car lst))) (+ (countZeros (cdr lst)) 0)]
    )
  )
)
(countZeros   '( a  b  0   4 6  0  q  3   “red” 0  0 ) )



;Problem 2
;Write a Scheme function that computes the area of a triangle, given the (x,y) 
;coordinates of its vertices. Use Heron’s Formula:  area = sqrt( s ( s -a) (s-b) (s-c) ) 
;where a,b,c are the length of the sides and s = (a+b+c)/2 .
;
;Example:  (areaOfTriangle ‘( 3 5)  ‘( 2 9)  (10  -2) ) =>  10.4999

(define areaOfTriangle 
  (lambda (v1 v2 v3)
    (let ([a (sqrt (+ (expt (- (car v2) (car v1)) 2) (expt (- (cadr v2) (cadr v1)) 2)))]) 
        (let ([b (sqrt (+ (expt (- (car v3) (car v2)) 2) (expt (- (cadr v3) (cadr v2)) 2)))]) 
            (let ([c (sqrt (+ (expt (- (car v1) (car v3)) 2) (expt (- (cadr v1) (cadr v3)) 2)))])
                (let ([ s (/ (+ a b c) 2)])
                    (sqrt (* s (- s a) (- s b) (- s c)))
                )
            )
        )
    )
  )
)
(areaOfTriangle '( 3 5)  '( 2 9)  '(10  -2) ) 



;Problem 3
;Write a recursive Scheme function (delete x lst) that deletes all top-level 
;instances of x in the lst. Assume that lst is a list of numbers and/or symbols.
;
;Example:  ( delete  5 ‘( 3 5 6 7 5 9 ( 5 6 5)  )  => ‘( 3  6  7  9  (5 6 5) )
;Example: ( delete ‘a  ‘(3 4  b c a a ) ) => ‘(3 4   b  c)
(define delete
  (lambda (x lst)
    (cond [(null? lst) `()]
          [(if (eqv? x (car lst)) (delete x (cdr lst)) (cons (car lst) (delete x (cdr lst))))]
    )
  )
)
(delete 5 '(3 4 5))
(delete 'a '(3 4 b c a a ))
    




;Problem 4.   
;Write a Scheme function (intersection lst1  lst2) that returns the 
;intersection  of  two lists  that represent sets. Note that a set has NO duplicates!  
;Your answer must have no duplicates.
;
;Example:  (intersection   ‘(  a r d b c  e)  ‘( q w e r d t b ) ) => ‘( r d  b  e)
(define intersection
  (lambda (l1 l2)
    (filter (member l2) l1)
  )
) 
(intersection   ‘(  a r d b c  e)  ‘( q w e r d t b ) )







;Problem 5
;Write a recursive Scheme function (removeDups lst1)  to remove duplicates from a list. 
;Return a new list.  Your function should work on lists of all types. You will need to use 
;cons since you are creating a new list. Do not use sort or remove.
;
;Hint: Use recursion  and use member to test if the (car lst)  is a member of  ( cdr lst) 
;Example:(removeDups  ‘( pink  yellow red  green green  yellow) ) => ‘(pink red green yellow)



;Problem 6
;A  greenlist is a non-empty list of pairs of integers where each pair ‘( x y)  has the 
;property that y – x  = 1.  Example:  ‘(  ( 5 6)  ( 3  4)  ( 2  3)  ( -5  -4)  ) is a greenlist.
;The following items are not  greenlists:
;‘(  ( 4  7)  (  10 )  )     
;‘(  ( 4.5  5.5)  (  7  8)  )   
;‘(  ) 
;‘(  3   4   5   6)     789    “greenlist”Write a Scheme predicate, ( greenlist?    z)   
;that returns #t if z is a greenlist; 
;otherwise return false. Check ALL conditions.  Use integer? to test for an integer and list? 
;to test for aa list. Use and  and  andmap.  Write a helper function goodpair? 
;that tests if a pair meets the specifications above.



;Problem 7
;Write a non-recursive Scheme function that take a list of integers as an argument and returns a 
;list of the squares of the even numbers in the list.  Use filter, map and even?.  Do not use recursion.
;Example:  (evenSquares '( 3 5 6 2 8 9 11 10) )  =  '(36 4 64 100)



;Problem 8
;A list of persons is a list of triples with name, age and employment status. Employment status 
;will be either  “employed” or “unemployed” . As an example the list could be ‘( (joe  21  “employed”)  
;( ann 19 “unemployed”)  (sue 18 “employed” )  )
;
;Write a nonrecursive function that counts the number persons in any list of persons who have a given status.  
;Use an anonymous function, filter and length. Example: (countStatus  lst  “employed” )  returns 2 on the 
;above list. 
;(countStatus lst  “unemployed” ) returns 1 on the above list.



;Problem 9
;Write a non-recursive Scheme function that finds the average of the ages of the persons in the list of persons 
;from Problem 8  that have a given status. Use map, filter and foldr .Example (averageAge   lst  “employed) 
;returns (21+18)/2 = 19.5 on above list.

