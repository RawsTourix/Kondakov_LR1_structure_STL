#ifndef KONDAKOV_LR1_STUDENT_LIST_H
#define KONDAKOV_LR1_STUDENT_LIST_H

#include "Kondakov_LR1_Student_def.h"

using namespace std;

void convert_vector_to_list() {
	// �������� Vector ��������� �� �������
	if (vector_student.empty())
		cout << endl << "List ��������� �� ����� ���� ������, ��� ��� Vector ��������� ������." << endl << endl
			 << "���������� �������� ������ � Vector ���������." << endl << endl;
	else {
		try {
			// ������� List ���������
			list_student.clear();

			// ���������� ��������� �� Vector ������ 21 ���� � ������, ��������� � � �����
			for (const auto& student : vector_student)
				if (student.age > 21)
					list_student.push_front(student);
				else
					list_student.push_back(student);

			// ����� List ���������
			for (const auto& student : list_student)
				student.print();

			cout << "List ��������� ������� ������." << endl << endl;
		}
		catch (...) { cerr << "��� ����������� Vector ��������� � List ��������� ������!" << endl << endl; }
	}
}

// �������� ��������� � ��������� > 20
void delete_students_from_list() {
	// �������� List ��������� �� �������
	if (list_student.empty())
		cout << endl << "� List ��������� ������. ���������� ������� ���." << endl << endl;
	else {
		try {
			// �������� ��������� � ��������� > 20
			for (auto it = list_student.begin(); it != list_student.end(); )
				if (it->age > 20)
					it = list_student.erase(it);
				else
					++it;

			// ����� List ���������
			for (const auto& student : list_student)
				student.print();
			cout << "�������� ������ 20 ��� ������� ������� �� List." << endl << endl;
		}
		catch (...) { cerr << "�������� ������ ��� �������� ��������� �� List ������ 20 ���!" << endl << endl; }
	}
}

// ���������� �������� � �������� List
void add_student_to_list() {
	Student student = new_student();

	if (student) {
		try {
			// ������� �������� � �������� List
			auto it = list_student.begin();
			advance(it, list_student.size() / 2); // ����������� ��������� � �������� List
			list_student.insert(it, student);
			
			// ����� List ���������
			for (const auto& student : list_student)
				student.print();
			cout << "������� ������� �������� � �������� List ���������." << endl << endl;
		}
		catch (...) {
			cout << "������� �� ��� �������� � �������� List ��������� ���������� ������." << endl
				 << "��������� ������������ �������� ������." << endl << endl;
		}
	}
	else cout << "������� �� ��� �������� � �������� List ���������, ��� ��� �������� ���� ��������." << endl << endl;
}

#endif // !KONDAKOV_LR1_STUDENT_LIST_H