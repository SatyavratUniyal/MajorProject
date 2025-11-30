#ifndef TYPING_H
#define TYPING_H

#include <time.h>

double calculateTime(clock_t start, clock_t end);
int countWords(const char text[]);
int calculateErrors(const char sampleText[], const char typedText[]);

#endif
