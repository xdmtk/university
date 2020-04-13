/*
 * Rules 
 */

/* Women */
female(evangeline).
female(gloria).
female(lynette).
female(ariel).
female(maria).
female(natalie).
female(laura).
female(karen).

/* Men */
male(nick).
male(harold).
male(gonzalo).
male(ben).
male(richard).
male(jeff).
male(leonard).

/* Parents */
% Parents
parent(harold, nick).
parent(harold, ariel).
parent(lynette, nick).
parent(lynette, ariel).

% Grandparents (Dads side)
parent(gonzalo,harold).
parent(evangeline,harold).
parent(gonzalo,leonard).
parent(evangeline,leonard).
parent(gonzalo,laura).
parent(evangeline,laura).
parent(gonzalo,karen).
parent(evangeline,karen).

% Grandparents (Moms side)
parent(ben,lynette).
parent(gloria,lynette).
parent(ben,natalie).
parent(gloria,natalie).

% GreatGrandparents (Moms Side)
parent(richard,gloria).
parent(maria,gloria).

% Great Grandparents (Dads side)



mother(X,Y) :- female(X),parent(X,Y).
father(X,Y) :- male(X),parent(X,Y).
grandparent(X,Y) :- parent(X,Z),parent(Z,Y).

ancestor(X,Y) :- parent(X,Y).
ancestor(X,Y) :- parent(X,Z), ancestor(Z,Y).

descendant(X,Y) :- parent(Y,X).
descendant(X,Y) :- parent(Y,Z), descendant(X,Z).

grandfather(X,Y) :- male(X),parent(X,Z),parent(Z,Y).
grandmother(X,Y) :- female(X),parent(X,Z),parent(Z,Y).

greatGrandfather(X,Y) :-
    male(X),parent(X,W),parent(W,Z),parent(Z,Y).
greatGrandmother(X,Y) :-
    female(X),parent(X,W),parent(W,Z),parent(Z,Y).

child(X,Y) :- parent(Y,X).

siblings(X,Y) :- child(X,Z),child(Y,Z),X \= Y.

brother(X,Y) :- siblings(X,Y),male(X).

sister(X,Y) :- siblings(X,Y),female(X).

aunt(X,Y) :- siblings(X,Z),parent(Z,Y),female(X).

uncle(X,Y) :- siblings(X,Z),parent(Z,Y),male(X).
