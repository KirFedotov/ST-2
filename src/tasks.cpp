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