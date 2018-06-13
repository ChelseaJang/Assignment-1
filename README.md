# Pic10C_Chelsea
repository for all assignments from the PIC10C class

I had some difficulties figuring how out how to do a merge commit.

I've tried my best to update it every 30 minutes. I have to be brutally honest, I don't really like this version control software. I really prefer working on it in visual studios or some other compiler and this is starting to get really frustrating expecially since I'm having trouble with cloning both branches when I clone my repositories.

I'm going to start commenting on my files a bit.

I also learned how to delete files, which was a relief because trying to find that delete button was quite scary, when I thought I couldn't find it...


**Website for stylizing text:**
https://help.github.com/articles/basic-writing-and-formatting-syntax/

*some explanation of code:*

```
bool vector::empty() const {
		return size == 0;
}
```
For function empty(), the function returns the status of the vector. If it is empty, boolean true is returned. If it has something in it, then boolean false is returned

```
size_t vector::size() const {
	return size;
}
```
The variable size contains the size of the vector. Function size() returns this value, letting the user know how big the vector is.

```
size_t vector::capacity() const {
	return capacity;
}
```
The variable capacity contains the size of the contained used to store the objects. This function is important when checking how big the container is so that we will know when to change the container (if the container gets too large, in other words, when adding a new element into the vector will lead to size > capacity).

```
double vector::front() const {
	return *the_data;
}
```
This function should return the element at the front of the vector.

```
double vector::back() const {
	return *(the_data + size - 1);
}
```
This function should return the element at the back of the vector.

```
double vector::at(size_t index) const {
	if (index < size)
		return the_data[index];
	return the_data[0];
}
```
This function should return the element at the position index of the vector. However, if the position passed is larger than the size, then an element wouldn't exist there. In this case, it will return the element at the first position.

```
double& vector::operator[](size_t index) {
	return the_data[index];
}
```
This function returns the element at position index of the vector like the at(index) function. However, the object is returned by reference so the data can be modified.

```
double vector::operator[](size_t index) const {
	return the_data[index];
}
```
This function returns the element at position index of the vector like the at(index) function. However, the object is returned by const reference so although we are interacting with the original object, the data can't be modified.

```
void vector::dump_data_to(std::ostream& out) const {
	out << "Vector (dump): ";
	for (size_t i = 0; i < capacity; ++i)
		out << the_data[i] << ' ';
	out << '\n';
}
```
This function prints the data into an ostream object.

```
void vector::dump_data() const {
	dump_data_to(std::cout);
}
```
This function dumps data into a cout ostream object.

```
void vector::push_back(double new_value) {
	if (size == capacity)
		reserve(capacity + 1);     // `the_data` is reassigned

	the_data[size++] = new_value;
}
```
This function adds a new object to the back of the vector. It increases the size and changes the container if the capacity is reached. When capacity is reached, it calls on the function reserve() which creates a new location for the vector container, moves the data over, and deletes the old data.

```
void vector::pop_back() {
	if (size > 0){
    		delete the_data[size];
		--size;
	}
}
```
This function deletes elements from the back of the vector.
