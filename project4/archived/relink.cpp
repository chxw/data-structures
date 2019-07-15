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

	delete current;
}