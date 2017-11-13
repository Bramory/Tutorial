#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

class matrix
{
public:
	matrix();
	matrix(size_t row, size_t col);
	matrix(const matrix& obj);
	virtual ~matrix();

	size_t getRow(void) const;
	size_t getCol(void) const;
	float det(void) const;

	void setCol(size_t);
	void setRow(size_t);
	void read(void);
	void print(void)const;
	matrix auto_fill(void)const;
	matrix transp(void)const;
	matrix adjoint(void)const;
	matrix inverse(void)const;
	matrix inverseGauss(void)const;

	matrix operator *(matrix&);
	matrix operator *(float);
private:
	size_t row, col;
	float *ptr;
};

//read only int numbers
int num_scan(void);
int random_int(int min, int max);

#endif // MATRIX_H_INCLUDED
