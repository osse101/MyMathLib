
#ifndef VECTOR2D_TEST_CPP
#define VECTOR2D_TEST_CPP

#include "stdafx.h"
#include <vector2.h>

class Vector2Test : public ::testing::Test{
	protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  Vector2Test() {
    // You can do set-up work for each test here.
	  testVect1 = Vector2();
	  testVect2 = Vector2(1.0f, 2.0f);
	  testVect3 = Vector2(10.5f, -9.4f);
	  testMax = Vector2(FLT_MAX, FLT_MAX);
	  testMin = Vector2(FLT_MIN, FLT_MIN);
  }

  virtual ~Vector2Test() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for Foo.
  Vector2 testVect1;		//Zero vector
  Vector2 testVect2;		//Simple vector
  Vector2 testVect3;		//Complex vector
  Vector2 testMax;			//Max values
  Vector2 testMin;			//Min values
  Vector2 testVectResult;	//result storage

};


TEST_F(Vector2Test, Vector_Init){
	//TODO: int constructor

	EXPECT_FLOAT_EQ(0.0f, testVect1.x);
	EXPECT_FLOAT_EQ(0.0f, testVect1.y);
	EXPECT_FLOAT_EQ(1.0f, testVect2.x);
	EXPECT_FLOAT_EQ(2.0f, testVect2.y);
	EXPECT_FLOAT_EQ(10.5f, testVect3.x);
	EXPECT_FLOAT_EQ(-9.4f, testVect3.y);
	EXPECT_FLOAT_EQ(FLT_MAX, testMax.x);
	EXPECT_FLOAT_EQ(FLT_MAX, testMax.y);
	EXPECT_FLOAT_EQ(FLT_MIN, testMin.x);
	EXPECT_FLOAT_EQ(FLT_MIN, testMin.y);
}

TEST_F(Vector2Test, Vector_Add){
	testVectResult = testVect1 + testVect1;
	EXPECT_FLOAT_EQ(0.0f, testVectResult.x);
	EXPECT_FLOAT_EQ(0.0f, testVectResult.y);

	testVectResult = testVect1 + testVect2;
	EXPECT_FLOAT_EQ(testVect2.x, testVectResult.x);
	EXPECT_FLOAT_EQ(testVect2.y, testVectResult.y);

	testVectResult = testVect2 + testVect3;
	EXPECT_FLOAT_EQ(testVect2.x + testVect3.x, testVectResult.x);
	EXPECT_FLOAT_EQ(testVect2.y + testVect3.y, testVectResult.y);
	// overflow
	testVectResult = testMax + testMax;
	//TODO: handle overflow

	// underflow
	testVectResult = testMin + testMin;	//addition of negatives
	//TODO: handle underflow
}

TEST_F(Vector2Test, Vector_Subtract){
	testVectResult = testVect1 - testVect1;
	EXPECT_FLOAT_EQ(0.0f, testVectResult.x);
	EXPECT_FLOAT_EQ(0.0f, testVectResult.y);

	testVectResult = testVect1 - testVect2;
	EXPECT_FLOAT_EQ(-testVect2.x, testVectResult.x);
	EXPECT_FLOAT_EQ(-testVect2.y, testVectResult.y);

	testVectResult = testVect2 - testVect3;
	EXPECT_FLOAT_EQ(testVect2.x - testVect3.x, testVectResult.x);
	EXPECT_FLOAT_EQ(testVect2.y - testVect3.y, testVectResult.y);
	
	// overflow
	testVectResult = testMax - testMin;
	//TODO: handle overflow

	// underflow
	testVectResult = testMin - testMax;	
	//TODO: handle underflow
}

TEST_F(Vector2Test, Vector_Multiply){
	testVectResult = testVect1 * testVect1;
	EXPECT_FLOAT_EQ(0.0f, testVectResult.x);
	EXPECT_FLOAT_EQ(0.0f, testVectResult.y);

	testVectResult = testVect1 * testVect2;
	EXPECT_FLOAT_EQ(-testVect2.x, testVectResult.x);
	EXPECT_FLOAT_EQ(-testVect2.y, testVectResult.y);

	testVectResult = testVect2 * testVect3;
	EXPECT_FLOAT_EQ(testVect2.x * testVect3.x, testVectResult.x);
	EXPECT_FLOAT_EQ(testVect2.y * testVect3.y, testVectResult.y);

	// overflow
	testVectResult = testMax * testMax;
	//TODO: handle overflow

	// can't underflow
}

TEST_F(Vector2Test, Vector_Divide){
	testVectResult = testVect1 / testVect1;
	EXPECT_FLOAT_EQ(0.0f, testVectResult.x);
	EXPECT_FLOAT_EQ(0.0f, testVectResult.y);

	testVectResult = testVect1 / testVect2;
	EXPECT_FLOAT_EQ(-testVect2.x, testVectResult.x);
	EXPECT_FLOAT_EQ(-testVect2.y, testVectResult.y);

	testVectResult = testVect2 / testVect3;
	EXPECT_FLOAT_EQ(testVect2.x / testVect3.x, testVectResult.x);
	EXPECT_FLOAT_EQ(testVect2.y / testVect3.y, testVectResult.y);

	//Divide by 0
	testVectResult = testVect2 / testVect1;
	EXPECT_FLOAT_EQ(testVect2.x / testVect3.x, testVectResult.x);
	EXPECT_FLOAT_EQ(testVect2.y / testVect3.y, testVectResult.y);
	
	// can't overflow
	// can't underflow
}


#endif