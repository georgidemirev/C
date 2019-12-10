#pragma once

template<class T>
class Matrix {

	T** mat = nullptr;
	int row; int col;

public:

	Matrix(int x,int y) {
		mat = new T*[x];
		for (int i = 0; i < x; i++) {
			mat[i] = new T[y];
		}
		for (int t = 0; t < x; t++) {
			for (int i = 0; i < y; i++) {
				mat[t][i] = T();
			}
		}
		row = x;
		col = y;
	};





};