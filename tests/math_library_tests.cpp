#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include <gtest/gtest.h>
#include <fstream>
#include "math_lib.h"

class MathLibTestFixture : public ::testing::Test
{
protected:

    void SetUp() override
    {
		// Do some job before test run
    }

    void TearDown() override
    {
		// Do some job after test run
    }
};

TEST_F(MathLibTestFixture, AddTwoValues)
{
    EXPECT_EQ(MathLib::add(10.5, 2.5), 13.0);
    EXPECT_TRUE(MathLib::isEqual(MathLib::add(10.5, 2.5), 13.0));
    EXPECT_FALSE(MathLib::isEqual(MathLib::add(10.5, 2.5), 13.0001));
}

TEST_F(MathLibTestFixture, SubTwoValues)
{
    EXPECT_NE(MathLib::subtract(10, 7), 4);
    EXPECT_EQ(MathLib::subtract(10, 7), 3);
}

TEST_F(MathLibTestFixture, MultiplyTwoValues)
{
    EXPECT_EQ(MathLib::multiply(10, 7), 70);
    EXPECT_NE(MathLib::multiply(10, 7), 71);
}

TEST_F(MathLibTestFixture, DivideTwoValues)
{
    EXPECT_EQ(MathLib::divide(10, 2), 5);
    EXPECT_NE(MathLib::divide(10, 2), 3);
}

TEST_F(MathLibTestFixture, DivideByZero)
{
    EXPECT_THROW(MathLib::divide(10, 0), std::invalid_argument);
}

TEST_F(MathLibTestFixture, SquareRoot)
{
    //EXPECT_EQ(MathLib::isEqual(MathLib::sqrt(0), 0));
    //EXPECT_EQ(MathLib::isEqual(MathLib::sqrt(1.231), 1.1095));
    //EXPECT_EQ(MathLib::isEqual(MathLib::sqrt(16), 4));
    //EXPECT_EQ(MathLib::isEqual(MathLib::sqrt(123), 11.0905));
    EXPECT_THROW(MathLib::sqrt(-1), std::invalid_argument);
}

TEST_F(MathLibTestFixture, LeastCommonMultiple)
{
    EXPECT_EQ(MathLib::leastCommonMultiple(4, 6), 12);
    EXPECT_EQ(MathLib::leastCommonMultiple(7, 5), 35);
    EXPECT_EQ(MathLib::leastCommonMultiple(10, 5), 10);
    EXPECT_NE(MathLib::leastCommonMultiple(4,6), 3);
}

TEST_F(MathLibTestFixture, IsPrimeTest)
{
    EXPECT_TRUE(MathLib::isPrime(2));
    EXPECT_TRUE(MathLib::isPrime(3));
    EXPECT_FALSE(MathLib::isPrime(4));
    EXPECT_TRUE(MathLib::isPrime(5));
}

TEST_F(MathLibTestFixture, GreatestCommonDivider)
{
    EXPECT_EQ(MathLib::GCD(10, 6), 2);
}
TEST(MathLibTestFixture, Trapez_ZeroFunction) {
    auto f = [](double){ return 0.0; };
    EXPECT_NEAR(trapez(f, 0, 10, 1e-6), 0.0, 1e-9);
}

TEST(MathLibTestFixture, Trapez_LinearFunction) {
    auto f = [](double x){ return x; };
    EXPECT_NEAR(trapez(f, 0, 1, 1e-6), 0.5, 1e-6);
}

TEST(MathLibTestFixture, Trapez_QuadraticFunction) {
    auto f = [](double x){ return x*x; };
    EXPECT_NEAR(trapez(f, 0, 1, 1e-6), 1.0/3.0, 1e-6);
}

TEST(MathLibTestFixture, Trapez_SinFunction) {
    auto f = [](double x){ return sin(x); };
    EXPECT_NEAR(trapez(f, 0, M_PI, 1e-6), 2.0, 1e-6);
}

TEST(MathLibTestFixture, Trapez_CustomFunction) {
    double result = trapez(y, 0, 5, 1e-6);
    EXPECT_NEAR(result, -0.212214, 1e-5);
}
TEST_F(MathLibTestFixture, ThirdAngle_Valid)
{
    EXPECT_DOUBLE_EQ(MathLib::thirdAngle(60, 90), 30.0);
    EXPECT_DOUBLE_EQ(MathLib::thirdAngle(45, 45), 90.0);
    EXPECT_DOUBLE_EQ(MathLib::thirdAngle(30, 60), 90.0);
}

TEST_F(MathLibTestFixture, ThirdAngle_InvalidNegative)
{
    EXPECT_THROW(MathLib::thirdAngle(-10, 60), std::invalid_argument);
    EXPECT_THROW(MathLib::thirdAngle(60, -5), std::invalid_argument);
    EXPECT_THROW(MathLib::thirdAngle(-10, -20), std::invalid_argument);
}

TEST_F(MathLibTestFixture, ThirdAngle_InvalidSum)
{
    EXPECT_THROW(MathLib::thirdAngle(100, 100), std::invalid_argument);
    EXPECT_THROW(MathLib::thirdAngle(90, 90), std::invalid_argument);
    EXPECT_THROW(MathLib::thirdAngle(179, 2), std::invalid_argument);
}
