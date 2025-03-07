#ifndef KONDAKOV_LR1_STUDENT_DEQUE_H
#define KONDAKOV_LR1_STUDENT_DEQUE_H

#include "kondakov_lr1_student_def.h"

using namespace std;

void convert_vector_to_deque() {
	// Проверка Vector студентов на пустоту
	if (vector_student.empty())
		cout << endl << "Deque студентов не может быть создан, так как Vector студентов пустой." << endl << endl
			 << "Необходимо добавить данные в Vector студентов." << endl << endl;
	else {
		try {
			// Очиска Deque студентов
			deque_student.clear();

			// Добавление студентов из Vector с чётным возрастом в конец Deque, а с нечётным — в начало
			for (const auto& student : vector_student)
				if (student.age % 2 == 0)
					deque_student.push_back(student);
				else
					deque_student.push_front(student);

			// Вывод Deque студентов
			for (const auto& student : deque_student)
				student.print();
			cout << "Deque студентов успешно создан." << endl << endl;
		}
		catch (...) { cerr << "При конвертации Vector студентов в Deque произошла ошибка!" << endl << endl; }
	}
}

// Вывод первых 3 и последних 3 элементов из Deque
void show_3_front_3_back_deque_student() {
	// Проверка Deque студентов на пустоту
	if (deque_student.empty())
		cout << endl << "Deque студентов пустой. Необходимо создать его." << endl << endl;
	else {
		try {
			deque<Student> deque_student_copy = deque_student;

			// Вывод первые 3 элемента (или меньше)
			size_t n1 = deque_student_copy.size() < 3 ? deque_student_copy.size() : 3;
			if (deque_student_copy.size() <= 3)
				cout << "В Deque всего " << n1 << " элемент" << (n1 == 1 ? "" : "а") << ":";
			else
				cout << "Первые 3 элемента Deque:";
			cout << endl << endl;

			// Вывод
			for (int i = 0; i < n1; i++) {
				deque_student_copy.front().print();
				deque_student_copy.pop_front();
			}
			cout << endl;

			// Вывод 3 последних элемента (или меньше)
			size_t n2 = deque_student_copy.size() < 3 ? deque_student_copy.size() : 3;
			if (!deque_student_copy.empty()) {
				if (deque_student_copy.size() <= 3)
					cout << "Оставши" << (n2 == 1 ? "йся" : "еся") << " " << n2 << " элемент" << (n2 == 1 ? "" : "а") << ":";
				else
					cout << "Последние 3 элемента Deque:";
				cout << endl << endl;

				// Вывод
				for (int i = 0; i < n2; i++) {
					deque_student_copy.back().print();
					deque_student_copy.pop_back();
				}
			}

			if (n1 == 1)
				cout << "Был выведен [1] единственный элемент." << endl << endl;
			else if (n1 > 1 && n2 == 0)
				cout << "Было выведено [" << n1 << "] элемента." << endl << endl;
			else if (n1 > 1 && n2 == 1)
				cout << "Было выведено [" << n1 << "] первых элемента и [1] последний." << endl << endl;
			else
				cout << "Было выведено [" << n1 << "] первых элемента и [" << n2 << "] последних." << endl << endl;

		} catch (...) { cerr << "При выводе первых 3 и последних 3 элементов из Deque произошла ошибка!" << endl << endl; }
	}
}

#endif // !KONDAKOV_LR1_STUDENT_DEQUE_H