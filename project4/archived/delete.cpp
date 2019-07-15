void StudentDatabase::delete_current(BSTNode* previous, BSTNode* current){
	// leaf current
	if(current->getLeft() == nullptr and current->getRight() == nullptr){
		std::cout << "leaf current" << std::endl;
		relink(previous, current, nullptr);
		return;
	}

	// current only has left child
	else if(current->getRight() == nullptr){
		std::cout << "current only has left child" << std::endl;
		if (previous == nullptr){
			root = current->getLeft();
		}
		else if (previous->getRight() == current){
			previous->setRight(current->getLeft());
		}
		else{
			previous->setLeft(current->getLeft());
		}
		delete current;
		return;
	}

	// current only has right child
	else if (current->getLeft() == nullptr){
		std::cout << "current only has right child" << std::endl;
		std::cout << "current's right child is " << current->getRight()->getData()->getID() << std::endl;
		if (previous == nullptr){
			root = current->getRight();
		}
		else if (previous->getRight() == current){
			previous->setRight(current->getRight());
		}
		else{
			previous->setLeft(current->getRight());
		}
		delete current;
		return;
	}

	// current has both children
	else{
		// current is right child
		if (previous->getRight() == current){
			std::cout << "current is right child" << std::endl;
			relink(previous, current, min_node(current->getRight()));
			return;
		}
		// current is left child
		else {
			std::cout << "current is left child" << std::endl;
			relink(previous, current, min_node(current->getRight()));
			return;
		}
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
	if (previous != nullptr){
		if(previous->getRight() == current){
			previous->setRight(to_swap);
		}
		else{
			previous->setLeft(to_swap);
		}
	}
	else{
		root = to_swap;
	}

	std::cout << "root is " << root->getData()->getID() << std::endl;

	delete current;
}
