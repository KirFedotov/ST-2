// Copyright 2024 Fedotov Kirill
#include "gtest/gtest.h"
#include "circle.h"
#include "tasks.h"

TEST(CircleTest, DefaultConstructor) {
    Circle circle;
    EXPECT_DOUBLE_EQ(circle.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(circle.getArea(), 0.0);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 0.0);
}

TEST(CircleTest, ParameterizedConstructor) {
    Circle circle(1.0);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 1.0);
    EXPECT_DOUBLE_EQ(circle.getArea(), M_PI);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 2 * M_PI);
}

TEST(CircleTest, SetArea) {
    Circle circle;
    circle.setArea(M_PI);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 1.0);
    EXPECT_DOUBLE_EQ(circle.getArea(), M_PI);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 2 * M_PI);
}

TEST(CircleTest, SetAreaToZero) {
    Circle circle;
    circle.setArea(0.0);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(circle.getArea(), 0.0);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 0.0);
}

TEST(CircleTest, SetAreaPositive) {
    Circle circle;
    double area = 4 * M_PI;
    circle.setArea(area);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 2.0);
    EXPECT_DOUBLE_EQ(circle.getArea(), area);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 4 * M_PI);
}

TEST(CircleTest, SetFerence) {
    Circle circle;
    circle.setFerence(2 * M_PI);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 1.0);
    EXPECT_DOUBLE_EQ(circle.getArea(), M_PI);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 2 * M_PI);
}

TEST(CircleTest, SetFerenceToZero) {
    Circle circle;
    circle.setFerence(0.0);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(circle.getArea(), 0.0);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 0.0);
}

TEST(CircleTest, SetFerencePositive) {
    Circle circle;
    double ference = 4 * M_PI;
    circle.setFerence(ference);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 2.0);
    EXPECT_DOUBLE_EQ(circle.getArea(), 4 * M_PI);
    EXPECT_DOUBLE_EQ(circle.getFerence(), ference);
}

TEST(CircleTest, SetRadius) {
    Circle circle;
    circle.setRadius(1.0);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 1.0);
    EXPECT_DOUBLE_EQ(circle.getArea(), M_PI);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 2 * M_PI);
}

TEST(CircleTest, SetRadiusToZero) {
    Circle circle;
    circle.setRadius(0.0);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(circle.getArea(), 0.0);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 0.0);
}

TEST(CircleTest, SetRadiusPositive) {
    Circle circle;
    double radius = 2.0;
    circle.setRadius(radius);
    EXPECT_DOUBLE_EQ(circle.getRadius(), radius);
    EXPECT_DOUBLE_EQ(circle.getArea(), M_PI * radius * radius);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 2 * M_PI * radius);
}

TEST(CircleTest, GetArea) {
    Circle circle(1.0);
    EXPECT_DOUBLE_EQ(circle.getArea(), M_PI);
}

TEST(CircleTest, GetFerence) {
    Circle circle(1.0);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 2 * M_PI);
}

TEST(CircleTest, GetRadius) {
    Circle circle(1.0);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 1.0);
}

TEST(CircleTest, ComplexTest1) {
    Circle circle(2.0);
    circle.setArea(M_PI * 4);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 2.0);
    EXPECT_DOUBLE_EQ(circle.getArea(), M_PI * 4);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 4 * M_PI);
}

TEST(CircleTest, ComplexTest2) {
    Circle circle(2.0);
    circle.setFerence(2 * M_PI * 3);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 3.0);
    EXPECT_DOUBLE_EQ(circle.getArea(), M_PI * 9);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 2 * M_PI * 3);
}

TEST(CircleTest, ComplexTest3) {
    Circle circle;
    circle.setRadius(3.0);
    circle.setArea(M_PI * 9);
    circle.setFerence(2 * M_PI * 3);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 3.0);
    EXPECT_DOUBLE_EQ(circle.getArea(), M_PI * 9);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 2 * M_PI * 3);
}

TEST(CircleTest, ComplexTest4) {
    Circle circle;
    circle.setRadius(3.0);
    circle.setFerence(2 * M_PI * 3);
    circle.setArea(M_PI * 9);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 3.0);
    EXPECT_DOUBLE_EQ(circle.getArea(), M_PI * 9);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 2 * M_PI * 3);
}

TEST(CircleTest, ComplexTest5) {
    Circle circle(4.0);
    circle.setFerence(2 * M_PI * 2);
    circle.setArea(M_PI * 2 * 2);
    EXPECT_DOUBLE_EQ(circle.getRadius(), 2.0);
    EXPECT_DOUBLE_EQ(circle.getArea(), M_PI * 2 * 2);
    EXPECT_DOUBLE_EQ(circle.getFerence(), 2 * M_PI * 2);
}

TEST(TasksTest, EarthAndRopeTest) {
    double rope_len = 10.0;
    double expected_increase = rope_len / (2 * M_PI);
    double actual_increase = earthAndRope(rope_len);
    EXPECT_NEAR(actual_increase, expected_increase, 1e-6);
}

TEST(TasksTest, PoolCostTest) {
    double pool_rad = 5.0;
    double road_wid = 2.0;
    double concrete_cost = 10.0;
    double fence_cost = 5.0;

    double concreteArea = M_PI * (std::pow(pool_rad + road_wid, 2)
     - std::pow(pool_rad, 2));
    double fenceFerence = 2 * M_PI * (pool_rad + road_wid);

    double expected_cost = concreteArea * concrete_cost
     + fenceFerence * fence_cost;
    double actual_cost = poolCost(pool_rad, road_wid,
     concrete_cost, fence_cost);
    EXPECT_NEAR(actual_cost, expected_cost, 1e-6);
}
