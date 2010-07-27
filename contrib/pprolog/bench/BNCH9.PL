% [15] Differentiation
%           This program is the same as that written in Lisp.

:- public d/3, diff1/1, diff2/1.
:- public q151/1, q152/1.

/*
To optimize the compiled code, add the next declarations:

:- mode d(+,+,-), simp_plus(+,+,-), simp_diff(+,+,-).
:- mode simp_times(+,+,-), simp_expt(+,+,-).
:- mode diff1(-), diff2(-).
:- mode q151(-), q152(-).
:- fastcode.
:- compactcode.
*/

:-op(300,xfy,^).

d(U+V,X,DY) :- !, d(U,X,DU), d(V,X,DV), simp_plus(DU,DV,DY).
d(U-V,X,DY) :- !, d(U,X,DU), d(V,X,DV), simp_diff(DU,DV,DY).
d(U*V,X,DY) :- !, d(U,X,DU), d(V,X,DV),
   simp_time(DU,V,D1), simp_time(U,DV,D2), simp_plus(D1,D2,DY).
d(U^0,X,0) :- !.
d(U^1,X,DY) :- !, d(U,X,DY).
d(U^N,X,DY) :- !, N1 is N-1, simp_expt(U,N1,Y), d(U*Y,X,DY).
d(X,X,1) :-!.
d(C,X,0) :- atomic(C), C \== 0.

simp_plus(X,Y,Z) :- integer(X), integer(Y), !, Z is X+Y.
simp_plus(0,Y,Y) :- !.
simp_plus(X,0,X) :- !.
simp_plus(X,Y,X+Y).

simp_diff(X,Y,Z) :- integer(X), integer(Y), !, Z is X-Y.
simp_diff(0,Y,-1*Y) :- !.
simp_diff(X,0,X) :- !.
simp_diff(X,Y,X+V) :- integer(Y), !, V is -Y.
simp_diff(X,Y,X-Y).

simp_time(X,Y,Z) :- integer(X), integer(Y), !, Z is X*Y.
simp_time(_,0,0) :- !.
simp_time(0,_,0) :- !.
simp_time(X,1,X) :- !.
simp_time(1,Y,Y) :- !.
simp_time(X,Y,X*Y).

simp_expt(_,0,1) :- !.
simp_expt(X,1,X) :- !.
simp_expt(X,N,X^N).

diff1(DF) :- d(x^3+3*x^2+3*x+1,x,DG),d(DG,x,DF).

diff2(DF) :-
   d((x-1)^5,x,D1),d(D1,x,D2),d(D2,x,D3),d(D3,x,D4),d(D4,x,DF).

/*
[15-1:] D(x^3+3*x^2+3*x+1)/DX
	do "q151(100)." for one hundred iterations.
*/

q151(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q151(0,N),
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

loop_q151(N,N) :- !.
loop_q151(I,N) :-
     I1 is I+1, diff1(DF), !, loop_q151(I1,N).

loop_dummy(N,N) :- !.
loop_dummy(I,N) :-
     I1 is I+1, !, loop_dummy(I1,N).

/*
[15-2:] D^5((x-1)^5)/DX
	do "q152(1)." for only once.
*/

q152(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q152(0,N),
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

loop_q152(N,N) :- !.
loop_q152(I,N) :-
     I1 is I+1, diff2(DF), !, loop_q152(I1,N).

