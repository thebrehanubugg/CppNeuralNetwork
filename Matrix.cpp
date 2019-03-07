/* Matrix C++ Library written in C++
   Created by Brehanu Bugg
   A mini-learning project
*/

/* Importing the string, printing, and vector libraries */
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

/* So we don't have to do std::print or std::string every time */
using namespace std;


/* Initializing a Matrix class */
class Matrix {

	/* Our public variables (items that anything can access */
	public:
		int rows, cols;
		string size;

		void init(int rows_, int cols_);
		void print();

		Matrix add(Matrix b);
		Matrix subtract(Matrix b);

		void sub(float n);
		void scale(float n);

		Matrix dot(Matrix b);

		vector<vector<float>> data;

		/* Constructor method call */
		Matrix();
};

/* Constructor method: required, but doesn't have to do anything */
Matrix::Matrix(void) {
	int m = 0;
};

/* Initialization method: populate the data with numbers between 0-100 */
void Matrix::init(int rows_, int cols_) {
	rows = rows_;
	cols = cols_;
	
	for(int i = 0; i < rows; i++) {
		vector<float> row;

		for(int j = 0; j < cols; j++) {
			row.push_back(rand() % 100 + 1);			
		}

		data.push_back(row);
	}
};

/* Print out the Matrix's data row by row */
void Matrix::print() {
	for(int i = 0; i < data.size(); i++) {
		for(int j = 0; j < data[i].size(); j++) {
			cout << data[i][j] << " ";
		}

		cout << "\n";
	}
};

/* Adding two Matricies of the same size */
Matrix Matrix::add(Matrix b) {
	Matrix result;
	result.init(rows, cols);

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			float sum = data[i][j] + b.data[i][j];
			result.data[i][j] = sum;
		}
	}

	return result;
};

/* Subtracting two Matricies of the same size */
Matrix Matrix::subtract(Matrix b) {
	Matrix result;
	result.init(rows, cols);

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			float difference  = data[i][j] - b.data[i][j];
			result.data[i][j] = difference;
		}
	}

	return result;
};

/* Subtract a scalar from each number in the Matrix */
void Matrix::sub(float n) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			data[i][j] -= n;
		}
	}
};

/* Multiply a scalar to each number in the Matrix */
void Matrix::scale(float n) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			data[i][j] *= n;
		}
	}
};

/* Dot Product of two Matricies */
Matrix Matrix::dot(Matrix b) {
	Matrix result;
	result.init(rows, b.cols);

	if(rows != b.cols && cols != b.rows) {
		throw invalid_argument("Rows of matrix A must equal the colums of matrix B");
	}

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			float sum = 0;

			for(int k = 0; k < cols; k++) {
				sum += data[i][k] * b.data[k][j];
			}
			
			result.data[i][j] = sum;
		}
	}

	return result;
}

/* The required 'int main()' function */
int main() {
	Matrix a;
	a.init(3, 4);
	a.print();

	cout << "\n";

	Matrix b;
	b.init(4, 3);
	b.print();

	cout << "\n";
	Matrix c;

	try {
		c = a.dot(b);
		c.print();
	} catch(const invalid_argument e) {
		throw;
	}
	
	return 0;
};
