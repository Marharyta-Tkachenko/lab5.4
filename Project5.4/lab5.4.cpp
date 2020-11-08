// Лабораторна робота № 5.4

#include <iostream>
#include <cmath>

using namespace std;

double P0(const int j)
{
	double P = 1;
	for (int j = 1; j <= 15; j++)
		P *= sqrt(j * j / (1.0 + exp(-j)));
	return P;
}

double P1(const int j)
{
	if (j > 15)
		return 0;
	else
		return sqrt(j * j / (1.0 + exp(-j))) + P1(j + 1);
}

double P2(const int j)
{
	if (j < 1)
		return 0;
	else
		return sqrt(j * j / (1.0 + exp(-j))) + P1(j - 1);
}

double P3(const int j, double t)
{
	t = t + sqrt(j * j / (1.0 + exp(-j)));
	if (j >= 15)
		return t;
	else
		return P3(j + 1, t);
}

double P4(const int j, double t)
{
	t = t + sqrt(j * j / (1.0 + exp(-j)));
	if (j <= 1)
		return t;
	else
		return P4(j - 1, t);
}

int main()
{
	int j;
	cout << "j = "; cin >> j;

	cout << "(iter) P0 = " << P0(j) << endl;
	cout << "(rec up ++) P1 = " << P1(j) << endl;
	cout << "(rec up --) P2 = " << P2(j) << endl;
	cout << "(rec down ++) P3 = " << P3(j, 0) << endl;
	cout << "(rec down --) P4 = " << P4(j, 0) << endl;

	return 0;
}