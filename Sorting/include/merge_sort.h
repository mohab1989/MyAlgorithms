#ifndef MERGE_SORT_ENABLED
#define MERGE_SORT_ENABLED
#include"sorting_common.h"
template<class T> class MergeSort : public SortingCommon<T> {
public:
    MergeSort()=default;
    void Sort(std::vector<T>*, SortingOrder sorting_order = K_ascending);
    virtual ~MergeSort() {}
private:
    std::function<bool(T&, T&)> compare;
	void Deconstruct(std::vector<T>& parent_vector);
	void Merge(std::vector<T>& parent_vector, std::vector<T>& left_vector, std::vector<T>& right_vector);
};

template<typename T>
void MergeSort<T>::Deconstruct(std::vector<T>& parent_vector)
{
	if (parent_vector.size() > 1) {
		std::vector<T> left_vector(parent_vector.begin(),
			parent_vector.begin() + parent_vector.size() / 2);
		Deconstruct(left_vector);
		std::vector<T> right_vector(parent_vector.begin() + parent_vector.size() / 2,
			parent_vector.end());
		Deconstruct(right_vector);
		Merge(parent_vector, left_vector, right_vector);
	}
}
template<typename T>
void MergeSort<T>::Merge(std::vector<T>& parent_vector,std::vector<T>& left_vector, std::vector<T>& right_vector) {
    parent_vector.clear();

    int i, j, k;
    for (i = 0, j = 0, k = 0; i < left_vector.size() && j < right_vector.size(); ++k) {
        if (compare( left_vector.at(i) , right_vector.at(j))) {
            parent_vector.push_back(left_vector.at(i));
            ++i;
        }
        else if (!compare(left_vector.at(i) , right_vector.at(j))) {
            parent_vector.push_back(right_vector.at(j));
            ++j;
        }
    }

    while (i < left_vector.size()) {
        parent_vector.push_back(left_vector.at(i));
        ++i;
    }

    while (j < right_vector.size()) {
        parent_vector.push_back(right_vector.at(j));
        ++j;
    }
}

template<typename T>
void MergeSort<T>::Sort(std::vector<T>* sort_vector, SortingOrder sorting_order) {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    switch (sorting_order)
    {
    case K_ascending:
    {
        compare = SortingCommon<T>::LessThanEqual;
        std::cout << "Sorting Order Ascending\n";
        break;
    }
    case k_descending:
    {
        compare = SortingCommon<T>::MoreThanEqual;
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

    std::cout << "Merge Sort started\n";
    Deconstruct(*sort_vector);
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << " s\n";
}
#endif // !MERGE_SORT_ENABLED
