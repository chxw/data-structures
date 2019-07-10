#include "StudentDatabase.hpp"

StudentDatabase::StudentDatabase(){
	root = nullptr;
	num_students = 0;
}

StudentDatabase::StudentDatabase(const StudentDatabase& other){

}

StudentDatabase& StudentDatabase::operator=(const StudentDatabase& other){
	throw std::runtime_error("Not Implemented");
}

StudentDatabase::~StudentDatabase(){

}

const Student* StudentDatabase::searchBy(int studentID) const{

}

bool StudentDatabase::insert(Student* student){
	if (student == nullptr){
		
	}
}

bool StudentDatabase::deleteBy(int studentID){

}

void StudentDatabase::balance(){

}

bool StudentDatabase::isEmpty() const{
	if (num_students > 0){
		return true;
	}
	return false;
}

int StudentDatabase::getNumberOfStudents() const{
	return num_students;
}

std::string StudentDatabase::toStringInOrder() const{

}

std::string StudentDatabase::toTreeString() const{

}