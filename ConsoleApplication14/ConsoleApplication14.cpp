#include <iostream>
#include <string>
#include <vector>


using namespace std;

int getCorrectNumber()
{
	unsigned int num;
	while (!(cin >> num) || (cin.peek() != '\n') || num < 0)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите корректное число: ";
	}
	return num;
}

void getEndOfWord(const unsigned int &num)
{
	cout << endl;
	if (num == 1 || ( num % 10 == 1))
	{
		cout << "Был удален " << num << " элемент" << endl;
	}
	else if ((num > 1 && num < 5) || ((num % 10) > 1 && (num % 10) < 5))
	{
		cout << "Было удалено " << num << " элемента" << endl;
	}
	else
	{
		cout << "Было удалено " << num << " элементов" << endl;
	}
}

struct Patient
{
	string surname, name, patronymic, homeAddress;
	int medicalCardNumber, insurancePolicyNumber;

	void fill()
	{
		cout << endl;
		cout << "Введите фамилию: ";
		cin >> surname;
		cout << "Введите имя: ";
		cin >> name;
		cout << "Введите отчество: ";
		cin >> patronymic;
		cin.ignore();
		cout << "Введите адресс: ";
		getline(cin, homeAddress);
		cout << "Введите номер медицинской карты: ";
		medicalCardNumber = getCorrectNumber();
		cout << "Введите номер страхового полиса: ";
		insurancePolicyNumber = getCorrectNumber();
		cout << endl;
	}
	void print()
	{
		cout << endl;
		cout << "Фамилия: " << surname << endl;
		cout << "Имя: " << name << endl;
		cout << "Отчество: " << patronymic << endl;
		cout << "Адресс: " << homeAddress << endl;
		cout << "Номер медицинской карты: " << medicalCardNumber << endl;
		cout << "Номер страхового полиса: " << insurancePolicyNumber << endl;
		cout << endl;
	}
};

void fillStruct(vector <Patient>& arr)
{
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		arr[i].fill();
	}
}

void printStruct(vector <Patient>& arr)
{
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		arr[i].print();
	}
}

void removeElement(vector <Patient>& arr)
{
	bool isFound = false;
	unsigned int counter = 0;
	unsigned int value;
	unsigned int size = arr.size();
	cout << "Введите номер медицинской карты который надо удалить: ";
	value = getCorrectNumber();
	for (int i = 0; i < size; i++)
	{
		if (arr[i].medicalCardNumber == value)
		{
			arr.erase(arr.begin() + i);
			counter++;
			isFound = true;
			size = arr.size();
		}
	}
	if (isFound == false)
	{
		cout << "Такого элемента нет\n";
		removeElement(arr);
	}
	else
	{
		getEndOfWord(counter);
	}
}

void addElement(vector <Patient>& arr)
{
	Patient newPatient;
	newPatient.fill();
	arr.push_back(newPatient);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int numberOfPatients;
	cout << "Введите количество пациентов: ";
	numberOfPatients = getCorrectNumber();
	vector <Patient> array(numberOfPatients);
	fillStruct(array);
	printStruct(array);
	removeElement(array);
	printStruct(array);

	cout << "Введите количество пациентов, которое вы хотите добавить:\t";
	numberOfPatients = getCorrectNumber();
	for (int i = 0; i < numberOfPatients; i++)
	{
		addElement(array);
	}
	printStruct(array);
}