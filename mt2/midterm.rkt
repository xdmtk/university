#lang racket
(define addNums 
  (lambda (lst)
    (foldl + 0 (filter number? lst))
  )
)



(define specialSquares 
  (lambda (lst)
    (define square (lambda (x) (* x x)))
    (define 3or5divisible (lambda (x) (or (= 0 (remainder x 3)) (= 0 (remainder x 5)))))
    (map square (filter 3or5divisible lst))
  )
)
(specialSquares '(5 6 7 8 9 10))
(specialSquares '(47 17 20 45 234 35 1234))


(define lista '(2 4 5 3 8 7 -5 0 3 9 10))
(define listb '("pink" "red" "orange" "red" "blue" "yellow" "tan"))

(define sortNums
  (lambda (lst)
    (sort lst (lambda (a b) (< a b) ))
  )
)
(sortNums lista)


(define sortStrings
  (lambda (lst)
    (sort lst 
          (lambda (a b) 
            (if (= (string-length a) (string-length b))
            (string<? a b)
            (< (string-length a) (string-length b)))
          )
    )
  )
)
(sortStrings listb)
(sortStrings '("pink" "red" "orange" "blue" "yellow"))
