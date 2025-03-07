#ifndef KONDAKOV_LR1_STUDENT_MAP_H
#define KONDAKOV_LR1_STUDENT_MAP_H

#include "kondakov_lr1_student_def.h"

using namespace std;

void convert_vector_to_map() {
	// Проверка Vector студентов на пустоту
	if (vector_student.empty())
		cout << endl << "Map студентов не может быть создан, так как Vector студентов пустой." << endl << endl
			 << "Необходимо добавить данные в Vector студентов." << endl << endl;
	else {
		try {
			// Очистка Map студентов
			map_student.clear();

			// Заполнение Map студентов из Vector
			// Ключ = возраст + номер зачётной книжки
			for (const auto& student : vector_student)
				map_student.emplace(student.age + student.id, student);

			// Вывод Map студентов
			for (const auto& student : map_student) {
				cout << "[" << student.first << "]:" << endl << endl; student.second.print(); cout << endl;
			}
			cout << "Map студентов успешно создан." << endl << endl;
		}
		catch (...) { cerr << "При конвертации Vector студентов в Map произошла ошибка!" << endl << endl; }
	}
}

// Поиск по номеру зачётной книжки
void search_map_student() {
	int id;
	bool escape = false;

	// Проверка Map студентов на пустоту
	if (map_student.empty())
		cout << endl << "Map нет ни одного студента. Поиск был отменён." << endl << endl;
	else {
		// Поиск и вывод
		try {
			enter_number(id, escape, "Номер зачётной книжки студента: ")();
			cout << endl;
			if (!escape) {
				auto it = find_if(map_student.begin(), map_student.end(), [&](pair<int, Student> student) { return student.second.id == id; });
				if (it == map_student.end())
					cout << "Студент с номером зачётной книжки \"" << id << "\" не найден." << endl << endl;
				else {
					cout << "Студент с номером зачётной книжки \"" << id << "\" найден:" << endl << endl;
					it->second.print();
				}
			}
		} catch (...) { cerr << "Возникла ошибка при поиске студена в Map по номеру зачётной книжки!" << endl << endl; }
	}
}

#endif // !KONDAKOV_LR1_STUDENT_MAP_H