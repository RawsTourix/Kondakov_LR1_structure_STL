#ifndef KONDAKOV_LR1_STUDENT_STACK
#define KONDAKOV_LR1_STUDENT_STACK

#include "kondakov_lr1_student_def.h"

using namespace std;

// ����� Stack ���������
void show_stack_student() {
	stack<Student> stack_student_copy = stack_student;

	while (!stack_student_copy.empty()) {
		stack_student_copy.top().print();
		stack_student_copy.pop();
	}
}

void convert_vector_to_stack() {
	// �������� Vector ��������� �� �������
	if (vector_student.empty())
		cout << endl << "Stack ��������� �� ����� ���� ������, ��� ��� Vector ��������� ������." << endl << endl
			 << "���������� �������� ������ � Vector ���������." << endl << endl;
	else {
		try {
			// ������� Stack ���������
			while (!stack_student.empty())
				stack_student.pop();

			// ���������� � Stack ��������� �� Vector � �������� �������
			for (const auto& student : vector_student)
				stack_student.push(student);

			// ����� Stack ���������
			show_stack_student();
			cout << "Stack ��������� ������� ������." << endl << endl;
		}
		catch (...) { cerr << "��� ����������� Vector ��������� � Stack ��������� ������!" << endl << endl; }
	}
}

// ������� �������� �� Stack, ���� �� ��������� 3 ��������
void show_last_3_stack_student() {
	// �������� Stack ��������� �� �������
	if (stack_student.empty())
		cout << endl << "Stack ��������� ������. ���������� �������� � ���� ������." << endl << endl;
	else {
		try {
			// ���������� ���������, ���� �� ��������� 3 ��������
			int n = 0;
			while (stack_student.size() > 3) {
				stack_student.pop();
				++n;
			}

			// ����� Stack ���������
			show_stack_student();
			if (n)
				cout << "������� ������" << extract_ending(n) << " [" << n << "] �������" << student_ending(n) << "." << endl << endl;
			else
				cout << "�� ���� ��������� �� ������ ��������, ��� ��� � Stack �� ���� ������ 3." << endl << endl;
		}
		catch (...) { cerr << "�������� ������ ��� ���������� ��������� �� Stack!" << endl << endl; }
	}
}

#endif // !KONDAKOV_LR1_STUDENT_STACK