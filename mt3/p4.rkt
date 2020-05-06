#lang racket

(define a 10)
(define poly
  (lambda (a b c)
    (let ( [b a] [a 5])
      (lambda (x)
        (+ ( * a x x ) (* b x) c )
      )
    )
  )
)

(define f (poly a 2 3))

(require racket/trace)
(trace f)
(trace poly)
(f 4)
((poly 4 6 2) a)


#|
What is the value of   ( f   4)  when the code above is run in Dr Racket?  Show, in detail, how the answer was computed
in Scheme. Trace the main steps of the computation by hand (typing ok).  That is, how do you get from ( f  4) to the
numeric answer?  Do not include the Prolog trace.

When (f 4) is called, a definition for the identifier `f` is searched in Rackets symbol table.
There it finds the definition for `f` saying that it is bound to the function `poly` with the parameters (a 2 3)
Next, `a` is found also in the symbol table to be 10.

Poly is then executed with the parameters 10 2 and 3
Then there is a binding of b to a, which a is defined as 10, and then binding a to 5

Then the inner lambda is executed with f's original parameter 4

This results in (+ ( * 5 4 4 ) (* 10 4) 3)

Which evaluates to ( + 80 40 3 )

Which results in 123




For `(poly 4 6 2)`
|#