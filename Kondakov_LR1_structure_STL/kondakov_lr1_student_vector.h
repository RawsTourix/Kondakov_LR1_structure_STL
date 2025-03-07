#ifndef KONDAKOV_LR1_STUDENT_VECTOR_H // ������ �� ���������� ���������
#define KONDAKOV_LR1_STUDENT_VECTOR_H

#include "kondakov_lr1_student_def.h"

using namespace std;

function<void()> load_students_to_vector(string filename) {
	return [filename]() {
		ifstream file(filename);
		if (!file.is_open()) {
			cerr << "�������� ������ ��� �������� �����: " << filename << endl;
		}
		vector_student.clear();
		string line = "";
		string err = "";
		try {
			// ���������� ������� ��� ������-������� ��� ������ �� try-catch
			// ������ finally
			Finally finally([] { cout << endl << endl; });

			while (getline(file, line)) {
				stringstream ss(line);
				string name, surname, id_str, age_str;
				int id, age;
				vector<int> grades;

				// ������ �����, �������, ������ �������� ������ � ��������
				err = "��� (name)";
				getline(ss, name, ',');
				trim(name);

				err = "������� (surname)";
				getline(ss, surname, ',');
				trim(surname);

				err = "����� ������ � �������� ������ (id)";
				getline(ss, id_str, ',');
				id = stoi(id_str);

				err = "������� (age)";
				getline(ss, age_str, ',');
				age = stoi(age_str);

				// ������ ������
				err = "������ (grades)";
				string grade;
				while (getline(ss, grade, ','))
					grades.push_back(stoi(grade));

				// ���������� �������� � ����� �������
				vector_student.emplace_back(name, surname, id, age, grades);
			}
			cout << "Vector ��������� ������� ������.";
			file.close();
		}
		catch (...) {
			cerr << "������ ��� �������� Vector ���������!" << endl;
			if (err == "") {
				cerr << "�������������� ���������� �� ������ �����������.";
			} else {
				cerr << "��������� ����: " << err << ".";
			}
			vector_student.clear();
		}
	};
}

// ������� ��������� ������ ���������
struct compare_grades {
	inline bool operator() (const Student& student1, const Student& student2) {
		return student1.grades[0] < student2.grades[0];
	}
};

// ����� ������� vector_student
void show_vector_student() {
	if (vector_student.empty())
		cout << endl << "Vector ��������� ������. ���������� ������� ���." << endl << endl;
	else {
		for (const auto& student : vector_student)
			student.print();
		cout << "Vector ��������� �������." << endl << endl;
	}
}

// ���������� ��������� �� ������ ������
void sort_vector_student() {
	if (vector_student.empty())
		cout << endl << "Vector ��������� ������. ���������� ������� ���." << endl << endl;
	else {
		try {
			// ���������� �� ������ ������
			sort(vector_student.begin(), vector_student.end(), compare_grades());
			// ����� Vector ���������
			for (const auto& student : vector_student)
				student.print();
			cout << "Vector ��������� ������� ������������." << endl << endl;
		}
		catch (...) { cerr << "��� ���������� Vector ��������� �������� ������!" << endl << endl; }
	}
}

// ���������� �������� � ������
void add_student_to_vector() {
	cout << "���������� �������� � Vector:" << endl;
	Student student = new_student();
	
	if (student) {
		try {
			vector_student.emplace_back(student);
			student.print();
			cout << "������� ������� �������� � Vector ���������." << endl << endl;
		} catch (...) { cout << "������� �� ��� �������� � Vector ��������� ���������� ������." << endl
			<< "��������� ������������ �������� ������." << endl << endl; }
	}
	else cout << "������� �� ��� �������� � Vector ���������, ��� ��� �������� ���� ��������." << endl << endl;
}

// �������� ���� ��������� �� Vector
void clear_vector_student() {
	if (vector_student.empty())
		cout << endl << "Vector ��������� � ��� ������." << endl << endl;
	else {
		try {
			vector_student.clear();
			cout << endl << "��� ������ �� Vector ��������� ���� �������." << endl << endl;
		}
		catch (...) { cerr << "��� �������� ������ �� Vector ��������� �������� ������!" << endl << endl; }
	}
}

#endif // !KONDAKOV_LR1_STUDENT_DEF_H