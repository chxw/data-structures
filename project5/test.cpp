#include <cassert>
#include "Hash.hpp"

int main(){
	Hash h;

	h.put("chelsea", 1);
	h.put("tomoki", 2);
	h.put("matt", 3);
	h.put("test", 4);

	h.print();

  return 0;
}
