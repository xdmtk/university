female(evangeline).
female(gloria).
female(lynette).
female(ariel).

male(nick).
male(harold).
male(gonzalo).
male(ben).

parent(harold, nick).
parent(harold, ariel).
parent(lynette, nick).
parent(lynette, ariel).

parent(gonzalo,harold).
parent(evangeline,harold).
parent(ben,lynette).
parent(gloria,lynette).

mother(X,Y) :- female(X),parent(X,Y).
father(X,Y) :- male(X),parent(X,Y).
grandparent(X,Y) :- parent(X,Z),parent(Z,Y).
ancestor(X,Y) :- parent(X,Y).
ancestor(X,Y) :- parent(X,Y), ancestor(Z,Y).
descendant(X,Y) :- parent(Y,X).
descendant(X,Y) :- parent(Y,Z), descendant(Z,X).
