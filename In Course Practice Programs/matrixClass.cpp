/*Program to implement the all operations on matrices using OOP concepts*/
#include <iostream>
#include <cstdio>
using namespace std;

class matrix
{
private:
	int row;
	int column;
	double **mat;
public:
	matrix() {}												// default constructor
    matrix(int, int); 										// parameterized constructor
	matrix(const matrix&);									// copy constructor
	~matrix();              								// destructor
	friend matrix operator+(const matrix&, const matrix&);	// operator function to overload '+' for addition of two matrices
	friend matrix operator-(const matrix&, const matrix&);	// operator function to overload '-' for subtraction of two matrices
	friend matrix operator*(const matrix&, const matrix&);	// operator function to overload '*' for multiplication of two matrices or multiplying a constant with a matrix
	matrix operator/(const matrix&);						// operator function to overload '/' for dividing a constant with a matrix
	friend istream& operator>>(istream&, const matrix&);	// function to overload '>>' for input of a matrix from a user
	friend ostream& operator<<(ostream&, const matrix&);	// function to overload '<<' for displaying a matrix on the console
    matrix operator=(const matrix&);
};

matrix::matrix(int r, int c) : row(r), column(c), mat(new double*[row]{nullptr})
{
	for(int i = 0; i < row; i++)
		mat[i] = new double[column];
	// initializing every element with 0
	    for(int i = 0; i < row; i++)
	    {
	        for(int j = 0; j < column; j++)
	        {
	            mat[i][j] = 0.0;
	        }
	    }
}

matrix::matrix(const matrix &m1)
{
	row = m1.row;
	column = m1.column;
	mat = new double*[row];

	for(int i = 0; i < row; i++)
		mat[i] = new double[column]{0.0};

	for(int i = 0; i < row; i++)
		for(int j = 0; j < column; j++)
			mat[i][j] = m1.mat[i][j];
}

matrix::~matrix()
{
    for(int i = 0; i < row; i++)
        delete [] mat[i];
}

matrix matrix::operator=(const matrix& m1)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            mat[i][j] = m1.mat[i][j];
        }
    }
    return *this;
}

istream& operator>>(istream &ist, const matrix &ma)
{
	for(int i = 0; i < ma.row; i++)
		for(int j = 0; j < ma.column; j++)
			ist >> ma.mat[i][j];
	return ist;
}

ostream& operator<<(ostream &os, const matrix &ma)
{
	for(int i = 0; i < ma.row; i++)
	{
		for(int j = 0; j < ma.column; j++)
			printf("%5.2f  ", ma.mat[i][j]);
		os << endl;
	}
	return os;
}

matrix operator+(const matrix &m1, const matrix &m2)
{
	matrix sum(m1.row, m1.column);
    for(int i = 0; i < m1.row; i++)
    {
        for(int j = 0; j < m1.column; j++)
        {
            sum.mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
        }
    }
    return sum;
}

matrix operator-(const matrix &m1, const matrix &m2)
{
	matrix diff(m1.row, m1.column);
	for(int i = 0; i < m1.row; i++)
	{
		for(int j = 0; j < m1.column; j++)
		{
			diff.mat[i][j] = m1.mat[i][j] - m2.mat[i][j];
		}
	}
	return diff;
}

matrix operator*(const matrix &m1, const matrix &m2)
{
	matrix mult(m1.row, m2.column);
	cout << mult;
	int i, j, k;
	for(i = 0; i < m1.row; i++)
	{
        for(j = 0; i < m2.column; j++)
        {
            mult.mat[i][j] = 0.0;
            for(k = 0; k < m1.column; k++)
            {
                mult.mat[i][j] = mult.mat[i][j] + (m1.mat[i][k] * m2.mat[k][j]);
            }
        }
	}
	cout << mult;
    return mult;
}

int main()
{
    matrix ma1(2, 2), ma2(2, 2), ma4(2, 2);
    cin >> ma1;
    cin >> ma2;

    cout << ma1 << ma2;

    ma4 = ma1 - ma2;

    cout << ma4;

    return 0;
}
