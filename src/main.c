#include <stdio.h>
#include <string.h>
#include <time.h>
#include "typing.h"

int main() {

    char sampleText[] = "The quick brown fox jumps over the lazy dog.";
    char typedText[500];

    printf("\nTyping Speed Tester\n");
    printf("Type the following sentence:\n\n%s\n\n", sampleText);

    printf("Press ENTER when ready...\n");
    getchar();  // Wait for user to press enter

    printf("Start typing below:\n");

    clock_t start = clock();     // Start timer
    fgets(typedText, sizeof(typedText), stdin);   // Read typed text
    clock_t end = clock();       // Stop timer

    // Calculate values
    double timeTaken = calculateTime(start, end);
    int words = countWords(typedText);
    int chars = strlen(typedText) - 1;    // ignore newline
    int errors = calculateErrors(sampleText, typedText);

    double wpm = words / timeTaken;
    double cpm = chars / timeTaken;
    double accuracy = ((double)(chars - errors) / chars) * 100;

    // Display results
    printf("\n RESULTS \n");
    printf("Time Taken: %.2f seconds\n", timeTaken * 60);
    printf("Words Typed: %d\n", words);
    printf("Characters Typed: %d\n", chars);
    printf("Errors: %d\n", errors);
    printf("WPM (Words/Minute): %.2f\n", wpm);
    printf("CPM (Characters/Minute): %.2f\n", cpm);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("/n");

    return 0;
}
