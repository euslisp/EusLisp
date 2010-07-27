% <OKUNO>BNCH4.PL.2,  7-Jul-84 11:55:34, Edit by OKUNO

% [10] **** Quick sort ****

:- public q101/1, qsort/3, partition/4, list50/1.

/*
To optimize the compiled code, add the next declarations:

:- mode qsort(+,-,+), partition(+,+,-,-), list50(-).
:- mode q101(-).
:- fastcode.
:- compactcode.

and also replace the definition of qsort and partition by:

qsort([X|L],R,R0) :- !,
           partition(L,X,L1,L2),
           qsort(L2,R1,R0),
           qsort(L1,R,[X|R1]).
qsort([],R,R).

partition([X|L],Y,[X|L1],L2) :- X =< Y, !, partition(L,Y,L1,L2).
partition([X|L],Y,L1,[X|L2]) :- !, partition(L,Y,L1,L2).
partition([],_,[],[]).

*/

qsort([X|L],R,R0) :-
           partition(L,X,L1,L2),
           qsort(L2,R1,R0),
           qsort(L1,R,[X|R1]).
qsort([],R,R).

partition([X|L],Y,[X|L1],L2) :- X =< Y, !, partition(L,Y,L1,L2).
partition([X|L],Y,L1,[X|L2]) :-  partition(L,Y,L1,L2).
partition([],_,[],[]).

list50( [27,74,17,33,94,18,46,83,65, 2,
	  32,53,28,85,99,47,28,82, 6,11,
	  55,29,39,81,90,37,10, 0,66,51,
	   7,21,85,27,31,63,75, 4,95,99,
	  11,28,61,74,18,92,40,53,59, 8 ]).
/*
[10-1:] Sort 50 elements.
        The complexity of this computation is 609 LI.
	do "q101(10)." for ten iterations.
*/

q101(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q101(0,N),
     statistics(runtime,[_,T1]),!,
     statistics(garbage_collection,[_,_|G2]),!,
     statistics(runtime,[_,_]),!,
     loop_list50(0,N),
     statistics(runtime,[_,T2]),
     statistics(garbage_collection,[_,_|G3]),!,
     G1 = [Gt1], G2 = [Gt2], G3 = [Gt3],
     G4 is Gt2 + Gt2 - Gt1 - Gt3,
     T3 is T1-T2-G4, Total is T1-T2,
     write('Total = '), write(Total),
     write('ms,  runtime = '), write(T3),
     write('ms,  gctime = '), write(G4),
     write('ms,   for '), write(N), write(' iterations.'), nl.

loop_q101(N,N) :- !.
loop_q101(I,N) :-
     I1 is I+1, list50(L), qsort(L,X,[]), !, loop_q101(I1,N).

loop_list50(N,N) :- !.
loop_list50(I,N) :-
     I1 is I+1, list50(L), !, loop_list50(I1,N).

