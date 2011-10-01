
#include "seq.h"
#include <vector>

namespace m {

template <typename T>
class seq;

template <typename T>
class list;

template <typename T>
class list_iterator : public iterator<typename T>
{
	list<typename T>* _list;
	typename std::vector<typename T>::iterator _iter;

public:
	
	list_iterator(list<typename T>* l) {
		init(l);
	}

	void init(list<typename T>* l) {
		_list = l;
		_iter = _list->_vec.begin();
	}

	bool hasNext() {
		auto has = _list->_vec.size() != 0 && _iter < _list->_vec.end();

		if (!has) {
			delete this;
		}

		return has;
	}

	const T& next() {
		return *_iter++;
	}
};

template <typename T>
class list : public seq<typename T>
{
	friend class list_iterator<typename T>;

public:
	std::vector<typename T> _vec;

	iterator<typename T>* getIterator() {
		return new list_iterator<typename T>(this);
	}
};

}