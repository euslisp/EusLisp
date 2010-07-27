% <OKUNO>BNCH5.PL.2,  7-Jul-84 11:59:06, Edit by OKUNO

% [11] **** Tree traversing ****

/* Bigapp : A non-determinate computation involving structure
   accessing and lots of backtracking.  Written by Paul F. Wilk.
*/

:- public q111/1, conslist/2, concat/3, bigapp/1.
:- public q112/1.

/*
To optimize the compiled code, add the next declarations:

:- mode conslist(+,-), concat(-,-,+), bigapp(+).
:- mode q111(-), q112(-).
:- fastcode.
:- compactcode.
*/

conslist(0 ,[]).
conslist(N,[1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5|L]) :-
        N > 0,
        N1 is N - 25,
        conslist(N1,L).

concat([],L,L).
concat([X|L1],L2,[X|L3]) :- concat(L1,L2,L3).

bigapp(L) :- concat(L1,L2,L), fail.
bigapp(_).

/*
[11-1:] Measure the time of consing 1000 elements by 25 elements.
	do "q111(100)." for one hundred iterations.
*/

q111(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q111(0,N),
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

loop_q111(N,N) :- !.
loop_q111(I,N) :-
     I1 is I+1, conslist(1000,L), !, loop_q111(I1,N).

loop_dummy(N,N) :- !.
loop_dummy(I,N) :-
     I1 is I+1, !, loop_dummy(I1,N).

/*
[11-2:] Measure the time of decomposing a list of length 1000.
	do "q112(1)." for only once.
*/

q112(N) :- 
     conslist(1000,L), assert(list1000(L)), !,
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q112(0,N),
     statistics(runtime,[_,T1]),!,
     statistics(garbage_collection,[_,_|G2]),!,
     statistics(runtime,[_,_]),!,
     loop_list1000(0,N),
     statistics(runtime,[_,T2]),
     statistics(garbage_collection,[_,_|G3]),!,
     G1 = [Gt1], G2 = [Gt2], G3 = [Gt3],
     G4 is Gt2 + Gt2 - Gt1 - Gt3,
     T3 is T1-T2-G4, Total is T1-T2,
     write('Total = '), write(Total),
     write('ms,  runtime = '), write(T3),
     write('ms,  gctime = '), write(G4),
     write('ms,   for '), write(N), write(' iterations.'), nl.

loop_q112(N,N) :- !.
loop_q112(I,N) :-
     I1 is I+1, list1000(L), !, bigapp(L), loop_q112(I1,N).

loop_list1000(N,N) :- !.
loop_list1000(I,N) :-
     I1 is I+1, list1000(L), !, loop_list1000(I1,N).

