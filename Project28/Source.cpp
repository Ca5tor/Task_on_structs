/*
My attempt at doing  job on  structs)

A list of students is given by surname, indicating:
gender, height, weight and class number.
Body mass index (BMI) is determined by:
the ratio of body weight in kilograms to the square of height in meters.
For each grade, identify the children with the lowest BMI value.

Started to work: 09/11/20 - 23:30
Finished work: 09/12/20 - 07:05
*/

#include<iostream>
#include<string>

using namespace std;

struct Person {
	string surname;

	char floor;				

	double	growth;			//Growth in meters

	int	weight;				//Weight in kg
	int class_number;		

	double Body_mass_index;	
};

//To display the entire list
void Get_all (Person* b, int m) {
	for (int i = 0; i < m; i++){
		cout << "Surname " << b[i].surname << endl;
		cout << "Body mass index = " << b[i].Body_mass_index << endl;
		cout << "Class number " << b[i].class_number << endl;

	}

}

//Output of a specific student
void Get_info(Person a) {
	cout << "Pupil "<< a.class_number<<"-th class with the lowest I.M.T." << endl;
	cout << "Surname: " << a.surname << endl;
	cout << "Floor: " << a.floor << endl;
	cout << "Body mass index = " << a.Body_mass_index << endl << endl;
	
}

//Bubble Sort By Body Mass Index
Person Sort_body_mass_index(Person* p, int var, int size) {
	for (int i = var; i < size; i++){
		for (int j = var; j < size-1; j++){

			//Compare the body mass index, if p [j] is less than p [j + 1] make an exchange
			if (p[j].Body_mass_index < p[j+1].Body_mass_index) {
				Person temp = p[j];	//"Temporary" variable for exchange

				p[j] = p[j + 1];
				p[j + 1] = temp;
			}

		}

	}

	return p[size-1];	//Return the last smallest structure element

}

//Bubble sort by class number
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
	int const SIZE = 12;

	//Static array of structures
	Person apprentice[SIZE]{
		{"Komarov",  'M', 1.43, 59, 7, 0},
		{"Komarova", 'W', 1.98, 64, 9, 0},
		{"Karpova",  'W', 1.44, 62, 8, 0},
		{"Rybakova", 'W', 1.41, 79, 7, 0},
		{"Zhukova",  'W', 1.58, 61, 8, 0},
		{"Karpov",   'M', 1.70, 77, 9, 0},
		{"Fedotova", 'W', 1.40, 56, 7, 0},
		{"Smirnov",  'M', 1.92, 64, 9, 0},
		{"Lazareva", 'W', 1.81, 69, 9, 0},
		{"Sobolev",  'M', 1.62, 61, 8, 0},
		{"Frolova",  'W', 1.60, 61, 8, 0},
		{"Rybakov",  'M', 1.36, 53, 7, 0}

	};

	//Calculate the Body Mass Index of all students(Body_mass_index)
	for (int i = 0; i < SIZE; i++) {
		apprentice[i].Body_mass_index = apprentice[i].weight / pow(apprentice[i].growth, 2);

	}
	
	//List all unsorted list
	//Get_all(apprentice, SIZE);

	//Sort by class from highest to lowest
	Sort_number_class(apprentice, SIZE);
	
	int i = 0;		//External variable of the cycle start counter
	int iter = 0;	//Starting iterating a list

	//walking through the list and look for the number of students from grade 9
	for (; i < SIZE; ){
		//We are looking for the number of students from grade 9
		if (apprentice[i].class_number == 9) i++;
		
		//Exit if there are no more matches
		else break;
	
	}
	
	//We save the last cycle so that we do not start from scratch in the other cycle
	int temp = i;	
	
	
	//The 9th grade apprentice with the lower body mass index
	Person student_9th_class_with_the_smallest_BMI;	
	
	//From the sorted structure we take the structure with the smallest I.M.T
	student_9th_class_with_the_smallest_BMI = Sort_body_mass_index(apprentice, iter, temp);
	
	//Output on display
	Get_info(student_9th_class_with_the_smallest_BMI);

	//Transfer of the number of cycles to continue the move through
	// the list without going through the past cycles
	int j = temp;	
	
	//2nd cycle where we select students of grade 8
	//Continuing through the list from where we left off in the last loop
	for (; j < SIZE; ){
		if (apprentice[j].class_number == 8) j++;

		else break;
		
	}

	//Grade 8 student with the lowest body mass index
	Person student_8th_class_with_the_smallest_BMI;	

	//From the sorted structure, take the structure with the smallest I.M.T
	// temp gives the position number from which we ended the last cycle
	//Go from temp = 3 to j = 6
	student_8th_class_with_the_smallest_BMI = Sort_body_mass_index(apprentice, temp, j);

	//Output on display
	Get_info(student_8th_class_with_the_smallest_BMI);

	temp = j;	//Save the end of the last cycle
	int x = j;	

	//3rd cycle where we select 7th grade students
	//Continuing through the list from where we left off in the last loop
	for (; x < SIZE; ) {
		if (apprentice[x].class_number == 7) x++;

		else break;

	}

	//7th grade student with the lowest body mass index
	Person student_7th_class_with_the_smallest_BMI;

	//From the sorted structure, take the structure with the smallest I.M.T
	// temp gives the position number from which we ended the last cycle
	//Go from temp = 6 to x = 9
	student_7th_class_with_the_smallest_BMI = Sort_body_mass_index(apprentice, temp, x);

	//Output on display
	Get_info(student_7th_class_with_the_smallest_BMI);

	//Display the entire sorted list
	//Get_all(apprentice, SIZE);

		system("pause");

		return 0;

	}
