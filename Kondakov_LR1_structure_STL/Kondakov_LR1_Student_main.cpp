#include "kondakov_lr1_student_def.h"
#include "kondakov_lr1_student_vector.h"
#include "kondakov_lr1_student_list.h"
#include "kondakov_lr1_student_deque.h"
#include "kondakov_lr1_student_map.h"
#include "kondakov_lr1_student_set.h"
#include "kondakov_lr1_student_stack.h"

// ���� � ����� ��
const string file_name1 = "bd1.txt";

// ��������� ����
struct MenuItem {
	string title;				// �������� ������ ����
	function<void()> action;	// ��������, ����������� ��� ������ ������
};

// ������� ��� ������ ����
static function<void()> show_menu(const std::map<int, MenuItem>& menu) {
	return [menu]() {
		std::cout << "����:" << endl;

		for (const auto& item : menu) {
			std::cout << item.first << ". " << item.second.title << std::endl;
		}

		std::cout << "0. �����" << std::endl << std::endl;
	};
}

int main() {
	setlocale(LC_ALL, "Russian");

	std::map<int, MenuItem> menu = {
		{ 1, { "������� Vector ��������� �� ��;", load_students_to_vector(file_name1) } },
		{ 2, { "������� Vector ���������;", show_vector_student } },
		{ 3, { "�������� �������� � Vector;", add_student_to_vector } },
		{ 4, { "������������� Vector ��������� �� ����������� 1-� ������;", sort_vector_student } },
		{ 5, { "������� ���� ��������� �� Vector;", clear_vector_student } },
		{ 6, { "������� List ���������, �������� �������� ����� ������ ��������� � ��������� > 21 � ������� ���;", convert_vector_to_list } },
		{ 7, { "������� �� List ���� ��������� ������ 20 ���;", delete_students_from_list } },
		{ 8, { "�������� ������ �������� � �������� List;", add_student_to_list } },
		{ 9, { "������� Deque ���������, �������� ��������� � �������� ��������� � ������, ��������� � � ����� � �������;", convert_vector_to_deque } },
		{ 10, { "������� ������ 3 � ��������� 3 �������� Deque;", show_3_front_3_back_deque_student } },
		{ 11, { "������� Map ���������, ��� ���� � ����� �������� � id � ������� ���;", convert_vector_to_map } },
		{ 12, { "����� �������� �� ������ �������� ������ � Map � ������� ��� ������;", search_map_student } },
		{ 13, { "������� Set � �������� �������� ������ ���������, ���������, ��� ��� ����� � Vector ��������� ���������;", convert_vector_to_set } },
		{ 14, { "���������, �������� �� Set ����� �������� ������ ����������� ��������, � ������� ���������� � ��;", search_set_id_student } },
		{ 15, { "������� Stack ���������, �������� ��������� � �������� ������� � �������;", convert_vector_to_stack } },
		{ 16, { "������� �������� �� Stack, ���� �� ��������� 3 ��������.", show_last_3_stack_student } },

	};

	int choice = 0;
	bool escape = false;

	// ����� ������ ����
	
	cout << "[����������: ��� ������ ���������� ���� �������� �������� ���� ������ � ������� Enter]" << endl << endl;
	while (true) {
		// ����� ����
		show_menu(menu)();

		// ���� ������ ���� � ���������� choice
		enter_number(choice, escape, "������� ����� ������: ")();
		cout << endl;
		if (!escape) {
			// ���������� ��������� ��� choice == 0
			if (choice == 0) {
				std::cout << "� 2025 Fedor Kondakov" << std::endl;
				break;
			}

			std::cout << std::endl;

			// �������� �� ������������� ���������� ������ ����
			if (menu.find(choice) != menu.end()) {
				menu[choice].action();
			}
			else {
				std::cout << "������������ ����!" << std::endl;
			}
		}

		escape = false;
		std::cout << std::endl << std::endl;
	}

	return 0;
}