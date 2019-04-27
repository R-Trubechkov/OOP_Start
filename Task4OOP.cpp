/*4.Класс Равнобочная трапеция, члены класса : координаты 4 - х точек.
Предусмотреть в классе конструктор и методы :
проверка, является ли фигура равнобочной трапецией;
вычисления и вывода сведений о фигуре :
длины сторон, периметр, площадь.
В функции main продемонстрировать работу с классом :
дано N трапеций, найти количество трапеций, у которых площадь больше средней площади.*/
#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;
class Trapezium {
	
private:
	
	class Dot {
	private:
		int x, y;
	public:
		Dot()
		{
			cout << "Enter coordinates of dot(x,y):" << endl;
			cin >> x >> y;
		}
		int Get_coordinateX()
		{
			return x;
		}
		int Get_coordinateY()
		{
			return y;
		}
			
	};
	Dot A, B, C, D;

public:
	
	double lengthOfside(Dot, Dot);
	double perimeterCalculation();
	double squareCalculation();
	bool Is_equilateral();
	
};
double Trapezium::lengthOfside(Dot firstdot, Dot lastdot)
{
	int sumX = abs(firstdot.Get_coordinateX() - lastdot.Get_coordinateX());
	int sumY = abs(firstdot.Get_coordinateY() - lastdot.Get_coordinateY());
	double length = sqrt(pow(sumX, 2) + pow(sumY, 2));
	return length;
}
bool Trapezium::Is_equilateral()
{
	if (lengthOfside(B, C) == lengthOfside(A, D))
		return 1;
	else
	{
		cout << "Trapezium is not equilateral!!!" << endl;
		return 0;
	}
}
double Trapezium::perimeterCalculation()
{
	double P =(lengthOfside(A, B) + lengthOfside(B, C) + lengthOfside(C, D) + lengthOfside(A, D));
	return P;
}
double Trapezium::squareCalculation()
{

	double h = sqrt(pow(lengthOfside(B, C), 2)-((pow(lengthOfside(A, B),2) - pow( lengthOfside(A, D),2))/4.));
	double S = ((lengthOfside(A, B) + lengthOfside(A, D)) / 2.)*h;
	return S;
}
double averageSquare(Trapezium*trapeziumArr, int count)
{
	double averageS = 0;
	for (int i = 0; i < count; i++)
	{
		if (trapeziumArr[i].Is_equilateral())
			averageS += trapeziumArr[i].squareCalculation();
	}
	averageS = averageS / count;
	return averageS;
}
int trapeziumCounter(Trapezium*trapeziumArr, int count)
{
	int counterofBigTrapeziums=0;
	for (int i = 0; i < count; i++)
	{
		if ((trapeziumArr[i].Is_equilateral()) && (trapeziumArr[i].squareCalculation() > averageSquare(trapeziumArr, count)))
			counterofBigTrapeziums++;
	}
	return counterofBigTrapeziums;
}
int main()
{
	int count;
	
	cout << "Enter a number of figures:" << endl;
	cin >> count;
	Trapezium *trapeziumArr = new Trapezium[count]; 
	for (int i = 0; i < count; i++)
	{
		int k = i + 1;
		cout << k <<" Trapezium: " << trapeziumArr[i].squareCalculation() << endl;
	}

	cout <<"Average Square:"<< averageSquare(trapeziumArr, count) << endl;

	cout << "Number of the biggest Trapeziums:" << trapeziumCounter(trapeziumArr, count) << endl;
	delete[]trapeziumArr;
	return 0;
}


