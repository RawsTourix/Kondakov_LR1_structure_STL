#ifndef KONDAKOV_LR1_STUDENT_DEQUE_H
#define KONDAKOV_LR1_STUDENT_DEQUE_H

#include "kondakov_lr1_student_def.h"

using namespace std;

void convert_vector_to_deque() {
	// �������� Vector ��������� �� �������
	if (vector_student.empty())
		cout << endl << "Deque ��������� �� ����� ���� ������, ��� ��� Vector ��������� ������." << endl << endl
			 << "���������� �������� ������ � Vector ���������." << endl << endl;
	else {
		try {
			// ������ Deque ���������
			deque_student.clear();

			// ���������� ��������� �� Vector � ������ ��������� � ����� Deque, � � �������� � � ������
			for (const auto& student : vector_student)
				if (student.age % 2 == 0)
					deque_student.push_back(student);
				else
					deque_student.push_front(student);

			// ����� Deque ���������
			for (const auto& student : deque_student)
				student.print();
			cout << "Deque ��������� ������� ������." << endl << endl;
		}
		catch (...) { cerr << "��� ����������� Vector ��������� � Deque ��������� ������!" << endl << endl; }
	}
}

// ����� ������ 3 � ��������� 3 ��������� �� Deque
void show_3_front_3_back_deque_student() {
	// �������� Deque ��������� �� �������
	if (deque_student.empty())
		cout << endl << "Deque ��������� ������. ���������� ������� ���." << endl << endl;
	else {
		try {
			deque<Student> deque_student_copy = deque_student;

			// ����� ������ 3 �������� (��� ������)
			size_t n1 = deque_student_copy.size() < 3 ? deque_student_copy.size() : 3;
			if (deque_student_copy.size() <= 3)
				cout << "� Deque ����� " << n1 << " �������" << (n1 == 1 ? "" : "�") << ":";
			else
				cout << "������ 3 �������� Deque:";
			cout << endl << endl;

			// �����
			for (int i = 0; i < n1; i++) {
				deque_student_copy.front().print();
				deque_student_copy.pop_front();
			}
			cout << endl;

			// ����� 3 ��������� �������� (��� ������)
			size_t n2 = deque_student_copy.size() < 3 ? deque_student_copy.size() : 3;
			if (!deque_student_copy.empty()) {
				if (deque_student_copy.size() <= 3)
					cout << "�������" << (n2 == 1 ? "���" : "���") << " " << n2 << " �������" << (n2 == 1 ? "" : "�") << ":";
				else
					cout << "��������� 3 �������� Deque:";
				cout << endl << endl;

				// �����
				for (int i = 0; i < n2; i++) {
					deque_student_copy.back().print();
					deque_student_copy.pop_back();
				}
			}

			if (n1 == 1)
				cout << "��� ������� [1] ������������ �������." << endl << endl;
			else if (n1 > 1 && n2 == 0)
				cout << "���� �������� [" << n1 << "] ��������." << endl << endl;
			else if (n1 > 1 && n2 == 1)
				cout << "���� �������� [" << n1 << "] ������ �������� � [1] ���������." << endl << endl;
			else
				cout << "���� �������� [" << n1 << "] ������ �������� � [" << n2 << "] ���������." << endl << endl;

		} catch (...) { cerr << "��� ������ ������ 3 � ��������� 3 ��������� �� Deque ��������� ������!" << endl << endl; }
	}
}

#endif // !KONDAKOV_LR1_STUDENT_DEQUE_H