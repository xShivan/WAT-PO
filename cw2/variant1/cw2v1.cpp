#include <iostream>
#include <stdlib.h>

using namespace std;

int StrLen(char* input)
{
	int i = 0;
	while (input[i] != '\0') i++;
	return i + 1;
}

class String
{
private:
	int length;
public:
	char* contents;

	String(char *input);
	~String();
	String operator+ (const String operand);
	bool operator== (const String operand);
	void Display();
};

String::String(char* input)
{
	int len = StrLen(input);
	contents = input;
	length = len;
}

String::~String()
{
	//free(contents);
}

String String::operator+ (const String operand2)
{
	String operand1 = *this;
	int length = operand1.length + operand2.length + 1;
	char* concat = (char*)malloc(length * sizeof(char));
	int j = 0;
	int i = 0;
	while (operand1.contents[i] != '\0')
	{
		concat[j] = operand1.contents[i];
		i++;
		j++;
	}
	i = 0;
	while (operand2.contents[i] != '\0')
	{
		concat[j] = operand2.contents[i];
		i++;
		j++;
	}
	concat[j] = '\0';
	String result(concat);
	return result;
}

bool String::operator==(String operand2)
{
	String operand1 = *this;
	int i = 0;
	bool err = false;
	while (operand1.contents[i] != '\0' && operand2.contents[i] != '\0' && !err)
	{
		i++;
		if (operand1.contents[i] != operand2.contents[i]) err = true;
	}
	return !err;
}

void String::Display()
{
	cout << contents << endl;
}

int main()
{
	cout << "Demo: przeci��anie operator�w" << endl;
	char* input1 = "Ala ma";
	char* input2 = " kota";
	char* input3 = " kota";
	//Alokacja danych do dema

	String str1(input1);
	String str2(input2);
	String str3(input3);

	cout << "Dane wejsciowe 1: ";
	str1.Display();
	cout << "Dane wejsciowe 2: ";
	str2.Display();

	//Demo konktatenacji

	String result = str1 + str2;
	cout << "Wynik konkatenacji: ";
	result.Display();
	
	//Demo por�wnania
	if (str1 == str2)
	{
		cout << "�a�cuchy s� r�wne" << endl;
	}
	else
	{
		cout << "�a�cuchy nie s� r�wne" << endl;
	}
	if (str2 == str3)
	{
		cout << "�a�cuchy s� r�wne" << endl;
	}
	else
	{
		cout << "�a�cuchy nie s� r�wne" << endl;
	}

	fflush(stdin);
	getchar();
	return 0;
}
