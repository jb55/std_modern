
namespace m {

template <typename T>
class iterator {
public:
	virtual bool hasNext() = 0;
	virtual const T& next() = 0;
};

} /* namespace m */