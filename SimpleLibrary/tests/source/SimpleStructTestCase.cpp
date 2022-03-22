#include "gtest/gtest.h"

#include <stdexcept>

#include <SimpleLibrary/SimpleStruct.h>

using namespace std;

TEST(SimpleStructTest, initialize){
  double a = 0;
  double b = 0;
  SimpleStruct<double> s = SimpleStruct<double>(a, b);
  ASSERT_EQ(s.a, a);
  ASSERT_EQ(s.b, b);
}

TEST(SimpleStructTest, greaterThanOverload){
  SimpleStruct<double> s1 = SimpleStruct<double>(0, 0);
  SimpleStruct<double> s2 = SimpleStruct<double>(1, 1);

  ASSERT_TRUE((s2 > s1));
  ASSERT_FALSE((s1 > s2));
}

TEST(SimpleStructTest, lessThanOverload){
  SimpleStruct<double> s1 = SimpleStruct<double>(0, 0);
  SimpleStruct<double> s2 = SimpleStruct<double>(1, 1);

  ASSERT_TRUE((s1 < s2));
  ASSERT_FALSE((s2 < s1));
}

TEST(SimpleStructTest, equalOverload){
  {
  SimpleStruct<double> s1 = SimpleStruct<double>(0, 0);
  SimpleStruct<double> s2 = SimpleStruct<double>(0, 0);
  ASSERT_TRUE((s1 == s2));
  }

  {
  SimpleStruct<double> s1 = SimpleStruct<double>(1, 1);
  SimpleStruct<double> s2 = SimpleStruct<double>(1, 1);
  ASSERT_TRUE((s1 == s2));
  }

  {
  SimpleStruct<double> s1 = SimpleStruct<double>(0, 1);
  SimpleStruct<double> s2 = SimpleStruct<double>(0, 0);
  ASSERT_FALSE((s1 == s2));
  }
}

TEST(SimpleStructTest, minusOverload){
  {
  SimpleStruct<double> s1 = SimpleStruct<double>(0, 0);
  SimpleStruct<double> s2 = SimpleStruct<double>(1, 5);
  SimpleStruct<double> s3 = (s2 - s1);

  ASSERT_EQ(s3.a, 1);
  ASSERT_EQ(s3.b, 5);
  }
}

TEST(SimpleStructTest, arrayOverload){
  SimpleStruct<double> s1 = SimpleStruct<double>(0, 1);

  ASSERT_EQ(s1[0], 0);
  ASSERT_EQ(s1[1], 1);
}

TEST(SimpleStructTest, arrayOverloadOutOfBounds){
  SimpleStruct<double> s1 = SimpleStruct<double>(0, 1);

  int index = -1;
  try{
    s1[index];
    FAIL() << "Expected std::out_of_range";
  }
  catch(std::out_of_range const & err) {
    EXPECT_EQ(err.what(), std::string("Index out of range"));
  }
  catch(...){
    FAIL() << "Expected std::out_of_range";
  }

  index = 2;
  try{
    s1[index];
    FAIL() << "Expected std::out_of_range";
  }
  catch(std::out_of_range const & err) {
    EXPECT_EQ(err.what(), std::string("Index out of range"));
  }
  catch(...){
    FAIL() << "Expected std::out_of_range";
  }
}

