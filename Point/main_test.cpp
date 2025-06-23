#include <iostream>
#include <cassert>
#include <cmath>
#include "Point.h"
#include "../Line/Line.h"
#include "../Vector/Vector.h"

// Simple test framework
int tests_passed = 0;
int tests_failed = 0;

#define ASSERT_EQ(expected, actual) \
    do { \
        if ((expected) == (actual)) { \
            std::cout << "✓ PASS: " << #expected << " == " << #actual << std::endl; \
            tests_passed++; \
        } else { \
            std::cout << "✗ FAIL: " << #expected << " == " << #actual << " (expected: " << (expected) << ", actual: " << (actual) << ")" << std::endl; \
            tests_failed++; \
        } \
    } while(0)

#define ASSERT_DOUBLE_EQ(expected, actual) \
    do { \
        if (std::abs((expected) - (actual)) < 1e-9) { \
            std::cout << "✓ PASS: " << #expected << " ≈ " << #actual << std::endl; \
            tests_passed++; \
        } else { \
            std::cout << "✗ FAIL: " << #expected << " ≈ " << #actual << " (expected: " << (expected) << ", actual: " << (actual) << ")" << std::endl; \
            tests_failed++; \
        } \
    } while(0)

void test_point_default_constructor() {
    std::cout << "\n=== Testing Point Default Constructor ===" << std::endl;
    Point p;
    ASSERT_DOUBLE_EQ(0.0, p.getX());
    ASSERT_DOUBLE_EQ(0.0, p.getY());
}

void test_point_parameterized_constructor() {
    std::cout << "\n=== Testing Point Parameterized Constructor ===" << std::endl;
    Point p1(3.0, 4.0);
    Point p2(-2.0, 1.0);
    
    ASSERT_DOUBLE_EQ(3.0, p1.getX());
    ASSERT_DOUBLE_EQ(4.0, p1.getY());
    ASSERT_DOUBLE_EQ(-2.0, p2.getX());
    ASSERT_DOUBLE_EQ(1.0, p2.getY());
}

void test_point_setters_getters() {
    std::cout << "\n=== Testing Point Setters and Getters ===" << std::endl;
    Point p;
    p.setX(5.5);
    p.setY(-3.2);
    
    ASSERT_DOUBLE_EQ(5.5, p.getX());
    ASSERT_DOUBLE_EQ(-3.2, p.getY());
    
    p.setXY(7.8, -9.1);
    ASSERT_DOUBLE_EQ(7.8, p.getX());
    ASSERT_DOUBLE_EQ(-9.1, p.getY());
}

void test_point_delimiter() {
    std::cout << "\n=== Testing Point Static Delimiter ===" << std::endl;
    ASSERT_EQ(',', Point::delimiter);
}

void test_line_default_constructor() {
    std::cout << "\n=== Testing Line Default Constructor ===" << std::endl;
    Line l;
    // Can only test length since no getters available
    ASSERT_DOUBLE_EQ(0.0, l.length());
}

void test_line_parameterized_constructor() {
    std::cout << "\n=== Testing Line Parameterized Constructor ===" << std::endl;
    Point start(0.0, 0.0);
    Point end(3.0, 4.0);
    Line line(start, end);
    
    // Distance from (0,0) to (3,4) should be 5.0
    ASSERT_DOUBLE_EQ(5.0, line.length());
}

void test_line_length() {
    std::cout << "\n=== Testing Line Length ===" << std::endl;
    Point start(0.0, 0.0);
    Point end(3.0, 4.0);
    Line line(start, end);
    
    // Distance from (0,0) to (3,4) should be 5.0
    double expected = std::sqrt(3.0*3.0 + 4.0*4.0);
    ASSERT_DOUBLE_EQ(expected, line.length());
    ASSERT_DOUBLE_EQ(5.0, line.length());
    
    // Test different line
    Point start2(1.0, 1.0);
    Point end2(4.0, 5.0);
    Line line2(start2, end2);
    // Distance from (1,1) to (4,5) = sqrt(9+16) = 5.0
    ASSERT_DOUBLE_EQ(5.0, line2.length());
}

void test_vector_default_constructor() {
    std::cout << "\n=== Testing Vector Default Constructor ===" << std::endl;
    Vector<int> vec;
    ASSERT_EQ(0, vec.size());
    ASSERT_EQ(true, vec.isEmpty());
}

void test_vector_push_back() {
    std::cout << "\n=== Testing Vector Push Back ===" << std::endl;
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    
    ASSERT_EQ(3, vec.size());
    ASSERT_EQ(false, vec.isEmpty());
    ASSERT_EQ(10, vec[0]);
    ASSERT_EQ(20, vec[1]);
    ASSERT_EQ(30, vec[2]);
}

void test_vector_copy_constructor() {
    std::cout << "\n=== Testing Vector Copy Constructor ===" << std::endl;
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    
    Vector<int> vec2(vec);
    
    ASSERT_EQ(3, vec2.size());
    ASSERT_EQ(1, vec2[0]);
    ASSERT_EQ(2, vec2[1]);
    ASSERT_EQ(3, vec2[2]);
}

void test_vector_assignment_operator() {
    std::cout << "\n=== Testing Vector Assignment Operator ===" << std::endl;
    Vector<int> vec;
    vec.push_back(5);
    vec.push_back(10);
    
    Vector<int> vec2;
    vec2 = vec;
    
    ASSERT_EQ(2, vec2.size());
    ASSERT_EQ(5, vec2[0]);
    ASSERT_EQ(10, vec2[1]);
}

void test_vector_clear() {
    std::cout << "\n=== Testing Vector Clear ===" << std::endl;
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    
    ASSERT_EQ(3, vec.size());
    ASSERT_EQ(false, vec.isEmpty());
    
    vec.clear();
    
    ASSERT_EQ(0, vec.size());
    ASSERT_EQ(true, vec.isEmpty());
}

void test_vector_of_points() {
    std::cout << "\n=== Testing Vector of Points ===" << std::endl;
    Vector<Point> pointVec;
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);
    
    pointVec.push_back(p1);
    pointVec.push_back(p2);
    
    ASSERT_EQ(2, pointVec.size());
    ASSERT_DOUBLE_EQ(1.0, pointVec[0].getX());
    ASSERT_DOUBLE_EQ(2.0, pointVec[0].getY());
    ASSERT_DOUBLE_EQ(3.0, pointVec[1].getX());
    ASSERT_DOUBLE_EQ(4.0, pointVec[1].getY());
}

void test_integration_total_distance() {
    std::cout << "\n=== Testing Integration: Total Distance Calculation ===" << std::endl;
    Vector<Point> points;
    points.push_back(Point(0.0, 0.0));
    points.push_back(Point(3.0, 4.0));
    points.push_back(Point(6.0, 8.0));
    
    double totalDistance = 0.0;
    for (int i = 0; i < points.size() - 1; i++) {
        Line line(points[i], points[i + 1]);
        totalDistance += line.length();
    }
    
    // Distance from (0,0) to (3,4) = 5.0
    // Distance from (3,4) to (6,8) = 5.0
    ASSERT_DOUBLE_EQ(10.0, totalDistance);
}

int main() {
    std::cout << "==================================" << std::endl;
    std::cout << "   POINT PROJECT TEST SUITE" << std::endl;
    std::cout << "==================================" << std::endl;
    
    // Run all tests
    test_point_default_constructor();
    test_point_parameterized_constructor();
    test_point_setters_getters();
    test_point_delimiter();
      test_line_default_constructor();
    test_line_parameterized_constructor();
    test_line_length();
    
    test_vector_default_constructor();
    test_vector_push_back();
    test_vector_copy_constructor();
    test_vector_assignment_operator();
    test_vector_clear();
    test_vector_of_points();
    
    test_integration_total_distance();
    
    // Print summary
    std::cout << "\n==================================" << std::endl;
    std::cout << "        TEST SUMMARY" << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "Tests Passed: " << tests_passed << std::endl;
    std::cout << "Tests Failed: " << tests_failed << std::endl;
    std::cout << "Total Tests:  " << (tests_passed + tests_failed) << std::endl;
    
    if (tests_failed == 0) {
        std::cout << "\n🎉 ALL TESTS PASSED! 🎉" << std::endl;
        return 0;
    } else {
        std::cout << "\n❌ SOME TESTS FAILED! ❌" << std::endl;
        return 1;
    }
}