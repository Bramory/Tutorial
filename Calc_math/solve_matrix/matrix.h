#ifndef matrix_h
#define matrix_h

class matrix {
public:
	matrix();
	matrix(size_t row, size_t col);
	matrix(const matrix &obj);
	~matrix();

	float detGauss;
	matrix inverseGauss(void);
	void print(void);
	void read(void);
	matrix solveSystem(void);

private:
	size_t row, col;
	float *ptr;
};

#endif