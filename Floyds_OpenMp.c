/*-----------------------------------------------------------------
 * File:    Floyds_OpenMp.c
 * 
 * Purpose: Floyd-Warshall Algorithm in C using OpenMP
 *
 * Compile: gcc -g -w -fopenmp -o floydom Floyds_OpenMp.c 
 *   
 * Run:     ./floydom
 *
 * Input:   Vertices, Number of threads (default 8)  
 * Output:  Overall time period for threads,  
 			Performance Analysis Parameters: Speed_up, Efficiency, 
 			Serial_Fraction
 ------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <limits.h>
#define INF INT_MAX  
#define N 1200

#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

//Initialize All Parameters
int distance_matrix[N][N] = {0};
float Sequential_Time = 0; 
float Parallel_Time = 0; 
float Efficiency = 0; 
float Speed_up = 0;
float Serial_Fraction = 0; 
int threads = 8;

int main(int argc, char *argv[])
{
	//Generate Matrix with random data 
	printf("Number of Vertices: %d and Threads: %d \n", N, threads);
	auto num_of_threads; 
	auto source, destination, middle; 
	for (source = 0; source < N; source++)
	{
		for(destination = 0; destination < N; destination++)
		{
			if(source != destination)
			{
				distance_matrix[source][destination] = rand()%20;
				if (distance_matrix[source][destination] == 0)
				{
					distance_matrix[source][destination] = INF;
				}
			}
		}
	}

//Floyds Loop Begin
for(num_of_threads=1; num_of_threads<=threads; num_of_threads++)
{
	omp_set_num_threads(num_of_threads);
	double start_time = omp_get_wtime(); 

	#pragma omp parallel shared(distance_matrix)
	for(middle = 0; middle < N; middle++)
	{
		int *dm = distance_matrix[middle];
		#pragma omp parallel for private (source, destination) schedule(dynamic)
		for(source = 0; source < N; source++)
		{
			int *ds = distance_matrix[source]; 
			for(destination = 0; destination < N; destination++)
			{
				ds[destination] = min(ds[destination], ds[middle]+dm[destination]);

			}
		}
	}
	//Time Calculation
	double time = omp_get_wtime() - start_time; 
	printf("Total time for thread %d (in sec):%.2f\n", num_of_threads, time);
	if (num_of_threads == 1)
	{
		Sequential_Time = time;
	}
	//Performance Parameters 
	Parallel_Time = time; 
	Speed_up = Sequential_Time/Parallel_Time; 
	Efficiency = (1 / (1 + (Parallel_Time/Sequential_Time)));
	Serial_Fraction = (((1/Speed_up) - (1/num_of_threads)) / 1 - (1/num_of_threads)); 
	printf(" Number of Thread: %d Speedup: %.2f Efficiency: %.2f Serial_Fraction: %.2f\n", num_of_threads, Speed_up, Efficiency, Serial_Fraction);

}
return 0; 

}