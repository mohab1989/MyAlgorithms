#include"sorting_algorithms.h"
#include<random>
#include<gtest/gtest.h>
#include<gmock/gmock.h>
const int sort_vector_length = 10000;
//Bubble Sort Tests
class BubbleSortIntFixtureAscending : public ::testing::Test{
public:
    std::vector<int> sorted_integers = std::vector<int>(sort_vector_length);
    std::vector<int> to_be_sorted;
    SortingOrder sort_order = K_ascending;
    BubbleSortIntFixtureAscending(){

    }
    void SetUp(){
        // init vector
        std::iota(std::begin(sorted_integers), std::end(sorted_integers), 0);
        // copy vector
        to_be_sorted = sorted_integers;
        // shuffle vector
        std::random_device r;
        std::shuffle(to_be_sorted.begin(),to_be_sorted.end(),r);

    }
    void TearDown(){
    }

    ~BubbleSortIntFixtureAscending(){
        sorted_integers.clear();
        to_be_sorted.clear();
    }
};

TEST_F (BubbleSortIntFixtureAscending,BubbleSortIntAscending){
    auto bubble_sort =  SortingAlgorithms::GetSortingAlgorithm<int>(k_bubble);
    bubble_sort->Sort(&to_be_sorted,sort_order);
    EXPECT_THAT(to_be_sorted, ::testing::ContainerEq(sorted_integers));
}

class BubbleSortIntFixtureDescending : public ::testing::Test{
public:
    std::vector<int> sorted_integers = std::vector<int>(sort_vector_length);
    std::vector<int> to_be_sorted;
    SortingOrder sort_order = k_descending;
    BubbleSortIntFixtureDescending(){

    }
    void SetUp(){
        // init vector
        std::iota(std::begin(sorted_integers), std::end(sorted_integers), 0);
        std::reverse(sorted_integers.begin(),sorted_integers.end());
        // copy vector
        to_be_sorted = sorted_integers;
        // shuffle vector
        std::random_device r;
        std::shuffle(to_be_sorted.begin(),to_be_sorted.end(),r);

    }
    void TearDown(){
    }

    ~BubbleSortIntFixtureDescending(){
        sorted_integers.clear();
        to_be_sorted.clear();
    }
};

TEST_F (BubbleSortIntFixtureDescending,BubbleSortIntDescending){
    auto bubble_sort = SortingAlgorithms::GetSortingAlgorithm<int>(k_bubble);
    bubble_sort->Sort(&to_be_sorted,sort_order);
    EXPECT_THAT(to_be_sorted, ::testing::ContainerEq(sorted_integers));
}

//Selection Sort Tests
class SelectionSortIntFixtureAscending : public ::testing::Test{
public:
    std::vector<int> sorted_integers = std::vector<int>(sort_vector_length);
    std::vector<int> to_be_sorted;
    SortingOrder sort_order = K_ascending;
    SelectionSortIntFixtureAscending(){

    }
    void SetUp(){
        // init vector
        std::iota(std::begin(sorted_integers), std::end(sorted_integers), 0);
        // copy vector
        to_be_sorted = sorted_integers;
        // shuffle vector
        std::random_device r;
        std::shuffle(to_be_sorted.begin(),to_be_sorted.end(),r);

    }
    void TearDown(){
    }

    ~SelectionSortIntFixtureAscending(){
        sorted_integers.clear();
        to_be_sorted.clear();
    }
};

TEST_F (SelectionSortIntFixtureAscending,SelectionSortIntAscending){
    auto selection_sort = SortingAlgorithms::GetSortingAlgorithm<int>(k_selection);
    selection_sort->Sort(&to_be_sorted,sort_order);
    EXPECT_THAT(to_be_sorted, ::testing::ContainerEq(sorted_integers));
}

class SelectionSortIntFixtureDescending : public ::testing::Test{
public:
    std::vector<int> sorted_integers = std::vector<int>(sort_vector_length);
    std::vector<int> to_be_sorted;
    SortingOrder sort_order = k_descending;
    SelectionSortIntFixtureDescending(){

    }
    void SetUp(){
        // init vector
        std::iota(std::begin(sorted_integers), std::end(sorted_integers), 0);
        std::reverse(sorted_integers.begin(),sorted_integers.end());
        // copy vector
        to_be_sorted = sorted_integers;
        // shuffle vector
        std::random_device r;
        std::shuffle(to_be_sorted.begin(),to_be_sorted.end(),r);

    }
    void TearDown(){
    }

    ~SelectionSortIntFixtureDescending(){
        sorted_integers.clear();
        to_be_sorted.clear();
    }
};

TEST_F (SelectionSortIntFixtureDescending,SelectionSortIntDescending){
    auto selection_sort = SortingAlgorithms::GetSortingAlgorithm<int>(k_selection);
    selection_sort->Sort(&to_be_sorted,sort_order);
    EXPECT_THAT(to_be_sorted, ::testing::ContainerEq(sorted_integers));
}

//Insertion Sort Tests
class InsertionSortIntFixtureAscending : public ::testing::Test{
public:
    std::vector<int> sorted_integers = std::vector<int>(sort_vector_length);
    std::vector<int> to_be_sorted;
    SortingOrder sort_order = K_ascending;
    InsertionSortIntFixtureAscending(){

    }
    void SetUp(){
        // init vector
        std::iota(std::begin(sorted_integers), std::end(sorted_integers), 0);
        // copy vector
        to_be_sorted = sorted_integers;
        // shuffle vector
        std::random_device r;
        std::shuffle(to_be_sorted.begin(),to_be_sorted.end(),r);

    }
    void TearDown(){
    }

    ~InsertionSortIntFixtureAscending(){
        sorted_integers.clear();
        to_be_sorted.clear();
    }
};

TEST_F (InsertionSortIntFixtureAscending,InsertionSortIntAscending){
    auto insertion_sort = SortingAlgorithms::GetSortingAlgorithm<int>(k_insertion);
    insertion_sort->Sort(&to_be_sorted,sort_order);
    EXPECT_THAT(to_be_sorted, ::testing::ContainerEq(sorted_integers));
}

class InsertionSortIntFixtureDescending : public ::testing::Test{
public:
    std::vector<int> sorted_integers = std::vector<int>(sort_vector_length);
    std::vector<int> to_be_sorted;
    SortingOrder sort_order = k_descending;
    InsertionSortIntFixtureDescending(){

    }
    void SetUp(){
        // init vector
        std::iota(std::begin(sorted_integers), std::end(sorted_integers), 0);
        std::reverse(sorted_integers.begin(),sorted_integers.end());
        // copy vector
        to_be_sorted = sorted_integers;
        // shuffle vector
        std::random_device r;
        std::shuffle(to_be_sorted.begin(),to_be_sorted.end(),r);

    }
    void TearDown(){
    }

    ~InsertionSortIntFixtureDescending(){
        sorted_integers.clear();
        to_be_sorted.clear();
    }
};

TEST_F (InsertionSortIntFixtureDescending,InsertionSortIntDescending){
    auto insertion_sort = SortingAlgorithms::GetSortingAlgorithm<int>(k_insertion);
    insertion_sort->Sort(&to_be_sorted,sort_order);
    EXPECT_THAT(to_be_sorted, ::testing::ContainerEq(sorted_integers));
}

//Merge Sort Tests
class MergeSortIntFixtureAscending : public ::testing::Test{
public:
    std::vector<int> sorted_integers = std::vector<int>(sort_vector_length);
    std::vector<int> to_be_sorted;
    SortingOrder sort_order = K_ascending;
    MergeSortIntFixtureAscending(){

    }
    void SetUp(){
        // init vector
        std::iota(std::begin(sorted_integers), std::end(sorted_integers), 0);
        // copy vector
        to_be_sorted = sorted_integers;
        // shuffle vector
        std::random_device r;
        std::shuffle(to_be_sorted.begin(),to_be_sorted.end(),r);

    }
    void TearDown(){
    }

    ~MergeSortIntFixtureAscending(){
        sorted_integers.clear();
        to_be_sorted.clear();
    }
};

TEST_F (MergeSortIntFixtureAscending,MergeSortIntAscending){
    auto merge_sort = SortingAlgorithms::GetSortingAlgorithm<int>(k_merge);
    merge_sort->Sort(&to_be_sorted,sort_order);
    EXPECT_THAT(to_be_sorted, ::testing::ContainerEq(sorted_integers));
}

class MergeSortIntFixtureDescending : public ::testing::Test{
public:
    std::vector<int> sorted_integers = std::vector<int>(sort_vector_length);
    std::vector<int> to_be_sorted;
    SortingOrder sort_order = k_descending;
    MergeSortIntFixtureDescending(){

    }
    void SetUp(){
        // init vector
        std::iota(std::begin(sorted_integers), std::end(sorted_integers), 0);
        std::reverse(sorted_integers.begin(),sorted_integers.end());
        // copy vector
        to_be_sorted = sorted_integers;
        // shuffle vector
        std::random_device r;
        std::shuffle(to_be_sorted.begin(),to_be_sorted.end(),r);

    }
    void TearDown(){
    }

    ~MergeSortIntFixtureDescending(){
        sorted_integers.clear();
        to_be_sorted.clear();
    }
};

TEST_F (MergeSortIntFixtureDescending,MergeSortIntDescending){
    auto merge_sort = SortingAlgorithms::GetSortingAlgorithm<int>(k_merge);
    merge_sort->Sort(&to_be_sorted,sort_order);
    EXPECT_THAT(to_be_sorted, ::testing::ContainerEq(sorted_integers));
}

//Quick Sort Tests
class QuickSortIntFixtureAscending : public ::testing::Test{
public:
    std::vector<int> sorted_integers = std::vector<int>(sort_vector_length);
    std::vector<int> to_be_sorted;
    SortingOrder sort_order = K_ascending;
    QuickSortIntFixtureAscending(){

    }
    void SetUp(){
        // init vector
        std::iota(std::begin(sorted_integers), std::end(sorted_integers), 0);
        // copy vector
        to_be_sorted = sorted_integers;
        // shuffle vector
        std::random_device r;
        std::shuffle(to_be_sorted.begin(),to_be_sorted.end(),r);

    }
    void TearDown(){
    }

    ~QuickSortIntFixtureAscending(){
        sorted_integers.clear();
        to_be_sorted.clear();
    }
};

TEST_F (QuickSortIntFixtureAscending,QuickSortIntAscending){
    auto quick_sort = SortingAlgorithms::GetSortingAlgorithm<int>(k_quick);
    quick_sort->Sort(&to_be_sorted,sort_order);
    EXPECT_THAT(to_be_sorted, ::testing::ContainerEq(sorted_integers));
}

class QuickSortIntFixtureDescending : public ::testing::Test{
public:
    std::vector<int> sorted_integers = std::vector<int>(sort_vector_length);
    std::vector<int> to_be_sorted;
    SortingOrder sort_order = k_descending;
    QuickSortIntFixtureDescending(){

    }
    void SetUp(){
        // init vector
        std::iota(std::begin(sorted_integers), std::end(sorted_integers), 0);
        std::reverse(sorted_integers.begin(),sorted_integers.end());
        // copy vector
        to_be_sorted = sorted_integers;
        // shuffle vector
        std::random_device r;
        std::shuffle(to_be_sorted.begin(),to_be_sorted.end(),r);

    }
    void TearDown(){
    }

    ~QuickSortIntFixtureDescending(){
        sorted_integers.clear();
        to_be_sorted.clear();
    }
};

TEST_F (QuickSortIntFixtureDescending,QuickSortIntDescending){
    auto quick_sort = SortingAlgorithms::GetSortingAlgorithm<int>(k_quick);
    quick_sort->Sort(&to_be_sorted,sort_order);
    EXPECT_THAT(to_be_sorted, ::testing::ContainerEq(sorted_integers));
}
//Counting Sort Tests
class CountingSortIntFixtureAscending : public ::testing::Test{
public:
    std::vector<int> sorted_integers = std::vector<int>(sort_vector_length);
    std::vector<int> to_be_sorted;
    SortingOrder sort_order = K_ascending;
    CountingSortIntFixtureAscending(){

    }
    void SetUp(){
        // init vector
        std::iota(std::begin(sorted_integers), std::end(sorted_integers), 0);
        // copy vector
        to_be_sorted = sorted_integers;
        // shuffle vector
        std::random_device r;
        std::shuffle(to_be_sorted.begin(),to_be_sorted.end(),r);

    }
    void TearDown(){
    }

    ~CountingSortIntFixtureAscending(){
        sorted_integers.clear();
        to_be_sorted.clear();
    }
};

TEST_F (CountingSortIntFixtureAscending,CountingSortIntAscending){
    auto counting_sort = SortingAlgorithms::GetSortingAlgorithm<int>(k_quick);
    counting_sort->Sort(&to_be_sorted,sort_order);
    EXPECT_THAT(to_be_sorted, ::testing::ContainerEq(sorted_integers));
}

class CountingSortIntFixtureDescending : public ::testing::Test{
public:
    std::vector<int> sorted_integers = std::vector<int>(sort_vector_length);
    std::vector<int> to_be_sorted;
    SortingOrder sort_order = k_descending;
    CountingSortIntFixtureDescending(){

    }
    void SetUp(){
        // init vector
        std::iota(std::begin(sorted_integers), std::end(sorted_integers), 0);
        std::reverse(sorted_integers.begin(),sorted_integers.end());
        // copy vector
        to_be_sorted = sorted_integers;
        // shuffle vector
        std::random_device r;
        std::shuffle(to_be_sorted.begin(),to_be_sorted.end(),r);

    }
    void TearDown(){
    }

    ~CountingSortIntFixtureDescending(){
        sorted_integers.clear();
        to_be_sorted.clear();
    }
};
TEST_F (CountingSortIntFixtureDescending,CountingSortIntDescending){
    auto counting_sort = SortingAlgorithms::GetSortingAlgorithm<int>(k_quick);
    counting_sort->Sort(&to_be_sorted,sort_order);
    EXPECT_THAT(to_be_sorted, ::testing::ContainerEq(sorted_integers));
}
int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc,argv);
    ::testing::InitGoogleMock(&argc,argv);

    return RUN_ALL_TESTS();
}
