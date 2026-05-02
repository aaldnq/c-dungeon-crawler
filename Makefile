CC = gcc
CFLAGS = -Wall -Wextra -g

inventory: main.o item.o inventory.o
	$(CC) $(CFLAGS) -o inventory main.o item.o inventory.o

main.o: main.c inventory.h item.h
	$(CC) $(CFLAGS) -c main.c

item.o: item.c item.h
	$(CC) $(CFLAGS) -c item.c

inventory.o: inventory.c inventory.h item.h
	$(CC) $(CFLAGS) -c inventory.c

clean:
	rm -f *.o inventory
