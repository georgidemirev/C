/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Georgi Demirev
* @idnumber 62296
* @task 2
* @compiler VC
*
*/
#include "stdafx.h"
#include <iostream>
using namespace std;
double inverse_matrix(double *mat, int n, int m)
{
	double determinant = 0;
	double matInverse[3][3];
	for (int i = 0; i < 3; i++)
		determinant = determinant + (mat[i] * (mat[3 + (i + 1) % 3] * mat[6 + (i + 2) % 3] - mat[3 + (i + 2) % 3] * mat[6 + (i + 1) % 3]));

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matInverse[i][j] = ((mat[((j + 1) % 3) * 3 + (i + 1) % 3] * mat[((j + 2) % 3) * 3 + (i + 2) % 3]) - (mat[((j + 1) % 3) * 3 + (i + 2) % 3] * mat[((j + 2) % 3) * 3 + (i + 1) % 3])) / determinant;
		}
	}
	return matInverse[n][m];
}
double multiplication(double *a, double *b, int i, int j)
{
	double mat[3][3];
	mat[i][j] = a[i * 3] * b[j] + a[i * 3 + 1] * b[j + 3] + a[i * 3 + 2] * b[j + 6];
	return mat[i][j];
}
double transpositioning(double *mat, int n, int m)
{
	double p[3][3];
	p[n][m] = mat[m * 3 + n];
	return p[n][m];
}
void manipulation(double a[3][3], double c[3][3],double x[3][3])
{
	double q[3][3]; // q=(A + 5E)
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			q[i][j] = a[i][j];
		}
	}
	q[0][0] += 5;			//here i add (5E) to (A) 						
	q[1][1] += 5;
	q[2][2] += 5;
	double p[3][3];// p = inverse (A+5E)
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			p[i][j] = inverse_matrix(*q, i, j);
		}
	}
	double transpositioned_A[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			transpositioned_A[i][j] = transpositioning(*a, i, j);
		}
	}
	double multiplicated_3AC[3][3]; // (-3AtC)
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			multiplicated_3AC[i][j] = (-3)*multiplication(*transpositioned_A, *c, i, j);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			x[i][j] = multiplication(*multiplicated_3AC, *p, i, j);
		}
	}
}
int main()
{
	double a[3][3] = { -4., 1., 1.,
						1., -3., 2.,
						1., 2., -4 };
	double c[3][3] = {  -1., -2., -2.,
						-1., -3., -4.,              
						-1., -3., -5 }; // Here i do not make a case in which the customer enters wrong
										// input becouse the matrixes are hardcoded.
	double x[3][3]; // ANSWER
	manipulation(a, c, x);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}