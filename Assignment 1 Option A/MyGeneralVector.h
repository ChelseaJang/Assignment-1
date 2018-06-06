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
		// The big 4 
		vector();
		vector(const vector&);
		vector& operator=(const vector&);
		~vector();

		// Other members [public]
		bool empty() const;
		size_t size() const;
		size_t capacity() const;
		typename front() const;
		typename back() const;
		typename at(size_t index) const;
		typename& operator[](size_t index);
		typename operator[](size_t index) const;
		void dump_data_to(std::ostream& out) const;
		void dump_data() const;
		void push_back(typename new_value);
		void pop_back();

	private:
		//Other members [private]
		void reserve(size_t new_capacity);

	}; // end Pic10b::vector


	/** ************************* THE BIG 4 ************************* **/
	vector::vector() :the_data(nullptr), size(0), capacity(INIT_CAP) {
		the_data = new typename[capacity];
	}

	vector::vector(const vector& source): the_data(nullptr), size(source.size), capacity(source.capacity) {

		the_data = new typename[capacity];

		// Deep copy of internal array
		for (int i = 0; i < size; ++i) {
			the_data[i] = source.the_data[i];
		}
	}

	vector& vector::operator=(const vector& rhs) {
		if (this != &rhs) {     // Self-assignment?
								// Release old memory and request more 
			delete[] the_data;
			the_data = new double[rhs.capacity];

			// Shallow copy non-pointers
			size = rhs.size;
			capacity = rhs.capacity;

			// Deep copy internal array
			for (int i = 0; i < size; ++i)
				the_data[i] = rhs.the_data[i];
		}
		return *this;
	}

	vector::~vector() {
		delete[] the_data;
	}

	/** *********************** OTHER MEMBERS *********************** **/
	bool vector::empty() const {
		return size == 0;
	}

	size_t vector::size() const {
		return size;
	}

	size_t vector::capacity() const {
		return capacity;
	}

	double vector::front() const {
		return *the_data;
	}

	double vector::back() const {
		return *(the_data + size - 1);
	}

	double vector::at(size_t index) const {
		if (index < size)
			return the_data[index];
		return the_data[0];
	}

	double& vector::operator[](size_t index) {
		return the_data[index];
	}
	double vector::operator[](size_t index) const {
		return the_data[index];
	}

	void vector::dump_data_to(std::ostream& out) const {
		out << "Vector (dump): ";
		for (size_t i = 0; i < capacity; ++i)
			out << the_data[i] << ' ';
		out << '\n';
	}

	void vector::dump_data() const {
		dump_data_to(std::cout);
	}


	void vector::push_back(double new_value) {
		if (size == capacity)
			reserve(capacity + 1);     // `the_data` is reassigned

		the_data[size++] = new_value;
	}

	// This implementation does not shrink the vector (ever)
	void vector::pop_back() {
		if (size > 0)
			--size;
	}


	void vector::reserve(size_t new_capacity) {
		if (new_capacity > capacity) {
			if (new_capacity <= 2 * capacity)
				new_capacity = 2 * capacity;

			typename* old_location = the_data;

			the_data = new typename[new_capacity];
			capacity = new_capacity;

			for (size_t i = 0; i < size; ++i)
				the_data[i] = old_location[i];

			delete old_location;
		}
	}

} // end Pic10b namespace



	  /** ************************ OTHER FUNCTIONS ************************ **/
	std::ostream& operator<<(std::ostream& out, const Pic10C::vector& v) {
		for (size_t i = 0; i < v.size(); ++i)
			out << v[i] << ' ';
		return out;
	}


	void print_vector(const Pic10C::vector& v) {
		if (v.empty())
			std::cout << "Vector is empty\n";
		else
			std::cout << "Vector (contents): " << v << '\n';
}

#endif
