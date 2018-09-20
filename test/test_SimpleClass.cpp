#include "../src/SimpleClass.h"

#include "gtest/gtest.h"

using namespace std;

class SimpleClassTest
  : public testing::Test
{
protected:
  SimpleClass accumulator;

  virtual void SetUp()
  {

  }

  virtual void TearDown()
  {
  }
};

TEST_F(SimpleClassTest, accumulateStartsZero){
  ASSERT_EQ(0, accumulator.getValue());
}

TEST_F(SimpleClassTest, accumulateOne){
  accumulator.addValue(1);
  ASSERT_EQ(1, accumulator.getValue());
}

TEST_F(SimpleClassTest, accumulateTwo){
  accumulator.addValue(1);
  accumulator.addValue(2);
  ASSERT_EQ(3, accumulator.getValue());
}

TEST_F(SimpleClassTest, accumulateThree){
  accumulator.addValue(1);
  accumulator.addValue(2);
  accumulator.addValue(3);
  ASSERT_EQ(6, accumulator.getValue());
}

TEST_F(SimpleClassTest, accumulateNegative){
  accumulator.addValue(-1);
  ASSERT_EQ(-1, accumulator.getValue());
}

TEST_F(SimpleClassTest, accumulateBackForth){
  accumulator.addValue(-1);
  accumulator.addValue(1);
  ASSERT_EQ(0, accumulator.getValue());
}