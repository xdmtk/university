maxList([H], R) :- R = H.
maxList([H|T],R):-
    maxList(T,TMax),
    H > TMax,
    R = H.
maxList([H|T],R):-
    maxList(T,TMax),
    H =<TMax,
    R = TMax.
