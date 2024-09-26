#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    float ans[200], input[400][198]; //initialize
    int i, j, k;
    freopen("data.txt", "r", stdin);    //open the file and read it
    memset(ans, 0, sizeof(ans));

    for (i = 0; i < 400; i++)           //store in the array input
        for (j = 0; j < 198; j++)
            scanf("%f", &input[i][j]);

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);  // Record the start time 
    //calculation
    for (k = 0; k < 200; k++)
        for (i = 200; i < 400; i++)
            for (j = 0; j < 198; j++)
                ans[k] = ans[k] + input[k][j] * input[i][j];

    clock_gettime(CLOCK_MONOTONIC, &end);  // Record the end time

    // Calculate the elapsed time in seconds
    float elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Elapsed time: %f seconds\n", elapsed_time);
	freopen("output.txt", "w", stdout);
    for (i = 0; i < 200; i++)
        printf("%f\n", ans[i]);

    return 0;
}

