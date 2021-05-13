remdups([], []).
remdups([H|T], R) :- 
    member(H,T),
    remdups(T, R).
remdups([H|T], R) :- 
    \+member(H, T),
    R = [He|Ta],
    He = H,
    remdups(T, Ta).

/*

?- remdups([1,3,2,4,3,2,5,1,1], R).
R = [4, 3, 2, 5, 1] .

?- remdups([2,2,2,2], R).
R = [2] .

?- remdups([a,b,c,a,b,d,a], R).
R = [c, b, d, a] .

?- remdups([2,2,2,2,1,3,3], R).
R = [2, 1, 3] .

?- remdups([6,5,4,3,2,1], R).
R = [6, 5, 4, 3, 2, 1].

?- remdups([], R).
R = [].

*/


    
