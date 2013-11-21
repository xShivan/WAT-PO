#include <iostream>
#include <stdlib.h>

using namespace std;

class Number
{
public:
	int value;
	Number(int val);
	void Display();
	int operator* (const Number operand);
	int operator% (const Number operand);
};

Number::Number(int val)
{
	value = val;
}

void Number::Display()
{
	cout << value << endl;
}

int Number::operator*(const Number oper2)
{
	Number oper1 = *this;
	int result = 0;
	for (int i = 1; i <= oper1.value; i++) result = result + oper2.value;
	return result;
}

int Number::operator%(const Number oper2)
{
	Number oper1 = *this;
	int a, b;
	a = oper1.value;
	b = oper2.value;
	while (a >= b) a = a - b;
	return a;
}

int main()
{
	int val1, val2;
	cout << "Podaj liczbe 1: ";
	cin >> val1;
	cout << "Podaj liczbe 2: ";
	cin >> val2;
	
	Number n1(val1);
	Number n2(val2);
	
	cout << "Mnozenie: " << n1 * n2 << endl;
	cout << "Modulo: " << n1 % n2 << endl;
	
	fflush(stdin);
	getchar();
	return 0;
}
