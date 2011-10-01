
#include "iterator.h"

namespace m {

template <typename T>
class seq {
	virtual iterator<typename T>* getIterator() = 0;
};

}