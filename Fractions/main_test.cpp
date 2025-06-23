#include <iostream>
#include <cassert>
#include <string>
#include "Fractions.h"
#include "../Vector/Vector.h"
#include "../utils/utils.h"

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

void test_fraction_default_constructor() {
    std::cout << "\n=== Testing Fraction Default Constructor ===" << std::endl;
    Fraction f;
    ASSERT_EQ(0, f.getNumerator());
    ASSERT_EQ(1, f.getDenominator());
}

void test_fraction_parameterized_constructor() {
    std::cout << "\n=== Testing Fraction Parameterized Constructor ===" << std::endl;
    Fraction frac1(1, 2);    // 1/2
    Fraction frac2(3, 4);    // 3/4
    
    ASSERT_EQ(1, frac1.getNumerator());
    ASSERT_EQ(2, frac1.getDenominator());
    ASSERT_EQ(3, frac2.getNumerator());
    ASSERT_EQ(4, frac2.getDenominator());
}

void test_fraction_automatic_reduction() {
    std::cout << "\n=== Testing Fraction Automatic Reduction ===" << std::endl;
    Fraction frac3(6, 8);    // 6/8 = 3/4 (should be reduced)
    
    // 6/8 should be reduced to 3/4
    ASSERT_EQ(3, frac3.getNumerator());
    ASSERT_EQ(4, frac3.getDenominator());
}

void test_fraction_negative_fractions() {
    std::cout << "\n=== Testing Fraction Negative Values ===" << std::endl;
    Fraction frac4(-2, 3);   // -2/3
    
    ASSERT_EQ(-2, frac4.getNumerator());
    ASSERT_EQ(3, frac4.getDenominator());
}

void test_fraction_setters_getters() {
    std::cout << "\n=== Testing Fraction Setters and Getters ===" << std::endl;
    Fraction f;
    f.setNumerator(5);
    f.setDenominator(7);
    
    ASSERT_EQ(5, f.getNumerator());
    ASSERT_EQ(7, f.getDenominator());
}

void test_fraction_set_fraction() {
    std::cout << "\n=== Testing Fraction SetFraction ===" << std::endl;
    Fraction f;
    f.setFraction(9, 12);  // Should be reduced to 3/4
    
    ASSERT_EQ(3, f.getNumerator());
    ASSERT_EQ(4, f.getDenominator());
}

void test_fraction_addition() {
    std::cout << "\n=== Testing Fraction Addition ===" << std::endl;
    Fraction frac1(1, 2);    // 1/2
    Fraction frac2(3, 4);    // 3/4
    
    // 1/2 + 3/4 = 2/4 + 3/4 = 5/4
    Fraction result = frac1 + frac2;
    ASSERT_EQ(5, result.getNumerator());
    ASSERT_EQ(4, result.getDenominator());
}

void test_fraction_subtraction() {
    std::cout << "\n=== Testing Fraction Subtraction ===" << std::endl;
    Fraction frac1(1, 2);    // 1/2
    Fraction frac2(3, 4);    // 3/4
    
    // 3/4 - 1/2 = 3/4 - 2/4 = 1/4
    Fraction result = frac2 - frac1;
    ASSERT_EQ(1, result.getNumerator());
    ASSERT_EQ(4, result.getDenominator());
}

void test_fraction_multiplication() {
    std::cout << "\n=== Testing Fraction Multiplication ===" << std::endl;
    Fraction frac1(1, 2);    // 1/2
    Fraction frac2(3, 4);    // 3/4
    
    // 1/2 * 3/4 = 3/8
    Fraction result = frac1 * frac2;
    ASSERT_EQ(3, result.getNumerator());
    ASSERT_EQ(8, result.getDenominator());
}

void test_fraction_to_string() {
    std::cout << "\n=== Testing Fraction ToString ===" << std::endl;
    Fraction frac1(1, 2);
    Fraction frac2(3, 4);
    
    ASSERT_EQ(std::string("1/2"), frac1.toString());
    ASSERT_EQ(std::string("3/4"), frac2.toString());
    
    // Test whole number
    Fraction whole(5, 1);
    ASSERT_EQ(std::string("5"), whole.toString());
}

void test_fraction_delimiter() {
    std::cout << "\n=== Testing Fraction Static Delimiter ===" << std::endl;
    ASSERT_EQ('/', Fraction::delimiter);
}

void test_utils_gcd() {
    std::cout << "\n=== Testing Utils GCD ===" << std::endl;
    ASSERT_EQ(4, utils::gcd(12, 8));
    ASSERT_EQ(5, utils::gcd(15, 25));
    ASSERT_EQ(1, utils::gcd(7, 13));
    ASSERT_EQ(5, utils::gcd(0, 5));
    ASSERT_EQ(5, utils::gcd(5, 0));
}

void test_utils_lcm() {
    std::cout << "\n=== Testing Utils LCM ===" << std::endl;
    ASSERT_EQ(12, utils::lcm(4, 6));
    ASSERT_EQ(75, utils::lcm(15, 25));
    ASSERT_EQ(91, utils::lcm(7, 13));
}

void test_utils_absolute_value() {
    std::cout << "\n=== Testing Utils Absolute Value ===" << std::endl;
    ASSERT_EQ(5, utils::abs(-5));
    ASSERT_EQ(5, utils::abs(5));
    ASSERT_EQ(0, utils::abs(0));
}

void test_vector_fraction_default_constructor() {
    std::cout << "\n=== Testing Vector<Fraction> Default Constructor ===" << std::endl;
    Vector<Fraction> vec;
    ASSERT_EQ(0, vec.size());
    ASSERT_EQ(true, vec.isEmpty());
}

void test_vector_fraction_push_back() {
    std::cout << "\n=== Testing Vector<Fraction> Push Back ===" << std::endl;
    Vector<Fraction> vec;
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(5, 6);
    
    vec.push_back(f1);
    vec.push_back(f2);
    vec.push_back(f3);
    
    ASSERT_EQ(3, vec.size());
    ASSERT_EQ(false, vec.isEmpty());
    
    ASSERT_EQ(1, vec[0].getNumerator());
    ASSERT_EQ(2, vec[0].getDenominator());
    ASSERT_EQ(3, vec[1].getNumerator());
    ASSERT_EQ(4, vec[1].getDenominator());
    ASSERT_EQ(5, vec[2].getNumerator());
    ASSERT_EQ(6, vec[2].getDenominator());
}

void test_vector_fraction_copy_constructor() {
    std::cout << "\n=== Testing Vector<Fraction> Copy Constructor ===" << std::endl;
    Vector<Fraction> vec;
    vec.push_back(Fraction(1, 3));
    vec.push_back(Fraction(2, 5));
    
    Vector<Fraction> vec2(vec);
    
    ASSERT_EQ(2, vec2.size());
    ASSERT_EQ(1, vec2[0].getNumerator());
    ASSERT_EQ(3, vec2[0].getDenominator());
    ASSERT_EQ(2, vec2[1].getNumerator());
    ASSERT_EQ(5, vec2[1].getDenominator());
}

void test_integration_sum_of_fractions() {
    std::cout << "\n=== Testing Integration: Sum of Fractions ===" << std::endl;
    Vector<Fraction> fractions;
    fractions.push_back(Fraction(1, 2));  // 1/2
    fractions.push_back(Fraction(1, 3));  // 1/3
    fractions.push_back(Fraction(1, 6));  // 1/6
    
    // Sum: 1/2 + 1/3 + 1/6 = 3/6 + 2/6 + 1/6 = 6/6 = 1/1
    Fraction sum(0, 1);
    for (int i = 0; i < fractions.size(); i++) {
        sum = sum + fractions[i];
    }
    
    ASSERT_EQ(1, sum.getNumerator());
    ASSERT_EQ(1, sum.getDenominator());
}

void test_edge_case_large_fractions() {
    std::cout << "\n=== Testing Edge Case: Large Fractions ===" << std::endl;
    Fraction large(1000000, 2000000);  // Should be reduced to 1/2
    ASSERT_EQ(1, large.getNumerator());
    ASSERT_EQ(2, large.getDenominator());
}

void test_edge_case_zero_numerator() {
    std::cout << "\n=== Testing Edge Case: Zero Numerator ===" << std::endl;
    Fraction zero(0, 5);
    ASSERT_EQ(0, zero.getNumerator());
    ASSERT_EQ(1, zero.getDenominator());  // Should be reduced to 0/1
}

int main() {
    std::cout << "==================================" << std::endl;
    std::cout << "  FRACTION PROJECT TEST SUITE" << std::endl;
    std::cout << "==================================" << std::endl;
    
    // Run all tests
    test_fraction_default_constructor();
    test_fraction_parameterized_constructor();
    test_fraction_automatic_reduction();
    test_fraction_negative_fractions();
    test_fraction_setters_getters();
    test_fraction_set_fraction();
    
    test_fraction_addition();
    test_fraction_subtraction();
    test_fraction_multiplication();
    test_fraction_to_string();
    test_fraction_delimiter();
    
    test_utils_gcd();
    test_utils_lcm();
    test_utils_absolute_value();
    
    test_vector_fraction_default_constructor();
    test_vector_fraction_push_back();
    test_vector_fraction_copy_constructor();
    
    test_integration_sum_of_fractions();
    
    test_edge_case_large_fractions();
    test_edge_case_zero_numerator();
    
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