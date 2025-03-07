#ifndef KONDAKOV_LR1_STUDENT_STACK
#define KONDAKOV_LR1_STUDENT_STACK

#include "kondakov_lr1_student_def.h"

using namespace std;

// Вывод Stack студентов
void show_stack_student() {
	stack<Student> stack_student_copy = stack_student;

	while (!stack_student_copy.empty()) {
		stack_student_copy.top().print();
		stack_student_copy.pop();
	}
}

void convert_vector_to_stack() {
	// Проверка Vector студентов на пустоту
	if (vector_student.empty())
		cout << endl << "Stack студентов не может быть создан, так как Vector студентов пустой." << endl << endl
			 << "Необходимо добавить данные в Vector студентов." << endl << endl;
	else {
		try {
			// Очистка Stack студентов
			while (!stack_student.empty())
				stack_student.pop();

			// Добавление в Stack элементов из Vector в обратном порядке
			for (const auto& student : vector_student)
				stack_student.push(student);

			// Вывод Stack студентов
			show_stack_student();
			cout << "Stack студентов успешно создан." << endl << endl;
		}
		catch (...) { cerr << "При конвертации Vector студентов в Stack произошла ошибка!" << endl << endl; }
	}
}

// Извлечь элементы из Stack, пока не останется 3 студента
void show_last_3_stack_student() {
	// Проверка Stack студентов на пустоту
	if (stack_student.empty())
		cout << endl << "Stack студентов пустой. Необходимо добавить в него данные." << endl << endl;
	else {
		try {
			// Извлечение элементов, пока не останется 3 студента
			int n = 0;
			while (stack_student.size() > 3) {
				stack_student.pop();
				++n;
			}

			// Вывод Stack студентов
			show_stack_student();
			if (n)
				cout << "Успешно извлеч" << extract_ending(n) << " [" << n << "] студент" << student_ending(n) << "." << endl << endl;
			else
				cout << "Не было извлечено ни одного студента, так как в Stack их было меньше 3." << endl << endl;
		}
		catch (...) { cerr << "Возникла ошибка при извлечении элементов из Stack!" << endl << endl; }
	}
}

#endif // !KONDAKOV_LR1_STUDENT_STACK