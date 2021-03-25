#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

enum Specialnist { KN, ME, IF, FI, TN }; // перелік спеціальностей
string specialnistList[] = { "Комп науки", "Матем і ек", "Інформатика", "Фіз і інформ", "Труд навч" };
struct Student
{
	string prizv;
	int kurs;
	Specialnist spec;
	int fiz;
	int mat;
	union
	{
		int prog;
		int chis_metod;
		int pedagog;
	};
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
double percent(Student* p, const int N);

int main()
{
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
	int N;
	cout << "Введіть кількість студентів: "; cin >> N;
	Student* p = new Student[N]; // створення посилання student

	Create(p, N);
	Print(p, N);

	cout << "Процент студентів які мають 5 з фіз і матем: " << percent(p, N) << "%" << endl;
	return 0;
}
void Create(Student* p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Cтудент № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
		cout << "прізвище: "; getline(cin, p[i].prizv);
		cout << "курс: "; cin >> p[i].kurs;
		cout << "оцінка з фізики: "; cin >> p[i].fiz;
		cout << "оцінка з математики: "; cin >> p[i].mat;
		cout << "cпеціальність (0 - комп. науки, 1 - мат і економ, 2 - інформ, 3 - фіз і інформ, 4 - труд. навч): ";  cin >> spec;
		if (spec > 4) {
			cout << "неправильне значення, вибрано 0 (комп. науки)" << endl;
			spec = 0;
		}

		p[i].spec = (Specialnist)spec; // присвоєння спеціальності, введенної користувачем через перелік
		switch (p[i].spec)
		{
		case KN:
			cout << "оцінка з програмування: "; cin >> p[i].prog;
			break;
		case ME:
			cout << "оцінка з педагогіки: "; cin >> p[i].pedagog;
			break;
		case IF:
			cout << "оцінка з чисельних методів: "; cin >> p[i].chis_metod;
			break;
		case FI:
			cout << "оцінка з педагогіки: "; cin >> p[i].pedagog;
			break;
		case TN:
			cout << "оцінка з педагогіки: "; cin >> p[i].pedagog;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "============================================================================================================"
		<< endl;
	cout << "| № | Прізвище | Курс | Cпеціальність | Фізика | Математика | Програмування | Чисельні методи | Педагогіка |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "|" << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(9) << left << p[i].prizv
			<< "| " << setw(2) << right << p[i].kurs << "  "
			<< " | " << setw(14) << left << specialnistList[p[i].spec]
			<< setw(4) << "| " << setw(3) << left << p[i].fiz << "  "
			<< setw(6) << "| " << setw(6) << left << p[i].mat << " ";
		switch (p[i].spec)
		{
		case KN:
			cout << setw(8) << "| " << setw(7) << left << p[i].prog << setw(19)
				<< " | " << setw(12) << left
				<< "| " << left << " |" << endl;
			break;
		case ME:
			cout << "" << setw(15) << "| " << " "
				<< "" << setw(18) << "| "
				<< setw(6) << "| " << setw(6) << left << p[i].pedagog << " |" << endl;
			break;
		case IF:
			cout << "" << setw(15) << "| " << setw(9) << " |" << " "
				<< setw(8) << p[i].chis_metod << " |" << " "
				<< setw(10) << "" << " |" << endl;
			break;
		case FI:
			cout << "" << setw(15) << "| " << " "
				<< "" << setw(18) << "| "
				<< setw(6) << "| " << setw(6) << left << p[i].pedagog << " |" << endl;
			break;
		case TN:
			cout << "" << setw(15) << "| " << " "
				<< "" << setw(18) << "| "
				<< setw(6) << "| " << setw(6) << left << p[i].pedagog << " |" << endl;
			break;
		}
	}
	cout << "============================================================================================================"
		<< endl;
	cout << endl;
}

double percent(Student* p, const int N)
{
	double k = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].mat == 5 && p[i].fiz == 5)
			k++;
	}
	return k / N * 100;
}