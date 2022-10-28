#include "lab2.h"

// Вспомогательные функции

void printPyramid(int rows)
{
	int spaceQuantity = 38;

	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < spaceQuantity - i * 2; k++)
		{
			cout << u8' ';
		}

		for (int j = 0; j < 1 + i * 2; j++)
		{
			cout << u8'X';
		}

		cout << u8'\n';
	}
	cout << u8'\n';
}
unsigned long factorial(unsigned long num)
{
	if (num == 0)
		return 1;

	if (num == 1)
		return 1;

	return factorial(num - 1) * num;
}
double income(double deposit, double percent)
{
	return deposit + (deposit * percent / 100);
}
void printPaymentSum(double apartmentCost, int term, double percent, double firstPayment)
{
	apartmentCost -= firstPayment;
	double fixedPayment = apartmentCost / term;
	double ordinalPayment, paymentSum = 0;

	for (int i = 0; i < term; i++)
	{
		ordinalPayment = fixedPayment + apartmentCost * (percent / 100);
		paymentSum += ordinalPayment;
		apartmentCost -= fixedPayment;
	}

	cout << fixed << u8"Итоговая сумма платежей составит: " << u8'\t' << paymentSum << endl;
}
void printPaymentHistory(double apartmentCost, int term, double percent, double firstPayment)
{
	apartmentCost -= firstPayment;
	double fixedPayment = apartmentCost / term;
	double ordinalPayment;

	for (int i = 0; i < term; i++)
	{
		ordinalPayment = fixedPayment + apartmentCost * (percent / 100);
		apartmentCost -= fixedPayment;

		cout << fixed << u8"Ваш платеж за " << i + 1 << u8" год кредитования: " << u8'\t' << ordinalPayment << endl;
	}
}
int countShillingsSum(int& shillings1Ref, int& shillings2Ref, int& totalShillingsRef)
{
	totalShillingsRef += shillings1Ref + shillings2Ref;
	int pounds = 0;

	if (totalShillingsRef >= 20)
	{
		pounds = (int)(totalShillingsRef / 20);
		totalShillingsRef = totalShillingsRef % 20;
	}

	return pounds;
}
int countPenceSum(int& pence1Ref, int& pence2Ref, int& totalPenceRef)
{
	totalPenceRef += pence1Ref + pence2Ref;
	int shillings = 0;

	if (totalPenceRef >= 12)
	{
		shillings = (int)(totalPenceRef / 12);
		totalPenceRef = totalPenceRef % 12;
	}

	return shillings;
}
void printSum(int pounds1, int pounds2, int shillings1, int shillings2, int pence1, int pence2)
{
	int totalPounds, totalShillings = 0, totalPence = 0;

	totalPounds = pounds1 + pounds2;

	totalShillings += countPenceSum(pence1, pence2, totalPence);
	totalPounds += countShillingsSum(shillings1, shillings2, totalShillings);

	cout << u8"Всего: £" << totalPounds << u8'.' << totalShillings << u8'.' << totalPence << endl;
}
void parseUserInput(string userInputStr, int& pounds, int& shillings, int& pence)
{
	string poundsStr, shillingsStr, penceStr;
	bool poundsPassed = false, shillingsPassed = false;

	int counter = 0;

	for (int i = 0; i < userInputStr.size(); i++)
	{
		if (userInputStr[i] == u8'.')
		{
			counter += 1;
			continue;
		}

		switch (counter)
		{
		case 0:
			poundsStr += userInputStr[i];

			break;
		case 1:
			shillingsStr += userInputStr[i];
			break;

		case 2:
			penceStr += userInputStr[i];
			break;
		}
	}

	pounds = stoi(poundsStr);
	shillings = stoi(shillingsStr);
	pence = stoi(penceStr);

}

// Сценарии задач

void lab2task1()
{
	const int pyramidRows = 20;

	printPyramid(pyramidRows);
}
void lab2task2()
{
	unsigned long usrNumber;

	while (true)
	{
		cout << u8"Введите число, для которого следует вычислить факториал: ";

		unsigned long usrNumber;
		cin >> usrNumber;

		if (usrNumber == 0)
			break;

		cout << u8'\n' << u8'!' << usrNumber << u8" = " << factorial(usrNumber) << u8'\n' << u8'\n';
	}
}
void lab2task3()
{
	double userDeposit, userPercent;
	int userDepositYears;

	cout << u8"Введите начальный вклад: ";
	cin >> userDeposit;

	cout << u8"Введите число лет: ";
	cin >> userDepositYears;

	cout << u8"Введите процентную ставку: ";
	cin >> userPercent;

	for (int i = 0; i < userDepositYears; i++)
	{
		userDeposit = income(userDeposit, userPercent);
	}

	cout << u8"Через " << userDepositYears << u8" лет вы получите " << userDeposit << u8" доллара." << endl << endl;
}
void lab2task4()
{
	double apartmentCost, firstPayment, percent;
	int term;

	cout << u8"Введите стоимость квартиры: ";
	cin >> apartmentCost;
	cout << endl;

	cout << u8"Введите начальный взнос: ";
	cin >> firstPayment;
	cout << endl;

	cout << u8"Введите число лет ипотеки: ";
	cin >> term;
	cout << endl;

	cout << u8"Введите процентную ставку: ";
	cin >> percent;
	cout << endl;

	printPaymentHistory(apartmentCost, term, percent, firstPayment);
	printPaymentSum(apartmentCost, term, percent, firstPayment);

	cout << endl << endl;

}
void lab2task5()
{
	string userInput1, userInput2, userCommonInput;

	int pounds1 = 0, shillings1 = 0, pence1 = 0,
		pounds2 = 0, shillings2 = 0, pence2 = 0;

	do
	{
		cout << u8"Введите первую сумму: ";
		cin >> userInput1;

		cout << u8"Введите вторую сумму: ";
		cin >> userInput2;

		parseUserInput(userInput1, pounds1, shillings1, pence1);
		parseUserInput(userInput2, pounds2, shillings2, pence2);

		printSum(pounds1, pounds2, shillings1, shillings2, pence1, pence2);

		cout << u8"Продолжить (y/n)? ";
		cin >> userCommonInput;
		cout << endl;
	} while (userCommonInput != "n");
}