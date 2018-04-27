#ifndef ___MY_VECTOR___
#define ___MY_VECTOR___

namespace pic10C {
	template<typename objectType>
	class vector {
	private:
		objectType *the_data; // should I use a smartpointer?
		size_t size; // size of vector
		size_t capacity; // the capacity of vector

	public:
		vector() :the_data(nullptr), size(0), capacity(20) {
			the_data = new double[capacity];
		}

	};
}

#endif