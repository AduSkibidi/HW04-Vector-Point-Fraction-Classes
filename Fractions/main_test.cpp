#include <iostream>
#include <string>
#include "Fractions.h"
#include "../Vector/Vector.h"
#include "../utils/utils.h"

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

#define EXPECT_EQ(expected, actual) ((expected) == (actual))
#define EXPECT_TRUE(condition) (condition)
#define EXPECT_FALSE(condition) (!(condition))

void testFraction() {
    std::cout << "\n=== FRACTION TESTS ===" << std::endl;
    
    // Test default constructor
    Fraction f;
    TEST_ASSERT(EXPECT_EQ(0, f.getNumerator()) && EXPECT_EQ(1, f.getDenominator()), 
                "Fraction Default Constructor");
    
    // Test parameterized constructor
    Fraction frac1(1, 2);
    Fraction frac2(3, 4);
    TEST_ASSERT(EXPECT_EQ(1, frac1.getNumerator()) && EXPECT_EQ(2, frac1.getDenominator()), 
                "Fraction Parameterized Constructor 1");
    TEST_ASSERT(EXPECT_EQ(3, frac2.getNumerator()) && EXPECT_EQ(4, frac2.getDenominator()), 
                "Fraction Parameterized Constructor 2");
    
    // Test automatic reduction
    Fraction frac3(6, 8);  // Should reduce to 3/4
    TEST_ASSERT(EXPECT_EQ(3, frac3.getNumerator()) && EXPECT_EQ(4, frac3.getDenominator()), 
                "Fraction Automatic Reduction");
    
    // Test setters and getters
    Fraction f2;
    f2.setNumerator(5);
    f2.setDenominator(7);
    TEST_ASSERT(EXPECT_EQ(5, f2.getNumerator()) && EXPECT_EQ(7, f2.getDenominator()), 
                "Fraction Setters and Getters");
    
    // Test setFraction
    Fraction f3;
    f3.setFraction(9, 12);  // Should reduce to 3/4
    TEST_ASSERT(EXPECT_EQ(3, f3.getNumerator()) && EXPECT_EQ(4, f3.getDenominator()), 
                "Fraction SetFraction");
    
    // Test addition
    Fraction a(1, 2);
    Fraction b(3, 4);
    Fraction sum = a + b;  // 1/2 + 3/4 = 5/4
    TEST_ASSERT(EXPECT_EQ(5, sum.getNumerator()) && EXPECT_EQ(4, sum.getDenominator()), 
                "Fraction Addition");
    
    // Test subtraction
    Fraction diff = b - a;  // 3/4 - 1/2 = 1/4
    TEST_ASSERT(EXPECT_EQ(1, diff.getNumerator()) && EXPECT_EQ(4, diff.getDenominator()), 
                "Fraction Subtraction");
    
    // Test multiplication
    Fraction prod = a * b;  // 1/2 * 3/4 = 3/8
    TEST_ASSERT(EXPECT_EQ(3, prod.getNumerator()) && EXPECT_EQ(8, prod.getDenominator()), 
                "Fraction Multiplication");
    
    // Test toString
    TEST_ASSERT(a.toString() == "1/2", "Fraction ToString Regular");
    
    Fraction whole(5, 1);
    TEST_ASSERT(whole.toString() == "5", "Fraction ToString Whole Number");
    
    // Test static delimiter
    TEST_ASSERT(EXPECT_EQ('/', Fraction::delimiter), "Fraction Static Delimiter");
}

void testUtils() {
    std::cout << "\n=== UTILS TESTS ===" << std::endl;
    
    // Test GCD
    TEST_ASSERT(EXPECT_EQ(4, gcd(12, 8)), "Utils GCD Test 1");
    TEST_ASSERT(EXPECT_EQ(5, gcd(15, 25)), "Utils GCD Test 2");
    TEST_ASSERT(EXPECT_EQ(1, gcd(7, 13)), "Utils GCD Test 3");
    TEST_ASSERT(EXPECT_EQ(6, gcd(18, 24)), "Utils GCD Test 4");
}

void testVectorFraction() {
    std::cout << "\n=== VECTOR FRACTION TESTS ===" << std::endl;
    
    // Test default constructor
    Vector<Fraction> vec;
    TEST_ASSERT(EXPECT_EQ(0, vec.size()) && EXPECT_TRUE(vec.isEmpty()), 
                "Vector<Fraction> Default Constructor");
    
    // Test push_back
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(5, 6);
    
    vec.push_back(f1);
    vec.push_back(f2);
    vec.push_back(f3);
    
    TEST_ASSERT(EXPECT_EQ(3, vec.size()) && EXPECT_FALSE(vec.isEmpty()), 
                "Vector<Fraction> Push Back Size");
    TEST_ASSERT(EXPECT_EQ(1, vec[0].getNumerator()) && EXPECT_EQ(2, vec[0].getDenominator()), 
                "Vector<Fraction> Element Access 1");
    TEST_ASSERT(EXPECT_EQ(3, vec[1].getNumerator()) && EXPECT_EQ(4, vec[1].getDenominator()), 
                "Vector<Fraction> Element Access 2");
    
    // Test copy constructor
    Vector<Fraction> vec2(vec);
    TEST_ASSERT(EXPECT_EQ(3, vec2.size()), "Vector<Fraction> Copy Constructor");
    
    // Test clear
    vec2.clear();
    TEST_ASSERT(EXPECT_EQ(0, vec2.size()) && EXPECT_TRUE(vec2.isEmpty()), 
                "Vector<Fraction> Clear");
}

void testIntegration() {
    std::cout << "\n=== INTEGRATION TESTS ===" << std::endl;
    
    // Test sum of fractions
    Vector<Fraction> fractions;
    fractions.push_back(Fraction(1, 2));  // 1/2
    fractions.push_back(Fraction(1, 3));  // 1/3
    fractions.push_back(Fraction(1, 6));  // 1/6
    
    // Sum: 1/2 + 1/3 + 1/6 = 3/6 + 2/6 + 1/6 = 6/6 = 1/1
    Fraction sum(0, 1);
    for (int i = 0; i < fractions.size(); i++) {
        sum = sum + fractions[i];
    }
    
    TEST_ASSERT(EXPECT_EQ(1, sum.getNumerator()) && EXPECT_EQ(1, sum.getDenominator()), 
                "Sum of Fractions Integration Test");
    
    // Test complex operations
    Fraction a(2, 3);   // 2/3
    Fraction b(3, 4);   // 3/4
    Fraction c(1, 6);   // 1/6
    
    // Test: (2/3 + 3/4) * 1/6
    Fraction sumAB = a + b;       // 2/3 + 3/4 = 8/12 + 9/12 = 17/12
    Fraction result = sumAB * c;  // 17/12 * 1/6 = 17/72
    
    TEST_ASSERT(EXPECT_EQ(17, result.getNumerator()) && EXPECT_EQ(72, result.getDenominator()), 
                "Complex Fraction Operations");
}

void testEdgeCases() {
    std::cout << "\n=== EDGE CASE TESTS ===" << std::endl;
    
    // Test large fractions
    Fraction large(1000000, 2000000);  // Should reduce to 1/2
    TEST_ASSERT(EXPECT_EQ(1, large.getNumerator()) && EXPECT_EQ(2, large.getDenominator()), 
                "Large Fraction Reduction");
    
    // Test zero numerator
    Fraction zero(0, 5);
    TEST_ASSERT(EXPECT_EQ(0, zero.getNumerator()) && EXPECT_EQ(1, zero.getDenominator()), 
                "Zero Numerator");
    
    // Test improper fractions
    Fraction improper(7, 3);  // 7/3
    TEST_ASSERT(EXPECT_EQ(7, improper.getNumerator()) && EXPECT_EQ(3, improper.getDenominator()), 
                "Improper Fraction");
    TEST_ASSERT(improper.toString() == "7/3", "Improper Fraction ToString");
    
    // Test unit fraction
    Fraction unit(1, 1);
    TEST_ASSERT(unit.toString() == "1", "Unit Fraction ToString");
}

int main() {
    std::cout << "======================================" << std::endl;
    std::cout << "  FRACTION PROJECT SIMPLE TEST SUITE" << std::endl;
    std::cout << "======================================" << std::endl;
    
    testFraction();
    testUtils();
    testVectorFraction();
    testIntegration();
    testEdgeCases();
    
    std::cout << "\n======================================" << std::endl;
    std::cout << "TEST SUMMARY:" << std::endl;
    std::cout << "Total Tests: " << total_tests << std::endl;
    std::cout << "Passed: " << passed_tests << " ✓" << std::endl;
    std::cout << "Failed: " << failed_tests << " ✗" << std::endl;
    std::cout << "Success Rate: " << (passed_tests * 100.0 / total_tests) << "%" << std::endl;
    std::cout << "======================================" << std::endl;
    
    return failed_tests == 0 ? 0 : 1;
}