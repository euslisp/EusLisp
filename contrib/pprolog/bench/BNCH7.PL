% [13] ******** Lisp interpreter in Prolog ********
% 			Micro Lisp in Prolog

:- public lisp/2.
:- public tarai3/1, fib20/1, reverse30/1.
:- public q131/1, q132/1, q133/1.

/*
To optimize the compiled code, add the next declarations:

:- mode apply(+,+,+,-), eval(+,+,-), evcon(+,+,-), evlis(+,+,-).
:- mode bind(+,+,+,-), value(+,+,-), lisp(+,-).
:- mode tarai3(-), fib10(-), reverse30(-).
:- mode q131(-), q132(-), q133(-).
:- fastcode.
:- compactcode.
*/

apply(S,car,[[X|_]|_],X) :- !.
apply(S,cdr,[[_|Y]|_],Y) :- !.
apply(S,atom,[[_|_]|_],[]) :- !.
apply(S,atom,[X|_],t) :- atomic(X).

/* If atomic is not available, use the following definition:
		atomic([X|Y]) :- !, fail.
		atomic(X).
*/

apply(S,cons,[X,Y|_],[X|Y]) :- !.
apply(S,eq,[X,X|_],t) :- !.
apply(S,eq,[X,Y|_],[]) :- neq(X,X).
apply(S,null,[[]|_],t) :- !.
apply(S,sub1,[X|_],Y) :- !, Y is X-1.
apply(S,add1,[X|_],Y) :- !, Y is X+1.
apply(S,plus,[X,Y|_],V) :- !, V is X+Y.
apply(S,difference,[X,Y|_],V) :- !, V is X-Y.
apply(S,times,[X,Y|_],V) :- !, V is X*Y.
apply(S,greaterp,[X,Y|_],t) :- X>Y, !.
apply(S,greaterp,[_,_|_],[]).
apply(S,zerop,[0|_],t) :- !.
apply(S,zerop,[_|_],[]).
apply(S,[lambda,X,Y|_],R,V) :- !, bind(S,X,R,S1), eval(S1,Y,V).
apply(S,[label,X,Y|_],R,V) :- !, bind(S,[X],[Y],S1), apply(S1,Y,R,V).
apply(S,A,R,V) :- value(S,A,W), apply(S,W,R,V), !.

eval(S,[quote,X|_],X) :- !.
eval(S,[cond|X],V) :- !, evcon(S,X,V).
eval(S,[X|Y],V) :- !, evlis(S,Y,W), apply(S,X,W,V).
eval(S,A,V) :- value(S,A,V), !.

evcon(S,[[X,Y|_]|_],V) :- eval(S,X,W), neq(W,[]), !, eval(S,Y,V).
evcon(S,[_|U],V) :- evcon(S,U,V), !.

evlis(S,[],[]) :- !.
evlis(S,[X|Y],[U|V]) :- !, eval(S,X,U), evlis(S,Y,V).

bind(S,[],[],S) :- !.
bind(S,[A|X],[V|Y],S1) :- bind([[A|V]|S],X,Y,S1), !.

value([[A|V]|S],A,V) :- !.
value([X|S],A,V) :- value(S,A,V), !.

neq(X,X) :- !, fail.
neq(X,Y).

lisp(X,V) :-
   eval([[[]],[t|t],[f],
	 [reverse|[lambda,[l],[rev,l,[]]]],
         [rev|[lambda,[l,m],
                  [cond,[[atom,l],m],
	                [t,[rev,[cdr,l],[cons,[car,l],m]]] ]]]
	],X,V).

% ---- Lisp programs ----

tarai3(V) :-
 lisp([[label,tarai,
          [lambda,[x,y,z],
	      [cond,[[greaterp,x,y],
	             [tarai,[tarai,[sub1,x],y,z],
		            [tarai,[sub1,y],z,x],
			    [tarai,[sub1,z],x,y]]],
		    [t,y] ]]],
       [quote,6],[quote,3],[quote,0] ], V).

fib10(V) :-
 lisp([[label,fib,
          [lambda,[n],
	     [cond,[[eq,n,[quote,1]],[quote,1]],
	           [[eq,n,[quote,2]],[quote,1]],
		   [t,[plus,[fib,[sub1,n]],[fib,[difference,n,[quote,2]]]]]
	     ]]],
       [quote,10]], V).

reverse30(V) :-
 lisp([reverse,[quote,[1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,
                       1,2,3,4,5,6,7,8,9,0]]], V).

/*
[13-1:] TARAI-3
	do "q131(1)." for one once.
*/

q131(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q131(0,N),
     statistics(runtime,[_,T1]),!,
     statistics(garbage_collection,[_,_|G2]),!,
     statistics(runtime,[_,_]),!,
     loop_dummy(0,N),
     statistics(runtime,[_,T2]),
     statistics(garbage_collection,[_,_|G3]),!,
     G1 = [Gt1], G2 = [Gt2], G3 = [Gt3],
     G4 is Gt2 + Gt2 - Gt1 - Gt3,
     T3 is T1-T2-G4, Total is T1-T2,
     write('Total = '), write(Total),
     write('ms,  runtime = '), write(T3),
     write('ms,  gctime = '), write(G4),
     write('ms,   for '), write(N), write(' iterations.'), nl.

loop_q131(N,N) :- !.
loop_q131(I,N) :-
     I1 is I+1, tarai3(V), !, loop_q131(I1,N).

loop_dummy(N,N) :- !.
loop_dummy(I,N) :-
     I1 is I+1, !, loop_dummy(I1,N).

/*
[13-2:] Fibonacci number for 10
	do "q132(1)." for one once.
*/

q132(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q132(0,N),
     statistics(runtime,[_,T1]),!,
     statistics(garbage_collection,[_,_|G2]),!,
     statistics(runtime,[_,_]),!,
     loop_dummy(0,N),
     statistics(runtime,[_,T2]),
     statistics(garbage_collection,[_,_|G3]),!,
     G1 = [Gt1], G2 = [Gt2], G3 = [Gt3],
     G4 is Gt2 + Gt2 - Gt1 - Gt3,
     T3 is T1-T2-G4, Total is T1-T2,
     write('Total = '), write(Total),
     write('ms,  runtime = '), write(T3),
     write('ms,  gctime = '), write(G4),
     write('ms,   for '), write(N), write(' iterations.'), nl.

loop_q132(N,N) :- !.
loop_q132(I,N) :-
     I1 is I+1, fib10(V), !, loop_q132(I1,N).

/*
[13-3:] Reverse a list of 30 elements
	do "q133(1)." for one once.
*/

q133(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q133(0,N),
     statistics(runtime,[_,T1]),!,
     statistics(garbage_collection,[_,_|G2]),!,
     statistics(runtime,[_,_]),!,
     loop_dummy(0,N),
     statistics(runtime,[_,T2]),
     statistics(garbage_collection,[_,_|G3]),!,
     G1 = [Gt1], G2 = [Gt2], G3 = [Gt3],
     G4 is Gt2 + Gt2 - Gt1 - Gt3,
     T3 is T1-T2-G4, Total is T1-T2,
     write('Total = '), write(Total),
     write('ms,  runtime = '), write(T3),
     write('ms,  gctime = '), write(G4),
     write('ms,   for '), write(N), write(' iterations.'), nl.

loop_q133(N,N) :- !.
loop_q133(I,N) :-
     I1 is I+1, reverse30(V), !, loop_q133(I1,N).

