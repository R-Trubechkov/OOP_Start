//2. ќпределить класс Children, который содержит такие пол€(члены класса) :
//закрытые Ц им€ ребенка, фамилию и возраст, публичные Ц методы ввода данных и отображени€ их на экран.
//ќбъ€вить два объекта класса, внести данные и показать их.
#include "pch.h"

#include <iostream>
#include <string>
using namespace std;
class Children {
private:
	string name, surname;
	int ages;
public:
	void Set_informationAboutChild()
	{
		cout << "Enter the name:"  << endl;
		cin >> name;

		cout << "Enter the surname:" << endl;
		cin >> surname;

		cout << "Enter ages:" <<  endl;
		cin >> ages;

	}
	void Get_informationAboutChild()
	{
		cout << "Name:" << name << endl;
		cout << "Surname:" << surname << endl;
		cout << "Ages:" << ages << endl;

	}
};
int main()
{
	Children Roma,Mark;
	Roma.Set_informationAboutChild();

	Mark.Set_informationAboutChild();

	Roma.Get_informationAboutChild();

	Mark.Get_informationAboutChild();
	return 0;

}