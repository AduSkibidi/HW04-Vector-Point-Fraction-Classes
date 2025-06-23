#include <iostream>
#include <cmath>
#include <string>
#include "Point.h"
#include "../Line/Line.h"
#include "../Vector/Vector.h"

// Simple test framework
int total_tests = 0;
int passed_tests = 0;
int failed_tests = 0;

#define TEST_ASSERT(condition, test_name) \
    do { \
        total_tests++; \
        if (condition) { \
            std::cout << "✓ " << test_name << " PASSED" << std::endl; \
            passed_tests++; \
        } else { \
            std::cout << "✗ " << test_name << " FAILED" << std::endl; \
            failed_tests++; \
        } \
    } while(0)

#define EXPECT_DOUBLE_EQ(expected, actual) (std::abs((expected) - (actual)) < 1e-9)
#define EXPECT_EQ(expected, actual) ((expected) == (actual))
#define EXPECT_TRUE(condition) (condition)
#define EXPECT_FALSE(condition) (!(condition))

void testPoint() {
    std::cout << "\n=== POINT TESTS ===" << std::endl;
    
    // Test default constructor
    Point p;
    TEST_ASSERT(EXPECT_DOUBLE_EQ(0.0, p.getX()) && EXPECT_DOUBLE_EQ(0.0, p.getY()), 
                "Point Default Constructor");
    
    // Test parameterized constructor
    Point p1(3.0, 4.0);
    Point p2(-2.0, 1.0);
    TEST_ASSERT(EXPECT_DOUBLE_EQ(3.0, p1.getX()) && EXPECT_DOUBLE_EQ(4.0, p1.getY()), 
                "Point Parameterized Constructor 1");
    TEST_ASSERT(EXPECT_DOUBLE_EQ(-2.0, p2.getX()) && EXPECT_DOUBLE_EQ(1.0, p2.getY()), 
                "Point Parameterized Constructor 2");
    
    // Test setters and getters
    Point p3;
    p3.setX(5.5);
    p3.setY(-3.2);
    TEST_ASSERT(EXPECT_DOUBLE_EQ(5.5, p3.getX()) && EXPECT_DOUBLE_EQ(-3.2, p3.getY()), 
                "Point Setters and Getters");
    
    // Test setXY
    p3.setXY(7.8, -9.1);
    TEST_ASSERT(EXPECT_DOUBLE_EQ(7.8, p3.getX()) && EXPECT_DOUBLE_EQ(-9.1, p3.getY()), 
                "Point SetXY Method");
    
    // Test static delimiter
    TEST_ASSERT(EXPECT_EQ(',', Point::delimiter), "Point Static Delimiter");
}

void testLine() {
    std::cout << "\n=== LINE TESTS ===" << std::endl;
    
    // Test default constructor
    Line l;
    TEST_ASSERT(EXPECT_DOUBLE_EQ(0.0, l.length()), "Line Default Constructor");
    
    // Test parameterized constructor
    Point start(0.0, 0.0);
    Point end(3.0, 4.0);
    Line line(start, end);
    TEST_ASSERT(EXPECT_DOUBLE_EQ(5.0, line.length()), "Line Parameterized Constructor");
    
    // Test horizontal line
    Point start1(0.0, 0.0);
    Point end1(5.0, 0.0);
    Line horizontalLine(start1, end1);
    TEST_ASSERT(EXPECT_DOUBLE_EQ(5.0, horizontalLine.length()), "Line Horizontal Length");
    
    // Test vertical line
    Point start2(0.0, 0.0);
    Point end2(0.0, 3.0);
    Line verticalLine(start2, end2);
    TEST_ASSERT(EXPECT_DOUBLE_EQ(3.0, verticalLine.length()), "Line Vertical Length");
    
    // Test zero length line
    Point start3(2.0, 3.0);
    Point end3(2.0, 3.0);
    Line zeroLine(start3, end3);
    TEST_ASSERT(EXPECT_DOUBLE_EQ(0.0, zeroLine.length()), "Line Zero Length");
}

void testVector() {
    std::cout << "\n=== VECTOR TESTS ===" << std::endl;
    
    // Test default constructor
    Vector<int> vec;
    TEST_ASSERT(EXPECT_EQ(0, vec.size()) && EXPECT_TRUE(vec.isEmpty()), 
                "Vector Default Constructor");
    
    // Test push_back
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    TEST_ASSERT(EXPECT_EQ(3, vec.size()) && EXPECT_FALSE(vec.isEmpty()) && 
                EXPECT_EQ(10, vec[0]) && EXPECT_EQ(20, vec[1]) && EXPECT_EQ(30, vec[2]), 
                "Vector Push Back");
    
    // Test copy constructor
    Vector<int> vec2(vec);
    TEST_ASSERT(EXPECT_EQ(3, vec2.size()) && EXPECT_EQ(10, vec2[0]) && 
                EXPECT_EQ(20, vec2[1]) && EXPECT_EQ(30, vec2[2]), 
                "Vector Copy Constructor");
    
    // Test independence after copy
    vec.push_back(40);
    TEST_ASSERT(EXPECT_EQ(3, vec2.size()), "Vector Copy Independence");
    
    // Test assignment operator
    Vector<int> vec3;
    vec3 = vec2;
    TEST_ASSERT(EXPECT_EQ(3, vec3.size()) && EXPECT_EQ(10, vec3[0]), 
                "Vector Assignment Operator");
    
    // Test clear
    vec3.clear();
    TEST_ASSERT(EXPECT_EQ(0, vec3.size()) && EXPECT_TRUE(vec3.isEmpty()), 
                "Vector Clear");
    
    // Test vector of points
    Vector<Point> pointVec;
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);
    pointVec.push_back(p1);
    pointVec.push_back(p2);
    TEST_ASSERT(EXPECT_EQ(2, pointVec.size()) && 
                EXPECT_DOUBLE_EQ(1.0, pointVec[0].getX()) && 
                EXPECT_DOUBLE_EQ(3.0, pointVec[1].getX()), 
                "Vector of Points");
}

void testIntegration() {
    std::cout << "\n=== INTEGRATION TESTS ===" << std::endl;
    
    // Test total distance calculation
    Vector<Point> points;
    points.push_back(Point(0.0, 0.0));
    points.push_back(Point(3.0, 4.0));
    points.push_back(Point(6.0, 8.0));
    
    double totalDistance = 0.0;
    for (int i = 0; i < points.size() - 1; i++) {
        Line line(points[i], points[i + 1]);
        totalDistance += line.length();
    }
    TEST_ASSERT(EXPECT_DOUBLE_EQ(10.0, totalDistance), "Total Distance Calculation");
    
    // Test triangle perimeter
    Vector<Point> triangle;
    triangle.push_back(Point(0.0, 0.0));
    triangle.push_back(Point(3.0, 0.0));
    triangle.push_back(Point(0.0, 4.0));
    triangle.push_back(Point(0.0, 0.0));
    
    double perimeter = 0.0;
    for (int i = 0; i < triangle.size() - 1; i++) {
        Line line(triangle[i], triangle[i + 1]);
        perimeter += line.length();
    }
    TEST_ASSERT(EXPECT_DOUBLE_EQ(12.0, perimeter), "Triangle Perimeter");
}

int main() {
    std::cout << "======================================" << std::endl;
    std::cout << "    POINT PROJECT SIMPLE TEST SUITE" << std::endl;
    std::cout << "======================================" << std::endl;
    
    testPoint();
    testLine();
    testVector();
    testIntegration();
    
    std::cout << "\n======================================" << std::endl;
    std::cout << "TEST SUMMARY:" << std::endl;
    std::cout << "Total Tests: " << total_tests << std::endl;
    std::cout << "Passed: " << passed_tests << " ✓" << std::endl;
    std::cout << "Failed: " << failed_tests << " ✗" << std::endl;
    std::cout << "Success Rate: " << (passed_tests * 100.0 / total_tests) << "%" << std::endl;
    std::cout << "======================================" << std::endl;
    
    return failed_tests == 0 ? 0 : 1;
}