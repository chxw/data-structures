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
			Student* s_temp = new Student(*(to_swap->getData()));
			BSTNode* temp = new BSTNode(s_temp);
			temp->setRight(current->getRight());
			temp->setLeft(current->getLeft());
			root = temp;
			std::cout << "here";
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