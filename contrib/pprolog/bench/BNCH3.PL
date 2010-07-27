% <OKUNO>BNCH3.PL.2,  7-Jul-84 11:40:50, Edit by OKUNO
% [9] **** Naive Reverse ****

:- public q91/1, nreverse/2, concatenate/3, list30/1.

/*
To optimize the compiled code, add the next declarations:

:- mode nreverse(+,-), concatenate(+,+,-), list30(-).
:- mode q91(-).
:- fastcode.
:- compactcode.

and also replace the definition of nreverse and concatenate by:

nreverse([X|L0],L) :- !, nreverse(L0,L1), concatenate(L1,[X],L).
nreverse([],[]).

concatenate([X|L1],L2,[X|L3]) :- !, concatenate(L1,L2,L3).
concatenate([],L,L).

*/

nreverse([X|L0],L) :- nreverse(L0,L1), concatenate(L1,[X],L).
nreverse([],[]).

concatenate([X|L1],L2,[X|L3]) :- concatenate(L1,L2,L3).
concatenate([],L,L).

list30( [ 1, 2, 3, 4, 5, 6, 7, 8, 9,10,
          11,12,13,14,15,16,17,18,19,20,
	  21,22,23,24,25,26,27,28,29,30 ]).

/*
[9-1:] Reverse a list of 30 elements.
       This comptation involves 496 LI (Logical Inference).
	do "q91(10)." for ten iterations.
*/

q91(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q91(0,N),
     statistics(runtime,[_,T1]),!,
     statistics(garbage_collection,[_,_|G2]),!,
     statistics(runtime,[_,_]),!,
     loop_list30(0,N),
     statistics(runtime,[_,T2]),
     statistics(garbage_collection,[_,_|G3]),!,
     G1 = [Gt1], G2 = [Gt2], G3 = [Gt3],
     G4 is Gt2 + Gt2 - Gt1 - Gt3,
     T3 is T1-T2-G4, Total is T1-T2,
     write('Total = '), write(Total),
     write('ms,  runtime = '), write(T3),
     write('ms,  gctime = '), write(G4),
     write('ms,   for '), write(N), write(' iterations.'), nl.

loop_q91(N,N) :- !.
loop_q91(I,N) :-
     I1 is I+1, list30(L), nreverse(L,X), !, loop_q91(I1,N).

loop_list30(N,N) :- !.
loop_list30(I,N) :-
     I1 is I+1, list30(L), !, loop_list30(I1,N).
