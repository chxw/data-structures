#include <cassert>
#include <string>
#include <climits>
#include <stdexcept>

#include <iostream>

#include "Student.hpp"
#include "StudentDatabase.hpp"
#include "Course.hpp"
#include "CourseManager.hpp"
// #include "EnrollmentManager.hpp"

void student(){
	char ID;
	std::string fname;
	std::string lname;
	char response = 'n';

	while (true){
		std::cout << "ID?: \n";
		std::cin >> ID;
		std::cout << "First Name?: \n";
		std::cin >> fname;
		std::cout << "Last Name?:\n";
		std::cin >> lname;
		Student* student = new Student(ID, fname, lname);
		std::cout << "Add another? Enter y/n: \n";
		std::cin >> response;

		if (response == 'Y' or 'y'){
			continue;
		}
		return;
	}

}


void menu(){
	char response;

	while (true){
		std::cout << "What would you like to do? \n 1. Add student. \n 2. Add Course. \n 3. See students in Student Database. \n 4. See courses in Course Manager. \n Enter number: \n";
		std::cin >> response;

		if (response == '1'){
			student();
		}
		else if (response == '2'){

		}
		else if (response ==  '3'){

		}
		else if (response == '4'){

		}
		else {
			std::cout << "Error. Try again." << std::endl;
		}
	}
}

int main(){
	CourseManager* cm = new CourseManager();
	StudentDatabase* sd = new StudentDatabase();

	menu();

	delete cm;
	delete sd;

	return 0;
}