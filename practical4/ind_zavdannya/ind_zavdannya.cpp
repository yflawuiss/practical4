#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>
#include <iomanip> // Додаємо бібліотеку для форматування

using namespace std;

// Структура Record
struct Record
{
    int id = 0;
    string type;
    string subject;
    string form;
    int grade = 0;
    string education_form;
};

// **Базовий клас для введення та виводу записів**
class BaseRecords
{
protected:
    vector<Record> records;

public:
    // Конструктор за замовчуванням
    BaseRecords() {}

    // ** Базовий клас, функція введення записів **
    void input()
    {
        int n;
        cout << " Введіть кількість записів: ";
        cin >> n;
        cin.ignore();

        vector<string> types = { "залік", "екзамен" };
        vector<string> subjects = { "математика", "фізика", "графіка" };
        vector<string> forms = { "усна", "письмова" };
        vector<string> educations = { "заочна", "стаціонарна" };

        for (int i = 0; i < n; ++i)
        {
            Record r;
            r.id = i + 1;
            cout << "\n       Запис №" << r.id << " " << endl;

            r.type = chooseOption("(Тип оцінювання):", types);
            r.subject = chooseOption("(Предмет):", subjects);
            r.form = chooseOption("(Форма здачі):", forms);

            cout << "Оцінка (2-5): ";
            do
            {
                cin >> r.grade;
                if (r.grade < 2 || r.grade > 5)
                    cout << "Неправильна оцінка. Спробуйте ще раз: ";
            } while (r.grade < 2 || r.grade > 5);
            cin.ignore();

            r.education_form = chooseOption("(Форма навчання):", educations);

            records.push_back(r);
        }
    }

    // ** Базовий клас, функція виведення записів **
    virtual void output() const
    {
        // Верхня лінія розділення
        cout << string(79, '-') << endl; 

        cout << "| " << "ID  " << setw(2)
            << "| " << "Тип оцінювання " << setw(2)
            << "| " << "Предмет    " << setw(2)
            << "| " << "Форма здачі   " << setw(2) 
            << "| " << "Оцінка " << setw(2) 
            << "| " << "Форма навчання" << " |" << endl;

        // Нижня лінія розділення
        cout << "|" << string(5, '-') << "|" << string(16, '-') << "|" << string(12, '-')
            << "|" << string(15, '-') << "|" << string(8, '-') << "|" << string(16, '-') << "|"
            << endl;                 

        for (size_t i = 0; i < records.size(); ++i)
        {
            cout << "|  " << left << setw(3) << records[i].id
                << "| " << setw(15) << records[i].type
                << "| " << setw(11) << records[i].subject
                << "| " << setw(14) << records[i].form
                << "|   " << setw(5) << records[i].grade
                << "| " << setw(14) << records[i].education_form << " |" << endl;

            // Додавання нижньої лінії тільки після останнього запису
            if (i == records.size() - 1)
            {
                cout << string(79, '-') << endl;
            }
        }
    }

protected:
    string chooseOption(const string& title, const vector<string>& options)
    {
        int choice;
        cout << title << endl;
        for (size_t i = 0; i < options.size(); ++i)
        {
            cout << " " << i + 1 << " - " << options[i] << endl;
        }
        do
        {
            cout << "    Введіть номер варіанту: ";
            cin >> choice;
        } while (choice < 1 || choice > options.size());
        cin.ignore();
        return options[choice - 1];
    }
};

// ** Похідний клас для сортування записів **
class SortedRecords : public BaseRecords
{
public:
    // ** Похідний клас, функція сортування за оцінкою (спадання) **
    void sortByGrade()
    {
        sort(records.begin(), records.end(), [](const Record& a, const Record& b) 
            {
            return a.grade > b.grade;
            });
    }

    // ** Похідний клас, функція сортування за формою здачі ** 
    void sortByForm()
    {
        sort(records.begin(), records.end(), [](const Record& a, const Record& b) 
            {
            return a.form < b.form;
            });
    }

    // Перевизначення успадкованого метода виводу
    void output() const override
    {
        BaseRecords::output();
    }
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    SortedRecords group1;
    group1.input();

    cout << "\n                              <- Введені записи ->\n\n";
    group1.output();

    // Сортування за оцінкою
    group1.sortByGrade();
    cout << "\n\n                        Сортування за оцінкою (спадання)\n\n";
    group1.output();

    // Сортування за формою здачі
    group1.sortByForm();
    cout << "\n\n                          Сортування за формою здачі\n\n";
    group1.output();

    return 0;
}