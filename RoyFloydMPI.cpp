// RoyFloydMPI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>


int main()
{
	double INF = INFINITY;
	int mat[5][5] = { {0, 2, INF, 2, INF},
					  {2, 0, 3, INF, INF}, 
					  {INF, 3, 0, 1, 8},
					  {10, INF, 1, 0, INF},
					  {INF, INF, 8, INF, 0} };
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
}

