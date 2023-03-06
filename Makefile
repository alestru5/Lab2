vector:
	gcc -w -c -g input.c
	gcc -w -c -g -USE_VECTOR main.c
	gcc -c vector.c
	ar cr libinput.a input.o
	ar cr libvector.a vector.o
	gcc -w -c -g -USE_VECTOR translate.c -L. -lvector
	ar cr libtranslate.a translate.o
	gcc -w main.o -o a.out -L. -linput -L. -ltranslate -L. -lvector
list:
	gcc -w -c -g input.c
	gcc -w -c -USE_LIST main.c
	gcc -c list.c
	ar cr libinput.a input.o
	ar cr liblist.a list.o
	gcc -w -c -g -USE_LIST translate.c -L. -llist
	ar cr libtranslate.a translate.o
	gcc -w main.o -o a.out -L. -linput -L. -ltranslate -L. -llist
clean:
	rm *.o
	rm *.a
	rm a.out
