/*-----------------------------------------------------------------
 * File:    Floyds_Sequential.c
 * 
 * Purpose: Floyd-Warshall Algorithm in C 
 *
 * Compile: gcc -g -w -fopenmp -o floydc Floyds_Sequential.c 
 *   
 * Run:     ./floydc
 *
 * Input:   Default Inputs from Question 
 * Output:  Shortest distance matrix 
 ------------------------------------------------------------------*/
#include <stdio.h>
#include <limits.h>
// defining the number of vertices
#define nV 6 //10
#define INF INT_MAX  

void printMatrix(int matrix[][nV]);

// Implementing floyd warshall algorithm
void floydWarshall(int graph[][nV]) {
  unsigned int matrix[nV][nV], i, j, k;

  for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
      matrix[i][j] = graph[i][j];

  // Adding vertices individually
  for (k = 0; k < nV; k++) {
    for (i = 0; i < nV; i++) {
      for (j = 0; j < nV; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix);
}

void printMatrix(int matrix[][nV]) {
  for (int i = 0; i < nV; i++) {
    for (int j = 0; j < nV; j++) {
      if (matrix[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  
  int graph[nV][nV] = {{0, 2, 5, INF, INF, INF},
                       {INF, 0, 7, 1, INF, 8},
                       {INF, INF, 0, 4, INF, INF},
                       {INF, INF, INF, 0, 3, INF},
                       {INF, INF, 2, INF, 0, 3},
                       {INF, 5, INF, 2, 4, 0}}; 
  /*                     
  int graph[nV][nV] = {{0, INF, INF, 14, INF, INF, INF, INF, 3, 11},
                       {INF, 0, 1, 13, INF, 9, INF, 3, 3, 8},
                       {INF, 3, 0, INF, INF, INF, INF, 3, 14, 20},
                       {INF, INF, INF, 0, INF, 7, INF, INF, INF, INF},
                       {INF, INF, INF, INF, 0, INF, 17, 7, 14, INF},
                       {16, INF, INF, 8, INF, 0, INF, INF, INF, 17},
                       {INF, INF, INF, 12, INF, INF, 0, INF, INF, INF},
                       {7, INF, INF, INF, INF, INF, INF, 0, INF, 18},
                       {18, INF, INF, INF, 1, INF, INF, INF, 0, INF},
                       {1, 12, 18, INF, INF, INF, 8, INF, INF, 0}}; */                  
  floydWarshall(graph);
}