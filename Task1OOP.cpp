
// Создать класс Tiles (кафель), который будет содержать поля с открытым доступом: brand, size_h, size_w, price и метод класса getData().
//В главной функции объявить пару объектов класса и внести данные в поля.
//Затем отобразить их, вызвав метод getData().

#include "pch.h"
#include <iostream>
#include<string>
using namespace std;
class Tiles
{
public:
	Tiles(string brand, int size_h,int size_w,int price)
	{
		
		this->brand = brand;
		this->price = price;
		this->size_h = size_h;
		this->size_w = size_w;
	
	}
	string brand;
	int size_h, size_w, price;
	void getData()
	{
		cout << "brand of tile:"<< brand<< endl;
		cout << "price of tile:" << price << endl;
		cout << "size_h of tile:" << size_h << endl;
		cout << "size_w of tile:" << size_w << endl;
	}
};


int main()
{
	Tiles laminat("lamiat", 3, 4, 5);
	laminat.getData();
	Tiles parket("prket", 50, 45, 35);
	parket.getData();
	return 0;
}
