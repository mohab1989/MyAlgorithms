#ifndef SORTING_ALGORITHMS_DEFINED
#define SORTING_ALGORITHMS_DEFINED
#include"bubble_sort.h"
#include"insertion_sort.h"
#include"selection_sort.h"
#include"merge_sort.h"
#include"quick_sort.h"
#include"counting_sort.h"

enum SortingAlgorithmType
{
	k_bubble,
	k_insertion,
	k_merge,
	k_selection,
	k_quick,
	k_counting
};

class SortingAlgorithms
{
public:
	template<typename T>
	static std::function<void(std::vector<T>*,SortingOrder)> GetSortingAlgorithm(SortingAlgorithmType sorting_type) {
		switch (sorting_type)
		{
		case k_bubble:
		{
			BubbleSort<T> bubble_sort;
			return
				std::function<void(std::vector<T>*, SortingOrder)>
				(std::bind(&BubbleSort<T>::Sort, &bubble_sort, std::placeholders::_1, std::placeholders::_2));
			break;
		}
		case k_insertion:
		{
			InsertionSort<T> insertion_sort;
			return
				std::function<void(std::vector<T>*, SortingOrder)>
				(std::bind(&InsertionSort<T>::Sort, &insertion_sort, std::placeholders::_1, std::placeholders::_2));
			;
			break;
		}
		case k_merge:
		{
			MergeSort<T> merge_sort;
			return
				std::function<void(std::vector<T>*,SortingOrder)>
				(std::bind(&MergeSort<T>::Sort,&merge_sort,std::placeholders::_1,std::placeholders::_2));
			break;
		}
		case k_selection:
		{
			SelectionSort<T> selection_sort;
			return 
				std::function<void(std::vector<T>*,SortingOrder)>
				(std::bind(&SelectionSort<T>::Sort,&selection_sort,std::placeholders::_1,std::placeholders::_2));
			break;
		}
		case k_quick:
		{
			QuickSort<T> quick_sort;
			return
			std::function<void(std::vector<T>*, SortingOrder)>
				(std::bind(&QuickSort<T>::Sort, &quick_sort, std::placeholders::_1, std::placeholders::_2));

			break;
		}
		case k_counting:
		{
			CountingSort<T> counting_sort;
			return
				std::function<void(std::vector<T>*, SortingOrder)>
				(std::bind(&CountingSort<T>::Sort, &counting_sort, std::placeholders::_1, std::placeholders::_2));

			break;
		}

		default:
		{
			return nullptr;
			break;
		}
		}
	}
};

#endif // !SORTING_ALGORITHMS_DEFINED
