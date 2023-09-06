#include <iostream>
#include <cmath>
using namespace std;
const double eps = 0.002;
double y(double x) { return 2 * exp(x) * exp(x); }

double CMV(double x, double y1, double eps, int& iter)
{
	int i = 0;

	double s = 0, a = -(2 * x) * (2 * x) / 2;

	while (abs(s - y1) > eps)
	{
		s += a;
		a *= -(4 * x * x) / (2 * i + 1) / (2 * i + 2);
		i++;
	}
	iter = i;
	return s;
}
double CMV2(double x, double eps, int& iter)
{
	int i = 0;
	double s = 0, a = -(2 * x) * (2 * x) / 2;
	while (abs((-(4 * x * x) / (2 * i + 1) / (2 * i + 2) * a) - (a)) > eps)
	{
		s += a;
		a *= -(4 * x * x) / (2 * i + 1) / (2 * i + 2);
		i++;

	}
	iter = i;
	return s;
}

double CMV3(double x, double eps, int& iter)
{
	int i = 0;
	double s = 0, a = -(2 * x) * (2 * x) / 2;
	while (abs(a) > eps)
	{
		s += a;
		a *= -(4 * x * x) / (2 * i + 1) / (2 * i + 2);
		i++;

	}
	iter = i;
	return s;
}

void main()
{
	double x;
	cout << "\nx==\t";
	cin >> x;
	int iter = 0;
	cout << CMV2(x, eps, iter) << "\t" << iter << "\n" << "\t" << CMV3(x, eps, iter) << "\t" << iter << "\n";
	system("Pause");
}