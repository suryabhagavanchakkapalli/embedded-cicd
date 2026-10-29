#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("/proc/uptime", "r");

    if (fp == NULL) {
        perror("Failed to open /proc/uptime");
        return 1;
    }

    double uptime_seconds;

    if (fscanf(fp, "%lf", &uptime_seconds) != 1) {
        fprintf(stderr, "Failed to read uptime\n");
        fclose(fp);
        return 1;
    }

    fclose(fp);

    printf("System uptime: %.2f seconds\n", uptime_seconds);

    return 0;
}
