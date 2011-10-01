
#include <functional>

namespace m {

template<typename T, typename T2>
class mapped;

template<typename T>
class seq;

template <typename T, typename T2>
class mapped_iterator : public iterator<typename T2>
{
	mapped<typename T, typename T2>* mapd;
	iterator<typename T>* m;

public:
	mapped_iterator(mapped<typename T, typename T2>* mapped) {
		mapd = mapped;
		m = mapped->init->getIterator();
	}

	bool hasNext() {
		auto has = m->hasNext();
		if (!has) delete this;
		return has;
	}

	const T2& next() {
		return mapd->fn(m->next());
	}
};

template <typename T, typename T2>
class mapped : public seq<typename T2>
{
	friend class mapped_iterator<typename T, typename T2>;

	seq<typename T>* init;
	std::function<typename T2 (typename T)> fn;

public:

	mapped(seq<typename T>* _init, std::function<typename T2 (typename T)> _fn) {
		init = _init;
		fn = _fn;
	}

	iterator<typename T2>* getIterator() {
		return new mapped_iterator<typename T, typename T2>(this);
	}
};

template <typename T, typename T2>
mapped<typename T, typename T2> map(seq<typename T>* s, std::function<typename T2 (typename T)> fn) {
	return mapped<typename T, typename T2>(s, fn);
}




}