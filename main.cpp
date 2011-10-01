
#include "list.h"
#include "mapped.h"
#include <iostream>

int main() {

	m::list<int> myList;

	myList._vec.push_back(2);
	myList._vec.push_back(3);
	myList._vec.push_back(5);

	auto iter = myList.getIterator();

	auto doubled = m::map<int, int>(iter, [](int i) { return i * 2; });

	while(doubled.hasNext()) {
		auto res = doubled.next();
		std::cout << res << "";
	}

}
