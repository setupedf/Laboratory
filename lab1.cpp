#include "lab1.h"


// Вспомогательные функции

double translate(int pounds, int shillings, int pence)
{
	double decimalPounds;
	double penceAmount;

	penceAmount = pounds * 20 * 12 + shillings * 12 + pence;
	decimalPounds = penceAmount / 240;

	decimalPounds = round(decimalPounds * 100);

	decimalPounds /= 100;

	return decimalPounds;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else if (a == 0)
		return b;

	if (a > b)
		return gcd(b, a % b);
	else if (a < b)
		return gcd(a, b % a);
	else if (a == b)
		return a;
}

float translate(float temperature)
{
	return temperature * 9 / 5 + 32;
}

void parseFraction(int arr[], string str)
{
	bool numeratorFilled = false;
	string numerator, denominator;

	for (int i = 0; i < str.size(); i++) {

		if (str[i] == '/') {
			numeratorFilled = true;
			continue;
		}

		if (!numeratorFilled) {
			numerator += str[i];
		}
		else {
			denominator += str[i];
		}
	}

	int a = stoi(numerator);
	int b = stoi(denominator);

	*(arr) = a;
	*(arr + 1) = b;
}

void parseIntoArr(int arr[], int frac1[], int frac2[])
{
	int a = frac1[0];
	int b = frac1[1];
	int c = frac2[0];
	int d = frac2[1];

	*(arr) = a * d + b * c;
	*(arr + 1) = b * d;
}

void transform(int cardinalPart, int decimalPart, int& poundsRef, int& shillingsRef, int& penceRef)
{
	poundsRef = int(cardinalPart);
	shillingsRef = int(decimalPart * 2.4 / 12);
	penceRef = int(((decimalPart * 2.4 / 12) - (double)shillingsRef) * 12); // pence rounding at the end
}

void parseDecimalStringInput(string input, int& cardinalPart, int& decimalPart)
{
	string cardinalPartStr, decimalPartStr;
	bool cardinalPartEnded = false;

	for (int i = 0; i < input.size(); i++)
	{

		if (input[i] == '.')
		{
			cardinalPartEnded = true;
			continue;
		}

		if (!cardinalPartEnded)
			cardinalPartStr += input[i];
		else
			decimalPartStr += input[i];

	}

	cardinalPart = stoi(cardinalPartStr);

	if (cardinalPartEnded)
		decimalPart = stoi(decimalPartStr);
}

// Задачи из лабораторной работы

void lab1task1()
{
	printf(
		u8"Август\n\n"
		u8"Август — астры,\n"
		u8"Август — звезды,\n"
		u8"Август — грозди\n"
		u8"Винограда и рябины\n"
		u8"Ржавой — август!\n\n"
		u8"Полновесным, благосклонным\n"
		u8"Яблоком своим имперским,\n"
		u8"Как дитя, играешь, август.\n"
		u8"Как ладонью, гладишь сердце\n"
		u8"Именем своим имперским:\n"
		u8"Август! — Сердце!\n\n"
		u8"Месяц поздних поцелуев,\n"
		u8"Поздних роз и молний поздних!\n"
		u8"Ливней звездных —\n"
		u8"Август! — Месяц\n"
		u8"Ливней звездных!\n");

	cout << endl;
}

void lab1task2()
{
	float t;

	cout << u8"Введите температуру в Цельсиях: ";
	cin >> t;
	cout << endl;

	cout << u8"Ваша температура в Кельвинах: " << translate(t) << endl << endl;
}

void lab1task3()
{

	string firstFraction;
	string secondFraction;

	cout << u8"Введите первую дробь: ";
	cin >> firstFraction;
	cout << endl;

	cout << u8"Введите вторую дробь: ";
	cin >> secondFraction;
	cout << endl;

	const int SIZE = 2;

	int frac1[SIZE];
	int frac2[SIZE];

	parseFraction(frac1, firstFraction);
	parseFraction(frac2, secondFraction);

	int arr[SIZE];

	parseIntoArr(arr, frac1, frac2);


	int divisor = 1;
	divisor = gcd(arr[0], arr[1]);
	cout << u8"Сумма равна: " << arr[0] / divisor << "/" << arr[1] / divisor << endl << endl;
}

void lab1task4()
{
	setlocale(LC_ALL, "C");
	SetConsoleOutputCP(CP_UTF8);

	const string POUND = u8"£";

	int pounds, shillings, pence;

	cout << u8"Введите количество фунтов: ";
	cin >> pounds;

	cout << u8"Введите количество шиллингов: ";
	cin >> shillings;

	cout << u8"Введите количество пенсов: ";
	cin >> pence;

	cout << u8"Десятичных фунтов: " << POUND << translate(pounds, shillings, pence) << endl << endl;

}

void lab1task5()
{
	string decimalPounds;
	int poundsRef = 0, shillingsRef = 0, penceRef = 0;
	int cardinalPart = 0, decimalPart = 0; // decimal number parsed parts


	cout << u8"Введите число десятичных фунтов: ";
	cin >> decimalPounds;

	string str = "abc";
	int a = str.size();

	parseDecimalStringInput(decimalPounds, cardinalPart, decimalPart);
	transform(cardinalPart, decimalPart, poundsRef, shillingsRef, penceRef);

	cout << endl << u8"Эквивалентная сумма в старой форме записи: £" << poundsRef << "." << shillingsRef << "." << penceRef << endl << endl;
}
