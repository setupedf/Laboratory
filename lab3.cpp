#include "lab3.h"
#define END_LINE std::cout << std::endl;



//	Returns the greatest common divisor of two numbers a and b
int Gcd(int a, int b)
{
	int remainder = 0;

	if (a == 0)
	{
		return b;
	}
	else if (b == 0)
	{
		return a;
	}

	if (a > b)
	{
		remainder = a % b;
		return Gcd(remainder, b);
	}
	else if (a < b)
	{
		remainder = b % a;
		return Gcd(remainder, a);
	}
	else
	{
		return a;
	}
}

int CharIntoInt(char a) 
{
	return a - '0';
}

int Pow(int a, int b) 
{
	if (b <= 0) 
	{
		return 1;
	}

	return a * Pow(a, b - 1);
}



//=========================================tasks=========================================



void lab3task1() 
{
	struct Employee 
	{

	private:

		int id;
		float salary;

	public:

		Employee(int id) 
		{
			this->id = id;
		}

		void SetSalary(float salary) 
		{
			this->salary = salary;
		}

		float GetSalary() 
		{
			return this->salary;
		}

		int GetId() 
		{
			return this->id;
		}
	};

	int id[3];
	float salary[3];

	for (int i = 0; i < 3; i++)
	{
		std::cout << i + 1 << u8" сотрудник." << std::endl;
		std::cout << u8"Введите id: ";
		std::cin >> id[i];
		std::cout << std::endl;

		std::cout << u8"Введите зарплату в рублях: ";
		std::cin >> salary[i];
		std::cout << std::endl;
	}

	Employee first(id[0]);
	first.SetSalary(salary[0]);

	Employee second(id[1]);
	second.SetSalary(salary[1]);

	Employee third(id[2]);
	third.SetSalary(salary[2]);

	Employee emps[3] { first, second, third };

	for (int i = 0; i < 3; i++)
	{
		std::cout << i + 1 << u8" сотрудник." << std::endl;
		std::cout << u8"Id: " << emps[i].GetId() << std::endl;
		std::cout << u8"Зарплата: " << emps[i].GetSalary() << std::endl;
	}
}

void lab3task2() 
{
	enum etype { laborer, secretary, manager, accountant, executive, researcher };

	char c;

	std::cout << u8"Введите первую букву должности. " << std::endl;
	std::cout << u8"(laborer, secretary, manager, accountant, executive, researcher): ";
	std::cin >> c;
	std::cout << std::endl;

	switch (c) 
	{
	case 'l':
		std::cout << u8"Полное название должности: laborer" << std::endl;
		break;

	case 's':
		std::cout << u8"Полное название должности: secretary" << std::endl;
		break;

	case 'm':
		std::cout << u8"Полное название должности: manager" << std::endl;
		break;

	case 'a':
		std::cout << u8"Полное название должности: accountant" << std::endl;
		break;

	case 'e':
		std::cout << u8"Полное название должности: executive" << std::endl;
		break;

	case 'r':
		std::cout << u8"Полное название должности: researcher" << std::endl;
		break;
	default:
		std::cout << u8"Такой должности не существует!" << std::endl;
	}
}

void lab3task3() 
{
	//	Stores fraction that represents a/b
	struct Fraction
	{
	private:
		std::string fraction = "0/1";
		
	public:
		int a = 0;
		int b = 0;

	public:

		//	Struct Constructor
		Fraction(std::string fraction) 
		{
			this->fraction = fraction;
			this->ParseFraction();
		}
		
		//	Returns number of chars in numerator
		int CountNumerator() 
		{
			int c = 0, i = 0;

			while (fraction[i++] != '/')
			{
				c++;
			}

			return c;
		}

		//	Returns number of chars in denominator
		int CountDenominator()
		{
			int c = 0, i = fraction.size() - 1;

			while (fraction[i--] != '/')
			{
				c++;
			}

			return c;
		}

	private:
		//	Parses fraction in string into a, b fields
		void ParseFraction() 
		{
			char c;
			bool switched = false;

			int i = 0;
			int j = this->CountNumerator() - 1;
			int k = this->CountDenominator() - 1;

			while ((c = fraction[i]) != '\0')
			{
				if (c == '/')
				{
					switched = true;
					i++;
					continue;
				}

				if (!switched)
				{
					this->a += j != 0 ? CharIntoInt(c) * Pow(10, j) : CharIntoInt(c);
					j--;
					i++;
				}
				else
				{
					this->b += k != 0 ? CharIntoInt(c) * Pow(10, k) : CharIntoInt(c);
					k--;
					i++;
				}
			}
		}
	};


	std::string fraction;

	std::cout << u8"Введите первую дробь: ";
	std::cin >> fraction;

	Fraction first(fraction);
	END_LINE;

	std::cout << u8"Введите вторую дробь: ";
	std::cin >> fraction;
	
	Fraction second(fraction);

	END_LINE;

	int arr[2]{};

	arr[0] = (first.a * second.b + first.b * second.a);
	arr[1] = (first.b * second.b);
	
	int divisor = Gcd(arr[0], arr[1]);
	
	std::cout << arr[0] / divisor << "/" << arr[1] / divisor << std::endl;
}
