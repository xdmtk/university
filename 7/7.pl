min3(X,Y,Z,R) :-  X =< Y, X =< Z, R = X.
min3(X,Y,Z,R) :-  Y =< X, Y =< Z, R = Y.
min3(X,Y,Z,R) :-  Z =< Y, Z =< X, R = Z.
