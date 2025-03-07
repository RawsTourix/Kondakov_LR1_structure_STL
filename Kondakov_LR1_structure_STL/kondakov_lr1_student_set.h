#ifndef KONDAKOV_LR1_STUDENT_SET_H
#define KONDAKOV_LR1_STUDENT_SET_H

#include "kondakov_lr1_student_def.h"

using namespace std;

// Получение Map(Повторяющееся имя: { Номера зачётных книжек })
// Для проверки на повторяющиеся имена
static map< string, vector<int> > get_names_map() {
	map< string, vector<int> > names_map; // name: { ids }
	for (const auto& student : vector_student)
		names_map[student.name].push_back(student.id);
	return names_map;
}

void convert_vector_to_set() {
	// Проверка Vector номеров зачётных книжек на пустоту
	if (vector_student.empty())
		cout << endl << "Set студентов не может быть создан, так как Vector студентов пустой." << endl << endl
			 << "Необходимо добавить данные в Vector студентов." << endl << endl;
	else {
		try {
			// Проверка Vector студентов на повторяющиеся имена
			map< string, vector<int> > names_map = get_names_map();
			for (auto it = names_map.begin(); it != names_map.end(); )
				if (it->second.size() < 2)
					it = names_map.erase(it);
				else
					++it;
			if (names_map.empty())
				cout << "Повторяющихся имён в Vector студентов не обнаружено." << endl << endl;
			else {
				cout << "Обнаружены повторяющиеся имена в Vector студентов:" << endl << endl;

				// Вывод повторяющихся имён с количеством повторений и номерами зачётных книжек
				for (const auto& name_info : names_map) {
					cout << "Имя: " << name_info.first << endl;
					cout << "Количество повторений: " << name_info.second.size() << endl;
					cout << "Номера зачётных книжек: ";
					copy(name_info.second.begin(), name_info.second.end(), ostream_iterator<int>(cout, ", "));
					cout << endl << endl;
				}
			}
		} catch (...) { cerr << "Возникла ошибка при проверке на повторяющиеся имена в Vector студентов!" << endl << endl; }

		try {
			// Очистка Set номеров зачётных книжек студентов
			set_id_student.clear();

			// Добавление в Set номеров зачётных книжек из Vector
			for (const auto& student : vector_student)
				set_id_student.insert(student.id);
			cout << "Set номеров зачётных книжек студентов успешно создан." << endl << endl;

			// Сравнение количества элементов в Vector и Set
			cout << "Количество элементов в Set номеров зачётных книжек студентов ("
				<< set_id_student.size() << ") и в Vector студентов ("
				<< vector_student.size() << ") "
				<< (set_id_student.size() == vector_student.size() ? "совпадает." : "отличается!")
				<< endl << endl;

			// Вывод Set номеров зачётных книжек студентов
			cout << "Set номеров зачётных книжек студентов: ";
			for (auto it = set_id_student.begin(); it != set_id_student.end(); it++)
				cout << (it == set_id_student.begin() ? "" : ", ") << *it;
			cout << endl;
		}
		catch (...) { cerr << "При конвертации Vector студентов в Stack произошла ошибка!" << endl << endl; }
	}
}

// Поиск по номеру зачётной книжки
void search_set_id_student() {
	int id;
	bool escape = false;

	// Проверка Set номеров зачётных книжек на пустоту
	if (set_id_student.empty())
		cout << endl << "Set номеров зачётных книжек пустой. Поиск был отменён" << endl << endl;
	else {
		try {
			enter_number(id, escape, "Номер зачётной книжки студента: ")();
			cout << endl;
			if (!escape) {
				if (set_id_student.find(id) == set_id_student.end())
					cout << "Номер зачётной книжки \"" << id << "\" в Set не найден." << endl << endl;
				else {
					cout << "Номер зачётной книжки \"" << id << "\" в Set найден." << endl << endl;
					auto it = find_if(vector_student.begin(), vector_student.end(), [&](Student student) { return student.id == id; });
					if (it == vector_student.end())
						cout << "Студент с таким номером зачётной книжки в Vector не найден." << endl << endl;
					else {
						cout << "Студент:" << endl;
						it->print();
					}
				}
			}
		} catch (...) { cerr << "Возникла ошибка при поиске студена в Set по номеру зачётной книжки!" << endl << endl; }
	}
}

#endif // !KONDAKOV_LR1_STUDENT_SET_H