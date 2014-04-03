output=INTRA_e

$(output): INTRA.o p11.o
	gcc -o $(output) INTRA.o p11.o -lpthread -g
INTRA.o: INTRA.c local_mutex.h
	gcc -o INTRA.o INTRA.c -c -lpthread -g
p11.o: p11.c local_mutex.h
	gcc -o p11.o p11.c -c -lpthread -g
clean:
	rm -rf *.o $(output)  
