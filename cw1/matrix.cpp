#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Matrix
{
private:
	int** arr;
	int dimX;
	int dimY;
public:
	//Podstawowe
	Matrix(int x, int y);
	~Matrix();

	//Macierzowe
	void ShowMatrix();
	void WriteToPosition(int x, int y);
	void Fill();

	//Macierzowe - statyczne
	static Matrix* AddMatrix(Matrix *a, Matrix* b)
	{
		if (a->dimX != b->dimX || a->dimY != b->dimY)
		{
			cout << "Wymiary macierzy sa niezgodne! Nie mozna ich dodac!" << endl;
			return NULL;
		}
		Matrix* result = new Matrix(a->dimX, a->dimY);

		for (int i = 0; i < result->dimX; i++)
		{
			for (int j = 0; j < result->dimY; j++)
			{
				result->arr[i][j] = a->arr[i][j] + b->arr[i][j];
			}
		}
		return result;
	}
	static Matrix* MultiplyMatrix(Matrix* a, Matrix* b)
	{
		if (a->dimY != b->dimX)
		{
			cout << "Wymiary macierzy sa niezgodne! Nie mozna ich pomnozyc!" << endl;
			return NULL;
		}
		Matrix* result = new Matrix(a->dimX, b->dimY);
		for (int i = 0; i < a->dimX; i++)
		{
			for (int j = 0; j < b->dimY; j++)
			{
				int sum = 0;
				for (int k = 0; k < a->dimY; k++)
				{
					sum = sum + (a->arr[i][k] * b->arr[k][j]);
				}
				result->arr[i][j] = sum;
			}
		}
		return result;
	}
};

Matrix::Matrix(int x, int y)
{
	dimX = x;
	dimY = y;

	//Tworzenie
	arr = (int**)malloc(dimX * sizeof(int*));
	for (int i = 0; i < dimX; i++) arr[i] = (int*)malloc(dimY * sizeof(int));

	//Wype³nianie
	for (int i = 0; i < dimX; i++)
	{
		for (int j = 0; j < dimY; j++)
		{
			arr[i][j] = 0;
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < dimX; i++) free(arr[i]);
	free(arr);
}

void Matrix::Fill()
{
	for (int i = 0; i < dimX; i++)
	{
		for (int j = 0; j < dimY; j++)
		{
			WriteToPosition(i, j);
		}
	}
}

void Matrix::WriteToPosition(int x, int y)
{
	//cout << "Podaj wartosc na pozycji " << x + 1 << "x" << y + 1 << ": ";
	//cin >> arr[x][y];
	arr[x][y] = rand() % 10;
	
}

void Matrix::ShowMatrix()
{
	for (int i = 0; i < dimX; i++)
	{
		for (int j = 0; j < dimY; j++) cout << arr[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	srand(time(0));
	int m, n;

	//Pobieranie danych
	cout << "Podaj liczbe wierszy macierzy 1: ";
	cin >> m;
	cout << "Podaj liczbe kolumn macierzy 1: ";
	cin >> n;

	cout << "Macierz A: " << endl;
	Matrix* a = new Matrix(m, n);
	a->Fill();
	a->ShowMatrix();
	cout << endl;

	cout << "Podaj liczbe wierszy macierzy 2: ";
	cin >> m;
	cout << "Podaj liczbe kolumn macierzy 2: ";
	cin >> n;

	cout << "Macierz B: " << endl;
	Matrix* b = new Matrix(m, n);
	b->Fill();
	b->ShowMatrix();
	cout << endl;

	cout << "Wynik dodawania A + B: " << endl;
	Matrix* c = Matrix::AddMatrix(a, b);
	if (c != NULL)
	{
		c->ShowMatrix();
		delete(c);
	}

	cout << "Wynik mnozenia A * B: " << endl;
	Matrix* d = Matrix::MultiplyMatrix(a, b);
	if (d != NULL)
	{
		d->ShowMatrix();
		delete(d);
	}

	delete(a);
	delete(b);
	fflush(stdin);
	getchar();
	return 0;
}
