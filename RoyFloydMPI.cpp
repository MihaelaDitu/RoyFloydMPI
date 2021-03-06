// RoyFloydMPI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include "mpi.h"
#include "stdio.h"
#include "stdlib.h"


int min(int a, int b) {
	return a > b ? a : b;
}

int main(int argc, char* argv[])
{
	MPI_Init(&argc, &argv);

	int rank;
	double INF = INFINITY;
	int n = 5, k, i, j;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	int a[5][5] = { {0, 2, INF, 2, INF},
					{2, 0, 3, INF, INF}, 
					{INF, 3, 0, 1, 8},
					{10, INF, 1, 0, INF},
					{INF, INF, 8, INF, 0} };
	int temp_a[5][5];

	MPI_Bcast(a, 25, MPI_INT, 0, MPI_COMM_WORLD);
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = min(a[i][j], a[i][rank] + a[rank][j]);
		}
	}

	MPI_Send(&a, 25, MPI_INT, 0, 0, MPI_COMM_WORLD);

	if (rank == 0) {
		for (k = 1; k < n; k++) {
			MPI_Recv(&temp_a, 25, MPI_INT, k, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					if (temp_a[i][j] > a[i][j]) {
						a[i][j] = temp_a[i][j];
					}

				}
			}
		}
		

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				printf("%d ", a[i][j]);
			}
		printf("\n");
	}

	MPI_Finalize;

}



