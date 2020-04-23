% Problem 1 - Min3

min3(X,Y,Z,R) :-  X =< Y, X =< Z, R = X.
min3(X,Y,Z,R) :-  Y =< X, Y =< Z, R = Y.
min3(X,Y,Z,R) :-  Z =< Y, Z =< X, R = Z.

% Problem 2 - maxList(L,R)
maxList([H], R) :- R = H.
maxList([H|T], R) :- maxList(T,R), H > R, H = R.
maxList([H|T], R) :- maxList(T,R), H =< R, T = R.
