#include "StudentDatabase.hpp"

StudentDatabase::StudentDatabase(){

}

StudentDatabase::StudentDatabase(const StudentDatabase& other){

}

StudentDatabase& StudentDatabase::operator=(const StudentDatabase& other){
	throw std::runtime_error("Not Implemented");
}

StudentDatabase::~StudentDatabase(){

}

const Student* searchBy(int studentID) const;
bool insert(Student* student);
bool deleteBy(int studentID);
void balance();

bool isEmpty() const;
int getNumberOfStudents() const;
std::string toStringInOrder() const;
std::string toTreeString() const;