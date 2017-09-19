#include"sorting_algorithms.h"
#include<random>
#include<gtest/gtest.h>
#include<gmock/gmock.h>

class BubbleSortIntFixture : public ::testing::Test{
public:
    std::vector<int> ten_integers = std::vector<int>(10);
    std::vector<int> to_be_sorted;
    SortingOrder sort_order = K_ascending;
    BubbleSortIntFixture(){

    }
    void SetUp(){
        // init vector
        std::iota(std::begin(ten_integers), std::end(ten_integers), 0);
        // copy vector
        to_be_sorted = ten_integers;
        // shuffle vector
        std::random_device r;
        std::shuffle(to_be_sorted.begin(),to_be_sorted.end(),r);

    }
    void TearDown(){
    }

    ~BubbleSortIntFixture(){
        ten_integers.clear();
        to_be_sorted.clear();
    }
};

TEST_F (BubbleSortIntFixture,BubbleSortInt){
    auto Sort = SortingAlgorithms::GetSortingAlgorithm<int>(k_bubble);
    Sort(&to_be_sorted,sort_order);
    EXPECT_THAT(to_be_sorted, ::testing::ContainerEq(ten_integers));
}

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
    ::testing::InitGoogleTest(&argc,argv);
    ::testing::InitGoogleMock(&argc,argv);

    return RUN_ALL_TESTS();
}
