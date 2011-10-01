
#include "iterator.h"

namespace m {

template <typename T>
class seq {
public:
	virtual iterator<typename T>* getIterator() = 0;
};

}