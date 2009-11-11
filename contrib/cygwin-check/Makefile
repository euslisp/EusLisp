all: 
	make -k lockf priority getnetbyname dlltest tzname

lockf: lockf.c
	@echo ";;"
	@echo ";; check if lockf exists"
	@echo ";;"
	gcc -o lockf lockf.c

priority: priority.c
	@echo ";;"
	@echo ";; check if setpriority/getpriority exists"
	@echo ";;"
	gcc -o priority priority.c

getnetbyname: getnetbyname.c
	@echo ";;"
	@echo ";; check if getnetbyname exists"
	@echo ";;"
	gcc -o getnetbyname getnetbyname.c

dlltest: dlltest.c
	@echo ";;"
	@echo ";; check if getnetbyname exists"
	@echo ";;"
	gcc -o dlltest.o -c dlltest.c
	#gcc -shared -o dlltest.dll dlltest.o -Wl,--export-all-symbols -Wl,--enable-auto-import -Wl,--enable-runtime-pseudo-reloc -Wl,--no-whole-archive -Wl,--unresolved-symbols="ignore-all" -Wl,--warn-unresolved-symbols -Wl,--allow-shlib-undefined -Wl,--warn-once
	gcc -shared -o dlltest.dll dlltest.o -Wl,--allow-shlib-undefined -Wl,--undefined
	gcc -shared -o dlltest.dll dlltest.o -Wl,--allow-shlib-undefined -Wl,--no-undefined

tzname: tzname.c
	@echo ";;"
	@echo ";; check tzname"
	@echo ";;"
	gcc -o tzname tzname.c; ./tzname

clean:
	rm -f *~ *.dll *.o *.exe *.stackdump lockf priority getnetbyname

