#include "StudentDatabase.hpp"
#include <math.h>

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

	if (num_students >= 3){
		balance();
	}

	return true;
}

void StudentDatabase::place(BSTNode* current, BSTNode* newbie){
	// needs to go left
	if (newbie->getData()->getID() < current->getData()->getID() and current->getLeft() != nullptr){
		place(current->getLeft(), newbie);
	}
	// found setLeft place
	else if (newbie->getData()->getID() < current->getData()->getID() and current->getLeft() == nullptr){
		current->setLeft(newbie);
	}
	// needs to go right
	else if (newbie->getData()->getID() >= current->getData()->getID() and current->getRight() != nullptr){
		place(current->getRight(), newbie);
	}
	// found setRight place
	else if (newbie->getData() >= current->getData() and current->getRight() == nullptr){
		current->setRight(newbie);
	}
}

bool StudentDatabase::deleteBy(int studentID){
	BSTNode* previous = nullptr;
	BSTNode* current = root;

	std::cout << "root is " << root->getData()->getID() << std::endl;
	std::cout << "to delete " << studentID << std::endl;

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

BSTNode* StudentDatabase::min_node(BSTNode* current){
	while (current and current->getLeft() != nullptr)
		current = current->getLeft();

	return current;
}

void StudentDatabase::delete_current(BSTNode* previous, BSTNode* current){
	// delete root
	if (previous == nullptr){
		// leaf current
		if(current->getLeft() == nullptr and current->getRight() == nullptr){
			root = nullptr;
		}
		// current only has left child
		else if(current->getRight() == nullptr){
			root = current->getLeft();
		}
		// current only has right child
		else if (current->getLeft() == nullptr){
			root = current->getRight();
		}
		else{
			BSTNode* to_swap = min_node(current->getRight());
			root = to_swap;
			delete to_swap;
		}
		delete current;
	}
	// current is previous right child
	else if (previous->getRight() == current){
		//leaf current
		if (current->getLeft() == nullptr and current->getRight() == nullptr){
			previous->setRight(nullptr);
		}
		//current only has left child
		else if (current->getRight() == nullptr){
			previous->setRight(current->getLeft());
		}
		// current only has right child
		else if (current->getLeft() == nullptr){
			previous->setRight(current->getLeft());
		}
		// current has both children
		else {
			// current is right child
			if (previous->getRight() == current){
				relink(previous, current, min_node(current->getRight()));
				return;
			}
			// current is left child
			else {
				relink(previous, current, min_node(current->getRight()));
				return;
			}
		}
		delete current;
	}
	//current is previous left child
	else{
		//leaf current
		if (current->getLeft() == nullptr and current->getRight() == nullptr){
			previous->setLeft(nullptr);
		}
		//current only has left child
		else if (current->getRight() == nullptr){
			previous->setLeft(current->getLeft());
		}
		// current only has right child
		else if (current->getLeft() == nullptr){
			previous->setLeft(current->getLeft());
		}
		else {
			// current is right child
			if (previous->getRight() == current){
				relink(previous, current, min_node(current->getRight()));
				return;
			}
			// current is left child
			else {
				std::cout << "previous is " << previous->getData()->getID() << std::endl;
				std::cout << "current is " << current->getData()->getID() << std::endl;
				std::cout << "min node is " << min_node(current->getRight())->getData()->getID() << std::endl;
				relink(previous, current, min_node(current->getRight()));
				return;
			}
		}
		delete current;
	}
}

void StudentDatabase::relink(BSTNode* previous, BSTNode* current, BSTNode* to_swap){
	//to_swap always a leaf
	if (to_swap != nullptr){
		Student* s_temp = new Student(*(to_swap->getData()));
		BSTNode* temp = new BSTNode(s_temp);
		temp->setRight(current->getRight());
		temp->setLeft(current->getLeft());
		delete to_swap;
		to_swap = temp;
		temp = nullptr;
	} 

	//find where to_swap can replace current
	if(previous->getRight() == current){
		previous->setRight(to_swap);
	}
	else{
		previous->setLeft(to_swap);
	}

	std::cout << toStringInOrder() << std::endl;

	delete current;
}

void StudentDatabase::balance(){
	BSTNode* pseudoroot;
	pseudoroot->setRight(root);
	tree_to_vine(pseudoroot);
	vine_to_tree(pseudoroot, double(num_students));
	root = pseudoroot->getRight();
	pseudoroot = nullptr;
}

BSTNode* StudentDatabase::rightRotate(BSTNode* current){
	BSTNode* to_move = current->getLeft();
	current->setLeft(to_move->getRight());
	to_move->setRight(current);
	return to_move;
}

BSTNode* StudentDatabase::leftRotate(BSTNode* current){
	BSTNode* to_move = current->getRight();
	current->setRight(to_move->getLeft());
	to_move->setLeft(current);
	return to_move;
}

void StudentDatabase::tree_to_vine(BSTNode* root){
	BSTNode* tail = root;
	BSTNode* rest = tail->getRight();

	while (rest != nullptr){
		// continue
		if (rest->getLeft() == nullptr){
			tail = rest;
			rest = rest->getRight();
		}
		// if there is left child, rotate right
		else{
			BSTNode* temp = rest->getLeft();
			rest->setLeft(temp->getRight());
			temp->setRight(rest);
			rest = temp;
			tail->setRight(temp);
		}
	}
}

void StudentDatabase::vine_to_tree(BSTNode* root, double size){
	double leaves = size + 1 - pow(2,(log2(size + 1)));
	compress(root, leaves);
	size = size - leaves;
	while (size > 1){
		compress(root, (size/2));
		size = size/2;
	}
}

void StudentDatabase::compress(BSTNode* root, double count){
	BSTNode* scanner = root;
	for (double i = double(1); i < count; i++){
		BSTNode* child = scanner->getRight();
		scanner->setRight(child->getRight());
		scanner = scanner->getRight();
		child->setRight(scanner->getLeft());
		scanner->setLeft(child);
	}
}

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