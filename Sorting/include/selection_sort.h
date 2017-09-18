#ifndef SELECTION_SORT_ENABLED
#define SELECTION_SORT_ENABLED
#include"sorting_common.h"

template<class T> class SelectionSort : public SortingCommon<T> {
public:
	SelectionSort() {};
	void Sort(std::vector<T>*, SortingOrder sorting_order = K_ascending);
	~SelectionSort() {};
};

template<typename T>
void SelectionSort<T>::Sort(std::vector<T>* sort_vector, SortingOrder sorting_order) {
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	std::cout << "Selection Sort started\n";
	std::function<bool(T&, T&)> compare;
	switch (sorting_order)
	{
	case K_ascending:
	{
        compare = SortingCommon<T>::MoreThan;
		std::cout << "Sorting Order Ascending\n";
		break;
	}
	case k_descending:
	{
        compare = SortingCommon<T>::LessThan;
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
	for (int first_element_id = 0; first_element_id < sort_vector->size();++first_element_id) {
		T& first_element = (*sort_vector)[first_element_id];
		int min_max_id = first_element_id;
		T min_max_element = (*sort_vector)[min_max_id];
		for (int second_element_id = first_element_id+1; second_element_id < sort_vector->size();++second_element_id) {
			T& second_element = (*sort_vector)[second_element_id];
			if (compare(min_max_element, second_element)) {
				min_max_id = second_element_id;
				min_max_element = (*sort_vector)[min_max_id];
			}
		}
		if (first_element_id != min_max_id) {
            SortingCommon<T>::Swap(first_element, (*sort_vector)[min_max_id]);
		}
	}
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << " s\n";
}
#endif // !SELECTION_SORT_ENABLED
