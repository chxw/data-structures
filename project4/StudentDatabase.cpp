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
		else{
			return current->getData();
		}
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
	if (searchBy(studentID) == nullptr){
		return false;
	}

	root = delete_current(studentID, root, nullptr);
	return true;
}

BSTNode* StudentDatabase::delete_current(int key, BSTNode* current, BSTNode* previous){
	if (key < current->getData()->getID()){
		current = delete_current(key, current->getRight(), current);
	}
	else if (key < current->getData()->getID()){
		current = delete_current(key, current->getLeft(), current);
	}
	else{
		// current is leaf
		if (current->getLeft() == nullptr and current->getRight() == nullptr){
			return nullptr;
		}
		// current only has right node
		else if (current->getLeft() == nullptr){
			return current->getRight();
		}
		// current only has left node
		else if (current->getRight() == nullptr){
			return current->getLeft();
		}
		else{
			BSTNode* min;
			min = min_node(current->getRight());
			Student* s_temp = new Student(*(min->getData()));
			BSTNode* temp = new BSTNode(s_temp);
			if (previous != nullptr){
				if (previous->getRight() == current){
					previous->setRight(temp);
				}
				else{
					previous->setLeft(temp);
				}
			}
			delete_current(current->getData()->getID(), current->getRight(), current);
		}
	}
	return current;
}

BSTNode* StudentDatabase::min_node(BSTNode* current){
	while (current and current->getLeft() != nullptr)
		current = current->getLeft();

	return current;
}

void StudentDatabase::balance(){
	BSTNode** arr = new BSTNode*[num_students];
	inOrderArray(root, arr);
	int size = sizeof(arr) / sizeof(arr[0]);
	createBalancedTree(arr, 0, size-1);
}

void StudentDatabase::inOrderArray(BSTNode* current, BSTNode** arr){
	int index = 0;
	while (current != nullptr){
		if (current->getLeft() == nullptr){
			arr[index] = current;
			index++;
			current = current->getRight();
		}
		else{
			BSTNode* pre = current->getLeft();
			while (pre->getRight() != nullptr and pre->getRight() != current){
				pre = pre->getRight();
			}

			if (pre->getRight() == nullptr){
				pre->setRight(current);
				current = current->getLeft();
			}

			else {
				pre->setRight(nullptr);
				arr[index] = current;
				index++;
				current = current->getRight();
			}
		}
	}
}

BSTNode* StudentDatabase::createBalancedTree(BSTNode** arr, int start, int end){
	if (start > end){
		return nullptr;
	}

	int mid = (start + end)/2;
	BSTNode* mini_root = arr[mid];
	mini_root->setLeft(createBalancedTree(arr, start, mid - 1));
	mini_root->setRight(createBalancedTree(arr, mid + 1, end));

	return root;
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