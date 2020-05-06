
% Problem 1
minlist([H], R) :- R = H.
minlist([H|T],R):-
    minlist(T,Tmin),
    H < Tmin,
    R = H.
minlist([H|T],R):-
    minlist(T,Tmin),
    H >= Tmin,
    R = Tmin.

/* Test cases

?- minlist([7, 4, 3, 8, 9, 10, 3], R).
R = 3 .

?- minlist([19], R).
R = 19 .

?- minlist([4, -3, 8, 9, -2, 10], R).
R = -3 .

?- minlist([], R).
false.

*/
