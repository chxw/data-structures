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
	
	// if (num_students >= 3){
	// 	balance();
	// }

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

	BSTNode* previous = nullptr;
	BSTNode* current = root;

	while (true){
		// go right
		if (studentID > current->getData()->getID()){
			previous = current;
			current = current->getRight();
		}
		// go left
		else if (studentID < current->getData()->getID()){
			previous = current;
			current = current->getLeft();
		}
		// found
		else{
			// current is leaf
			if (current->getLeft() == nullptr and current->getRight() == nullptr){
				// root
				if (previous == nullptr){
					delete root;
					root = nullptr;
					break;
				}
				// current is prev left child
				else if (previous->getLeft() == current){
					delete current;
					previous->setLeft(nullptr);
					break;
				}
				// current is prev right child
				else{
					delete current;
					previous->setRight(nullptr);
					break;
				}
			}
			// current only has right child
			else if (current->getLeft() == nullptr){
				// root
				if (previous == nullptr){
					root = current->getRight();
					delete current;
					break;
				}
				// current is prev left child
				else if (previous->getLeft() == current){
					previous->setLeft(current->getRight());
					delete current;
					break;
				}
				// current is prev right child
				else{
					previous->setRight(current->getRight());
					delete current;
					break;
				}
			}
			// current only has left child
			else if (current->getRight() == nullptr){
				// root
				if (previous == nullptr){
					root = current->getRight();
					delete current;
					break;
				}
				// current is prev left child
				else if (previous->getLeft() == current){
					previous->setLeft(current->getLeft());
					delete current;
					break;
				}
				// current is prev right child
				else{
					previous->setRight(current->getLeft());
					delete current;
					break;
				}
			}
			// current has both children
			else{
				BSTNode* to_swap = min_node(current->getRight());
				Student* data = new Student(*(to_swap->getData()));
				std::cout << "to_swap data is " << data->toString() << std::endl;

				BSTNode* newbie = new BSTNode(data);

				std::cout << "newbie data is " << newbie->getData()->toString() << std::endl;

				delete to_swap;
				// current->setRight(nullptr);
				std::cout << "to_swap deleted" << std::endl;

				std::cout << "current data is " << current->getData()->toString() << std::endl;
				std::cout << "current->getLeft " << current->getLeft()->getData()->toString() << std::endl;
				newbie->setLeft(current->getLeft());
				// std::cout << "current->getRight " << current->getRight()->getData()->toString() << std::endl;
				newbie->setRight(current->getRight());

				// assert(current->getRight() == nullptr);
				// assert(newbie->getRight() == nullptr);

				if (previous == nullptr){
					root = newbie;
					delete current;
					break;
				}
				else if (previous->getLeft() == current){
					previous->setLeft(newbie);
					delete current;
					break;
				}
				else{
					previous->setRight(newbie);
					delete current;
					break;
				}
			}

		}
	}

	return true;
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
		// no left
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

	order.pop_back();

	return order;
}

// std::string StudentDatabase::toTreeString() const{

// }
