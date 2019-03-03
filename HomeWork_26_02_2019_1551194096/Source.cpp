#include<iostream>
#include<locale.h>
#include<time.h>
#include<Windows.h>
#include<iomanip>


using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


float rain (float volume)
{
	return volume = float(100 + rand() % 200)/ (10 + rand() % 20);
	
}

float hail(float volume)
{
	return volume = float(100 + rand() % 200) / (10 + rand() % 20);

}

float snow (float volume)
{
	return volume = float(100 + rand() % 200) / (10 + rand() % 20);
}

void precipitationType(char *arrType, float *arrVolume, int day)
{
	float(*pointer[3])(float) = { rain, hail, snow };
	
	int elem = -1, buf = -1;
	
	// ���������� ���� ��� �������� ���� ������ �������, c �������� ����� ������ �� ����������� �� ���� ����

	for (int i = 0; i < day; i++)
	{
		while (elem == buf)
		{
			elem = 0 + rand() % 3;
		}
		buf = elem;

		if (elem == 0) arrType[i] = 'R';
		else if (elem == 1) arrType[i] = 'H';
		else if (elem == 2) arrType[i] = 'S';

		float volume = 0;
		arrVolume[i] = pointer[elem](volume);
	}
	
	cout << endl;

	for (int i = 0; i < day; i++)
	{
		cout << arrType[i] << "\t";
	}
	
	cout << endl;

	for (int i = 0; i < day; i++)
	{
		cout << setprecision(3) << arrVolume[i] << "\t";
	}

}

void forecastDay(int *arrDay, int day)
{
	for (int i = 0; i < day; i++)
	{
		arrDay[i] = i+1;
	}
	
	cout << endl;

	for (int i = 0; i < day; i++)
	{
		cout<<arrDay[i]<<"\t";
	}
}


void convertDecToOct(int *arr, int dec)
{
	// ���������� ����������� ������ �������, ������� �����������, ����� �������� ���������� 8-� ����� ����������
	
	int tmp = dec, size=1;

	while (tmp>=8)
	{
		tmp /= 8;
		size++;
	}

	
	arr = new int[size];
	

	// ��������� 10-� ����� � 8-� � ���������� ���������� ��� � ������

	int div, ost, oct = 0, i=0;

	for (i = size - 1; i >= 0; i--)
	{
		div = dec / 8;
		ost = dec - (div * 8);
		arr[i] = ost;
		dec = div;
	}

	
	// ����� ������� �� �����

	cout << endl << "��������� 10-� ����� � 8-�� ������� ���������� \t-> ";

	for (i = 0; i < size; i++)
	{
		cout << arr[i];
	}

	cout << "\n\n";
}


void Task1()
{
	/* 1.	�������� ��������� �������� �������. ������� ��� �������: ������ �������� � ������ ������������ �����. 
	������ �������� ��������� ��� �������, ������ ������������ ����� � ����� �������. ��� ������ ������� ��������� 
	������������ ������ ���������� �������. 
     ������������:
	��� ������� ����� �������� �� ������� (��� ����� ������� ����������� ������ � �������� �������, � ������������ 
	������� �� �������). �������, ����� ���� � ��� �� ������ �� ���������� ����� ������ ����. ���������� ������� 
	������������ ��������� �������. */

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask1\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	int *arrDay;
	char *arrType;
	float *arrVolume;

	cout << "�������� �� ������� ���� ������������ ������� ������ �� 1 �� 10 - > ";
	int day;
	cin >> day;

	arrDay = new int[day]; 
	arrType = new char[day];
	arrVolume = new float[day];

	forecastDay(arrDay, day);
	precipitationType(arrType, arrVolume, day);
	
	

	

	

}

void Task2()
{
	/* 2.	�������� ���������, ������� ��������� ��������� ���������� ����� � ������������ �����. ��������� �������� 
		��������� � ������ ���������� ���������� �������. */


	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask2\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	cout << "������� ����� � 10-�� ������� ���������� \t-> ";
	int dec;
	cin >> dec;

	int arr[1] = { 0 };

	convertDecToOct(arr, dec);

}


int main()
{
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n Orlov Vladimir HomeWork_26_02_2019_1551194096 \n\n";
	SetConsoleTextAttribute(hConsole, 7);


	setlocale(LC_ALL, "");
	srand(time(NULL));

	int number;
	char flag;

	do
	{
		cout << endl << "Enter number of Task (1) to (2) => ";
		cin >> number;

		switch (number)
		{
		case 1: {Task1(); } break;
		case 2: {Task2(); } break;


		default: cout << "\nEntered number of Task does not exist...\n\n";

		}

		SetConsoleTextAttribute(hConsole, 10);
		cout << "\n--------------------------------------------------------------------------\n\n";
		SetConsoleTextAttribute(hConsole, 7);

		cout << "Do you want to continue? \n\nIf YES press (y) if NO any keys => ";
		cin >> flag;

	} while (flag == 'y');
}
