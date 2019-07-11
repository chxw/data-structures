template<typename K, typename V>

BSTNode(K key, V value);

V getData();


---------------------------------

int main(){
	const int* a = new int(1);		// a is a ptr to const int
	int* const b = new int(2); 		// b is a const ptr to int
	const int * const c = new int(3);	// c is a const ptr to const int
	int const * const d = new int (4);	// d is a const ptr to const int
						// d sometimes more preferred than c
						// bc you can read the type from right to left

}


