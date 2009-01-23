#include "Matrix.h"

Matrix::Matrix(const Matrix& mat){
	for(int x = 0; x < 4; x++){
		for(int y = 0; y < 4; y++){
			values[x][y] = mat.values[x][y];
		}
	}
}

Matrix Matrix::operator *(const Matrix& rhs){
	Matrix result;

	for(int x = 0; x < 4; x++){
		for(int y = 0; y < 4; y++){
			result.values[x][y] = 0.0f;

			for(int z = 0; z < 4; z++){
				result.values[x][y] += ( values[z][y] * rhs.values[x][z] );
			}
		}
	}
	return result;
}

void Matrix::Identify(){
	for(int x = 0; x < 4; x++){
		for(int y = 0; y < 4; y++){
			values[x][y] = x == y ? 1.0f : 0.0f;
		}
	}
}