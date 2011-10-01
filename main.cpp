
#include "list.h"
#include "mapped.h"
#include <iostream>

int main() {

	m::list<int> myList;

	myList._vec.push_back(2);
	myList._vec.push_back(3);
	myList._vec.push_back(5);

	auto doubled = m::map<int, int>(&myList, [](int i) { return i * 2; });
	auto tripled = m::map<int, int>(&doubled, [](int i) { return i * 3; });

	auto loop = tripled.getIterator();

	while(loop->hasNext()) {
		auto res = loop->next();
		std::cout << res << " ";
	}

	loop = tripled.getIterator();

	while(loop->hasNext()) {
		auto res = loop->next();
		std::cout << res << " ";
	}


}
