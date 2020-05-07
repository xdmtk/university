#lang racket


#|
(15 pts) Write a Scheme function ,  ( maxFunc  f   a   b) ,  that finds the maximum value of the function f evaluated
on the integers a, a+1, a+2, ..., b  . Assume that a and b are integers ; a <= b ; and that f is a function defined on
these integers. For example, (maxFunc  sqr 4  7) returns 49 since 49 is the largest value of sqr on the range 4,5,6,7.

|#

(define maxFunc
    (lambda (f a b)
        (car
            (sort
                (map f (range a (+ b 1))) >
            )
        )
    )
)

(maxFunc sqr 4 7)
(maxFunc (lambda (x) (+ ( * -1 x x x ) (* 7 x x) (* -10 x))) 0 5)
(maxFunc (lambda (x) (sqr (+ x 4))) -10 0)
(maxFunc sin 0 10)
