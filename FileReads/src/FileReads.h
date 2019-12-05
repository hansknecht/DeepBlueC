#ifndef FILEREADS
#define FILEREADS

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

void printClockTime(clock_t, clock_t);
void readWriteUnbufferedStd(char*, char*);
void readWriteSystem(char*, char*);
int main(void);
#endif
