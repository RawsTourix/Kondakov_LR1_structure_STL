#ifndef KONDAKOV_LR1_STUDENT_DEF_H // защита от повторного включения
#define KONDAKOV_LR1_STUDENT_DEF_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <functional>
#include <numeric>
#include <algorithm>

using namespace std;

// Разделитель при вводе
const char* SEP = "= ";	

// finally для конструкции try-catch
struct Finally {
private:
	function<void()> func;

public:
	// Конструктор, принимающий лямбда-функцию для вызова её при выходе из конструкции try-catch
	Finally(function<void()> f) : func(f) {};
	// Вызов переданной лямбда-функции при вызове деструктора
	~Finally() { func(); }
};

// Удаление пробелов вначале и в конце (trim)
void trim(string& str) {
	// Удаляем пробелы с начала
	while (!str.empty() && str.front() == ' ')
		str.erase(str.begin());

	// Удаляем пробелы с конца
	while (!str.empty() && str.back() == ' ')
		str.pop_back();
}

// Возвращает окончание слова "студент" в зависимости от его количества
string student_ending(int n) {
	n %= 100;
	if (n >= 11 && n <= 19) return "";
	n %= 10;
	if (n == 1) return "";
	if (n >= 2 && n <= 4) return "а";
	return "ов";
}

// Возвращает окончание слова "студент" в зависимости от его количества
string extract_ending(int n) {
	n %= 100;
	if (n == 11) return "ено";
	n %= 10;
	if (n == 1) return "ён";
	return "ено";
}

// Проверка на пустой ввод для отмены операции
bool is_input_empty(string input) {
	if (input.empty() || input == "") {
		cout << endl << "[Отмена операции]" << endl << endl;
		return true;
	}
	return false;
}

// Проверка конвертации в целое число
bool is_int(string input, int min, int max) {
	try {
		int number = stoi(input);
		if (number < min) { cout << endl << "Вы ввели \"" << number << "\" — значение должно быть больше \"" << min << "\"" << endl << endl; return false; }
		if (number > max) { cout << endl << "Вы ввели \"" << number << "\" — значение должно быть меньше \"" << max << "\"" << endl << endl; return false; }
	} catch (...) { cerr << endl << "Введённое вами значение \"" << input << "\" не является числом!" << endl << endl; return false; }
	return true;
}

// Вспомогательная функция для ввода целых чисел
function<void()> enter_number(int& varLink, bool& escapeLink, string label = "", int min = 0, int max = 2147483647) {
	return [&varLink, &escapeLink, label, min, max]() {
		string raw_input;

		do {
			cout << label << SEP;
			getline(cin, raw_input);
			trim(raw_input);
			escapeLink = is_input_empty(raw_input);
			if (escapeLink) return;
		} while (!is_int(raw_input, min, max));

		varLink = stoi(raw_input);
	};
}

// Вспомогательная функция для ввода строк
function<void()> enter_string(string& varLink, bool& escapeLink, string label = "") {
	return [&varLink, &escapeLink, label]() {
		string raw_input;

		cout << label << SEP;
		getline(cin, raw_input);
		trim(raw_input);
		escapeLink = is_input_empty(raw_input);
		if (!escapeLink)
			varLink = raw_input;
	};
}

// Структура студента
struct Student
{
	string name;
	string surname;
	int id;
	int age;
	vector<int> grades;

	// Студент с пустыми значениями
	Student() : name(""), surname(""), id(0), age(0), grades({ 0, 0, 0, 0, 0, 0 }) {};

	// Студент (string Имя, string Фамилия, int Номер зачётной книжки, int Возраст, vector<int> Оценки)
	Student(string name, string surname, int id, int age, vector<int> grades)
		: name(name), surname(surname), id(id), age(age), grades(grades) {};

	// Вывод данных о студенте
	void print() const {
		cout << "Имя: " << name << endl << "Фамилия: " << surname << endl << "Номер зачётной книжки: " << id << endl << "Возраст: " << age << endl << "Оценки: ";
		for (auto it = grades.begin(); it != grades.end(); it++)
			cout << (it == grades.begin() ? "" : ", ") << *it;
		std::cout << std::endl << std::endl;
	}

	explicit operator bool() const {
		return !name.empty() && !surname.empty() && id >= 0 && age >= 0 && grades != vector<int> { 0, 0, 0, 0, 0, 0 };
	}
};

// Глобальное объявление контейнеров типа студента
vector<Student> vector_student;
list<Student> list_student;
deque<Student> deque_student;
map<int, Student> map_student;
set<int> set_id_student;
stack<Student> stack_student;

// Проверка существования студента в Vector с таким же id
static bool is_student_id_exists_in_vector(int id) {
	for (const auto& student : vector_student)
		if (student.id == id) {
			cout << endl << "Студент с номером зачётной книжки \"" << id << "\" уже записан в Vector студентов!" << endl << endl;
			return true;
		}
	return false;
}

// Создание студента на основе введённых данных
Student new_student() {
	string name, surname;
	int id, age, grade;
	vector<int> grades;

	bool escape = false;

	// Имя
	enter_string(name, escape, "Имя: ")();							if (escape) return Student(); // Возврат пустого студента

	// Фамилия
	enter_string(surname, escape, "Фамилия: ")();					if (escape) return Student();

	// Номер зачётной книжки с проверкой на повтор
	do {
		enter_number(id, escape, "Номер зачётной книжки: ")();		if (escape) return Student();
	} while (is_student_id_exists_in_vector(id));

	// Возраст
	enter_number(age, escape, "Возраст: ", 0, 120)();				if (escape) return Student();

	// Оценки
	cout << endl << "Оценки: " << endl;
	for (int i = 1; i <= 6; i++) {
		enter_number(grade, escape, to_string(i) + ") ", 2, 5)();	if (escape) return Student();
		grades.push_back(grade);
	}
	cout << endl;

	return Student(name, surname, id, age, grades);
}

#endif // !KONDAKOV_LR1_STUDENT_DEF_H