#include <string.h>
#include <time.h>
#include "typing.h"

// Function to calculate time taken
double calculateTime(clock_t start, clock_t end) {
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    return timeTaken / 60.0;  // Convert to minutes
}

// Function to count words
int countWords(const char text[]) {
    int count = 0, inWord = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] != ' ' && text[i] != '\n' && !inWord) {
            inWord = 1;
            count++;
        } else if (text[i] == ' ' || text[i] == '\n') {
            inWord = 0;
        }
    }
    return count;
}

// Function to calculate errors
int calculateErrors(const char sampleText[], const char typedText[]) {
    int errors = 0;
    int len = strlen(sampleText);

    for (int i = 0; i < len; i++) {
        if (sampleText[i] != typedText[i])
            errors++;
    }
    return errors;
}
