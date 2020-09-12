/*
��� ������� ��������� ������� �� ����������) 

��� ����������� ������ �������� � ���������:
����, �����, ���� � ������ ������.
������ ����� ���� (���) ������������ :
��������� ����� ���� � ����������� � �������� ����� � ������.
��� ������� ������ ���������� ����� � ���������� ��������� ���.

��������� � ������: 11.09.20 - 23:30
�������� ������:    12.09.20 - 07:05
*/

#include<iostream>
#include<string>

using namespace std;

struct Person {
	string surname;

	char floor;				//���

	double	growth;			//���� � ������

	int	weight;				//��� � ��
	int class_number;		//����� ������

	double Body_mass_index;	//������ ����� ����
};

//��� ����� ����� ������
void Get_all (Person* b, int m) {
	for (int i = 0; i < m; i++){
		cout << "Surname " << b[i].surname << endl;
		cout << "Body mass index = " << b[i].Body_mass_index << endl;
		cout << "Class number " << b[i].class_number << endl;

	}

}

//����� ����������� �������
void Get_info(Person a) {
	cout << "������ "<< a.class_number<<"-�� ������ � ����� ������ �.�.�." << endl;
	cout << "�������: " << a.surname << endl;
	cout << "���: " << a.floor << endl;
	cout << "������ ����� ���� = " << a.Body_mass_index << endl << endl;
	
}

//����������� c��������� �� ������� ����� ����
Person Sort_body_mass_index(Person* p, int var, int size) {
	for (int i = var; i < size; i++){
		for (int j = var; j < size-1; j++){

			//���������� ������ ����� ����, ���� p[j] ������ p[j+1] ������ �����
			if (p[j].Body_mass_index < p[j+1].Body_mass_index) {
				Person temp = p[j];	//"���������" ���������� ��� ������

				p[j] = p[j + 1];
				p[j + 1] = temp;
			}

		}

	}

	return p[size-1];	//������� ��������� ���������� ������� ���������

}

//����������� c��������� �� ������ ������
void Sort_number_class(Person* p, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (p[j].class_number < p[j + 1].class_number) {
				Person temp = p[j];

				p[j] = p[j + 1];
				p[j + 1] = temp;
			}

		}

	}

}

int main() {
	setlocale(0, "");	//��������� �������� ����� � �������

	int const SIZE = 12;

	//������ ��������
	Person apprentice[SIZE]{
		{"�������",  '�', 1.43, 59, 7, 0},
		{"��������", '�', 1.98, 64, 9, 0},
		{"�������",  '�', 1.44, 62, 8, 0},
		{"��������", '�', 1.41, 79, 7, 0},
		{"������",   '�', 1.58, 61, 8, 0},
		{"������",   '�', 1.70, 77, 9, 0},
		{"��������", '�', 1.40, 56, 7, 0},
		{"�������",  '�', 1.92, 64, 9, 0},
		{"��������", '�', 1.81, 69, 9, 0},
		{"�������",  '�', 1.62, 61, 8, 0},
		{"�������",  '�', 1.60, 61, 8, 0},
		{"�������",  '�', 1.36, 53, 7, 0}

	};

	//������ ������� ����� ���� ���� ��������(Body_mass_index)
	for (int i = 0; i < SIZE; i++) {
		apprentice[i].Body_mass_index = apprentice[i].weight / pow(apprentice[i].growth, 2);

	}
	
	//������� ���� �� ������������� ������ 
	//Get_all(apprentice, SIZE);

	//���������� �� ������� �� ������� � �������
	Sort_number_class(apprentice, SIZE);
	
	int i = 0;		//������� ���������� �������� ������ ������
	int iter = 0;	//������ �������� ������

	//��� �� ������ � ���� ���������� �������� �� 9 ������ 
	for (; i < SIZE; ){
		//���� ���-�� �������� �� 9 ������
		if (apprentice[i].class_number == 9) i++;
		
		//����� ���� ���������� ������ ���
		else break;
	
	}
	
	int temp = i;	//��������� ��������� ���� ����� � ������ ����� �� �������� � ����
	
	//������ 9 ������ � ���������� �������� ����� ����
	Person student_9th_class_with_the_smallest_BMI;	
	
	//�� ������������� ��������� �������� ��������� � ���������� �.�.�
	student_9th_class_with_the_smallest_BMI = Sort_body_mass_index(apprentice, iter, temp);
	
	//����� �� �����
	Get_info(student_9th_class_with_the_smallest_BMI);

	int j = temp;	//������� ���-�� ������ ��� ����������� ���� �� ������ �� ������� �������� �����
	
	//2-� ���� ��� �������� �������� 8 ������
	//��������� ���� �� ������ � ���� ������� ��� ��������� � ������� �����
	for (; j < SIZE; ){
		if (apprentice[j].class_number == 8) j++;

		else break;
		
	}

	//������ 8 ������ � ���������� �������� ����� ����
	Person student_8th_class_with_the_smallest_BMI;	

	//�� ������������� ��������� �������� ��������� � ���������� �.�.�
	//temp ������� ����� ������� � ������� �� ��������� ������� ����
	//���� � temp = 3 �� j = 6
	student_8th_class_with_the_smallest_BMI = Sort_body_mass_index(apprentice, temp, j);

	//����� �� �����
	Get_info(student_8th_class_with_the_smallest_BMI);

	temp = j;	//���������� ����� �������� �����
	int x = j;	//������� ���������� ��������

	//3-� ���� ��� �������� �������� 7 ������
	//��������� ���� �� ������ � ���� ������� ��� ��������� � ������� �����
	for (; x < SIZE; ) {
		if (apprentice[x].class_number == 7) x++;

		else break;

	}

	//������ 7 ������ � ���������� �������� ����� ����
	Person student_7th_class_with_the_smallest_BMI;

	//�� ������������� ��������� �������� ��������� � ���������� �.�.�
	//temp ������� ����� ������� � ������� �� ��������� ������� ����
	//���� � temp = 6 �� x = 9
	student_7th_class_with_the_smallest_BMI = Sort_body_mass_index(apprentice, temp, x);

	//����� �� �����
	Get_info(student_7th_class_with_the_smallest_BMI);

	//������� ���� ������������� ������ 
	//Get_all(apprentice, SIZE);

		system("pause");

		return 0;

	}