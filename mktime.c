#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
    time_t tt;
    struct tm tmtt;

    memset(&tmtt, 0x00, sizeof(struct tm));
    char *byetime;
    strncpy(byetime, "2016-06-24 09:53:50", 32);
    sscanf(byetime, "%04d-%02d-%02d %02d:%02d:%02d", &tmtt.tm_year, &tmtt.tm_mon, &tmtt.tm_mday, &tmtt.tm_hour, &tmtt.tm_min, &tmtt.tm_sec);

    tt = mktime(&tmtt);

    printf("tt:%ld\n",tt);
    return 0;
}
