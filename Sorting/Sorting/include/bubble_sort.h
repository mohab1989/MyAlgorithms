#ifndef BUBBLE_SORT_ENABLED
#define BUBBLE_SORT_ENABLED
#include"sorting_common.h"

template<class T> class BubbleSort : public SortingCommon<T> {
public:
	BubbleSort() {};
	void Sort(std::vector<T>*, SortingOrder sorting_order=K_ascending);
	~BubbleSort() {};
};

template<typename T>
void BubbleSort<T>::Sort(std::vector<T>* sort_vector, SortingOrder sorting_order) {
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	std::cout << "Bubble Sort started\n";
	std::function<bool(T&, T&)> compare;
	switch (sorting_order)
	{
	case K_ascending: 
	{
		compare = LessThan;
		std::cout << "Sorting Order Ascending\n";
		break;
	}
	case k_descending:
	{
		compare = MoreThan;
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
	for (T& first_element : *sort_vector) {
		for (T& second_element : *sort_vector) {
			if (compare(first_element, second_element)) {
				Swap(first_element, second_element);
			}
		}
	}
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << " s\n";
}
#endif // !BUBBLE_SORT_ENABLED