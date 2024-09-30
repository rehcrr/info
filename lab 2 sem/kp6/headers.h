#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdbool.h>

#define MAX_PASSENGERS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int baggage_weight;
} Passenger;

void generate_data(const char *filename);
void print_passengers(const char *filename);
void find_passengers_within_limit(const char *filename, int limit);
bool is_valid_file(const char *filename);

#endif
