#include <iostream>  
#include <string>    

// Рисунок 2 - створення 2 класів: Person, Student
class Person
{
public:
	std::string Name;
	std::string Surname;

	Person() {}

	// Рисунок 5 - створення конструктору класу
	Person(std::string _Name, std::string _Surname)
	{
		Name = _Name;
		Surname = _Surname;
	}

	// Рисунок 7 - створення нової функції
	void SnowMessage()
	{
		std::cout << "The Person is eat" << std::endl;
	}
};

class Student : public Person // Рисунок 3 - успадкування в програмному коді
{
public:
	std::string Group;
	std::string Cours;
	std::string Specialty;

	// Рисунок 6 - приклад успадкування батьківського класу
	Student(std::string _Name, std::string _Surname) : Person(_Name, _Surname)
	{

	}

	// Рисунок 10 - перевизначення функції
	void ShowMessage()
	{
		std::cout << "The student is eat" << std::endl;
	}
};

int main()
{
	Person person1;  // Рисунок 4 - властивості дочірнього класу
	// Рисунок 6 - приклад успадкування батьківського класу
	Student student1("Name", "Surname");
	std::cout << student1.Name << std::endl;
	std::cout << student1.Surname << std::endl;
	// Рисунок 8 - виклик функції
	student1.ShowMessage();
}