#ifndef KONDAKOV_LR1_STUDENT_MAP_H
#define KONDAKOV_LR1_STUDENT_MAP_H

#include "kondakov_lr1_student_def.h"

using namespace std;

void convert_vector_to_map() {
	// �������� Vector ��������� �� �������
	if (vector_student.empty())
		cout << endl << "Map ��������� �� ����� ���� ������, ��� ��� Vector ��������� ������." << endl << endl
			 << "���������� �������� ������ � Vector ���������." << endl << endl;
	else {
		try {
			// ������� Map ���������
			map_student.clear();

			// ���������� Map ��������� �� Vector
			// ���� = ������� + ����� �������� ������
			for (const auto& student : vector_student)
				map_student.emplace(student.age + student.id, student);

			// ����� Map ���������
			for (const auto& student : map_student) {
				cout << "[" << student.first << "]:" << endl << endl; student.second.print(); cout << endl;
			}
			cout << "Map ��������� ������� ������." << endl << endl;
		}
		catch (...) { cerr << "��� ����������� Vector ��������� � Map ��������� ������!" << endl << endl; }
	}
}

// ����� �� ������ �������� ������
void search_map_student() {
	int id;
	bool escape = false;

	// �������� Map ��������� �� �������
	if (map_student.empty())
		cout << endl << "Map ��� �� ������ ��������. ����� ��� ������." << endl << endl;
	else {
		// ����� � �����
		try {
			enter_number(id, escape, "����� �������� ������ ��������: ")();
			cout << endl;
			if (!escape) {
				auto it = find_if(map_student.begin(), map_student.end(), [&](pair<int, Student> student) { return student.second.id == id; });
				if (it == map_student.end())
					cout << "������� � ������� �������� ������ \"" << id << "\" �� ������." << endl << endl;
				else {
					cout << "������� � ������� �������� ������ \"" << id << "\" ������:" << endl << endl;
					it->second.print();
				}
			}
		} catch (...) { cerr << "�������� ������ ��� ������ ������� � Map �� ������ �������� ������!" << endl << endl; }
	}
}

#endif // !KONDAKOV_LR1_STUDENT_MAP_H