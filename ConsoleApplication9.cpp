// ConsoleApplication9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstring>
using namespace std;

class STRING
{
public:
	STRING(const char* s) {
		strcpy_s(data, s);
	}
	STRING(string s) {
		strcpy_s(data, s.c_str());
	}
	STRING();
	~STRING();
	STRING& operator=(const STRING& right)
	{
		delete[] data;
		strcpy_s(data, right.data);
		return *this;
	}

	void Print() {
		cout « string(data);
	}

	friend STRING& operator+=(STRING& left, const STRING& right);
	friend bool operator==(const STRING& left, const STRING& right);
	friend bool operator!= (const STRING& c1, const STRING& c2);
	friend bool operator> (const STRING& d1, const STRING& d2);
	friend bool operator<= (const STRING& d1, const STRING& d2);
	friend bool operator< (const STRING& d1, const STRING& d2);
	friend bool operator>= (const STRING& d1, const STRING& d2);
private:
	char data[256];
};


STRING& operator+=(STRING& left, const STRING& right)
{
	strcat_s(left.data, right.data);
	return left;
}

bool operator==(const STRING& left, const STRING& right)
{
	return left.data == right.data;
}

bool operator!= (const STRING& c1, const STRING& c2)
{
	return !(c1.data == c2.data);
}

bool operator> (const STRING& d1, const STRING& d2)
{
	return d1.data > d2.data;
}

bool operator>= (const STRING& d1, const STRING& d2)
{
	return d1.data >= d2.data;
}

bool operator< (const STRING& d1, const STRING& d2)
{
	return d1.data < d2.data;
}

bool operator<= (const STRING& d1, const STRING& d2)
{
	return d1.data <= d2.data;
}

STRING::STRING()
{
}

STRING::~STRING()
{
}


int main()
{
	cout « "Enter first string" « endl;
	string s1;
	cin » s1;

	STRING c1(s1);
	cout « "\n" « endl;

	cout « "Enter second string" « endl;
	string s2;
	cin » s2;

	STRING c2(s2);
	cout « "\n" « endl;

	if (c1 > c2)
	{
		cout « "c1 > c2" « endl;
	}
	else if (c1 < c2)
	{
		cout « "c1 < c2" « endl;
	}
	else if (c1 == c2)
	{
		cout « "c1 == c2" « endl;
	}
	else
	{
		cout « "mein programm keine arbeiten" « endl;
	}

	if (c1 != c2)
	{
		cout « "c1!=c2" « endl;
	}

	c1 += c2;
	c1.Print();
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
