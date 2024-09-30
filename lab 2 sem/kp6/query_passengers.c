#include "passenger.h"
#include <stdio.h>
#include <stdlib.h>

void print_passengers(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Passenger passenger;
    int id = 1;
    printf("ID | Name               | Baggage Weight\n");
    printf("----------------------------------------\n");

    while (fread(&passenger, sizeof(Passenger), 1, file)) {
        printf("%2d | %-18s | %d kg\n", id++, passenger.name, passenger.baggage_weight);
    }

    fclose(file);
}

void find_passengers_within_limit(const char *filename, int limit) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Passenger passenger;
    int max_weight = 0;

    // First pass to find the maximum baggage weight
    while (fread(&passenger, sizeof(Passenger), 1, file)) {
        if (passenger.baggage_weight > max_weight) {
            max_weight = passenger.baggage_weight;
        }
    }

    rewind(file);

    printf("Passengers with baggage within %d kg of max (%d kg):\n", limit, max_weight);
    printf("ID | Name               | Baggage Weight\n");
    printf("----------------------------------------\n");

    int id = 1;
    while (fread(&passenger, sizeof(Passenger), 1, file)) {
        if (max_weight - passenger.baggage_weight <= limit) {
            printf("%2d | %-18s | %d kg\n", id++, passenger.name, passenger.baggage_weight);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <mode> [limit]\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    const char *mode = argv[2];

    if (strcmp(mode, "-f") == 0) {
        print_passengers(filename);
    } else if (strcmp(mode, "-q") == 0 && argc == 4) {
        int limit = atoi(argv[3]);
        find_passengers_within_limit(filename, limit);
    } else {
        printf("Invalid mode. Use -f to print or -q to query with limit.\n");
    }

    return 0;
}
