#ifndef SORTING_COMMON_DEFINED
#define SORTING_COMMON_DEFINED
#include<chrono>
#include<iostream>
#include<vector>
#include <functional>

enum SortingOrder
{
	K_ascending,
	k_descending
};

template<class T> class SortingCommon
{
public:
	SortingCommon() {};
	~SortingCommon() {};
	static void DisplayVector(std::vector<T>* vector);
private:

protected:
	static bool MoreThanEqual(T& first_element, T& second_element);
	static bool LessThanEqual(T& first_element, T& second_element);
	static bool MoreThan(T& first_element, T& second_element);
	static bool LessThan(T& first_element, T& second_element);

	static void Swap(T& first_element, T& second_element);
};
template<typename T>
bool SortingCommon<T>::MoreThanEqual(T& first_element, T& second_element) {
	return first_element >= second_element;
}
template<typename T>
bool SortingCommon<T>::LessThanEqual(T& first_element, T& second_element) {
	return first_element <= second_element;
}

template<typename T>
bool SortingCommon<T>::MoreThan(T& first_element, T& second_element) {
	return first_element > second_element;
}
template<typename T>
bool SortingCommon<T>::LessThan(T& first_element, T& second_element) {
	return first_element < second_element;
}
template<typename T>
void SortingCommon<T>::Swap(T& first_element, T& second_element) {
	T temp = first_element;
	first_element = second_element;
	second_element = temp;
}
template<typename T>
void SortingCommon<T>::DisplayVector(std::vector<T>* vector) {
	for (T element : *vector) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
}


#endif // !SORTING_COMMON_DEFINED
