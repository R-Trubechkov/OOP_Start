//3. ������������� ������ ���������� ������� � ������� �����������.
//����� ����� ��������� ��� ������ : ���� �������� ������ ����������,
//������ ���������� ������ �������� ����� �� �������� ��������.
#include "pch.h"
#include <iostream>
using namespace std;
class  TransporationofMatrix{
private:
	int** matrixA,**transporatedMatrixA;
	
public:
	TransporationofMatrix(int length, int windth)
	{
		matrixA = new int*[length];
		int i, j;
		for (i = 0; i < length; i++)
			matrixA[i] = new int[windth];
		cout << "Enter all elements:" << endl;
		for (i = 0; i < length; i++)
			for (j = 0; j < windth; j++)
				cin >> matrixA[i][j];
		cout << endl;
		
	}
	void transporation(int, int);
    void popMatrix(int,int);
	void Get_matrix(int, int);
	
};
bool isRectangle(int length, int windth) {
	if (length == windth)
		return 1;
	else
		return 0;
}

void TransporationofMatrix::transporation(int length, int windth)
{
	int i, j;
		transporatedMatrixA = new int*[length];
		for (i = 0; i < length; i++)
			transporatedMatrixA[i] = new int[windth];
		for (i = 0; i < length; i++)
			for (j = 0; j < windth; j++)
				transporatedMatrixA[i][j] = matrixA[j][i];
}

	

void TransporationofMatrix::Get_matrix(int length, int windth)
{
	cout << "transporated matrix:" << endl;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < windth; j++) {
			cout <<" "<<transporatedMatrixA[i][j];
		}
		cout << endl;
	}
}
void TransporationofMatrix::popMatrix(int length, int windth)
{
	int i;
	for (i = 0; i < length; i++)
		delete[]matrixA[i];
	delete[]matrixA;
	matrixA = NULL;
	for (i = 0; i < windth; i++)
		delete[]transporatedMatrixA[i];
	delete[]transporatedMatrixA;


}
int main()
{
	int length, windth;
	cout << "Enter a number of strings" << endl;
	cin >> length;
	cout << "Enter a number of columns" << endl;
	cin >> windth;
	TransporationofMatrix Transporation(length, windth);
	if (isRectangle(length, windth))
	{
		Transporation.transporation(length, windth);
		Transporation.Get_matrix(windth, length);
		Transporation.popMatrix(length, windth);
	}
	else
	{
		cout << "Matrix can't be transported" << endl;
		return 1;
	}

	
	return 0;
 }