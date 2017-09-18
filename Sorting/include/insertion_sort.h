#ifndef INSERTION_SORT_ENABLED
#define INSERTION_SORT_ENABLED
#include"sorting_common.h"
template<class T> class InsertionSort : public SortingCommon<T> {
public:
	InsertionSort() {};
	void Sort(std::vector<T>*, SortingOrder sorting_order = K_ascending);
	~InsertionSort() {};
};

template<typename T>
void InsertionSort<T>::Sort(std::vector<T>* sort_vector, SortingOrder sorting_order) {
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	std::cout << "Insertion Sort started\n";
	std::function<bool(T&, T&)> compare;
	switch (sorting_order)
	{
	case K_ascending:
	{
        compare = SortingCommon<T>::LessThan;
		std::cout << "Sorting Order Ascending\n";
		break;
	}
	case k_descending:
	{
        compare = SortingCommon<T>::MoreThan;
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
	for (int current_element_id = 1; current_element_id < sort_vector->size(); ++current_element_id) {
		int element_to_left_id = current_element_id;

		while (element_to_left_id > 0 && compare( (*sort_vector)[element_to_left_id] , (*sort_vector)[element_to_left_id - 1])) {
			int temp = (*sort_vector)[element_to_left_id];
			(*sort_vector)[element_to_left_id] = (*sort_vector)[element_to_left_id - 1];
			(*sort_vector)[element_to_left_id - 1] = temp;
			element_to_left_id--;
		}
	}
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << " s\n";
}
#endif // !INSERTION_SORT_ENABLED
