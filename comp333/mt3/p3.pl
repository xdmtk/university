astar([]).
astar([X]) :- X = a.
astar([H,H|T]) :- astar([H|T]).

/* 
?- astar([]).
true.

?- astar([a]).
true .

?- astar([a, a, a, a, a, a]).
true .

?- astar([a, a, a, b, b, a, a]).
false.

?- astar([a, aa, 3, 4, 5]).
false.
*/


bstar([]).
bstar([X]) :- X = b.
bstar([H,H|T]) :- bstar([H|T]).

/*
?- bstar([]).
true.

?- bstar([b]).
true .

?- bstar([b, b, b, b, b, b, b]).
true .

?- bstar([a, a, b, b, b, b, b]).
false.

?- bstar([b, b, a, b, b]).
false.
*/



