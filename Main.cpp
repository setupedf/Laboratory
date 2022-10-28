#include "lab1.h"
#include "lab2.h"
#include "lab3.h"

int main() 
{
	SetConsoleOutputCP(CP_UTF8);

	int num;

	while (true)
	{

		std::cout << u8"Наберите номер задачи: ";
		std::cin >> num;
		std::cout << std::endl;

		switch (num)
		{

		case 1:
			lab3task1();
			break;

		case 2:
			lab3task2();
			break;

		case 3:
			lab3task3();
			break;

		case 4:
			//lab2task4();
			break;

		case 5:
			//lab2task5();
			break;

		default:
			std::cout << u8"Такой задачи не существует!" << std::endl;
			break;
		}
	}

	return 0;
}