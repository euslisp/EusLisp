% <OKUNO>BNCH6.PL.2,  7-Jul-84 12:04:25, Edit by OKUNO

% [12] **** Slow reverse ****

:- public srev/2, sapp/3.
:- public q121/1, q122/1, q123/1.

/*
To optimize the compiled code, add the next declarations:

:- mode srev(+,-), sapp(+,+,-).
:- mode q121(-), q122(-), q123(-).
:- fastcode.
:- compactcode.

and also replace the definition of srev and sapp as follows:

srev([],[]) :- !.
srev([A|X],Z) :- srev(X,Y),sapp(Y,[A],Z).

sapp([],X,X) :- !.
sapp(X,Y,Z) :- srev(X,[A|RX]),
               srev(X,Dummy),  % necessary fo fairness with Lisp
               srev(RX,RRX),
               sapp(RRX,[A|Y],Z).

*/

srev([],[]).
srev([A|X],Z) :- srev(X,Y),sapp(Y,[A],Z).

sapp([],X,X).
sapp(X,Y,Z) :- srev(X,[A|RX]),
               srev(X,Dummy),  % necessary fo fairness with Lisp
               srev(RX,RRX),
               sapp(RRX,[A|Y],Z).

/*
[12-1:] Slow reverse of list of four elements.
	do "q121(100)" for one hundred iterations.
*/

q121(N) :-
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q121(0,N),                         % main loop
     statistics(runtime,[_,T1]),!,
     statistics(garbage_collection,[_,_|G2]),!,
     statistics(runtime,[_,_]),!,
     loop_dummy(0,N),                         % dummy loop
     statistics(runtime,[_,T2]),
     statistics(garbage_collection,[_,_|G3]),!,
     G1 = [Gt1], G2 = [Gt2], G3 = [Gt3],
     G4 is Gt2 + Gt2 - Gt1 - Gt3,
     T3 is T1-T2-G4, Total is T1-T2,
     write('Total = '), write(Total),
     write('ms,  runtime = '), write(T3),
     write('ms,  gctime = '), write(G4),
     write('ms,   for '), write(N), write(' iterations.'), nl.

loop_q121(N,N) :- !.
loop_q121(I,N) :-
     I1 is I+1, srev([1,2,3,4],X), !, loop_q121(I1,N).

loop_dummy(N,N) :- !.
loop_dummy(I,N) :-
     I1 is I+1, !, loop_dummy(I1,N).

/*
[12-2:] Slow reverse of list of five elements.
	do "q122(100)" for one hundred iterations.
*/

q122(N) :-
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q122(0,N),                         % main loop
     statistics(runtime,[_,T1]),!,
     statistics(garbage_collection,[_,_|G2]),!,
     statistics(runtime,[_,_]),!,
     loop_dummy(0,N),                         % dummy loop
     statistics(runtime,[_,T2]),
     statistics(garbage_collection,[_,_|G3]),!,
     G1 = [Gt1], G2 = [Gt2], G3 = [Gt3],
     G4 is Gt2 + Gt2 - Gt1 - Gt3,
     T3 is T1-T2-G4, Total is T1-T2,
     write('Total = '), write(Total),
     write('ms,  runtime = '), write(T3),
     write('ms,  gctime = '), write(G4),
     write('ms,   for '), write(N), write(' iterations.'), nl.

loop_q122(N,N) :- !.
loop_q122(I,N) :-
     I1 is I+1, srev([1,2,3,4,5],X), !, loop_q122(I1,N).

/*
[12-3:] Slow reverse of list of six elements.
	do "q123(1)" for only once.
*/

q123(N) :-
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q123(0,N),                         % main loop
     statistics(runtime,[_,T1]),!,
     statistics(garbage_collection,[_,_|G2]),!,
     statistics(runtime,[_,_]),!,
     loop_dummy(0,N),                         % dummy loop
     statistics(runtime,[_,T2]),
     statistics(garbage_collection,[_,_|G3]),!,
     G1 = [Gt1], G2 = [Gt2], G3 = [Gt3],
     G4 is Gt2 + Gt2 - Gt1 - Gt3,
     T3 is T1-T2-G4, Total is T1-T2,
     write('Total = '), write(Total),
     write('ms,  runtime = '), write(T3),
     write('ms,  gctime = '), write(G4),
     write('ms,   for '), write(N), write(' iterations.'), nl.

loop_q123(N,N) :- !.
loop_q123(I,N) :-
     I1 is I+1, srev([1,2,3,4,5,6],X), !, loop_q123(I1,N).

