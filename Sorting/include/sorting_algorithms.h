#ifndef SORTING_ALGORITHMS_DEFINED
#define SORTING_ALGORITHMS_DEFINED
#include"bubble_sort.h"
#include"insertion_sort.h"
#include"selection_sort.h"
#include"merge_sort.h"
#include"quick_sort.h"
#include"counting_sort.h"
#include<memory>

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
    static std::unique_ptr<SortingCommon<T>> GetSortingAlgorithm(SortingAlgorithmType sorting_type) {
        switch (sorting_type)
		{
		case k_bubble:
        {
            return std::make_unique<BubbleSort<T>>(BubbleSort<T>());
		}
        case k_insertion:
        {
            return std::make_unique<InsertionSort<T>>(InsertionSort<T>());
        }
        case k_merge:
        {
            return std::make_unique<MergeSort<T>>(MergeSort<T>());
        }
        case k_selection:
        {
            return std::make_unique<SelectionSort<T>>(SelectionSort<T>());
        }
        case k_quick:
        {
            return std::make_unique<QuickSort<T>>(QuickSort<T>());
        }
        case k_counting:
        {
            return std::make_unique<CountingSort<T>>(CountingSort<T>());
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
