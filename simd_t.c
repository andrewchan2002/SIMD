#include<stdio.h>
#include<xmmintrin.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main()
{
	float input[400][200]__attribute__((aligned(16))) ={0}; //array align
	float ans[200]__attribute__((aligned(16)))={0};    //final ans
	__m128 *a,*b;  // for counting array
	int i,j,k; 
	freopen("data.txt","r",stdin);	  //read the data
	for (i = 0;i < 400;i++)
		for (j = 0;j < 198;j++)
			scanf("%f",&input[i][j]);

	float temp[4]__attribute__((aligned(16)));
	__m128* temp2 = (__m128*)temp;
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);  // Record the start time
	for(i=0;i<200;i++){
		temp[0] = 0;
		temp[1] = 0;
		temp[2] = 0;
		temp[3] = 0;
		for (j = 0;j < 200;j++)
		{
			a = (__m128*)input[i];
			b = (__m128*)input[j+200];
			for (k = 0;k < 50;k++)			// 200/4=50
			{
				*temp2 = _mm_add_ps(*temp2,_mm_mul_ps(a[k],b[k]));  //simd instruction calculation
				//printf("%f %f %f %f\n",temp[0],temp[1],temp[2],temp[3]);
			}
			//printf("%f %f %f %f\n",temp[0],temp[1],temp[2],temp[3]);
		}
		ans[i] = (temp[0] + temp[1] + temp[2] + temp[3]); //for sum of the each temp is the answer of convolution 
			
    }
	clock_gettime(CLOCK_MONOTONIC, &end);  // Record the end time
    // Calculate the elapsed time in seconds
    float elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Elapsed time: %f seconds\n", elapsed_time);
    freopen("output_simd.txt","w",stdout);
	for(i = 0;i < 200;i++)
		printf("%f\n",ans[i]);
	return 0;
}
