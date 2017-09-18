#include"sorting_algorithms.h"
#include<random>
int main(int argc, char* argv[]) {
	int size_of_vector = 100000000;
	std::vector<int> sort_vector(size_of_vector) ;
	// Seed with a real random value, if available
	std::random_device r;

	// Choose a random mean between 1 and 6
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(1, sort_vector.size());
	for (int int_id = 0; int_id < sort_vector.size(); ++int_id) {
		sort_vector[int_id] = uniform_dist(e1);
	}

	SortingOrder sort_order = K_ascending;

	//auto Sort = SortingAlgorithms::GetSortingAlgorithm<int>(k_bubble);
	//auto Sort = SortingAlgorithms::GetSortingAlgorithm<int>(k_insertion);
	//auto Sort = SortingAlgorithms::GetSortingAlgorithm<int>(k_selection);
	//auto Sort = SortingAlgorithms::GetSortingAlgorithm<int>(k_merge);
	//auto Sort = SortingAlgorithms::GetSortingAlgorithm<int>(k_quick);
    auto Sort = SortingAlgorithms::GetSortingAlgorithm<int>(k_counting);

	std::vector<int>m{9 ,2 ,3,6,23,8,7,9,4,5,4,11,27,567,80};
	std::vector<int>p{ 3,8,2,1,5,4,6,7};
	std::vector<int>q{ 1, 12, 5, 26, 7, 14, 3, 7, 2 };
	std::vector<int>c{ 5, 9 ,3 ,9 ,10 ,9 ,2 ,4 ,13 ,10 };
	std::vector<char>chars{ 'b','e','a','w','d'};

    std::vector<int> input1 = sort_vector;
    std::vector<int> input2 = sort_vector;
	//SortingCommon<int>::DisplayVector(&input);
    Sort(&input1, sort_order);
	//SortingCommon<int>::DisplayVector(&input);

	//Sort(&p, k_descending);


    //Sort = SortingAlgorithms::GetSortingAlgorithm<int>(k_merge);
    //Sort(&input2, sort_order);
}
