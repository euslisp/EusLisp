% [17] **** Reversible functions ****

:- public fact/2, fib/2, sum/3, prod/3.
:- public q171/1, solve/1.

/*
To optimize the compiled code, add the next declarations:

:- mode q171(-), solve(1).
:- fastcode.
:- compactcode.
*/

sum(X,0,X).
sum(X,s(Y),s(Z)) :- sum(X,Y,Z).

prod(X,0,0).
prod(X,s(Y),Z) :- prod(X,Y,W), sum(W,X,Z).
fact(0,s(0)).
fact(s(X),Z) :- fact(X,Y), prod(s(X),Y,Z).

fib(0,s(0)).
fib(s(0),s(0)).
fib(s(s(N)),V) :- fib(s(N),X), fib(N,Y), sum(X,Y,V).

solve(Y) :- fib(X,s(s(s(s(s(s(s(s(s(s(s(s(s(0)))))))))))))),
            fact(X,Y).
/*
[17-1:] Calculate fact(fib*(13)) where fib* is the reverse funcition of fib.
	do "q171(10)." for ten iterations.
*/

q171(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q171(0,N),
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

loop_q171(N,N) :- !.
loop_q171(I,N) :-
     I1 is I+1, solve(Y), !, loop_q171(I1,N).

loop_dummy(N,N) :- !.
loop_dummy(I,N) :-
     I1 is I+1, !, loop_dummy(I1,N).

