magicSquare(X1, X2, X3, X4, X5, X6, X7, X8, X9):-

	permutation([1,2,3,4,5,6,7,8,9], [X1, X2, X3, X4, X5, X6, X7, X8, X9]),

	X1 + X2 + X3 =:= 15, X4 + X5 + X6 =:= 15, X7 + X8 + X9 =:= 15, 
    X1 + X4 + X7 =:= 15, X2 + X5 + X8 =:= 15, X1 + X5 + X9 =:= 15,
    X1 + X5 + X9 =:= 15, X3 + X5 + X7 =:= 15.
