#ifndef COUNTING_SORT_ENABLED
#define COUNTING_SORT_ENABLED
#include"sorting_common.h"

template<class T> class CountingSort : public SortingCommon<T> {
public:
	CountingSort() {};
	void Sort(std::vector<T>*, SortingOrder sorting_order = K_ascending);
	~CountingSort() {};
private:
	void ArrangeAscending(T& min, T& max,
		std::vector<int>& elements_count,std::vector<T>* sort_vector);
	void ArrangeDescending(T& min, T& max,
		std::vector<int>& elements_count,std::vector<T>* sort_vector);

};
template<typename T>
void CountingSort<T>::ArrangeAscending(T& min, T& max,
	std::vector<int>& elements_count, std::vector<T>* sort_vector) {
	int idx = 0;
	// iterate over range
	for (T i = min; i <= max; ++i)
		for (int j = 0; j < elements_count[i - min]; ++j) (*sort_vector)[idx++] = i;
}
template<typename T>
void CountingSort<T>::ArrangeDescending(T& min, T& max,
	std::vector<int>& elements_count, std::vector<T>* sort_vector) {
	int idx = 0;
	// iterate over range
	for (T i = max; i >= min; --i)
		for (int j = 0; j < elements_count[i - min]; ++j) (*sort_vector)[idx++] = i;
}

template<typename T>
void CountingSort<T>::Sort(std::vector<T>* sort_vector, SortingOrder sorting_order) {
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	std::cout << "Counting Sort started\n";
	std::function<void(T&, T&,std::vector<int>&,std::vector<T>*)> Arrange;
	switch (sorting_order)
	{
	case K_ascending:
	{
		Arrange = std::bind( &CountingSort<T>::ArrangeAscending,this,
			std::placeholders::_1, std::placeholders::_2, std::placeholders::_3
			,std::placeholders::_4);
		std::cout << "Sorting Order Ascending\n";
		break;
	}
	case k_descending:
	{
		Arrange = std::bind(&CountingSort<T>::ArrangeDescending, this,
			std::placeholders::_1, std::placeholders::_2, std::placeholders::_3
			, std::placeholders::_4);
		std::cout << "Sorting Order Descending\n";
		break;
	}
	default:
	{
		std::cout << "Problem with sorting order\n";
		system("pause");
		exit(1);
		break;
	}
	}

	T min, max;
	//find min & max to determine range
	min = max = (*sort_vector)[0];
	for (auto element : *sort_vector) {
		min = (element < min) ? element : min;
		max = (element > max) ? element : max;
	}
	// Create a count array to store count of inidividul
	// elements and initialize count array as 0
	std::vector<int> elements_count(max - min + 1);
	//sert count of elements - min
	for (auto element : *sort_vector) ++elements_count[element- min];
	Arrange(min, max, elements_count, sort_vector);
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << " s\n";
}
#endif // !COUNTING_SORT_ENABLED