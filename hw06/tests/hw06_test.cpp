#include <hw06.h>
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <cctype> 
#include <iostream>
#include <memory>
using namespace std;


TEST(Hw06Tests, Test1) {
    MyIntVector* v=new MyIntVector(5,1);
    ASSERT_EQ(5, (*v).size());
    ASSERT_EQ(5, (*v).capacity());
    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(1,(*v).get_array()[i]);
    }
}

TEST(Hw06Tests, Test2) {
    MyIntVector v=MyIntVector();
    v.push_back(1);
    ASSERT_EQ(1, v.size());
    ASSERT_EQ(1, v.capacity());
    ASSERT_EQ(1, v.get_array()[0]);
}

TEST(Hw06Tests, Test3) {
    MyIntVector v=MyIntVector();
    v.resize(5);
    ASSERT_EQ(5, v.size());
    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(0, v.get_array()[i]);
    }
}

TEST(Hw06Tests, Test4) {
    // MyIntVector v= *(new MyIntVector(2, 1));
    // v.reserve(5);
    // ASSERT_EQ(2, (v).size());
    // ASSERT_EQ(5, (v).capacity());
    // for (int i = 0; i < 2; i++) {
    //     ASSERT_EQ(1, (v).get_array()[i]);
    // }
       
    unique_ptr<MyIntVector> v(new MyIntVector());
    (*v).push_back(1);
    (*v).push_back(1);
    (*v).reserve(10);
    ASSERT_EQ(2, (*v).size());
    ASSERT_EQ(10, (*v).capacity());
    for (int i = 0; i < 2; i++) {
        ASSERT_EQ(1, (*v).get_array()[i]);
    }
}

TEST(Hw06Tests, Test5) {
    MyIntVector v=MyIntVector();
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.shrink_to_fit();
    ASSERT_EQ(5, v.size());
    ASSERT_EQ(5, v.capacity());
    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(1, v.get_array()[i]);
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
