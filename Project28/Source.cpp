/*
Моя попытка выполнить задание по структурам) 

Дан пофамильный список учеников с указанием:
пола, роста, веса и номера класса.
Индекс массы тела (ИМТ) определяется :
отношение массы тела в килограммах к квадрату роста в метрах.
Для каждого класса определить детей с наименьшим значением ИМТ.

Приступил к работе: 11.09.20 - 23:30
Закончил работу:    12.09.20 - 07:05
*/

#include<iostream>
#include<string>

using namespace std;

struct Person {
	string surname;

	char floor;				//пол

	double	growth;			//рост в метрах

	int	weight;				//вес в кг
	int class_number;		//номер класса

	double Body_mass_index;	//Индекс массы тела
};

//Для вывод всего списка
void Get_all (Person* b, int m) {
	for (int i = 0; i < m; i++){
		cout << "Surname " << b[i].surname << endl;
		cout << "Body mass index = " << b[i].Body_mass_index << endl;
		cout << "Class number " << b[i].class_number << endl;

	}

}

//вывод конкретного ученика
void Get_info(Person a) {
	cout << "Ученик "<< a.class_number<<"-го класса с самым низким И.М.Т." << endl;
	cout << "Фамилия: " << a.surname << endl;
	cout << "Пол: " << a.floor << endl;
	cout << "Индекс массы тела = " << a.Body_mass_index << endl << endl;
	
}

//Пузырьковая cортировка по индексу массы тела
Person Sort_body_mass_index(Person* p, int var, int size) {
	for (int i = var; i < size; i++){
		for (int j = var; j < size-1; j++){

			//Сравниваем индекс массы тела, если p[j] меньше p[j+1] делаем обмен
			if (p[j].Body_mass_index < p[j+1].Body_mass_index) {
				Person temp = p[j];	//"временная" переменная для обмена

				p[j] = p[j + 1];
				p[j + 1] = temp;
			}

		}

	}

	return p[size-1];	//Вернуть последний наименьший элемент структуры

}

//Пузырьковая cортировка по номеру класса
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
	setlocale(0, "");	//Поддержка русского языка в консоли

	int const SIZE = 12;

	//массив структур
	Person apprentice[SIZE]{
		{"Комаров",  'М', 1.43, 59, 7, 0},
		{"Комарова", 'Ж', 1.98, 64, 9, 0},
		{"Карпова",  'Ж', 1.44, 62, 8, 0},
		{"Рыбакова", 'Ж', 1.41, 79, 7, 0},
		{"Жукова",   'Ж', 1.58, 61, 8, 0},
		{"Карпов",   'М', 1.70, 77, 9, 0},
		{"Федотова", 'Ж', 1.40, 56, 7, 0},
		{"Смирнов",  'М', 1.92, 64, 9, 0},
		{"Лазарева", 'Ж', 1.81, 69, 9, 0},
		{"Соболев",  'М', 1.62, 61, 8, 0},
		{"Фролова",  'Ж', 1.60, 61, 8, 0},
		{"Рыбаков",  'М', 1.36, 53, 7, 0}

	};

	//Расчёт Индекса массы тела всех учеников(Body_mass_index)
	for (int i = 0; i < SIZE; i++) {
		apprentice[i].Body_mass_index = apprentice[i].weight / pow(apprentice[i].growth, 2);

	}
	
	//Вывести весь не сортированный список 
	//Get_all(apprentice, SIZE);

	//сортировка по классам от старших к младшим
	Sort_number_class(apprentice, SIZE);
	
	int i = 0;		//Внешняя переменная счётчика начала циклов
	int iter = 0;	//Начало итераций списка

	//идём по списку и ищем количество учеников из 9 класса 
	for (; i < SIZE; ){
		//Ищем кол-во учеников из 9 класса
		if (apprentice[i].class_number == 9) i++;
		
		//Выход если совпадений больше нет
		else break;
	
	}
	
	int temp = i;	//сохраняем последний цикл чтобы в дургом цикле не начинать с нуля
	
	//Ученик 9 класса с наименьшим индексом массы тела
	Person student_9th_class_with_the_smallest_BMI;	
	
	//из сортированной структуры забираем структуру с наименьшим И.М.Т
	student_9th_class_with_the_smallest_BMI = Sort_body_mass_index(apprentice, iter, temp);
	
	//Вывод на экран
	Get_info(student_9th_class_with_the_smallest_BMI);

	int j = temp;	//Перенос кол-ва циклов для продолжения хода по списку не проходя минувшие циклы
	
	//2-й цикл где отбираем учеников 8 класса
	//Продолжая идти по списку с того момента где закончили в прошлом цикле
	for (; j < SIZE; ){
		if (apprentice[j].class_number == 8) j++;

		else break;
		
	}

	//Ученик 8 класса с наименьшим индексом массы тела
	Person student_8th_class_with_the_smallest_BMI;	

	//Из сортированной структуры забираем структуру с наименьшим И.М.Т
	//temp передаёт номер позиции с которой мы закончили прошлый цикл
	//Идем с temp = 3 до j = 6
	student_8th_class_with_the_smallest_BMI = Sort_body_mass_index(apprentice, temp, j);

	//Вывод на экран
	Get_info(student_8th_class_with_the_smallest_BMI);

	temp = j;	//Сохранение конца прошлого цикла
	int x = j;	//внешняя переменная счётчика

	//3-й цикл где отбираем учеников 7 класса
	//Продолжая идти по списку с того момента где закончили в прошлом цикле
	for (; x < SIZE; ) {
		if (apprentice[x].class_number == 7) x++;

		else break;

	}

	//Ученик 7 класса с наименьшим индексом массы тела
	Person student_7th_class_with_the_smallest_BMI;

	//Из сортированной структуры забираем структуру с наименьшим И.М.Т
	//temp передаёт номер позиции с которой мы закончили прошлый цикл
	//Идем с temp = 6 до x = 9
	student_7th_class_with_the_smallest_BMI = Sort_body_mass_index(apprentice, temp, x);

	//Вывод на экран
	Get_info(student_7th_class_with_the_smallest_BMI);

	//Вывести весь сортированный список 
	//Get_all(apprentice, SIZE);

		system("pause");

		return 0;

	}