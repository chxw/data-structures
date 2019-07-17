#include "StudentDatabase.hpp"
#include <iomanip>
#include <cstdlib>

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
		num_students++;
		return true;
	}

	return place(root, newbie);
}

bool StudentDatabase::place(BSTNode* current, BSTNode* newbie){
	// needs to go left
	if (newbie->getData()->getID() < current->getData()->getID() and current->getLeft() != nullptr){
		place(current->getLeft(), newbie);
	}
	// found setLeft place
	else if (newbie->getData()->getID() < current->getData()->getID() and current->getLeft() == nullptr){
		current->setLeft(newbie);
		num_students++;
		return true;
	}
	// needs to go right
	else if (newbie->getData()->getID() >= current->getData()->getID() and current->getRight() != nullptr){
		place(current->getRight(), newbie);
	}
	// found setRight place
	else if (newbie->getData() >= current->getData() and current->getRight() == nullptr){
		current->setRight(newbie);
		num_students++;
		return true;
	}
	return false;
}

bool StudentDatabase::deleteBy(int studentID){
	if (searchBy(studentID) == nullptr){
		return false;
	}

	// if (num_students >= 3){
	// 	balance();
	// }

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
					root = current->getLeft();
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
				BSTNode* newbie = new BSTNode(data);

				BSTNode* to_swap_parent = find_parent(to_swap);
				BSTNode* to_swap_child = nullptr;

				// if to_swap has 1 child (it must be right child since to_swap is right subtree min_node), save it
				if (to_swap->getRight() != nullptr and to_swap->getLeft() == nullptr){
					to_swap_child = to_swap->getRight();
				}

				if (to_swap == to_swap_parent->getRight()){
					to_swap_parent->setRight(nullptr);
				}
				else if (to_swap == to_swap_parent->getLeft()){
					to_swap_parent->setLeft(nullptr);
				}

				newbie->setLeft(current->getLeft());

				// save to_swap_child
				if (to_swap_child != nullptr and current->getRight() != nullptr){
					if (to_swap_child->getData()->getID() < current->getRight()->getData()->getID()){
						newbie->setRight(to_swap_child);
						to_swap_child->setRight(current->getRight());
					}
					else{
						newbie->setRight(current->getRight());
						current->getRight()->setRight(to_swap_child);
					}
				}
				else if (to_swap_child != nullptr and current->getRight() == nullptr){
					newbie->setRight(to_swap_child);
				}
				else {
					newbie->setRight(current->getRight());
				}

				delete to_swap;

				// root
				if (previous == nullptr){
					root = newbie;
					delete current;
					break;
				}
				// current is prev left child
				else if (previous->getLeft() == current){
					previous->setLeft(newbie);
					delete current;
					break;
				}
				// current is prev right child
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

BSTNode* StudentDatabase::find_parent(BSTNode* child) const{
	int studentID = child->getData()->getID();
	BSTNode* parent = nullptr;
	BSTNode* current = root;

	while (current != nullptr){
		if (studentID > current->getData()->getID()){
			parent = current;
			current = current->getRight();
		}
		else if (studentID < current->getData()->getID()){
			parent = current;
			current = current->getLeft();
		}
		//found
		else{
			return parent;
		}
	}

	//not found
	return nullptr;
}

BSTNode* StudentDatabase::min_node(BSTNode* current){
	while (current and current->getLeft() != nullptr)
		current = current->getLeft();

	return current;
}

// bool StudentDatabase::isBalanced(){
// 	return checkBalance(root);
// }

// bool StudentDatabase::checkBalance(BSTNode* current){
// 	// empty tree is balanced
// 	if (current == nullptr){
// 		return true;
// 	}

// 	int leftDepth = find_depth(current->getLeft());
// 	int rightDepth = find_depth(current->getRight());

// 	// balanced tree def'n:
// 	// 1. difference between depth of left and right subtrees is <= 1
// 	// 2. left subtree balanced
// 	// 3. right subtree balanced
// 	if (abs(leftDepth - rightDepth) <= 1 and checkBalance(current->getLeft()) and checkBalance(current->getRight())){
// 		return true;
// 	}

// 	return false;
// }

void StudentDatabase::balance(){
	arr = new BSTNode*[num_students];
	inOrderArray(root, arr);
	// int size = sizeof(arr) / sizeof(arr[0]);

	// for (int i = 0; i < num_students; i++){
	// 	arr[i]->setLeft(nullptr);
	// 	arr[i]->setRight(nullptr);
	// }

	std::cout << "num_students " << num_students << std::endl;

	root = createBalancedTree(arr, 0, num_students-1);
	delete [] arr;
}

void StudentDatabase::inOrderArray(BSTNode* current, BSTNode** arr){
	int index = 0;
	while (current != nullptr){
		// no left
		if (current->getLeft() == nullptr){
			if (current){
				arr[index] = current;
				index++;
			}
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
				if (current){
					arr[index] = current;
					index++;
				}
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
	std::cout << "mini_root->getLeft()" << mini_root->getLeft()->getData()->getID() << std::endl;
	mini_root->setLeft(createBalancedTree(arr, start, mid - 1));
	mini_root->setRight(createBalancedTree(arr, mid + 1, end));

	return mini_root;
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

std::string StudentDatabase::toTreeString() const{
	if (root == nullptr){
		return "[]";
	}
	return preOrder(root, 0);
}

int StudentDatabase::find_depth(const BSTNode* node) const{
	int studentID = node->getData()->getID();
	BSTNode* current = root;
	int depth = 0;

	while (current != nullptr){
		if (studentID > current->getData()->getID()){
			current = current->getRight();
			depth++;
		}
		else if (studentID < current->getData()->getID()){
			current = current->getLeft();
			depth++;
		}
		//found
		else{
			return depth;
		}
	}

	//not found
	return -1;
}

std::string StudentDatabase::preOrder(const BSTNode* current, int depth) const{
	std::string order;

	if (current == nullptr){
		order += "[]";
		return order;
	}

	// left
	order += preOrder(current->getLeft(), depth);

	// node
	if (current->getLeft() == nullptr){
		depth = find_depth(current);
	}
	else{
		order += "]";
	}
	order += "("+current->getData()->toString()+")";
	if (current->getRight() == nullptr){
		depth = find_depth(current);
	}
	else{
		order += "[";
	}

	// right
	order += preOrder(current->getRight(), depth);

	return order;
}

void StudentDatabase::printTree() const{
	postOrder(root, 0);
}

void StudentDatabase::postOrder(const BSTNode* current, int indent) const{
	if (current == nullptr){
		return;
	}

	indent += 10;

	postOrder(current->getRight(), indent);

	std::cout << std::endl;
	for (int i = 10; i < indent; i++){
		std::cout << " ";
	}
	std::cout << current->getData()->getID() << "\n";

	postOrder(current->getLeft(), indent);
}