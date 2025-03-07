#include "kondakov_lr1_student_def.h"
#include "kondakov_lr1_student_vector.h"
#include "kondakov_lr1_student_list.h"
#include "kondakov_lr1_student_deque.h"
#include "kondakov_lr1_student_map.h"
#include "kondakov_lr1_student_set.h"
#include "kondakov_lr1_student_stack.h"

// Путь к файлу БД
const string file_name1 = "bd1.txt";

// Структура меню
struct MenuItem {
	string title;				// название пункта меню
	function<void()> action;	// действие, выполняемое при выборе пункта
};

// Функция для вывода меню
static function<void()> show_menu(const std::map<int, MenuItem>& menu) {
	return [menu]() {
		std::cout << "Меню:" << endl;

		for (const auto& item : menu) {
			std::cout << item.first << ". " << item.second.title << std::endl;
		}

		std::cout << "0. Выход" << std::endl << std::endl;
	};
}

int main() {
	setlocale(LC_ALL, "Russian");

	std::map<int, MenuItem> menu = {
		{ 1, { "Создать Vector студентов из БД;", load_students_to_vector(file_name1) } },
		{ 2, { "Вывести Vector студентов;", show_vector_student } },
		{ 3, { "Добавить студента в Vector;", add_student_to_vector } },
		{ 4, { "Отсортировать Vector студентов по возрастанию 1-й оценки;", sort_vector_student } },
		{ 5, { "Удалить всех студентов из Vector;", clear_vector_student } },
		{ 6, { "Создать List студентов, вставить студента перед каждым элементом с возрастом > 21 и вывести его;", convert_vector_to_list } },
		{ 7, { "Удалить из List всех студентов старше 20 лет;", delete_students_from_list } },
		{ 8, { "Добавить нового студента в середину List;", add_student_to_list } },
		{ 9, { "Создать Deque студентов, добавить студентов с нечётным возрастом в начало, остальных – в конец и вывести;", convert_vector_to_deque } },
		{ 10, { "Вывести первые 3 и последние 3 элемента Deque;", show_3_front_3_back_deque_student } },
		{ 11, { "Создать Map студентов, где ключ – сумма возраста и id и вывести его;", convert_vector_to_map } },
		{ 12, { "Найти студента по номеру зачётной книжки в Map и вывести его данные;", search_map_student } },
		{ 13, { "Создать Set с номерами зачётных книжек студентов, убедиться, что все имена в Vector студентов уникальны;", convert_vector_to_set } },
		{ 14, { "Проверить, содержит ли Set номер зачетной книжки конкретного студента, и вывести информацию о нём;", search_set_id_student } },
		{ 15, { "Создать Stack студентов, добавить студентов в обратном порядке и вывести;", convert_vector_to_stack } },
		{ 16, { "Извлечь элементы из Stack, пока не останется 3 студента.", show_last_3_stack_student } },

	};

	int choice = 0;
	bool escape = false;

	// Выбор пункта меню
	
	cout << "[Примечание: для отмены выбранного вами действия оставьте ввод пустым и нажмите Enter]" << endl << endl;
	while (true) {
		// Вывод меню
		show_menu(menu)();

		// Ввод пункта меню в переменную choice
		enter_number(choice, escape, "Введите номер пункта: ")();
		cout << endl;
		if (!escape) {
			// Завершение программы при choice == 0
			if (choice == 0) {
				std::cout << "© 2025 Fedor Kondakov" << std::endl;
				break;
			}

			std::cout << std::endl;

			// Проверка на существование выбранного пункта меню
			if (menu.find(choice) != menu.end()) {
				menu[choice].action();
			}
			else {
				std::cout << "Некорректный ввод!" << std::endl;
			}
		}

		escape = false;
		std::cout << std::endl << std::endl;
	}

	return 0;
}