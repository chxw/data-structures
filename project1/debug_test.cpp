/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
	int size = 13;
	int temp_size = size+1;
	int at = 3; 
	int at_value = 96;
	
	int *cards = new int[size];
	for(int i = 0; i < size; i++){
	    cards[i] = i;
	}
	
	int *temp = new int[size+1];
	
	for(int i = 0; i < at; i++){
		temp[i] = cards[i];
	}
	
	temp[at] = at_value;
	
	for(int i = at+1; i < size+1; i++){
		temp[i] = cards[i-1];
	}
	
	// print temp
	cout << "TEMP" << endl;
	for(int i = 0; i < temp_size; i++){
	    cout << temp[i] << endl;
    }
	cout << "end" << endl;
	
	// print cards
	cout << "CARDS" << endl;
	for(int i = 0; i < size; i++){
	    cout << cards[i] << endl;
	}
	cout << "end" << endl;

    delete[] cards;
	cards = temp;
	temp = NULL;
	
	cout << "Memory freed" << endl;
	
	// print temp
	cout << "TEMP" << endl;
	for(int i = 0; i < temp_size; i++){
	    cout << temp[i] << endl;
    }
	cout << "end" << endl;
	
	// print cards
	cout << "CARDS" << endl;
	for(int i = 0; i < temp_size; i++){
	    cout << cards[i] << endl;
	}
	cout << "end" << endl;
	
    return 0;
}
