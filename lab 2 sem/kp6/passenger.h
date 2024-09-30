#ifndef PASSENGER_H
#define PASSENGER_H

#define MAX_NAME_LEN 50
#define MAX_PASSENGERS 100

typedef struct {
    char name[MAX_NAME_LEN];
    int baggage_weight;
} Passenger;

void generate_passenger_data(const char *filename);
void print_passengers(const char *filename);
void find_passengers_within_limit(const char *filename, int limit);

#endif
