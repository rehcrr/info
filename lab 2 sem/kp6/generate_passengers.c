#include "passenger.h"
#include <stdio.h>

void generate_passenger_data(const char *filename) {
    Passenger passengers[MAX_PASSENGERS] = {
        {"Ivan Petrov", 25},
        {"Anna Sidorova", 30},
        {"Oleg Kuznetsov", 28},
        {"Maria Ivanova", 27},
        {"Sergey Volkov", 32}
    };

    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    fwrite(passengers, sizeof(Passenger), 5, file);
    fclose(file);
    printf("File '%s' successfully generated.\n", filename);
}

int main() {
    generate_passenger_data("passengers.dat");
    return 0;
}
