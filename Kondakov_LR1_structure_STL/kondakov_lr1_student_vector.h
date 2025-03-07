#ifndef KONDAKOV_LR1_STUDENT_VECTOR_H // защита от повторного включения
#define KONDAKOV_LR1_STUDENT_VECTOR_H

#include "kondakov_lr1_student_def.h"

using namespace std;

function<void()> load_students_to_vector(string filename) {
	return [filename]() {
		ifstream file(filename);
		if (!file.is_open()) {
			cerr << "Возникла ошибка при открытии файла: " << filename << endl;
		}
		vector_student.clear();
		string line = "";
		string err = "";
		try {
			// Деструктор вызовет эту лямбда-функцию при выходе из try-catch
			// Аналог finally
			Finally finally([] { cout << endl << endl; });

			while (getline(file, line)) {
				stringstream ss(line);
				string name, surname, id_str, age_str;
				int id, age;
				vector<int> grades;

				// Чтение имени, фамилии, номера зачётной книжки и возраста
				err = "Имя (name)";
				getline(ss, name, ',');
				trim(name);

				err = "Фамилия (surname)";
				getline(ss, surname, ',');
				trim(surname);

				err = "Номер записи в зачётной книжке (id)";
				getline(ss, id_str, ',');
				id = stoi(id_str);

				err = "Возраст (age)";
				getline(ss, age_str, ',');
				age = stoi(age_str);

				// Чтение оценок
				err = "Оценки (grades)";
				string grade;
				while (getline(ss, grade, ','))
					grades.push_back(stoi(grade));

				// Добавление студента в конец вектора
				vector_student.emplace_back(name, surname, id, age, grades);
			}
			cout << "Vector студентов успешно создан.";
			file.close();
		}
		catch (...) {
			cerr << "Ошибка при создании Vector студентов!" << endl;
			if (err == "") {
				cerr << "Дополнительная информация об ошибке отсутствует.";
			} else {
				cerr << "Проверьте поле: " << err << ".";
			}
			vector_student.clear();
		}
	};
}

// Функтор сравнения оценок студентов
struct compare_grades {
	inline bool operator() (const Student& student1, const Student& student2) {
		return student1.grades[0] < student2.grades[0];
	}
};

// Вывод вектора vector_student
void show_vector_student() {
	if (vector_student.empty())
		cout << endl << "Vector студентов пустой. Необходимо создать его." << endl << endl;
	else {
		for (const auto& student : vector_student)
			student.print();
		cout << "Vector студентов выведен." << endl << endl;
	}
}

// Сортировка студентов по первой оценке
void sort_vector_student() {
	if (vector_student.empty())
		cout << endl << "Vector студентов пустой. Необходимо создать его." << endl << endl;
	else {
		try {
			// Сортировка по первой оценке
			sort(vector_student.begin(), vector_student.end(), compare_grades());
			// Вывод Vector студентов
			for (const auto& student : vector_student)
				student.print();
			cout << "Vector студентов успешно отсортирован." << endl << endl;
		}
		catch (...) { cerr << "При сортировке Vector студентов возникла ошибка!" << endl << endl; }
	}
}

// Добавление студента в вектор
void add_student_to_vector() {
	cout << "Добавление студента в Vector:" << endl;
	Student student = new_student();
	
	if (student) {
		try {
			vector_student.emplace_back(student);
			student.print();
			cout << "Студент успешно добавлен в Vector студентов." << endl << endl;
		} catch (...) { cout << "Студент не был добавлен в Vector студентов вследствие ошибки." << endl
			<< "Проверьте правильность введённых данных." << endl << endl; }
	}
	else cout << "Студент не был добавлен в Vector студентов, так как операция была отменена." << endl << endl;
}

// Удаление всех студентов из Vector
void clear_vector_student() {
	if (vector_student.empty())
		cout << endl << "Vector студентов и так пустой." << endl << endl;
	else {
		try {
			vector_student.clear();
			cout << endl << "Все данные из Vector студентов были удалены." << endl << endl;
		}
		catch (...) { cerr << "При удалении данных из Vector студентов возникла ошибка!" << endl << endl; }
	}
}

#endif // !KONDAKOV_LR1_STUDENT_DEF_H