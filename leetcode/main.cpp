#include <iostream>
#include <vector>
#include "./googletest/include/gtest/gtest.h"
#include "11ContainerWithMostWater.h"
using namespace std;

TEST(ContainerWithMostWater, 11){
//    vector<int> height {1,2,3,4,5,6,7,8,9,10};
    vector<int> height {1,2};
    EXPECT_EQ(1, ContainerWithMostWater::maxArea1(height));
}

GTEST_API_ int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}