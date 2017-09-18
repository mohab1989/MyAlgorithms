#ifndef QUICK_SORT_ENABLED
#define QUICK_SORT_ENABLED
#include"sorting_common.h"
template<class T> class QuickSort : public SortingCommon<T> {
public:
	QuickSort() {};
	void Sort(std::vector<T>*, SortingOrder sorting_order = K_ascending);
	~QuickSort() {};
private:
	std::function<bool(T&, T&)> compare;
	void QuickSortFunction(std::vector<T>& parent_vector, int left, int right);
};

template<typename T>
void QuickSort<T>::QuickSortFunction(std::vector<T>& parent_vector, int left,int right)
{
	int i = left, j = right;
	T pivot = parent_vector[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (compare(parent_vector[i] , pivot))
			i++;
		while (!compare( parent_vector[j] , pivot) && parent_vector[j] != pivot)
			j--;
		if (i <= j) {
			Swap(parent_vector[i], parent_vector[j]);
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		QuickSortFunction(parent_vector, left, j);
	if (i < right)
		QuickSortFunction(parent_vector, i, right);
}

template<typename T>
void QuickSort<T>::Sort(std::vector<T>* sort_vector, SortingOrder sorting_order) {
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();

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

	std::cout << "Quick Sort started\n";
	QuickSortFunction(*sort_vector, 0,sort_vector->size()-1);
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << " s\n";
}
#endif // !QUICK_SORT_ENABLED