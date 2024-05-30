// Copyright 2024 Fedotov Kirill
#include "tasks.h"
#include "circle.h"

const double earth_rad = 6378100;

double earthAndRope(double rope_len) {
    Circle earth(earth_rad);
    double newFerence = earth.getFerence() + rope_len;
    Circle earth2(newFerence);
    return earth2.getRadius() - earth.getRadius();
}

double poolCost(double pool_rad, double road_wid,
    double concrete_cost, double fence_cost) {
    Circle pool(pool_rad);
    Circle poolWithRoad(pool.getRadius() + road_wid);
    double concreteArea = poolWithRoad.getArea() - pool.getArea();
    double fenceFerence = poolWithRoad.getFerence();

    return concreteArea * concrete_cost + fenceFerence * fence_cost;
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

    double concreteArea = M_PI * (std::pow(pool_rad + road_wid, 2) - std::pow(pool_rad, 2));
    double fenceFerence = 2 * M_PI * (pool_rad + road_wid);

    double expected_cost = concreteArea * concrete_cost + fenceFerence * fence_cost;
    double actual_cost = poolCost(pool_rad, road_wid, concrete_cost, fence_cost);
    EXPECT_NEAR(actual_cost, expected_cost, 1e-6);
}
