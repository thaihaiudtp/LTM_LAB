#include <stdio.h>
#include <string.h>
#include <time.h>
#include "log.h"
void writeLog(const char *mssv, int choice, const char *input, int result) {
    FILE *f = fopen("log_20225621.txt", "a"); 
    if (!f) return;
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    fprintf(f, "[%02d/%02d/%04d %02d:%02d:%02d] $ %d $ %s $ %s\n",
            t->tm_mday, t->tm_mon+1, t->tm_year+1900,
            t->tm_hour, t->tm_min, t->tm_sec,
            choice, input, result==0?"+OK":"-ERR");
    fclose(f);
}