#include "StudentDatabase.hpp"
#include <iostream>
#include <stdexcept>

StudentDatabase::StudentDatabase(){
	root = nullptr;
	num_students = 0;
}

// StudentDatabase::StudentDatabase(const StudentDatabase& other){

// }

StudentDatabase& StudentDatabase::operator=(const StudentDatabase& other){
	throw std::runtime_error("Not Implemented");
}

// StudentDatabase::~StudentDatabase(){

// }

const Student* StudentDatabase::searchBy(int studentID) const{
	BSTNode* current = root;

	while (current != nullptr){
		if (studentID > current->getData()->getID()){
			current = current->getRight();
		}
		else if (studentID < current->getData()->getID()){
			current = current->getLeft();
		}
		//found
		else
			return current->getData();
	}

	//not found
	return nullptr;
}

bool StudentDatabase::insert(Student* student){
	BSTNode* newbie = new BSTNode(student);

	if (isEmpty()){
		root = newbie;
		return true;
	}

	place(root, newbie);
	num_students++;

	return true;
}

void StudentDatabase::place(BSTNode* current, BSTNode* newbie){
	if (newbie->getData()->getID() < current->getData()->getID() and current->getLeft() != nullptr){
		place(current->getLeft(), newbie);
	}
	else if (newbie->getData()->getID() < current->getData()->getID() and current->getLeft() == nullptr){
		current->setLeft(newbie);
	}
	else if (newbie->getData()->getID() >= current->getData()->getID() and current->getRight() != nullptr){
		place(current->getRight(), newbie);
	}
	else if (newbie->getData() >= current->getData() and current->getRight() == nullptr){
		current->setRight(newbie);
	}
}

bool StudentDatabase::deleteBy(int studentID){
	BSTNode* previous = nullptr;
	BSTNode* current = root;

	while (current != nullptr){
		if (studentID > current->getData()->getID()){
			previous = current;
			current = current->getRight();
		}
		else if (studentID < current->getData()->getID()){
			previous = current;
			current = current->getLeft();
		}
		//found
		else{
			delete_current(previous, current);
			num_students--;
			return true;
		}
	}
	//not found
	return false;

}

void StudentDatabase::delete_current(BSTNode* previous, BSTNode* current){
	// leaf
	if(current->getLeft() == nullptr and current->getRight() == nullptr){
		delete current;
	}

	// only has left child
	else if(current->getRight() == nullptr){
		relink(previous, current, current->getLeft());
		return;
	}

	// only has right child
	else if (current->getLeft() == nullptr){
		relink(previous, current, current->getRight());
		return;
	}

	// has both children
	else{
		// current is right child
		if (previous->getRight() == current){
			relink(previous, current, current->getLeft());
			return;
		}
		// current is left child
		else {
			relink(previous, current, current->getRight());
			return;
		}
	}
}

void StudentDatabase::relink(BSTNode* previous, BSTNode* current, BSTNode* to_swap){
	BSTNode* temp;
	//copy to_swap to temp
	if (to_swap->getRight() == nullptr and to_swap->getRight() == nullptr){
		temp = new BSTNode(to_swap->getData());
	}
	//to_swap has children
	else{
		// to_swap is right child
		if (current->getRight() == to_swap){
			if(to_swap->getLeft() != nullptr){
				temp = new BSTNode(to_swap->getLeft()->getData());
				temp->setLeft(current->getLeft());
				temp->setRight(to_swap->getRight());
			}
			else{
				temp = new BSTNode(to_swap->getData());
				temp->setRight(to_swap->getRight());
			}
		}
		// to_swap is left child
		else{
			if(to_swap->getRight() != nullptr){
				temp = new BSTNode(to_swap->getRight()->getData());
				temp->setLeft(to_swap->getLeft());
				temp->setRight(current->getRight());
			}
			else{
				temp = new BSTNode(to_swap->getData());
				temp->setRight(to_swap->getRight());
			}
		}
	}

	delete to_swap;

	//find where temp can replace current
	if(previous->getRight() == current){
		previous->setRight(temp);
	}
	else{
		previous->setLeft(temp);
	}
	
	delete current;

}

// void StudentDatabase::balance(){

// }

bool StudentDatabase::isEmpty() const{
	if (root == nullptr){
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
	std::string order;

	if (current == nullptr){
		return "";
	}

	order += inOrder(current->getLeft());
	order += std::to_string(current->getData()->getID());
	order += ",";
	order += inOrder(current->getRight());

	return order;
}

// std::string StudentDatabase::toTreeString() const{

// }