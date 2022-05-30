//-----------------------------------------------------------------------
//  Header      : Vector2f.cpp
//  Created     : 30.05.2022
//  Modified    : 30.05.2022 
//  Author      : Dmitry Safronov 
//  Description : Tests for Vector2f class 
//-----------------------------------------------------------------------

#include "gtest/gtest.h"

#include "Vector2f.h"
#include <map>
#include <vector>

#define VECTOR_EPSILON 0.001

// lookup table for degrees and coordinates
std::map<int, std::vector<double>> anglesLTB = {
  {0, {1, 0}},
  {30, {sqrt(3)/2, 0.5}},
  {45, {sqrt(2)/2, sqrt(2)/2}},
  {60, {0.5, sqrt(3)/2}},
  {90, {0, 1}},
  {120, {-0.5, sqrt(3)/2}},
  {135, {-sqrt(2)/2, sqrt(2)/2}},
  {150, {-sqrt(3)/2, 0.5}},
  {180, {-1, 0}},
  {210, {-sqrt(3)/2, -0.5}},
  {225, {-sqrt(2)/2, -sqrt(2)/2}},
  {240, {-0.5, -sqrt(3)/2}},
  {270, {0, -1}},
  {300, {0.5, -sqrt(3)/2}},
  {315, {sqrt(2)/2, -sqrt(2)/2}},
  {330, {sqrt(3)/2, -0.5}},
  {360, {1, 0}}
};

// Test for getters and setters
TEST(Vector2f, properties)
{
  Vector2f uut(1, 0);
  
  EXPECT_EQ(uut.getX(), 1);
  EXPECT_EQ(uut.getY(), 0);

  uut.setX(0);
  uut.setY(1);

  EXPECT_EQ(uut.getX(), 0);
  EXPECT_EQ(uut.getY(), 1);
}
// Test for rotateD method
TEST(Vector2f, rotateD)
{
  // 0 - 360 degrees
  for(auto a : anglesLTB)
  {
    Vector2f uut(1, 0);
    uut.rotateD(a.first);
    std::vector<double> expected = a.second;
    std::vector<double> real = {uut.getX(), uut.getY()};
    ASSERT_NEAR(expected[0], real[0], VECTOR_EPSILON);
    ASSERT_NEAR(expected[1], real[1], VECTOR_EPSILON);
  }

  // -45 degrees
  Vector2f uut(sqrt(2)/2, sqrt(2)/2);
  uut.rotateD(-45);
  std::vector<double> expected = {1, 0};
  std::vector<double> real = {uut.getX(), uut.getY()};
  ASSERT_NEAR(expected[0], real[0], VECTOR_EPSILON);
  ASSERT_NEAR(expected[1], real[1], VECTOR_EPSILON);
}

// Test for rotateR methoc
TEST(Vector2f, rotateR)
{
  // 0 - 2PI radians
  for(auto a : anglesLTB)
  {
    Vector2f uut(1, 0);
    uut.rotateR(a.first*M_PI/180);
    std::vector<double> expected = a.second;
    std::vector<double> real = {uut.getX(), uut.getY()};
    ASSERT_NEAR(expected[0], real[0], VECTOR_EPSILON);
    ASSERT_NEAR(expected[1], real[1], VECTOR_EPSILON);
  }

  // PI/4 - 0 radians
  Vector2f uut(sqrt(2)/2, sqrt(2)/2);
  uut.rotateR(-M_PI/4);
  std::vector<double> expected = {1, 0};
  std::vector<double> real = {uut.getX(), uut.getY()};
  ASSERT_NEAR(expected[0], real[0], VECTOR_EPSILON);
  ASSERT_NEAR(expected[1], real[1], VECTOR_EPSILON);

}


// Test getAngleD method
TEST(Vector2f, getAngleD)
{
  // 0 - 330 degrees 
  for(auto a : anglesLTB)
  {
    if(a.first == 360)
      break;
    auto coords = a.second;
    Vector2f uut(coords[0], coords[1]);
    ASSERT_NEAR(a.first, uut.getAngelD(), VECTOR_EPSILON);
  }
}

// Test getAngleR method
TEST(Vector2f, getAngleR)
{
  // 0 - 11PI/6
  for(auto a : anglesLTB)
  {
    if(a.first == 360)
      break;
    auto coords = a.second;
    Vector2f uut(coords[0], coords[1]);
    ASSERT_NEAR(a.first*M_PI/180, uut.getAngleR(), VECTOR_EPSILON);
  }
}

// Test setModule method
TEST(Vector2f, setModule)
{
  // setModule 10 for Vector2f(1, 0)
  Vector2f uut(1, 0);
  uut.setModule(10);
  std::vector<double> expected(10, 0);
  std::vector<double> real(uut.getX(), uut.getY());
  ASSERT_NEAR(expected[0], real[0], VECTOR_EPSILON);
  ASSERT_NEAR(expected[1], real[1], VECTOR_EPSILON);

  // setModule 7 for Vector(0, -1)
  uut.setX(0);
  uut.setY(-1);
  uut.setModule(7);
  expected = {0, -7};
  real = {uut.getX(), uut.getY()};
  ASSERT_NEAR(expected[0], real[0], VECTOR_EPSILON);
  ASSERT_NEAR(expected[1], real[1], VECTOR_EPSILON);

  // setModule 2 for Vector(sqrt(2)/2, sqrt(2)/2)
  uut.setX(1);
  uut.setY(0);
  uut.rotateD(45);
  uut.setModule(2);
  ASSERT_NEAR(2, sqrt(pow(uut.getX(), 2) + pow(uut.getY(), 2)), VECTOR_EPSILON);

  // setModule 0.5 for Vector(1/2, sqrt(3)/2)
  uut.setX(1);
  uut.setY(0);
  uut.rotateD(60);
  uut.setModule(3);
  uut.setModule(0.5);
  ASSERT_NEAR(0.5, sqrt(pow(uut.getX(), 2) + pow(uut.getY(), 2)), VECTOR_EPSILON);
}