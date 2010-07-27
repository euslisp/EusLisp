% [16] **** Database Manipulations ****
%		This database is created by J. A. Robinson et al.

/*
If numerical values cannot be represented in your system,
chang the format.  For example, DEC-10 Prolog cannot
express more than 2^18 or floating numbers.
*/

% population(afghanistan,20900000). ===> 161 clauses.
% adjoins(canada,usa). ===> 313 clauses.
% open_water(atlantic_ocean). ===> 40 clauses.
% country(moscow,ussr). ===>220 clauses.
% region(canada,north_america). ===> 162 clauses.
% produces(ussr,oil,491,1975). ===> 252 clauses.
% belongs(canada,nato). ===> 177 clauses.

:- public population/2, adjoins/2, open_water/2, country/2.
:- public region/2, produces/2, belongs/2.
:- public iscountry/1, landlocked/1, bordres/1.
:- public border_sea/2, oil_production/2.
:- public db2/1, db3/1, db4/1, db5/1.
:- public db6/1, db7/1, db8/1, db9/1, db10/1.
:- public q161/1, q162/1, q163/1, q164/1, q165/1.
:- public q166/1, q167/1, q168/1, q169/1, q160/1.

/*
To optimize the compiled code, add the next declarations:

:- mode size(+,+).
:- mode db2(-), db3(-), db4(-), db5(-), db6(-).
:- mode db7(-), db8(-), db9(-), db10(-).
:- mode q161(-), q162(-), q163(-), q164(-), q165(-).
:- mode q166(-), q167(-), q168(-), q169(-), q160(-).
:- fastcode.
:- compactcode.
*/

db2(S) :- setof(C, country(C,japan), S).

db3(C) :- region(C,far_east), iscountry(C), landlocked(C).

db4(S) :- setof(C, db3(C), S).

db5(C) :- iscountry(C), setof(X, border_sea(C,X), S), size(S,2).

border_sea(C,X) :- borders(C,X), open_water(X).
size([_,_],2).

db6(T) :- setof(C, db5(C),T).

db7(C) :-
       population(india,Y), borders(C,mediterranean_sea), iscountry(C),
       borders(C,C1), iscountry(C1), borders(C1,C2),
       population(C2,X), X>Y.

db8(S) :- setof(C, db7(C), S).

db9(S) :- setof([C,P], oil_production(C,P), S).
oil_production(C,P) :- 
  belongs(C,opec), \+belongs(C,arab_league), produces(C,oil,P,1975).

db10(X) :-
  open_water(X), borders(X,C), region(C,africa), iscountry(C),
  borders(X,C1), region(C1,europe), iscountry(C1).

/*
[16-1:] Which country's capital is Tokyo?
	do "q161(1000)." for one thousand iterations.
*/

q161(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q161(0,N),
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

loop_q161(N,N) :- !.
loop_q161(I,N) :-
     I1 is I+1, country(tokyo,X), !, loop_q161(I1,N).

loop_dummy(N,N) :- !.
loop_dummy(I,N) :-
     I1 is I+1, !, loop_dummy(I1,N).

/*
[16-2:] What are the cities in Japan?
	do "q162(100)." for one hundred iterations.
*/

q162(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q162(0,N),
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

loop_q162(N,N) :- !.
loop_q162(I,N) :-
     I1 is I+1, db2(C), !, loop_q162(I1,N).

/*
[16-3:] Which far-east countres is landlocked?
	do "q163(1)." for only once.
*/

q163(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q163(0,N),
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

loop_q163(N,N) :- !.
loop_q163(I,N) :-
     I1 is I+1, db3(C), !, loop_q163(I1,N).

/*
[16-4:] List up all the far-east countres which are landlocked.
	do "q164(1)." for only once.
*/

q164(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q164(0,N),
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

loop_q164(N,N) :- !.
loop_q164(I,N) :-
     I1 is I+1, db4(C), !, loop_q164(I1,N).

/*
[16-5:] Which countries border two seas?
	do "q165(1)." for only once.
*/

q165(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q165(0,N),
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

loop_q165(N,N) :- !.
loop_q165(I,N) :-
     I1 is I+1, db5(C), !, loop_q165(I1,N).

/*
[16-6:] List up all the countries which border two seas.
	do "q166(1)." for only once.
*/

q166(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q166(0,N),
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

loop_q166(N,N) :- !.
loop_q166(I,N) :-
     I1 is I+1, db6(C), !, loop_q166(I1,N).

/*
[16-7:] Which country bordering the Mediterranean borders a country 
that is bordered by a country whose population exceeds the population 
of the United State?
	do "q167(1)." for only once.
*/

q167(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q167(0,N),
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

loop_q167(N,N) :- !.
loop_q167(I,N) :-
     I1 is I+1, db7(C), !, loop_q167(I1,N).

/*
[16-8:] List up all the countries which hold 16-7.
	do "q168(1)." for only once.
*/

q168(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q168(0,N),
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

loop_q168(N,N) :- !.
loop_q168(I,N) :-
     I1 is I+1, db8(C), !, loop_q168(I1,N).

/*
[16-9:] What are the oil production figures for the non-Arab OPEC
countries in the year 1975?
	do "q169(10)." for ten iterations.
*/

q169(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q169(0,N),
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

loop_q169(N,N) :- !.
loop_q169(I,N) :-
     I1 is I+1, db9(C), !, loop_q169(I1,N).

/*
[16-10:] Which is the ocean that borders African countries and that
borders European countries?
	do "q160(10)." for ten iterations.
*/

q160(N) :- 
     statistics(garbage_collection,[_,_|G1]),!,
     statistics(runtime,[_,_]),!,
     loop_q160(0,N),
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

loop_q160(N,N) :- !.
loop_q160(I,N) :-
     I1 is I+1, db10(C), !, loop_q160(I1,N).


% ******** Definition of Places database ********

open_water(atlantic_ocean).
open_water(pacific_ocean).
open_water(caribbea_sea).
open_water(gulf_of_mexico).
open_water(straits_of_magellan).
open_water(straits_of_gibraltar).
open_water(mediterranean_sea).
open_water(arctic_ocean).
open_water(india_ocean).
open_water(arabia_sea).
open_water(gulf_of_aden).
open_water(red_sea).
open_water(panama_canal).
open_water(persia_gulf).
open_water(gulf_of_oman).
open_water(bering_sea).
open_water(english_channel).
open_water(north_sea).
open_water(baltic_sea).
open_water(black_sea).
open_water(bay_of_bengal).
open_water(yellow_sea).
open_water(formosa_strait).
open_water(south_china_sea).
open_water(philippine_sea).
open_water(gulf_of_siam).
open_water(sea_of_japan).
open_water(korea_strait).
open_water(suez_canal).
open_water(straits_of_hormuz).
open_water(gulf_of_suez).
open_water(taiwa_straits).
open_water(bab_el_mandeb).
open_water(bosporus).
open_water(dardanelles).
open_water(aegea_sea).
open_water(sea_of_marmara).
open_water(skagerrak).
open_water(kattegat).
open_water(gulf_of_bothnia).

population(afghanistan,2090).
population(albania,269).
population(algeria,1850).
population(andorra,2).
population(angola,676).
population(argentina,2640).
population(australia,1422).
population(austria,750).
population(bahamas,23).
population(bahrain,28).
population(bangladesh,8250).
population(barbados,26).
population(belgium,984).
population(benin,338).
population(bhutan,123).
population(bolivia,611).
population(botswana,72).
population(brazil,11545).
population(bulgaria,884).
population(burma,3220).
population(burundi,410).
population(cambodia,889).
population(cameroon,682).
population(canada,2344).
population(cape_verde,31).
population(central_africa_empire,200).
population(chad,429).
population(chile,1088).
population(china,88000).
population(taiwan,1667).
population(colombia,2580).
population(comoro_islands,37).
population(congo,150).
population(costa_rica,212).
population(cuba,959).
population(cyprus,70).
population(czechoslovakia,1515).
population(denmark,511).
population(djibouti,22).
population(dominica_republic,517).
population(ecuador,782).
population(egypt,3950).
population(el_salvador,434).
population(ethiopia,2970).
population(greenland,5).
population(fiji,62).
population(finland,475).
population(france,5325).
population(gabon,54).
population(gambia,56).
population(east_germany,1657).
population(west_germany,6125).
population(ghana,1065).
population(greece,930).
population(grenada,11).
population(guatemala,663).
population(guinea,477).
population(guinea_bissau,54).
population(guyana,82).
population(haiti,483).
population(honduras,290).
population(hungary,1070).
population(iceland,22).
population(india,64300).
population(indonesia,14700).
population(iran,3420).
population(iraq,1235).
population(ireland,324).
population(italy,5667).
population(ivory_coast,671).
population(jamaica,211).
population(japan,11485).
population(jordan,208).
population(kenya,1480).
population(north_korea,1700).
population(south_korea,3700).
population(kuwait,119).
population(laos,354).
population(lebanon,316).
population(lesotho,109).
population(liberia,185).
population(libya,260).
population(liechtenstein,2).
population(luxembourg,37).
population(madagascar,877).
population(malawi,553).
population(malaysia,1295).
population(maldives,14).
population(mali,615).
population(malta,33).
population(mauritania,140).
population(mauritius,89).
population(mexico,6695).
population(monaco,3).
population(mongolia,157).
population(morocco,1867).
population(mozambique,995).
population(nauru,1).
population(nepal,1342).
population(netherlands,1393).
population(new_zealand,313).
population(nicaragua,239).
population(niger,500).
population(nigeria,6665).
population(norway,405).
population(oman,85).
population(pakistan,7750).
population(panama,182).
population(papua_new_guinea,298).
population(paraguay,287).
population(peru,1700).
population(philippines,4640).
population(poland,3505).
population(portugal,1000).
population(qatar,20).
population(zimbabwe_rhodesia,695).
population(romania,2163).
population(rwanda,460).
population(sa_marino,2).
population(sao_tome_and_principe,8).
population(saudi_arabia,980).
population(senegal,509).
population(seychelles,6).
population(sierra_leone,347).
population(singapore,234).
population(solomo_islands,20).
population(somalia,344).
population(south_africa,2676).
population(spain,3673).
population(sri_lanka,1420).
population(sudan,1655).
population(surinam,46).
population(swaziland,52).
population(sweden,830).
population(switzerland,631).
population(syria,800).
population(tanzania,1).
population(thailand,4538).
population(togo,241).
population(tonga,10).
population(trinidad_and_tobago,112).
population(tunisia,640).
population(turkey,4312).
population(uganda,1277).
population(ussr,26075).
population(united_arab_emirates,65).
population(uk,5580).
population(england_and_wales,4912).
population(scotland,519).
population(northern_ireland,153).
population(usa,21852).
population(upper_volta,648).
population(uruguay,282).
population(venezuela,1315).
population(vietnam,4927).
population(yeme_arab_republic,730).
population(yemen,185).
population(yugoslavia,2190).
population(zaire,2715).
population(zambia,550).
population(israel,370).

iscountry(X):-country(Y,X).

landlocked(X):- iscountry(X), \+(landlocked_test(X)).
landlocked_test(X):-borders(X,Z),open_water(Z).

country(moscow,ussr).
country(novaya_zemlya,ussr).
country(sverdlovsk,ussr).
country(vladivostok,ussr).
country(gorki,ussr).
country(novosibirsk,ussr).
country(syracuse,usa).
country(new_york_city,usa).
country(ithaca,usa).
country(albany,usa).
country(sa_francisco,usa).
country(sa_diego,usa).
country(washington,usa).
country(boston,usa).
country(rome_ny,usa).
country(rome,italy).
country(paris,france).
country(london,uk).
country(dublin,ireland).
country(stockholm,sweden).
country(copenhagen,denmark).
country(amsterdam,netherlands).
country(brussels,belgium).
country(madrid,spain).
country(athens,greece).
country(ankara,turkey).
country(istanbul,turkey).
country(tirane,albania).
country(sofia,bulgaria).
country(belgrade,yugoslavia).
country(warsaw,poland).
country(prague,czechoslovakia).
country(lisbon,portugal).
country(tehran,iran).
country(delhi,india).
country(islamabad,pakistan).
country(tokyo,japan).
country(brisbane,australia).
country(canberra,australia).
country(wellington,new_zealand).
country(djakarta,indonesia).
country(singapore,singapore).
country(peking,china).
country(hanoi,vietnam).
country(seoul,south_korea).
country(pyong_yang,north_korea).
country(recife,brazil).
country(brasilia,brazil).
country(santiago,chile).
country(oslo,norway).
country(vancouver,canada).
country(ottawa,canada).
country(montreal,canada).
country(toronto,canada).
country(havana,cuba).
country(rio_de_janeiro,brazil).
country(sa_paolo,brazil).
country(buenos_aires,argentina).
country(tierra_del_fuego,argentina).
country(punta_arenas,chile).
country(caracas,venezuela).
country(sa_juan,usa).
country(tampa,usa).
country(rangoon,burma).
country(bonn,west_germany).
country(frankfurt,east_germany).
country(rotterdam,netherlands).
country(tashkent,ussr).
country(pretoria,south_africa).
country(bucharest,romania).
country(budapest,hungary).
country(vienna,austria).
country(bern,switzerland).
country(geneva,switzerland).
country(zurich,switzerland).
country(bangkok,thailand).
country(seattle,usa).
country(tahiti,unknown).
country(saigon,vietnam).
country(yokohama,japan).
country(pnom_penh,cambodia).
country(panama_canal,panama).
country(naples,italy).
country(honolulu,usa).
country(berlin,east_germany).
country(helsinki,finland).
country(reykjavik,iceland).
country(thule,greenland).
country(godthab,greenland).
country(kabul,afghanistan).
country(wigan,uk).
country(damascus,syria).
country(jerusalem,israel).
country(beirut,lebanon).
country(amman,jordan).
country(kuala_lumpur,malaysia).
country(lima,peru).
country(quito,ecuador).
country(la_paz,bolivia).
country(asuncion,paraguay).
country(montevideo,uruguay).
country(suez_canal,egypt).
country(cairo,egypt).
country(tripoli,libya).
country(tunis,tunisia).
country(algiers,algeria).
country(rabat,morocco).
country(nicosia,cyprus).
country(riyadh,saudi_arabia).
country(baghdad,iraq).
country(manila,philippines).
country(taipei,taiwan).
country(vientiane,laos).
country(shanghai,china).
country(chunking,china).
country(canton,china).
country(mukden,china).
country(bombay,india).
country(madras,india).
country(calcutta,india).
country(dacca,bangladesh).
country(kuwait,kuwait).
country(doha,qatar).
country(samarkand,ussr).
country(addisababa,ethiopia).
country(mogadiscio,somalia).
country(kampala,uganda).
country(khartoum,sudan).
country(sana,yeme_arab_republic).
country(nairobi,kenya).
country(tananarive,madagascar).
country(durban,south_africa).
country(cape_town,south_africa).
country(windhoek,namibia).
country(luanda,angola).
country(kinshasa,zaire).
country(brazzaville,congo).
country(usambura,burundi).
country(kigali,rwanda).
country(libreville,gabon).
country(yaounde,cameroon).
country(fort_lamy,chad).
country(bangui,central_africa_empire).
country(lagos,nigeria).
country(porto_novo,benin).
country(lome,togo).
country(accra,ghana).
country(ouagadougou,upper_volta).
country(niamey,niger).
country(bamako,mali).
country(monrovia,liberia).
country(freetown,sierra_leone).
country(conakry,guinea).
country(bathurst,gambia).
country(dakar,senegal).
country(nouakchott,mauritania).
country(salisbury,zimbabwe_rhodesia).
country(lourenco_marques,mozambique).
country(darwin,australia).
country(lusaka,zambia).
country(timbuktu,mali).
country(mexico_city,mexico).
country(guatemala_city,guatemala).
country(tegucigalpa,honduras).
country(managua,nicaragua).
country(guantanamo,cuba).
country(kingston,jamaica).
country(port_au_prince,haiti).
country(santo_domingo,dominica_republic).
country(sa_jose,costa_rica).
country(panama_city,panama).
country(sa_salvador,el_salvador).
country(greenwich,uk).
country(omaha,usa).
country(denver,usa).
country(nassau,bahamas).
country(manama,bahrain).
country(bridgetown,barbados).
country(thimphu,bhutan).
country(gaborone,botswana).
country(bujumbura,burundi).
country(praia,cape_verde).
country(bogota,colombia).
country(moroni,comoro_islands).
country(djibouti,djibouti).
country(suva,fiji).
country(saint_georges,grenada).
country(bissau,guinea_bissau).
country(georgetown,guyana).
country(abidjan,ivory_coast).
country(maseru,lesotho).
country(vaduz,liechtenstein).
country(luxembourg,luxembourg).
country(blantyre,malawi).
country(male,maldives).
country(valetta,malta).
country(port_louis,mauritius).
country(monte_carlo,monaco).
country(ula_bator,mongolia).
country(yaren,nauru).
country(katmandu,nepal).
country(muscat,oman).
country(port_moresby,papua_new_guinea).
country(sa_marino,sa_marino).
country(sao_tome,sao_tome_and_principe).
country(victoria,seychelles).
country(honiara,solomo_islands).
country(colombo,sri_lanka).
country(paramaribo,surinam).
country(mbabane,swaziland).
country(dar_es_salaam,tanzania).
country(nuku_alofa,tonga).
country(port_of_spain,trinidad_and_tobago).
country(abu_dhabi,united_arab_emirates).
country(apia,western_samoa).
country(aden,yemen).
country(andorra_la_vella,andorra).
country(cayenne,french_guiana).
country(gangtok,sikkim).
country(pisa,italy).

region(canada,north_america).
region(mexico,north_america).
region(usa,north_america).
region(argentina,south_america).
region(bolivia,south_america).
region(brazil,south_america).
region(chile,south_america).
region(colombia,south_america).
region(ecuador,south_america).
region(guyana,south_america).
region(paraguay,south_america).
region(peru,south_america).
region(surinam,south_america).
region(uruguay,south_america).
region(venezuela,south_america).
region(costa_rica,central_america).
region(el_salvador,central_america).
region(guatemala,central_america).
region(honduras,central_america).
region(nicaragua,central_america).
region(panama,central_america).
region(bahamas,caribbean).
region(barbados,caribbean).
region(cuba,caribbean).
region(dominica_republic,caribbean).
region(grenada,caribbean).
region(haiti,caribbean).
region(jamaica,caribbean).
region(trinidad_and_tobago,caribbean).
region(albania,europe).
region(andorra,europe).
region(austria,europe).
region(belgium,europe).
region(bulgaria,europe).
region(cyprus,europe).
region(czechoslovakia,europe).
region(denmark,europe).
region(finland,europe).
region(france,europe).
region(east_germany,europe).
region(west_germany,europe).
region(greece,europe).
region(hungary,europe).
region(iceland,europe).
region(ireland,europe).
region(italy,europe).
region(liechtenstein,europe).
region(luxembourg,europe).
region(malta,europe).
region(monaco,europe).
region(netherlands,europe).
region(norway,europe).
region(poland,europe).
region(portugal,europe).
region(romania,europe).
region(sa_marino,europe).
region(spain,europe).
region(sweden,europe).
region(switzerland,europe).
region(ussr,europe).
region(uk,europe).
region(yugoslavia,europe).
region(bahrain,middle_east).
region(iran,middle_east).
region(iraq,middle_east).
region(israel,middle_east).
region(jordan,middle_east).
region(kuwait,middle_east).
region(lebanon,middle_east).
region(oman,middle_east).
region(qatar,middle_east).
region(saudi_arabia,middle_east).
region(syria,middle_east).
region(turkey,middle_east).
region(united_arab_emirates,middle_east).
region(yemen,middle_east).
region(yeme_arab_republic,middle_east).
region(china,far_east).
region(taiwan,far_east).
region(japan,far_east).
region(north_korea,far_east).
region(south_korea,far_east).
region(mongolia,far_east).
region(philippines,far_east).
region(cambodia,south_east_asia).
region(indonesia,south_east_asia).
region(laos,south_east_asia).
region(malaysia,south_east_asia).
region(singapore,south_east_asia).
region(thailand,south_east_asia).
region(vietnam,south_east_asia).
region(afghanistan,south_asia).
region(bangladesh,south_asia).
region(bhutan,south_asia).
region(burma,south_asia).
region(india,south_asia).
region(maldives,south_asia).
region(nepal,south_asia).
region(pakistan,south_asia).
region(sri_lanka,south_asia).
region(australia,oceania).
region(fiji,oceania).
region(nauru,oceania).
region(new_zealand,oceania).
region(papua_new_guinea,oceania).
region(solomo_islands,oceania).
region(tonga,oceania).
region(western_samoa,oceania).
region(algeria,africa).
region(angola,africa).
region(benin,africa).
region(botswana,africa).
region(burundi,africa).
region(cameroon,africa).
region(cape_verde,africa).
region(gabon,africa).
region(libya,africa).
region(nigeria,africa).
region(central_africa_empire,africa).
region(chad,africa).
region(comoro_islands,africa).
region(congo,africa).
region(djibouti,africa).
region(egypt,africa).
region(ethiopia,africa).
region(gambia,africa).
region(ghana,africa).
region(guinea,africa).
region(guinea_bissau,africa).
region(ivory_coast,africa).
region(kenya,africa).
region(lesotho,africa).
region(liberia,africa).
region(madagascar,africa).
region(malawi,africa).
region(mali,africa).
region(mauritania,africa).
region(mauritius,africa).
region(morocco,africa).
region(mozambique,africa).
region(namibia,africa).
region(niger,africa).
region(zimbabwe_rhodesia,africa).
region(rwanda,africa).
region(sao_tome_and_principe,africa).
region(senegal,africa).
region(seychelles,africa).
region(sierra,leone,africa).
region(somalia,africa).
region(south_africa,africa).
region(sudan,africa).
region(swaziland,africa).
region(tanzania,africa).
region(togo,africa).
region(tunisia,africa).
region(uganda,africa).
region(upper_volta,africa).
region(zaire,africa).
region(zambia,africa).
region(spanish_sahara,africa).
region(french_guiana,south_america).
region(sikkim,south_asia).

produces(ussr,oil,491,1975).
produces(ussr,oil,353,1970).
produces(usa,oil,41399,1975).
produces(usa,oil,475,1970).
produces(saudi_arabia,oil,352,1975).
produces(saudi_arabia,oil,188,1970).
produces(united_arab_emirates,oil,80,1975).
produces(united_arab_emirates,oil,37,1970).
produces(nigeria,oil,88,1975).
produces(nigeria,oil,54,1970).
produces(mexico,oil,36,1975).
produces(mexico,oil,21,1970).
produces(libya,oil,71,1975).
produces(libya,oil,159,1970).
produces(kuwait,oil,105,1975).
produces(kuwait,oil,150,1970).
produces(iraq,oil,111,1975).
produces(iran,oil,191,1970).
produces(iraq,oil,76,1970).
produces(iran,oil,267,1975).
produces(indonesia,oil,64,1975).
produces(indonesia,oil,42,1970).
produces(venezuela,oil,122,1975).
produces(venezuela,oil,194,1970).
produces(usa,wheat,58999,1975).
produces(usa,rice,5,1975).
produces(ussr,wheat,66,1975).
produces(ussr,rice,2,1975).
produces(algeria,oil,45999,1975).
produces(algeria,oil,47,1970).
produces(argentina,oil,20,1975).
produces(argentina,oil,20,1970).
produces(australia,oil,20,1975).
produces(australia,oil,8,1970).
produces(austria,oil,2,1975).
produces(austria,oil,2,1970).
produces(bahrain,oil,39999,1975).
produces(bahrain,oil,3,1970).
produces(brazil,oil,8,1975).
produces(brazil,oil,8,1970).
produces(bulgaria,oil,0,1975).
produces(bulgaria,oil,1,1970).
produces(canada,oil,67,1975).
produces(canada,oil,60,1970).
produces(chile,oil,1,1975).
produces(chile,oil,1,1970).
produces(china,oil,24,1975).
produces(china,oil,20999,1970).
produces(taiwan,oil,0,1975).
produces(taiwan,oil,1,1970).
produces(colombia,oil,8,1975).
produces(colombia,oil,11,1970).
produces(cuba,oil,0,1975).
produces(cuba,oil,0,1970).
produces(ecuador,oil,8,1975).
produces(ecuador,oil,0,1970).
produces(egypt,oil,8,1975).
produces(egypt,oil,16,1970).
produces(france,oil,1,1975).
produces(france,oil,2,1970).
produces(east_germany,oil,1,1975).
produces(west_germany,oil,5,1975).
produces(east_germany,oil,1,1970).
produces(west_germany,oil,7,1970).
produces(hungary,oil,2,1975).
produces(hungary,oil,1,1970).
produces(india,oil,8,1975).
produces(india,oil,6,1970).
produces(israel,oil,4,1975).
produces(israel,oil,4,1970).
produces(italy,oil,1,1975).
produces(italy,oil,1,1970).
produces(japan,oil,0,1975).
produces(japan,oil,1,1970).
produces(malaysia,oil,4,1975).
produces(malaysia,oil,1,1970).
produces(netherlands,oil,1,1975).
produces(netherlands,oil,2,1970).
produces(new_zealand,oil,1,1975).
produces(new_zealand,oil,1,1970).
produces(norway,oil,9,1975).
produces(pakistan,oil,1,1975).
produces(pakistan,oil,1,1970).
produces(peru,oil,4,1975).
produces(peru,oil,4,1970).
produces(poland,oil,1,1975).
produces(poland,oil,0,1970).
produces(romania,oil,14,1975).
produces(romania,oil,13,1970).
produces(spain,oil,2,1975).
produces(spain,oil,0,1970).
produces(syria,oil,10,1975).
produces(syria,oil,4,1970).
produces(tunisia,oil,5,1975).
produces(tunisia,oil,4,1970).
produces(turkey,oil,39999,1975).
produces(turkey,oil,3,1970).
produces(uk,oil,1,1975).
produces(uk,oil,1,1970).
produces(yugoslavia,oil,4,1975).
produces(yugoslavia,oil,3,1970).
produces(zaire,oil,1,1975).
produces(afghanistan,wheat,3,1975).
produces(argentina,wheat,9,1975).
produces(australia,wheat,12,1975).
produces(austria,wheat,1,1975).
produces(bangladesh,wheat,0,1975).
produces(belgium,wheat,1,1975).
produces(brazil,wheat,2,1975).
produces(bulgaria,wheat,3,1975).
produces(canada,wheat,17780,1975).
produces(chile,wheat,10200,1975).
produces(china,wheat,41029,1975).
produces(taiwan,wheat,0,1975).
produces(colombia,wheat,0,1975).
produces(czechoslovakia,wheat,4,1975).
produces(denmark,wheat,0,1975).
produces(ecuador,0,1975).
produces(egypt,wheat,23299,1975).
produces(ethiopia,wheat,1,1975).
produces(finland,wheat,1,1975).
produces(france,wheat,15410,1975).
produces(east_germany,wheat,2,1975).
produces(west_germany,wheat,71399,1975).
produces(greece,wheat,2,1975).
produces(hungary,wheat,40700,1975).
produces(india,wheat,24,1975).
produces(iran,wheat,5,1975).
produces(iraq,wheat,1,1975).
produces(ireland,wheat,0,1975).
produces(israel,wheat,0,1975).
produces(italy,wheat,10,1975).
produces(japan,wheat,0,1975).
produces(north_korea,wheat,0,1975).
produces(south_korea,wheat,0,1975).
produces(mexico,wheat,3,1975).
produces(nepal,wheat,0,1975).
produces(netherlands,wheat,0,1975).
produces(new_zealand,wheat,0,1975).
produces(pakistan,wheat,7,1975).
produces(peru,wheat,0,1975).
produces(poland,wheat,5,1975).
produces(portugal,wheat,0,1975).
produces(romania,wheat,4,1975).
produces(south_africa,wheat,1,1975).
produces(spain,wheat,4,1975).
produces(sweden,wheat,1,1975).
produces(switzerland,wheat,0,1975).
produces(syria,wheat,1,1975).
produces(turkey,wheat,14,1975).
produces(uk,wheat,4,1975).
produces(uruguay,wheat,0,1975).
produces(yugoslavia,wheat,4,1975).
produces(afghanistan,rice,0,1975).
produces(argentina,rice,0,1975).
produces(australia,rice,0,1975).
produces(bangladesh,rice,19,1975).
produces(brazil,rice,7,1975).
produces(bulgaria,rice,0,1975).
produces(burma,rice,9,1975).
produces(burma,wheat,0,1975).
produces(cambodia,rice,9,1975).
produces(chile,rice,0,1975).
produces(china,rice,116,1975).
produces(taiwan,rice,2,1975).
produces(colombia,rice,1,1975).
produces(cuba,rice,0,1975).
produces(ecuador,rice,0,1975).
produces(egypt,rice,2,1975).
produces(france,rice,0,1975).
produces(greece,rice,0,1975).
produces(hungary,rice,0,1975).
produces(india,rice,74,1975).
produces(indonesia,rice,22,1975).
produces(iran,rice,1,1975).
produces(iraq,rice,0,1975).
produces(italy,rice,1,1975).
produces(japan,rice,17,1975).
produces(north_korea,rice,3,1975).
produces(south_korea,rice,6,1975).
produces(laos,rice,0,1975).
produces(madagascar,rice,1,1975).
produces(malaysia,rice,2,1975).
produces(mexico,rice,0,1975).
produces(nepal,rice,2,1975).
produces(pakistan,rice,3,1975).
produces(panama,rice,0,1975).
produces(peru,rice,0,1975).
produces(philippines,rice,6,1975).
produces(portugal,rice,0,1975).
produces(romania,rice,0,1975).
produces(spain,rice,0,1975).
produces(sri_lanka,rice,1,1975).
produces(thailand,rice,15,1975).
produces(turkey,rice,0,1975).
produces(uruguay,rice,0,1975).
produces(venezuale,rice,0,1975).
produces(vietnam,rice,12,1975).
produces(yugoslavia,rice,0,1975).
produces(usa,uranium,9,1976).
produces(canada,uranium,4,1976).
produces(south_africa,uranium,3,1976).
produces(france,uranium,2,1976).
produces(niger,uranium,1,1976).
produces(belgium,steel,11,1975).
produces(canada,steel,13,1975).
produces(argentia,steel,1,1975).
produces(australia,steel,8,1975).
produces(austria,steel,4,1975).
produces(brazil,steel,8,1975).
produces(bulgaria,steel,2,1975).
produces(chile,steel,0,1975).
produces(china,steel,29,1975).
produces(taiwan,steel,0,1975).
produces(colombia,steel,0,1975).
produces(cuba,steel,0,1975).
produces(czechoslovakia,steel,14,1975).
produces(denmark,steel,0,1975).
produces(egypt,steel,0,1975).
produces(finland,steel,1,1975).
produces(france,steel,21,1975).
produces(east_germany,steel,6,1975).
produces(west_germany,steel,40,1975).
produces(greece,steel,0,1975).
produces(hungary,steel,3,1975).
produces(india,steel,7,1975).
produces(ireland,steel,0,1975).
produces(israel,steel,0,1975).
produces(italy,steel,21,1975).
produces(japan,steel,102,1975).
produces(north_korea,steel,2,1975).
produces(south_korea,steel,2,1975).
produces(luxembourg,steel,4,1975).
produces(mexico,steel,5,1975).
produces(netherlands,steel,4,1975).
produces(norway,steel,0,1975).
produces(peru,steel,0,1975).
produces(poland,steel,14,1975).
produces(portugal,steel,0,1975).
produces(romania,steel,9,1975).
produces(south_africa,steel,6,1975).
produces(zimbabwe_rhodesia,steel,0,1975).
produces(spain,steel,11,1975).
produces(sweden,steel,5,1975).
produces(switzerland,steel,0,1975).
produces(tunisia,steel,0,1975).
produces(turkey,steel,1,1975).
produces(ussr,steel,141,1975).
produces(uk,steel,20,1975).
produces(usa,steel,105,1975).
produces(venezuela,steel,1,1975).
produces(yugoslavia,steel,2,1975).

belongs(canada,nato).
belongs(canada,commonwealth).
belongs(canada,oecd).
belongs(mexico,oas).
belongs(usa,oas).
belongs(usa,nato).
belongs(argentina,oas).
belongs(bolivia,oas).
belongs(brazil,oas).
belongs(chile,oas).
belongs(ecuador,oas).
belongs(ecuador,opec).
belongs(guyana,commonwealth).
belongs(paraguay,oas).
belongs(peru,oas).
belongs(surinam,oas).
belongs(uruguay,oas).
belongs(venezuela,oas).
belongs(venezuela,opec).
belongs(costa_rica,oas).
belongs(el_salvador,oas).
belongs(guatemala,oas).
belongs(honduras,oas).
belongs(nicaragua,oas).
belongs(panama,oas).
belongs(bahamas,commonwealth).
belongs(barbados,oas).
belongs(barbados,commonwealth).
belongs(dominica_republic,oas).
belongs(grenada,oas).
belongs(grenada,commonwealth).
belongs(haiti,oas).
belongs(jamaica,oas).
belongs(jamaica,commonwealth).
belongs(trinidad_and_tobago,oas).
belongs(trinidad_and_tobago,commonwealth).
belongs(austria,efta).
belongs(austria,oecd).
belongs(belgium,nato).
belongs(belgium,eec).
belongs(belgium,oecd).
belongs(bulgaria,warsaw_pact).
belongs(cyprus,commonwealth).
belongs(czechoslovakia,warsaw_pact).
belongs(denmark,nato).
belongs(denmark,eec).
belongs(denmark,oecd).
belongs(finland,efta).
belongs(finland,oecd).
belongs(france,nato).
belongs(france,eec).
belongs(france,oecd).
belongs(east_germany,warsaw_pact).
belongs(west_germany,nato).
belongs(west_germany,eec).
belongs(west_germany,oecd).
belongs(greece,nato).
belongs(greece,oecd).
belongs(hungary,warsaw_pact).
belongs(iceland,nato).
belongs(iceland,efta).
belongs(iceland,oecd).
belongs(ireland,eec).
belongs(ireland,oecd).
belongs(italy,nato).
belongs(italy,eec).
belongs(italy,oecd).
belongs(luxembourg,nato).
belongs(luxembourg,eec).
belongs(luxembourg,oecd).
belongs(malta,commonwealth).
belongs(netherlands,nato).
belongs(netherlands,eec).
belongs(netherlands,oecd).
belongs(norway,nato).
belongs(norway,efta).
belongs(norway,oecd).
belongs(poland,warsaw_pact).
belongs(portugal,nato).
belongs(portugal,efta).
belongs(portugal,oecd).
belongs(romania,warsaw_pact).
belongs(spain,oecd).
belongs(sweden,oecd).
belongs(sweden,efta).
belongs(switzerland,efta).
belongs(switzerland,oecd).
belongs(ussr,warsaw_pact).
belongs(uk,nato).
belongs(uk,cento).
belongs(uk,eec).
belongs(uk,commonwealth).
belongs(uk,oecd).
belongs(bahrain,arab_league).
belongs(iran,opec).
belongs(iran,cento).
belongs(iraq,opec).
belongs(iraq,arab_league).
belongs(jordan,arab_league).
belongs(kuwait,opec).
belongs(kuwait,arab_league).
belongs(lebanon,arab_league).
belongs(oman,arab_league).
belongs(qatar,opec).
belongs(qatar,arab_league).
belongs(saudi_arabia,opec).
belongs(saudi_arabia,arab_league).
belongs(syria,arab_league).
belongs(turkey,nato).
belongs(turkey,cento).
belongs(turkey,oecd).
belongs(united_arab_emirates,opec).
belongs(united_arab_emirates,arab_league).
belongs(yemen,arab_league).
belongs(yeme_arab_republic,arab_league).
belongs(japan,oecd).
belongs(philippines,asean).
belongs(indonesia,opec).
belongs(indonesia,asean).
belongs(malaysia,asean).
belongs(malaysia,commonwealth).
belongs(singapore,asean).
belongs(singapore,commonwealth).
belongs(thailand,asean).
belongs(bangladesh,commonwealth).
belongs(india,commonwealth).
belongs(pakistan,cento).
belongs(sri_lanka,commonwealth).
belongs(australia,commonwealth).
belongs(fiji,commonwealth).
belongs(new_zealand,commonwealth).
belongs(new_zealand,oecd).
belongs(papua_new_guinea,commonwealth).
belongs(solomo_islands,commonwealth).
belongs(tonga,commonwealth).
belongs(western_samoa,commonwealth).
belongs(algeria,oau).
belongs(algeria,opec).
belongs(algeria,arab_league).
belongs(angola,oau).
belongs(benin,oau).
belongs(benin,ecwas).
belongs(botswana,oau).
belongs(botswana,commonwealth).
belongs(burundi,oau).
belongs(cameroon,oau).
belongs(cameroon,ecwas).
belongs(cape_verde,oau).
belongs(gabon,opec).
belongs(gabon,oau).
belongs(libya,opec).
belongs(libya,oau).
belongs(libya,arab_league).
belongs(nigeria,oau).
belongs(nigeria,opec).
belongs(nigeria,commonwealth).
belongs(nigeria,ecwas).
belongs(tunisia,arab_league).
belongs(somalia,arab_league).
belongs(sudan,arab_league).
belongs(morocco,arab_league).
belongs(mauritania,arab_league).
belongs(djibouti,arab_league).
belongs(egypt,arab_league).
belongs(gambia,commonwealth).
belongs(ghana,commonwealth).
belongs(kenya,commonwealth).
belongs(lesotho,commonwealth).
belongs(malawi,commonwealth).
belongs(mauritius,commonwealth).
belongs(seychelles,commonwealth).
belongs(sierra_leone,commonwealth).
belongs(swaziland,commonwealth).
belongs(tanzania,commonwealth).
belongs(togo,commonwealth).
belongs(uganda,commonwealth).
belongs(zambia,commonwealth).

adjoins(canada,usa).
adjoins(mexico,usa).
adjoins(atlantic_ocean,canada).
adjoins(canada,pacific_ocean).
adjoins(atlantic_ocean,usa).
adjoins(caribbea_sea,usa).
adjoins(pacific_ocean,usa).
adjoins(guatemala,mexico).
adjoins(guatemala,pacific_ocean).
adjoins(el_salvador,guatemala).
adjoins(guatemala,honduras).
adjoins(caribbea_sea,guatemala).
adjoins(british_honduras,guatemala).
adjoins(british_honduras,mexico).
adjoins(british_honduras,caribbea_sea).
adjoins(mexico,pacific_ocean).
adjoins(arctic_ocean,canada).
adjoins(arctic_ocean,greenland).
adjoins(arctic_ocean,norway).
adjoins(arctic_ocean,ussr).
adjoins(atlantic_ocean,greenland).
adjoins(atlantic_ocean,iceland).
adjoins(atlantic_ocean,ireland).
adjoins(atlantic_ocean,uk).
adjoins(atlantic_ocean,france).
adjoins(atlantic_ocean,spain).
adjoins(atlantic_ocean,portugal).
adjoins(atlantic_ocean,straits_of_gibraltar).
adjoins(mediterranean_sea,straits_of_gibraltar).
adjoins(spain,straits_of_gibraltar).
adjoins(morocco,straits_of_gibraltar).
adjoins(atlantic,ocean,morocco).
adjoins(atlantic_ocean,morocco).
adjoins(atlantic_ocean,spanish_sahara).
adjoins(atlantic_ocean,mauritania).
adjoins(atlantic_ocean,senegal).
adjoins(atlantic_ocean,gambia).
adjoins(atlantic_ocean,sierra_leone).
adjoins(atlantic_ocean,liberia).
adjoins(atlantic_ocean,ivory_coast).
adjoins(atlantic_ocean,ghana).
adjoins(atlantic_ocean,togo).
adjoins(atlantic_ocean,benin).
adjoins(atlantic_ocean,nigeria).
adjoins(atlantic_ocean,cameroon).
adjoins(atlantic_ocean,gabon).
adjoins(atlantic_ocean,angola).
adjoins(atlantic_ocean,namibia).
adjoins(atlantic_ocean,south_africa).
adjoins(atlantic_ocean,straits_of_magellan).
adjoins(argentina,atlantic,ocean).
adjoins(argentina,straits_of_magellan).
adjoins(chile,straits_of_magellan).
adjoins(chile,pacific_ocean).
adjoins(argentina,chile).
adjoins(argentina,bolivia).
adjoins(argentina,paraguay).
adjoins(argentina,uruguay).
adjoins(argentina,brazil).
adjoins(atlantic_ocean,uruguay).
adjoins(atlantic_ocean,brazil).
adjoins(atlantic_ocean,french_guiana).
adjoins(atlantic_ocean,guyana).
adjoins(atlantic_ocean,surinam).
adjoins(atlantic_ocean,venezuela).
adjoins(atlantic_ocean,trinidad_and_tobago).
adjoins(atlantic_ocean,caribbea_sea).
adjoins(atlantic_ocean,gulf_of_mexico).
adjoins(caribbea_sea,gulf_of_mexico).
adjoins(atlantic_ocean,india_ocean).
adjoins(india_ocean,south_africa).
adjoins(india_ocean,pacific_ocean).
adjoins(india_ocmozambique).
adjoins(india_ocean,mozambique).
adjoins(india_ocean,madagascar).
adjoins(arabia_sea,india_ocean).
adjoins(arabia_sea,gulf_of_aden).
adjoins(gulf_of_aden,red_sea).
adjoins(suez_canal,red_sea).
adjoins(mediterranean_sea,suez_canal).
adjoins(gulf_of_oman,persia_gulf).
adjoins(gulf_of_oman,arabia_sea).
adjoins(bering_sea,ussr).
adjoins(bering_sea,usa).
adjoins(arctic_ocean,bering_sea).
adjoins(bering_sea,pacific_ocean).
adjoins(egypt,suez_canal).
adjoins(panama,panama_canal).
adjoins(caribbea_sea,panama_canal).
adjoins(atlantic_ocean,english_channel).
adjoins(english_channel,north_sea).
adjoins(netherlands,north_sea).
adjoins(netherlands,west_germany).
adjoins(belgium,netherlands).
adjoins(belgium,north_sea).
adjoins(belgium,luxembourg).
adjoins(belgium,west_germany).
adjoins(belgium,france).
adjoins(english,channel,france).
adjoins(france,luxembourg).
adjoins(france,west_germany).
adjoins(france,switzerland).
adjoins(france,mediterranean_sea).
adjoins(france,italy).
adjoins(france,spain).
adjoins(andorra,france).
adjoins(mediterranean_sea,spain).
adjoins(portugal,spain).
adjoins(andorra,spain).
adjoins(italy,switzerland).
adjoins(italy,yugoslavia).
adjoins(austria,italy).
adjoins(italy,mediterranean_sea).
adjoins(east_germany,west_germany).
adjoins(east_germany,poland).
adjoins(czechoslovakia,west_germany).
adjoins(czechoslovakia,east_germany).
adjoins(austria,west_germany).
adjoins(switzerland,west_germany).
adjoins(denmark,west_germany).
adjoins(north_sea,west_germany).
adjoins(baltic_sea,west_germany).
adjoins(baltic_sea,east_germany).
adjoins(baltic_sea,poland).
adjoins(baltic_sea,ussr).
adjoins(baltic_sea,finland).
adjoins(baltic_sea,sweden).
adjoins(baltic_sea,kattegat).
adjoins(kattegat,skagerrak).
adjoins(skagerrak,north_sea).
adjoins(kattegat,denmark).
adjoins(kattegat,sweden).
adjoins(skagerrak,denmark).
adjoins(skagerrak,norway).
adjoins(norway,atlantic_ocean).
adjoins(norway,sweden).
adjoins(north_sea,norway).
adjoins(finland,norway).
adjoins(norway,ussr).
adjoins(finland,sweden).
adjoins(finland,ussr).
adjoins(czechoslovakia,poland).
adjoins(poland,ussr).
adjoins(austria,switzerland).
adjoins(austria,czechoslovakia).
adjoins(austria,yugoslavia).
adjoins(austria,hungary).
adjoins(hungary,romania).
adjoins(hungary,yugoslavia).
adjoins(czechoslovakia,hungary).
adjoins(czechoslovakia,ussr).
adjoins(hungary,ussr).
adjoins(romania,ussr).
adjoins(bulgaria,ussr).
adjoins(bulgaria,romania).
adjoins(black_sea,bulgaria).
adjoins(bulgaria,greece).
adjoins(bulgaria,turkey).
adjoins(bulgaria,yugoslavia).
adjoins(mediterranean_sea,yugoslavia).
adjoins(albania,yugoslavia).
adjoins(albania,greece).
adjoins(mediterranean_sea,albania).
adjoins(black_sea,turkey).
adjoins(black_sea,romania).
adjoins(black_sea,ussr).
adjoins(greece,yugoslavia).
adjoins(turkey,ussr).
adjoins(mediterranean_sea,turkey).
adjoins(iran,turkey).
adjoins(iraq,turkey).
adjoins(syria,turkey).
adjoins(pacific_ocean,straits_of_magellan).
adjoins(red_sea,suez_canal).
adjoins(india,pakistan).
adjoins(india,nepal).
adjoins(china,india).
adjoins(burma,india).
adjoins(bangladesh,india).
adjoins(bhutan,india).
adjoins(arabia_sea,india).
adjoins(bay_of_bengal,india).
adjoins(india,india_ocean).
adjoins(bay_of_bengal,india_ocean).
adjoins(arabia_sea,pakistan).
adjoins(india,sikkim).
adjoins(bhutan,sikkim).
adjoins(nepal,sikkim).
adjoins(china,nepal).
adjoins(afghanistan,iran).
adjoins(afghanistan,ussr).
adjoins(afghanistan,pakistan).
adjoins(afghanistan,china).
adjoins(china,ussr).
adjoins(china,mongolia).
adjoins(mongolia,ussr).
adjoins(burma,china).
adjoins(china,laos).
adjoins(china,vietnam).
adjoins(china,bhutan).
adjoins(china,sikkim).
adjoins(china,pakistan).
adjoins(china,north_korea).
adjoins(china,yellow_sea).
adjoins(east_china_sea,yellow_sea).
adjoins(china,east_china_sea).
adjoins(east_china_sea,pacific_ocean).
adjoins(east_china_sea,formosa_strait).
adjoins(formosa_strait,south_china_sea).
adjoins(china,south_china_sea).
adjoins(philippine_sea,pacific_ocean).
adjoins(philippines,philippine_sea).
adjoins(philippines,south_china_sea).
adjoins(south_china_sea,vietnam).
adjoins(laos,vietnam).
adjoins(cambodia,gulf_of_siam).
adjoins(gulf_of_siam,south_china_sea).
adjoins(israel,dead_sea).
adjoins(jordan,dead_sea).
adjoins(ethiopia,sudan).
adjoins(ethiopia,kenya).
adjoins(ethiopia,somalia).
adjoins(ethiopia,gulf_of_aden).
adjoins(djibouti,ethiopia).
adjoins(djibouti,gulf_of_aden).
adjoins(djibouti,somalia).
adjoins(ethiopia,red_sea).
adjoins(egypt,sudan).
adjoins(suez_canal,gulf_of_suez).
adjoins(gulf_of_suez,red_sea).
adjoins(taiwan,taiwa_straits).
adjoins(taiwan,pacific_ocean).
adjoins(gulf_of_siam,thailand).
adjoins(laos,thailand).
adjoins(cambodia,laos).
adjoins(north_korea,south_korea).
adjoins(north_korea,ussr).
adjoins(north_korea,yellow_sea).
adjoins(sea_of_japan,north_korea).
adjoins(south_korea,yellow_sea).
adjoins(sea_of_japan,south_korea).
adjoins(korea_strait,sea_of_japan).
adjoins(korea_strait,east_china_sea).
adjoins(korea_strait,south_korea).
adjoins(japan,korea_strait).
adjoins(japan,pacific_ocean).
adjoins(east_china_sea,japan).
adjoins(denmark,north_sea).
adjoins(greece,mediterraniea_sea).
adjoins(greece,mediterranean_sea).
adjoins(israel,mediterranean_sea).
adjoins(egypt,mediterranean_sea).
adjoins(libya,mediterranean_sea).
adjoins(tunisia,mediterranean_sea).
adjoins(algeria,mediterranean_sea).
adjoins(morocco,mediterranean_sea).
adjoins(malta,mediterranean_sea).
adjoins(libya,tunisia).
adjoins(libya,algeria).
adjoins(libya,niger).
adjoins(chad,libya).
adjoins(libya,sudan).
adjoins(libya,egypt).
adjoins(algeria,tunisia).
adjoins(algeria,morocco).
adjoins(algeria,mauritania).
adjoins(algeria,mali).
adjoins(algeria,niger).
adjoins(dahomey,nigeria).
adjoins(niger,nigeria).
adjoins(chad,nigeria).
adjoins(cameroon,nigeria).
adjoins(iran,ussr).
adjoins(caspia_sea,iran).
adjoins(iran,pakistan).
adjoins(iran,iraq).
adjoins(iran,persia_gulf).
adjoins(iran,gulf_of_oman).
adjoins(oman,gulf_of_oman).
adjoins(iraq,syria).
adjoins(iraq,jordan).
adjoins(iraq,saudi_arabia).
adjoins(iraq,kuwait).
adjoins(iraq,persia_gulf).
adjoins(iran,straits_of_hormuz).
adjoins(persia_gulf,straits_of_hormuz).
adjoins(jordan,israel).
adjoins(jordan,syria).
adjoins(jordan,saudi_arabia).
adjoins(jordan,gulf_of_aqabq).
adjoins(gulf_of_aqabq,red_sea).
adjoins(israel,egypt).
adjoins(israel,lebanon).
adjoins(israel,syria).
adjoins(israel,gulf_of_aqaba).
adjoins(dardanelles,turkey).
adjoins(dardanelles,sea_of_marmara).
adjoins(sea_of_marmara,turkey).
adjoins(sea_of_marmara,bosporus).
adjoins(bosporus,turkey).
adjoins(bab_el_mandeb,djibouti).
adjoins(bab_el_mandeb,yemen).
adjoins(bab_el_mandeb,yeme_arab_republic).
adjoins(bab_el_mandeb,red_sea).
adjoins(bab_el_mandeb,gulf_of_aden).
adjoins(straits_of_hormuz,united_arab_emirates).
adjoins(straits_of_hormuz,oman).
adjoins(straits_of_dover,uk).
adjoins(straits_of_dover,france).
adjoins(straits_of_dover,english_channel).
adjoins(straits_of_dover,north_sea).
adjoins(monaco,mediterranean_sea).
adjoins(arctic_ocean,usa).

borders(X,Y):-adjoins(X,Y).
borders(X,Y):-adjoins(Y,X).

% ******** That's all ********
