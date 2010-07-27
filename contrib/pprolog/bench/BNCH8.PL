% [14] **** Eight Queens ****

:- public queen/2, queen_8/0, queen_all/0.
:- public q141/1, q142/1.

/*
To optimize the compiled code, add the next declarations:

:- mode queen(+,-), generate(+,-), try(+,+,+,+,+,+), select(+,-,-).
:- mode notmem(+,+).
:- mode q141(-), q142(-).
:- fastcode.
:- compactcode.
*/

queen(N,L) :- generate(N,L1), try(N,L1,[],L,[],[]).

generate(0,[]) :- !.
generate(N,[N|L]) :- N1 is N-1, generate(N1,L).

try(_,[],L,L,_,_) :- !.
try(M,S,L1,L,C,D) :- 
    select(S,A,S1), C1 is M+A, notmem(C1,C), D1 is M-A,
    notmem(D1,D), M1 is M-1, try(M1,S1,[A|L1],L,[C1|C],[D1|D]).

select([A|L],A,L).
select([A|L],X,[A|L1]) :- select(L,X,L1).

notmem(_,[]) :- !.
notmem(A,[B|L]) :- A=\=B, notmem(A,L).

queen_8 :- queen(8,L).

queen_all :- queen(8,L), fail.
queen_all.

/*
[14-1:] Get the first solution.
	do "q141(1)." for only once.
*/

q141(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q141(0,N),
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

loop_q141(N,N) :- !.
loop_q141(I,N) :-
     I1 is I+1, queen_8, !, loop_q141(I1,N).

loop_dummy(N,N) :- !.
loop_dummy(I,N) :-
     I1 is I+1, !, loop_dummy(I1,N).

/*
[14-2:] Get all the solution.
	do "q142(1)." for only once.
*/

q142(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q142(0,N),
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

loop_q142(N,N) :- !.
loop_q142(I,N) :-
     I1 is I+1, queen_all, !, loop_q142(I1,N).

