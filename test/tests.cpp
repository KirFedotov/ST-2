// Copyright 2024 Fedotov Kirill
#include "gtest/gtest.h"
#include "circle.h"
#include "tasks.h"

TEST(Fedotov_tests_task, PoolRadius) {
    const double poolRadius = 3.0;
    const double roadWidth = 1.0;
    const double concreteCost = 1000.0;
    const double fenceCost = 2000.0;
    Circle pool(poolRadius);
    Circle poolWithRoad(pool.getRadius() + roadWidth);
    double concreteArea = poolWithRoad.getArea() - pool.getArea();
    double fenceFerence = poolWithRoad.getFerence();

    EXPECT_EQ(poolCost(poolRadius, roadWidth, concreteCost, fenceCost),
        concreteArea * concreteCost + fenceFerence * fenceCost);
}

TEST(Fedotov_tests_task, CustomParameters) {
    const double poolRadius = 2.5;
    const double roadWidth = 0.5;
    const double concreteCost = 800.0;
    const double fenceCost = 1500.0;
    EXPECT_NEAR(poolCost(poolRadius, roadWidth, concreteCost, fenceCost),
        35185.8, 1e-1);
}

TEST(Fedotov_tests_circle, Constructor) {
    Circle circle;
    EXPECT_EQ(circle.getRadius(), 0.0);
    EXPECT_EQ(circle.getFerence(), 0.0);
    EXPECT_EQ(circle.getArea(), 0.0);
}

TEST(Fedotov_tests_circle, SetRadius) {
    Circle circle;
    circle.setRadius(5.0);
    EXPECT_NEAR(circle.getRadius(), 5.0, 1e-8);
    EXPECT_NEAR(circle.getFerence(), 31.4159265359, 1e-8);
    EXPECT_NEAR(circle.getArea(), 78.5398163397, 1e-8);
}

TEST(Fedotov_tests_circle, SetFerence) {
    Circle circle;
    circle.setFerence(10.0);
    EXPECT_NEAR(circle.getRadius(), 1.59154943092, 1e-8);
    EXPECT_NEAR(circle.getFerence(), 10.0, 1e-8);
}

TEST(Fedotov_tests_circle, GetArea) {
    Circle circle(2.5);
    EXPECT_NEAR(circle.getArea(), 19.6349540849, 1e-8);
}

TEST(Fedotov_tests_circle, GetRadius) {
    Circle circle(2.5);
    EXPECT_NEAR(circle.getRadius(), 2.5, 1e-8);
}

TEST(Fedotov_tests_circle, SetArea) {
    Circle circle;
    circle.setArea(50.0);
    EXPECT_NEAR(circle.getRadius(), 3.98, 1e-1);
}

TEST(Fedotov_tests_circle, GetFerence) {
    Circle circle(2.5);
    EXPECT_NEAR(circle.getFerence(), 15.7079632679, 1e-8);
}

TEST(Fedotov_tests_circle, BigRadius) {
    Circle circle(1e9);
    EXPECT_NEAR(circle.getRadius(), 1e9, 1e-8);
}

TEST(Fedotov_tests_circle, SmallRadius) {
    Circle circle(1e-9);
    EXPECT_NEAR(circle.getRadius(), 1e-9, 1e-8);
    EXPECT_NEAR(circle.getFerence(), 6.28318530718e-9, 1e-8);
    EXPECT_NEAR(circle.getArea(), 3.14159265359e-18, 1e-8);
}

TEST(Fedotov_tests_circle, ZeroRadius) {
    Circle circle(0.0);
    EXPECT_EQ(circle.getRadius(), 0.0);
    EXPECT_EQ(circle.getFerence(), 0.0);
    EXPECT_EQ(circle.getArea(), 0.0);
}

TEST(Fedotov_tests_circle, SetRadiusToZero) {
    Circle circle(5.0);
    circle.setRadius(0.0);
    EXPECT_EQ(circle.getRadius(), 0.0);
    EXPECT_EQ(circle.getFerence(), 0.0);
    EXPECT_EQ(circle.getArea(), 0.0);
}

TEST(Fedotov_tests_circle, SetFerenceToZero) {
    Circle circle(5.0);
    circle.setFerence(0.0);
    EXPECT_EQ(circle.getRadius(), 0.0);
    EXPECT_EQ(circle.getFerence(), 0.0);
    EXPECT_EQ(circle.getArea(), 0.0);
}

TEST(Fedotov_tests_circle, SetAreaToZero) {
    Circle circle(5.0);
    circle.setArea(0.0);
    EXPECT_EQ(circle.getRadius(), 0.0);
    EXPECT_EQ(circle.getFerence(), 0.0);
    EXPECT_EQ(circle.getArea(), 0.0);
}

TEST(Fedotov_tests_circle, ShortRope) {
    const double ropeLength = 0.000001;
    EXPECT_NEAR(earthAndRope(ropeLength), 33696684.2, 1e-1);
}


TEST(Fedotov_tests_circle, LongRope) {
    const double ropeLength = 1000000.0;
    EXPECT_NEAR(earthAndRope(ropeLength), 34696684.2, 1e-1);
}
