#ifndef KONDAKOV_LR1_STUDENT_DEF_H // ������ �� ���������� ���������
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

// ����������� ��� �����
const char* SEP = "= ";	

// finally ��� ����������� try-catch
struct Finally {
private:
	function<void()> func;

public:
	// �����������, ����������� ������-������� ��� ������ � ��� ������ �� ����������� try-catch
	Finally(function<void()> f) : func(f) {};
	// ����� ���������� ������-������� ��� ������ �����������
	~Finally() { func(); }
};

// �������� �������� ������� � � ����� (trim)
void trim(string& str) {
	// ������� ������� � ������
	while (!str.empty() && str.front() == ' ')
		str.erase(str.begin());

	// ������� ������� � �����
	while (!str.empty() && str.back() == ' ')
		str.pop_back();
}

// ���������� ��������� ����� "�������" � ����������� �� ��� ����������
string student_ending(int n) {
	n %= 100;
	if (n >= 11 && n <= 19) return "";
	n %= 10;
	if (n == 1) return "";
	if (n >= 2 && n <= 4) return "�";
	return "��";
}

// ���������� ��������� ����� "�������" � ����������� �� ��� ����������
string extract_ending(int n) {
	n %= 100;
	if (n == 11) return "���";
	n %= 10;
	if (n == 1) return "��";
	return "���";
}

// �������� �� ������ ���� ��� ������ ��������
bool is_input_empty(string input) {
	if (input.empty() || input == "") {
		cout << endl << "[������ ��������]" << endl << endl;
		return true;
	}
	return false;
}

// �������� ����������� � ����� �����
bool is_int(string input, int min, int max) {
	try {
		int number = stoi(input);
		if (number < min) { cout << endl << "�� ����� \"" << number << "\" � �������� ������ ���� ������ \"" << min << "\"" << endl << endl; return false; }
		if (number > max) { cout << endl << "�� ����� \"" << number << "\" � �������� ������ ���� ������ \"" << max << "\"" << endl << endl; return false; }
	} catch (...) { cerr << endl << "�������� ���� �������� \"" << input << "\" �� �������� ������!" << endl << endl; return false; }
	return true;
}

// ��������������� ������� ��� ����� ����� �����
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

// ��������������� ������� ��� ����� �����
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

// ��������� ��������
struct Student
{
	string name;
	string surname;
	int id;
	int age;
	vector<int> grades;

	// ������� � ������� ����������
	Student() : name(""), surname(""), id(0), age(0), grades({ 0, 0, 0, 0, 0, 0 }) {};

	// ������� (string ���, string �������, int ����� �������� ������, int �������, vector<int> ������)
	Student(string name, string surname, int id, int age, vector<int> grades)
		: name(name), surname(surname), id(id), age(age), grades(grades) {};

	// ����� ������ � ��������
	void print() const {
		cout << "���: " << name << endl << "�������: " << surname << endl << "����� �������� ������: " << id << endl << "�������: " << age << endl << "������: ";
		for (auto it = grades.begin(); it != grades.end(); it++)
			cout << (it == grades.begin() ? "" : ", ") << *it;
		std::cout << std::endl << std::endl;
	}

	explicit operator bool() const {
		return !name.empty() && !surname.empty() && id >= 0 && age >= 0 && grades != vector<int> { 0, 0, 0, 0, 0, 0 };
	}
};

// ���������� ���������� ����������� ���� ��������
vector<Student> vector_student;
list<Student> list_student;
deque<Student> deque_student;
map<int, Student> map_student;
set<int> set_id_student;
stack<Student> stack_student;

// �������� ������������� �������� � Vector � ����� �� id
static bool is_student_id_exists_in_vector(int id) {
	for (const auto& student : vector_student)
		if (student.id == id) {
			cout << endl << "������� � ������� �������� ������ \"" << id << "\" ��� ������� � Vector ���������!" << endl << endl;
			return true;
		}
	return false;
}

// �������� �������� �� ������ �������� ������
Student new_student() {
	string name, surname;
	int id, age, grade;
	vector<int> grades;

	bool escape = false;

	// ���
	enter_string(name, escape, "���: ")();							if (escape) return Student(); // ������� ������� ��������

	// �������
	enter_string(surname, escape, "�������: ")();					if (escape) return Student();

	// ����� �������� ������ � ��������� �� ������
	do {
		enter_number(id, escape, "����� �������� ������: ")();		if (escape) return Student();
	} while (is_student_id_exists_in_vector(id));

	// �������
	enter_number(age, escape, "�������: ", 0, 120)();				if (escape) return Student();

	// ������
	cout << endl << "������: " << endl;
	for (int i = 1; i <= 6; i++) {
		enter_number(grade, escape, to_string(i) + ") ", 2, 5)();	if (escape) return Student();
		grades.push_back(grade);
	}
	cout << endl;

	return Student(name, surname, id, age, grades);
}

#endif // !KONDAKOV_LR1_STUDENT_DEF_H