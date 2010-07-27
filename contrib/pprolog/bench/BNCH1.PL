% <OKUNO>BNCH1.PL.6,  7-Jul-84 12:24:11, Edit by OKUNO

% **** Prolog Instruction Level Benchmark ****

% [1] Unification of atoms

:- public q11/1, q12/1, q21/1, q22/1, q31/1, q32/1.
:- public q41/1, q42/1, q51/1, q52/1, q61/1, q62/1.
:- public q71/1, q72/1, q73/1, q74/1.

/*
To optimize the compiled code, add the next declarations:

:- mode p11(+), p12(+,+,+,+,+), p31(+), p32(+,+,+,+,+).
:- mode q11(-), q12(-), q21(-), q22(-), q31(-), q32(-).
:- mode q41(-), q42(-), q51(-), q52(-), q61(-), q62(-).
:- mode q71(-), q72(-), q73(-), q74(-).
:- fastcode.
:- compactcode.
*/

p11(a).
p12(a,a,a,a,a).

/*
[1-1:] Arity of one
	do "q11(1000)." for one thousand iterations.
*/

q11(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q11(0,N),
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
     write('ms,  runtime = '),write(T3),
     write('ms,  gctime = '), write(G4),
     write('ms,   for '), write(N), write(' iterations.'), nl.

loop_dummy(N,N) :- !.
loop_dummy(I,N) :-
     I1 is I+1, !, loop_dummy(I1,N).

loop_q11(N,N) :- !.
loop_q11(I,N) :-
     I1 is I+1, p11(a), !, loop_q11(I1,N).

/*
[1-2:] Arity of five
	do "q12(1000)." for one thousand iterations.
*/

q12(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q12(0,N),
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

loop_q12(N,N) :- !.
loop_q12(I,N) :-
     I1 is I+1, p12(a,a,a,a,a), !, loop_q12(I1,N).

% [2] Unification of variables

p21(X).
p22(X,X,X,X,X).

/*
[2-1:] Arity of one
	do "q21(1000)." for one thousand iterations.
*/

q21(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q21(0,N),
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

loop_q21(N,N) :- !.
loop_q21(I,N) :-
     I1 is I+1, p21(X), !, loop_q21(I1,N).

/*
[2-2:] Arity of five
	do "q22(1000)." for one thousand iterations.
*/

q22(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q22(0,N),
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

loop_q22(N,N) :- !.
loop_q22(I,N) :-
     I1 is I+1, p22(X,X,X,X,X), !, loop_q22(I1,N).

% [3] Unification of constant structure

p31(f(a)).
p32(f(a),f(a),f(a),f(a),f(a)).

/*
[3-1:] Arity of one
	do "q31(1000)." for one thousand iterations.
*/

q31(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q31(0,N),
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

loop_q31(N,N) :- !.
loop_q31(I,N) :-
     I1 is I+1, p31(f(a)), !, loop_q31(I1,N).

/*
[3-2:] Arity of five
	do "q32(1000)." for one thousand iterations.
*/

q32(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q32(0,N),
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

loop_q32(N,N) :- !.
loop_q32(I,N) :-
     I1 is I+1, p32(f(a),f(a),f(a),f(a),f(a)), !, loop_q32(I1,N).

% [4] Unification of structures with variables

p41(f(X)).
p42(f(X),f(X),f(X),f(X),f(X)).

/*
[4-1:] Arity of one
	do "q41(1000)." for one thousand iterations.
*/

q41(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q41(0,N),
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

loop_q41(N,N) :- !.
loop_q41(I,N) :-
     I1 is I+1, p41(f(X)), !, loop_q41(I1,N).

/*
[4-2:] Arity of five
	do "q42(1000)." for one thousand iterations.
*/

q42(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q42(0,N),
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

loop_q42(N,N) :- !.
loop_q42(I,N) :-
     I1 is I+1, p42(f(X),f(X),f(X),f(X),f(X)), !, loop_q42(I1,N).

% [5] Unification of variables with structure

p51(f(X)).
p52(f(X),f(X),f(X),f(X),f(X)).

/*
[5-1:] Arity of one
	do "q51(1000)." for one thousand iterations.
*/

q51(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q51(0,N),
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

loop_q51(N,N) :- !.
loop_q51(I,N) :-
     I1 is I+1, p51(X), !, loop_q51(I1,N).

/*
[5-2:] Arity of five
	do "q52(1000)." for one thousand iterations.
*/

q52(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q52(0,N),
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

loop_q52(N,N) :- !.
loop_q52(I,N) :-
     I1 is I+1, p52(X,X,X,X,X), !, loop_q52(I1,N).

% [6] 

p61(X).
p62(X,X,X,X,X).

/*
[6-1:] Arity of one
	do "q61(1000)." for one thousand iterations.
*/

q61(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q61(0,N),
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

loop_q61(N,N) :- !.
loop_q61(I,N) :-
     I1 is I+1, p61(f(X)), !, loop_q61(I1,N).

/*
[6-2:] Arity of five
	do "q62(1000)." for one thousand iterations.
*/

q62(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q62(0,N),
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

loop_q62(N,N) :- !.
loop_q62(I,N) :-
     I1 is I+1, p62(f(X),f(X),f(X),f(X),f(X)), !, loop_q62(I1,N).

% [7] **** Clause Call/Return ****

p71(X) :- f71(X).
f71(X).

p72(X) :- f72(X).
f72(X) :- fail.
p72(X).

p73(X) :- fail.
p73(X) :- fail.
p73(X) :- fail.
p73(X) :- fail.
p73(X) :- fail.
p73(X) :- fail.
p73(X) :- fail.
p73(X) :- fail.
p73(X) :- fail.
p73(X) :- fail.
p73(X).

p74(X) :- f74(X),r74(X).
p74(X) :- a74(X),b74(X).
f74(X) :- s74(X),r74(X).
f74(X) :- s74(X),r74(X).
s74(X) :- r74(X).
s74(X) :- r74(X).
r74(X) :- fail.
r74(X) :- fail.
a74(X) :- s74(X),r74(X).
a74(X) :- b74(X),b74(X).
b74(X) :- fail.
b74(X).

/*
[7-1:] Deterministic simple call
	do "q71(1000)." for one thousand iterations.
*/

q71(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q71(0,N),
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

loop_q71(N,N) :- !.
loop_q71(I,N) :-
     I1 is I+1, p71(X), !, loop_q71(I1,N).

/*
% [7-2:] Nondeterministic simple call
	do "q72(1000)." for one thousand iterations.
*/

q72(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q72(0,N),
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

loop_q72(N,N) :- !.
loop_q72(I,N) :-
     I1 is I+1, p72(X), !, loop_q72(I1,N).

/*
[7-3] Sallow backtracking
	do "q73(1000)." for one thousand iterations.
*/

q73(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q73(0,N),
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

loop_q73(N,N) :- !.
loop_q73(I,N) :-
     I1 is I+1, p73(X), !, loop_q73(I1,N).

/*
[7-4] Deep backtracking
	do "q74(1000)." for one thousand iterations.
*/

q74(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q74(0,N),
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

loop_q74(N,N) :- !.
loop_q74(I,N) :-
     I1 is I+1, p74(X), !, loop_q74(I1,N).


/* Now measure the benchmarks.
   Replace 1000 by 10000 for compiled codes.
*/

q11(1000).
q12(1000).
q21(1000).
q22(1000).
q31(1000).
q32(1000).
q41(1000).
q42(1000).
q51(1000).
q52(1000).
q61(1000).
q62(1000).
q71(1000).
q72(1000).
q73(1000).
q74(1000).

