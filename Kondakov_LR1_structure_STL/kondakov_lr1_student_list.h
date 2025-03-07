#ifndef KONDAKOV_LR1_STUDENT_LIST_H
#define KONDAKOV_LR1_STUDENT_LIST_H

#include "Kondakov_LR1_Student_def.h"

using namespace std;

void convert_vector_to_list() {
	// Проверка Vector студентов на пустоту
	if (vector_student.empty())
		cout << endl << "List студентов не может быть создан, так как Vector студентов пустой." << endl << endl
			 << "Необходимо добавить данные в Vector студентов." << endl << endl;
	else {
		try {
			// Очистка List студентов
			list_student.clear();

			// Добавление студентов из Vector старше 21 года в начало, остальных — в конец
			for (const auto& student : vector_student)
				if (student.age > 21)
					list_student.push_front(student);
				else
					list_student.push_back(student);

			// Вывод List студентов
			for (const auto& student : list_student)
				student.print();

			cout << "List студентов успешно создан." << endl << endl;
		}
		catch (...) { cerr << "При конвертации Vector студентов в List произошла ошибка!" << endl << endl; }
	}
}

// Удаление студентов с возрастом > 20
void delete_students_from_list() {
	// Проверка List студентов на пустоту
	if (list_student.empty())
		cout << endl << "В List студентов пустой. Необходимо создать его." << endl << endl;
	else {
		try {
			// Удаление студентов с возрастом > 20
			for (auto it = list_student.begin(); it != list_student.end(); )
				if (it->age > 20)
					it = list_student.erase(it);
				else
					++it;

			// Вывод List студентов
			for (const auto& student : list_student)
				student.print();
			cout << "Студенты старше 20 лет успешно удалены из List." << endl << endl;
		}
		catch (...) { cerr << "Возникла ошибка при удалении студентов из List старше 20 лет!" << endl << endl; }
	}
}

// Добавление студента в середину List
void add_student_to_list() {
	Student student = new_student();

	if (student) {
		try {
			// Вставка студента в середину List
			auto it = list_student.begin();
			advance(it, list_student.size() / 2); // Перемещение итератора в середину List
			list_student.insert(it, student);
			
			// Вывод List студентов
			for (const auto& student : list_student)
				student.print();
			cout << "Студент успешно добавлен в середину List студентов." << endl << endl;
		}
		catch (...) {
			cout << "Студент не был добавлен в середину List студентов вследствие ошибки." << endl
				 << "Проверьте правильность введённых данных." << endl << endl;
		}
	}
	else cout << "Студент не был добавлен в середину List студентов, так как операция была отменена." << endl << endl;
}

#endif // !KONDAKOV_LR1_STUDENT_LIST_H