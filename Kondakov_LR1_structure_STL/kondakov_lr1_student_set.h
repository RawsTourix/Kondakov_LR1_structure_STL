#ifndef KONDAKOV_LR1_STUDENT_SET_H
#define KONDAKOV_LR1_STUDENT_SET_H

#include "kondakov_lr1_student_def.h"

using namespace std;

// ��������� Map(������������� ���: { ������ �������� ������ })
// ��� �������� �� ������������� �����
static map< string, vector<int> > get_names_map() {
	map< string, vector<int> > names_map; // name: { ids }
	for (const auto& student : vector_student)
		names_map[student.name].push_back(student.id);
	return names_map;
}

void convert_vector_to_set() {
	// �������� Vector ������� �������� ������ �� �������
	if (vector_student.empty())
		cout << endl << "Set ��������� �� ����� ���� ������, ��� ��� Vector ��������� ������." << endl << endl
			 << "���������� �������� ������ � Vector ���������." << endl << endl;
	else {
		try {
			// �������� Vector ��������� �� ������������� �����
			map< string, vector<int> > names_map = get_names_map();
			for (auto it = names_map.begin(); it != names_map.end(); )
				if (it->second.size() < 2)
					it = names_map.erase(it);
				else
					++it;
			if (names_map.empty())
				cout << "������������� ��� � Vector ��������� �� ����������." << endl << endl;
			else {
				cout << "���������� ������������� ����� � Vector ���������:" << endl << endl;

				// ����� ������������� ��� � ����������� ���������� � �������� �������� ������
				for (const auto& name_info : names_map) {
					cout << "���: " << name_info.first << endl;
					cout << "���������� ����������: " << name_info.second.size() << endl;
					cout << "������ �������� ������: ";
					copy(name_info.second.begin(), name_info.second.end(), ostream_iterator<int>(cout, ", "));
					cout << endl << endl;
				}
			}
		} catch (...) { cerr << "�������� ������ ��� �������� �� ������������� ����� � Vector ���������!" << endl << endl; }

		try {
			// ������� Set ������� �������� ������ ���������
			set_id_student.clear();

			// ���������� � Set ������� �������� ������ �� Vector
			for (const auto& student : vector_student)
				set_id_student.insert(student.id);
			cout << "Set ������� �������� ������ ��������� ������� ������." << endl << endl;

			// ��������� ���������� ��������� � Vector � Set
			cout << "���������� ��������� � Set ������� �������� ������ ��������� ("
				<< set_id_student.size() << ") � � Vector ��������� ("
				<< vector_student.size() << ") "
				<< (set_id_student.size() == vector_student.size() ? "���������." : "����������!")
				<< endl << endl;

			// ����� Set ������� �������� ������ ���������
			cout << "Set ������� �������� ������ ���������: ";
			for (auto it = set_id_student.begin(); it != set_id_student.end(); it++)
				cout << (it == set_id_student.begin() ? "" : ", ") << *it;
			cout << endl;
		}
		catch (...) { cerr << "��� ����������� Vector ��������� � Stack ��������� ������!" << endl << endl; }
	}
}

// ����� �� ������ �������� ������
void search_set_id_student() {
	int id;
	bool escape = false;

	// �������� Set ������� �������� ������ �� �������
	if (set_id_student.empty())
		cout << endl << "Set ������� �������� ������ ������. ����� ��� ������" << endl << endl;
	else {
		try {
			enter_number(id, escape, "����� �������� ������ ��������: ")();
			cout << endl;
			if (!escape) {
				if (set_id_student.find(id) == set_id_student.end())
					cout << "����� �������� ������ \"" << id << "\" � Set �� ������." << endl << endl;
				else {
					cout << "����� �������� ������ \"" << id << "\" � Set ������." << endl << endl;
					auto it = find_if(vector_student.begin(), vector_student.end(), [&](Student student) { return student.id == id; });
					if (it == vector_student.end())
						cout << "������� � ����� ������� �������� ������ � Vector �� ������." << endl << endl;
					else {
						cout << "�������:" << endl;
						it->print();
					}
				}
			}
		} catch (...) { cerr << "�������� ������ ��� ������ ������� � Set �� ������ �������� ������!" << endl << endl; }
	}
}

#endif // !KONDAKOV_LR1_STUDENT_SET_H