compile: test.o list.o
	gcc test.o

run:
	./a.out

clean:
	rm *.o a.out

test.o: test.c
	gcc -c test.c

list.o: list.c
	gcc -c list.c
