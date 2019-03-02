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
	
	// записываем ниже под массивом дней массив осадков, c условием чтобы осадки не повтор€лись на след день

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


void Task1()
{
	/* 1.	Ќаписать программу Ђѕрогноз погодыї. —оздать два массива: массив символов и массив вещественных чисел. 
	ћассив символов описывает тип осадков, массив вещественных чисел Ц объем осадков. ѕри каждом запуске программы 
	генерируетс€ разное количество осадков. 
     –екомендации:
	“ип осадков можно выбирать из перечн€ (дл€ этого создать статический массив с перечнем осадков, а генерировать 
	позицию из массива). —ледите, чтобы один и тот же осадок не повторилс€ более одного раза.  оличество осадков 
	генерируетс€ случайным образом. */

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask1\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	int *arrDay;
	char *arrType;
	float *arrVolume;

	cout << "¬ыберите на сколько дней предоставить прогноз погоды от 1 до 10 - > ";
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
	/* 2.	Ќаписать программу, котора€ переводит введенное дес€тичное число в восьмеричное число.–езультат перевода 
		сохранить в массив минимально возможного размера. */



	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask2\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	

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
