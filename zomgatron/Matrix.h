#ifndef __MATRIX_H__
#define __MATRIX_H__

class Matrix{
public:
	Matrix() { Identify(); }
	Matrix(const Matrix& mat);

	float values[4][4];

	Matrix operator *(const Matrix& rhs);

	void Identify();
};

#endif
