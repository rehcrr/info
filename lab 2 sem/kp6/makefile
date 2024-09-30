CC = gcc
CFLAGS = -Wall

all: generate_passengers query_passengers

generate_passengers: generate_passengers.o
	$(CC) $(CFLAGS) -o generate_passengers generate_passengers.o

query_passengers: query_passengers.o
	$(CC) $(CFLAGS) -o query_passengers query_passengers.o

generate_passengers.o: generate_passengers.c passenger.h
	$(CC) $(CFLAGS) -c generate_passengers.c

query_passengers.o: query_passengers.c passenger.h
	$(CC) $(CFLAGS) -c query_passengers.c

clean:
	rm -f *.o generate_passengers query_passengers
