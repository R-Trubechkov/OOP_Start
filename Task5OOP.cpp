#include "pch.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
class Sight;
class InformationaboutUser
{
private:
	string userfile,user_ID;
	time_t ts;
	int latitude, longitude;
public:
	InformationaboutUser()
	{
		time(&ts);
	}
	friend void inputDatafromLogFile(InformationaboutUser*,int);
	void SaveInfoinUserFile();
	friend  void defineLocation(Sight&, InformationaboutUser&);
};
void inputDatafromLogFile(InformationaboutUser* infoarr ,int numberofusers)
{
	
	fstream fs;
	string logfile = "LogFile.txt";
	fs.open(logfile, fstream::in |fstream::out | fstream::app);
	if (!fs.is_open())
		cout << "Taking data failed" << endl;
	else
	{
		while (fs.eof());
		{
			for (int i = 0; i < numberofusers; i++)
			{
				fs >> infoarr[i].user_ID;
				fs >> infoarr[i].latitude;
				fs >> infoarr[i].longitude;
			}
		}
		
	}
	fs.close();
	
}
void InformationaboutUser::SaveInfoinUserFile()
{
	
	userfile = user_ID + ".txt";
	ofstream f(userfile);
	fstream fs;
	fs.open(userfile, fstream::out | fstream::app);
	if (!fs.is_open())
		cout << "Taking data failed" << endl;
	else
	{
		fs << "User: " << user_ID << '\n';
		fs << "current time: " << ts << '\n';
		fs << "current coordinates: " << '(' << latitude << ',' << longitude << ')' << '\n';
	}
	fs.close();
}
class Sight
{
private:
	/*class Dot {
	private:

	public:
		Dot()
		{
			latitude = rand() % 240 + 60;
			srand(time(NULL));
			longitude = rand() % 245 + 65;
		}

		int Get_coordinatelatitude()
		{
			return latitude;
		}
		int Get_coordinatelongitude()
		{
			return longitude;
		}

		int Set_coordinatelatitude(int x)
		{
			latitude = x;
		}
		int Set_coordinatelongitude(int y)
		{
			longitude = y;
		}

	};*/
	int latitudeA, longitudeA, latitudeB, longitudeB;
	string nameOfthePlace;
public:

	friend void inputDatafromSightFile(Sight*, int);
	friend  void defineLocation(Sight&, InformationaboutUser&);

};
void inputDatafromSightFile(Sight*sightarr, int numberofsights)
{
	fstream fs;
	string logfile = "SightFileCoordinates.txt";
	fs.open(logfile, fstream::in);
	if (!fs.is_open())
		cout << "Taking data failed" << endl;
	else
	{
		while (fs.eof());
		{
			for (int i = 0; i < numberofsights; i++)
			{

				fs >> sightarr[i].latitudeA;
				fs >> sightarr[i].longitudeA;
				fs >> sightarr[i].latitudeB;
				fs >> sightarr[i].longitudeB;
			
			}
		}

	}
	fs.close();
	logfile = "SightFileNames.txt";
	fs.open(logfile, fstream::in );
	if (!fs.is_open())
		cout << "Taking data failed" << endl;
	else
	{
		while (fs.eof());
		{
			for (int i = 0; i < numberofsights; i++)
			{
				getline(fs, sightarr[i].nameOfthePlace);
				
			}
		}

	}
	fs.close();

}
void defineLocation(Sight &sight, InformationaboutUser &info)
{
	int xleft = sight.latitudeA;
	int xright = sight.latitudeB;
	int ytop = sight.longitudeA;
	int ybot = sight.longitudeB;
	int x = info.latitude;
	int y = info.longitude;
	if ((x > xleft) && (x < xright) && (y > ybot) && (y < ytop))
	{
		fstream fs;
		fs.open(info.userfile, fstream::out | fstream::app);
		if (!fs.is_open())
			cout << "Taking data failed" << endl;
		else
		{
			fs << "Sight: " << sight.nameOfthePlace <<"\n";
		}
		fs.close();

	}
}
void initializationofUserFile(InformationaboutUser*, Sight*, int, int);
int main()
{
	int numberofsights = 6;
	int numberofusers = 3;
	Sight* sightarr = new Sight[numberofsights];
	InformationaboutUser* userarr = new InformationaboutUser[numberofusers];
	inputDatafromSightFile(sightarr, numberofsights);
	inputDatafromLogFile(userarr, numberofusers);
	initializationofUserFile(userarr, sightarr, numberofsights, numberofusers);
	delete[]sightarr;
	delete[]userarr;
	return 0;
}
void initializationofUserFile(InformationaboutUser*userarr, Sight* sightarr, int numberofsights, int numberofusers)
{
	for (int i = 0; i < numberofusers; i++)
		userarr[i].SaveInfoinUserFile();
	for (int i = 0; i < numberofusers; i++)
		for (int j = 0; j < numberofsights; j++)
			defineLocation(sightarr[j], userarr[i]);
}

