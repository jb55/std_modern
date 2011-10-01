
#include <functional>

namespace m {

template <typename T, typename T2>
class mapped : public iterator<typename T2>
{
	iterator<typename T>* init;
	std::function<typename T2 (typename T)> fn;

public:
	mapped(iterator<typename T>* _init, std::function<typename T2 (typename T)> _fn) {
		init = _init;
		fn = _fn;
	}

	bool hasNext() {
		return init->hasNext();
	}

	const T2& next() {
		return fn(init->next());
	}
};

template <typename T, typename T2>
mapped<typename T, typename T2> map(iterator<typename T>* iter, std::function<typename T2 (typename T)> fn) {
	return mapped<typename T, typename T2>(iter, fn);
}




}