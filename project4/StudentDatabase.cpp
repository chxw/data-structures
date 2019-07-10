#include "StudentDatabase.hpp"

StudentDatabase::StudentDatabase(){
	root = nullptr;
	num_students = 0;
}

// StudentDatabase::StudentDatabase(const StudentDatabase& other){

// }

// StudentDatabase& StudentDatabase::operator=(const StudentDatabase& other){
// 	throw std::runtime_error("Not Implemented");
// }

// StudentDatabase::~StudentDatabase(){

// }

// const Student* StudentDatabase::searchBy(int studentID) const{

// }

bool StudentDatabase::insert(Student* student){
	BSTNode* current = new BSTNode(student);
	place(current, student->getID());
	return true;
}

BSTNode* StudentDatabase::place(BSTNode* current, int key){
	// pre-order recursive traversal

	// base case
	if (current == nullptr or current->getData()->getID() == key)
		return current;

	// if studentID to be inserted is greater, go right
	if (current->getData()->getID() < key){
		return place(current->getRight(), key);
	}
	// if studentID to be inserted is lesser, go left
	else{
		return place(current->getLeft(), key);
	}
}

// bool StudentDatabase::deleteBy(int studentID){

// }

// void StudentDatabase::balance(){

// }

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
	return inOrder(root);
}

std::string StudentDatabase::inOrder(const BSTNode* current) const{
	if (current == nullptr){
		return "";
	}

	std::string order;

	order += inOrder(current->getLeft());
	order += std::to_string(current->getData()->getID());
	order += ",";
	order += inOrder(current->getRight());

	return order;
}

// std::string StudentDatabase::toTreeString() const{

// }