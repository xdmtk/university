/*********************************
* 
* Name: Nicholas Martinez
* Course: COMP 333
* Homework #6
* Due Date: April 17th 2020
*
*/




% Problem 1
/***************************************************
 * Facts
 ****************************************************/

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


/***************************************************
 * Rules
 ****************************************************/
mother(X,Y) :- female(X),parent(X,Y).
father(X,Y) :- male(X),parent(X,Y).

grandparent(X,Y) :- parent(X,Z),parent(Z,Y).

ancestor(X,Y) :- parent(X,Y).
ancestor(X,Y) :- parent(X,Z), ancestor(Z,Y).

descendant(X,Y) :- parent(Y,X).
descendant(X,Y) :- parent(Y,Z), descendant(X,Z).

grandfather(X,Y) :- male(X),parent(X,Z),parent(Z,Y).
grandmother(X,Y) :- female(X),parent(X,Z),parent(Z,Y).

greatGrandfather(X,Y) :- male(X),parent(X,W),parent(W,Z),parent(Z,Y).
greatGrandmother(X,Y) :- female(X),parent(X,W),parent(W,Z),parent(Z,Y).

child(X,Y) :- parent(Y,X).

siblings(X,Y) :- child(X,Z),child(Y,Z),X \= Y.

brother(X,Y) :- siblings(X,Y),male(X).

sister(X,Y) :- siblings(X,Y),female(X).

aunt(X,Y) :- siblings(X,Z),parent(Z,Y),female(X).

uncle(X,Y) :- siblings(X,Z),parent(Z,Y),male(X).




% Problem 2
/***************************************************
 * Test Runs
 ****************************************************


1. List of fathers siblings 
    ?- father(F, nick), setof(Z, siblings(Z,F), FatherSiblings).
    F = harold,
    FatherSiblings = [karen, laura, leonard] 

2. List of all your aunts and uncles
    ?- setof(A, aunt(A, nick), Aunts).
    Aunts = [karen, laura, natalie].

3. List of all your siblings
    ?- setof(S, siblings(S, nick), Siblings).
    Siblings = [ariel].

4. A list of all your grandmothers children (Pick one grandmother)
    ?- setof(C, parent(evangeline, C), GrandMothersChildren).
    GrandMothersChildren = [harold, karen, laura, leonard].

5. A list of myour ancestors
    ?- setof(A, ancestor(A, nick), Ancestors).
    Ancestors = [ben, evangeline, gloria, gonzalo, harold, lynette, maria, richard].

6. A list of descendents of one of your great grandfathers.
    ?- setof(D, descendant(D, richard), Descendents).
    Descendents = [ariel, gloria, lynette, natalie, nick].
 */
