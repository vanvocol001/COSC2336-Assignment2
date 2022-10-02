/** @file assg02-tests.cpp
 * @brief Unit tests for Assignment 02, practice on classes and user
 *   defined types.
 *
 * @author Jane Programmer
 * @note   cwid : 123 45 678
 * @note   class: COSC 2336, Fall 2020
 * @note   ide  : VS Code 1.48 / build package / GNU gcc tools
 * @note   assg : Assignment 02
 * @date   June 1, 2020
 *
 * Assignment 02, classes and user defined data types.  This is
 * the file containing the unit tests for this assignment.  It uses the catch2
 * unit test framework.  Tests are given (commented out) for the member functions
 * you need to implement for the two classes for this assignment.
 */
#include "catch.hpp"
#include "Set.hpp"
#include <cmath>
#include <iostream>
using namespace std;


/** Task 1: Set default constructor, needs implement of stub isEmpty()
 * to test.
 * Uncomment the following test case block and write your code
 * to pass these tests for these parts of the assignment.
 */

TEST_CASE("<isEmpty> stub function test", "[task1]")
{
  Set s;
  
  CHECK(s.isEmpty());
}


/** Task 1: Set getSetSize stub accessor method
 * Uncomment the following test case block and write your code
 * to pass these tests for these parts of the assignment.
 */

TEST_CASE("<getSetSize> stub function test", "[task1]")
{
  Set s;
  
  CHECK(s.getSetSize() == 0);
}


/** Task 1: Set containsItem stub accessor method.  The set is still empty,
 * So any item we check should give a false result as it should
 * not be in the set yet.
 * Uncomment the following test case block and write your code
 * to pass these tests for these parts of the assignment.
 */

TEST_CASE("<containsItem> stub function test", "[task1]")
{
  Set s;

  CHECK_FALSE(s.containsItem(5));
  CHECK_FALSE(s.containsItem(3));
  CHECK_FALSE(s.containsItem(9));
  CHECK_FALSE(s.containsItem(0));
}


/** Task 1: Set str stub method.  The set is still empty,
 * So we should get an empty string as a result
 * Uncomment the following test case block and write your code
 * to pass these tests for these parts of the assignment.
 */

TEST_CASE("<str> stub function test", "[task1]")
{
  Set s;
  
  CHECK(s.str() == "[ ]");
}


/** Task 2: addItem tests
 * Our first real test of the set.  Lets add some items and
 * see if the set is correctly being maintained.  Adding a new item
 * will cause all of the methods we have tested to now give new
 * results, so we will be testing all of them again as well here.
 * Uncomment the following test case block and write your code
 * to pass these tests for these parts of the assignment.
 */

TEST_CASE("<addItem> test adding items and implementation of stub functions", "[task2]")
{
  Set s;
  
  SECTION("add our first item to the set")
  {
    s.addItem(5);
    CHECK_FALSE(s.isEmpty());
    CHECK(s.getSetSize() == 1);
    CHECK(s.containsItem(5));
    CHECK_FALSE(s.containsItem(0));
    CHECK(s.str() == "[ 5 ]");
  }
  
  SECTION("add 3 more items to the set")
  {
    s.addItem(5);
    s.addItem(9);
    s.addItem(-1);
    s.addItem(42);
    CHECK_FALSE(s.isEmpty());
    CHECK(s.getSetSize() == 4);
    
    CHECK(s.containsItem(5)); // still got it, right?
    CHECK(s.containsItem(9));
    CHECK(s.containsItem(-1));
    CHECK(s.containsItem(42));
    CHECK_FALSE(s.containsItem(0));
    CHECK_FALSE(s.containsItem(15));
    
    CHECK(s.str() == "[ 5 9 -1 42 ]"); // we are expecting an unsorted set of items here
  }
}


/** Task 3: test addItem duplicate items
 * This is a set, so adding existing items should not cause the set to
 * grow.  We test adding a duplicate of the first, last and a middle
 * value of the set.
 * Uncomment the following test case block and write your code
 * to pass these tests for these parts of the assignment.
 */

TEST_CASE("<addItem> test adding duplicate items", "[task3]")
{
  Set s;

  s.addItem(5);
  s.addItem(9);
  s.addItem(-1);
  s.addItem(42);
  
  SECTION("test adding duplicate that is at index 0 of the list")
  {
    s.addItem(5);
    
    CHECK_FALSE(s.isEmpty());
    CHECK(s.getSetSize() == 4);
    
    CHECK(s.containsItem(5));
    CHECK(s.containsItem(9));
    CHECK(s.containsItem(-1));
    CHECK(s.containsItem(42));
    
    CHECK(s.str() == "[ 5 9 -1 42 ]");
  }
  
  SECTION("test adding duplicate of the last item in the set/list")
  {
    s.addItem(42);
    
    CHECK_FALSE(s.isEmpty());
    CHECK(s.getSetSize() == 4);
    
    CHECK(s.containsItem(5));
    CHECK(s.containsItem(9));
    CHECK(s.containsItem(-1));
    CHECK(s.containsItem(42));
    
    CHECK(s.str() == "[ 5 9 -1 42 ]");
  }
  
  SECTION("test adding duplicate of item somewhere inside of the list")
  {
    s.addItem(-1);
    
    CHECK_FALSE(s.isEmpty());
    CHECK(s.getSetSize() == 4);
    
    CHECK(s.containsItem(5));
    CHECK(s.containsItem(9));
    CHECK(s.containsItem(-1));
    CHECK(s.containsItem(42));
    
    CHECK(s.str() == "[ 5 9 -1 42 ]");
  }
}


/** Task 4: removeItems tests
 * Test that removeItems is working.
 * Uncomment the following test case block and write your code
 * to pass these tests for these parts of the assignment.
 */

TEST_CASE("<removeItem> test removing items from set", "[task4]")
{
  Set s;

  s.addItem(5);
  s.addItem(9);
  s.addItem(-1);
  s.addItem(42);
  
  SECTION("first test that request to remove nonexistent item does nothing")
  {
    s.removeItem(-5);
    
    CHECK_FALSE(s.isEmpty());
    CHECK(s.getSetSize() == 4);
    
    CHECK(s.containsItem(5));
    CHECK(s.containsItem(9));
    CHECK(s.containsItem(-1));
    CHECK(s.containsItem(42));
    
    CHECK(s.str() == "[ 5 9 -1 42 ]");
  }
  
  SECTION("start with easiest case, remove middle item")
  {
    s.removeItem(9);
    
    CHECK_FALSE(s.isEmpty());
    CHECK(s.getSetSize() == 3);
    
    CHECK(s.containsItem(5));
    CHECK_FALSE(s.containsItem(9));
    CHECK(s.containsItem(-1));
    CHECK(s.containsItem(42));
    
    CHECK(s.str() == "[ 5 -1 42 ]");
  }
  
  SECTION("test that first item removal handled correctly")
  {
    s.removeItem(9);
    s.removeItem(5);
    
    CHECK_FALSE(s.isEmpty());
    CHECK(s.getSetSize() == 2);
    
    CHECK_FALSE(s.containsItem(5));
    CHECK_FALSE(s.containsItem(9));
    CHECK(s.containsItem(-1));
    CHECK(s.containsItem(42));
    
    CHECK(s.str() == "[ -1 42 ]");
  }
  
  SECTION("test that last item removal handled correctly")
  {
    s.removeItem(9);
    s.removeItem(5);
    s.removeItem(42);
    
    CHECK_FALSE(s.isEmpty());
    CHECK(s.getSetSize() == 1);
    
    CHECK_FALSE(s.containsItem(5));
    CHECK_FALSE(s.containsItem(9));
    CHECK(s.containsItem(-1));
    CHECK_FALSE(s.containsItem(42));
    
    CHECK(s.str() == "[ -1 ]");
  }
  
  SECTION("final boundary case, set of 1 item becomes empty set when item is removed")
  {
    s.removeItem(9);
    s.removeItem(5);
    s.removeItem(42);
    s.removeItem(-1);
    
    CHECK(s.isEmpty());
    CHECK(s.getSetSize() == 0);
    
    CHECK_FALSE(s.containsItem(5));
    CHECK_FALSE(s.containsItem(9));
    CHECK_FALSE(s.containsItem(-1));
    CHECK_FALSE(s.containsItem(42));
    
    CHECK(s.str() == "[ ]");
  }
}



/** A test fixture is a common Unit Test concept.  Basically catch2 will
 * create a new instance of this class for each TEST_CASE_METHOD where we
 * use this fixture.  We create instances of sets we can use to test
 * intersection and union operations in this fixture.
 *
 * Uncomment this before working on the final Tasks 5 and 6
 */

struct SetTestFixture
{
public:
  /// @brief set 1
  Set s1;
  /// @brief another set the same as s1
  Set sameAsS1;
  /// @brief set 2
  Set s2;
  /// @brief set 2 ends, the first and last item of set 2
  Set s2ends;
  /// @brief an empty set
  Set empty;
  
  // constructor to initialize the sets with some values
  SetTestFixture()
  {
    s1.addItem(5);
    s1.addItem(8);
    s1.addItem(-6);
    s1.addItem(12);
    
    sameAsS1.addItem(5);
    sameAsS1.addItem(8);
    sameAsS1.addItem(-6);
    sameAsS1.addItem(12);
    
    s2.addItem(8);
    s2.addItem(4);
    s2.addItem(-6);
    s2.addItem(18);
    
    s2ends.addItem(8);
    s2ends.addItem(18);
  }    
};


/** Task 5: operatorUnion tests
 * Test that the union operation on sets works correctly.
 * Uncomment the following test case block and write your code
 * to pass these tests for these parts of the assignment.
 */

TEST_CASE_METHOD(SetTestFixture,
                 "<operatorUnion> basic test", "[task5]")
{
  SECTION("first test basic union operation on 2 sets with more than 1 item in union")
  {
    s1.operatorUnion(s2);
    
    CHECK_FALSE(s1.isEmpty());
    CHECK(s1.getSetSize() == 6);
    
    CHECK(s1.containsItem(5));
    CHECK(s1.containsItem(8));
    CHECK(s1.containsItem(-6));
    CHECK(s1.containsItem(12));
    CHECK(s1.containsItem(4));
    CHECK(s1.containsItem(18));
    
    CHECK(s1.str() == "[ 5 8 -6 12 4 18 ]");
    
    // also make sure s2 wasn't changed
    CHECK(s2.getSetSize() == 4);
    CHECK(s2.str() == "[ 8 4 -6 18 ]");
  }
}


/** Task 5: operatorUnion tests
 * Test that the union operation on sets works correctly.
 * Uncomment the following test case block and write your code
 * to pass these tests for these parts of the assignment.
 */

TEST_CASE_METHOD(SetTestFixture,
                 "<operatorUnion> test the other way", "[task5]")
{
  SECTION("should get the same result if we use same 2 sets but have s2 perform the union on s1")
  {
    s2.operatorUnion(s1);
    
    CHECK_FALSE(s2.isEmpty());
    CHECK(s2.getSetSize() == 6);
    
    CHECK(s2.containsItem(5));
    CHECK(s2.containsItem(8));
    CHECK(s2.containsItem(-6));
    CHECK(s2.containsItem(12));
    CHECK(s2.containsItem(4));
    CHECK(s2.containsItem(18));
    
    CHECK(s2.str() == "[ 8 4 -6 18 5 12 ]");
    
    // also make sure s2 wasn't changed
    CHECK(s1.getSetSize() == 4);
    CHECK(s1.str() == "[ 5 8 -6 12 ]");
  }
}


/** Task 5: operatorUnion tests
 * Test that the union operation on sets works correctly.
 * Uncomment the following test case block and write your code
 * to pass these tests for these parts of the assignment.
 */

TEST_CASE_METHOD(SetTestFixture,
                 "<operatorUnion> test union with empty set", "[task5]")
{
  SECTION("The union of a set with an empty set is the original set")
  {
    s1.operatorUnion(empty);
    CHECK_FALSE(s1.isEmpty());
    CHECK(s1.getSetSize() == 4);
    CHECK(s1.containsItem(5));
    CHECK(s1.containsItem(8));
    CHECK(s1.containsItem(-6));
    CHECK(s1.containsItem(12));
    CHECK(s1.str() == "[ 5 8 -6 12 ]");
    
    s2.operatorUnion(empty);
    CHECK_FALSE(s2.isEmpty());
    CHECK(s2.getSetSize() == 4);
    CHECK(s2.containsItem(8));
    CHECK(s2.containsItem(4));
    CHECK(s2.containsItem(-6));
    CHECK(s2.containsItem(18));
    CHECK(s2.str() == "[ 8 4 -6 18 ]");
    
    // empty set with empty set is still empty
    empty.operatorUnion(empty);
    CHECK(empty.isEmpty());
    CHECK(empty.getSetSize() == 0);
  }
}


/** Task 5: operatorUnion tests
 * Test that the union operation on sets works correctly.
 * Uncomment the following test case block and write your code
 * to pass these tests for these parts of the assignment.
 */

TEST_CASE_METHOD(SetTestFixture,
                 "<operatorUnion> test union with same set", "[task5]")
{
  SECTION("The union of two equal sets is still the original set")
  {
    s1.operatorUnion(sameAsS1);
    
    CHECK_FALSE(s1.isEmpty());
    CHECK(s1.getSetSize() == 4);
    
    CHECK(s1.containsItem(5));
    CHECK(s1.containsItem(8));
    CHECK(s1.containsItem(-6));
    CHECK(s1.containsItem(12));
    
    CHECK(s1.str() == "[ 5 8 -6 12 ]");
    
    // we should be able to do sets and unions with ourself and in both cases
    // there will be no change
    sameAsS1.operatorUnion(sameAsS1);
    
    CHECK_FALSE(sameAsS1.isEmpty());
    CHECK(sameAsS1.getSetSize() == 4);
    
    CHECK(sameAsS1.containsItem(5));
    CHECK(sameAsS1.containsItem(8));
    CHECK(sameAsS1.containsItem(-6));
    CHECK(sameAsS1.containsItem(12));
    
    CHECK(sameAsS1.str() == "[ 5 8 -6 12 ]");
  }
}


/** Task 5: operatorUnion tests
 * Test that the union operation on sets works correctly.
 * Uncomment the following test case block and write your code
 * to pass these tests for these parts of the assignment.
 */

TEST_CASE_METHOD(SetTestFixture,
                 "<operatorUnion> test union of end values", "[task5]")
{
  SECTION("Look out for problems with index 0 and last index still on the sets, union of only first and last item of set")
  {
    s2.operatorUnion(s2ends);
    
    CHECK_FALSE(s2.isEmpty());
    CHECK(s2.getSetSize() == 4);
    
    CHECK(s2.containsItem(8));
    CHECK(s2.containsItem(4));
    CHECK(s2.containsItem(-6));
    CHECK(s2.containsItem(18));
    
    CHECK(s2.str() == "[ 8 4 -6 18 ]");
  }
  
  SECTION("test again but with ends which also tests union doesn't change when set is a subset of the other set")
  {
    s2ends.operatorUnion(s2);
    
    CHECK_FALSE(s2ends.isEmpty());
    CHECK(s2ends.getSetSize() == 4);
    
    CHECK(s2ends.containsItem(8));
    CHECK(s2ends.containsItem(4));
    CHECK(s2ends.containsItem(-6));
    CHECK(s2ends.containsItem(18));
    
    CHECK(s2ends.str() == "[ 8 18 4 -6 ]");
  }
}


/** Task 6: operatorIntersect tests
 * Test that the intersection operation on sets works correctly.
 * Uncomment the following test case block and write your code
 * to pass these tests for these parts of the assignment.
 */

TEST_CASE_METHOD(SetTestFixture,
                 "<operatorIntersect> basic test", "[task6]")
{
  SECTION("first test basic intersection operation on 2 sets with more than 1 item in intersection")
  {
    s1.operatorIntersect(s2);
    
    CHECK_FALSE(s1.isEmpty());
    CHECK(s1.getSetSize() == 2);
    
    CHECK_FALSE(s1.containsItem(5));
    CHECK(s1.containsItem(8));
    CHECK(s1.containsItem(-6));
    CHECK_FALSE(s1.containsItem(12));
    
    CHECK(s1.str() == "[ 8 -6 ]");
    
    // also make sure s2 wasn't changed
    CHECK(s2.getSetSize() == 4);
    CHECK(s2.str() == "[ 8 4 -6 18 ]");
  }
}


/** Task 6: operatorIntersect tests
 * Test that the intersection operation on sets works correctly.
 * Uncomment the following test case block and write your code
 * to pass these tests for these parts of the assignment.
 */

TEST_CASE_METHOD(SetTestFixture,
                 "<operatorIntersect> test the other way", "[task6]")
{
  SECTION("should get the same result if we use same 2 sets but have s2 perform the intersection")
  {
    s2.operatorIntersect(s1);
    
    CHECK_FALSE(s2.isEmpty());
    CHECK(s2.getSetSize() == 2);
    
    CHECK(s2.containsItem(8));
    CHECK_FALSE(s2.containsItem(4));
    CHECK(s2.containsItem(-6));
    CHECK_FALSE(s2.containsItem(18));
    
    CHECK(s2.str() == "[ 8 -6 ]");
    
    // also make sure s1 wasn't changed
    CHECK(s1.getSetSize() == 4);
    CHECK(s1.str() == "[ 5 8 -6 12 ]");
  }
}


/** Task 6: operatorIntersect tests
 * Test that the intersection operation on sets works correctly.
 * Uncomment the following test case block and write your code
 * to pass these tests for these parts of the assignment.
 */

TEST_CASE_METHOD(SetTestFixture,
                 "<operatorIntersect> test intersection empty set", "[task6]")
{
  SECTION("The intersection of a set with an empty set is always the empty set")
  {
    s1.operatorIntersect(empty);
    CHECK(s1.isEmpty());
    CHECK(s1.getSetSize() == 0);
    
    s2.operatorIntersect(empty);
    CHECK(s2.isEmpty());
    CHECK(s2.getSetSize() == 0);
    
    // empty set with empty set is still empty
    empty.operatorIntersect(empty);
    CHECK(empty.isEmpty());
    CHECK(empty.getSetSize() == 0);
  }
}


/** Task 6: operatorIntersect tests
 * Test that the intersection operation on sets works correctly.
 * Uncomment the following test case block and write your code
 * to pass these tests for these parts of the assignment.
 */

TEST_CASE_METHOD(SetTestFixture,
                 "<operatorIntersect> test intersection with same set", "[task6]")
{
  SECTION("The intersection of two equal sets is still the original set")
  {
    s1.operatorIntersect(sameAsS1);
    
    CHECK_FALSE(s1.isEmpty());
    CHECK(s1.getSetSize() == 4);
    
    CHECK(s1.containsItem(5));
    CHECK(s1.containsItem(8));
    CHECK(s1.containsItem(-6));
    CHECK(s1.containsItem(12));
    
    CHECK(s1.str() == "[ 5 8 -6 12 ]");
    
    // we should be able to do sets and unions with ourself and in both cases
    // there will be no change
    sameAsS1.operatorIntersect(sameAsS1);
    
    CHECK_FALSE(sameAsS1.isEmpty());
    CHECK(sameAsS1.getSetSize() == 4);
    
    CHECK(sameAsS1.containsItem(5));
    CHECK(sameAsS1.containsItem(8));
    CHECK(sameAsS1.containsItem(-6));
    CHECK(sameAsS1.containsItem(12));

    CHECK(sameAsS1.str() == "[ 5 8 -6 12 ]");
  }
}


/** Task 6: operatorIntersect tests
 * Test that the intersection operation on sets works correctly.
 * Uncomment the following test case block and write your code
 * to pass these tests for these parts of the assignment.
 */

TEST_CASE_METHOD(SetTestFixture,
                 "<operatorIntersect> test intersection of end values", "[task6]")
{
  SECTION("Look out for problems with index 0 and last index still on the sets, intersection of only first and last item of set")
  {
    s2.operatorIntersect(s2ends);
    
    CHECK_FALSE(s2.isEmpty());
    CHECK(s2.getSetSize() == 2);
    
    CHECK(s2.containsItem(8));
    CHECK_FALSE(s2.containsItem(4));
    CHECK_FALSE(s2.containsItem(-6));
    CHECK(s2.containsItem(18));
    
    CHECK(s2.str() == "[ 8 18 ]");
  }
  
  SECTION("test again but with ends which also tests intersection doesn't change when set is a subset of the other set")
  {
    s2ends.operatorIntersect(s2);
    
    CHECK_FALSE(s2ends.isEmpty());
    CHECK(s2ends.getSetSize() == 2);
    
    CHECK(s2ends.containsItem(8));
    CHECK_FALSE(s2ends.containsItem(4));
    CHECK_FALSE(s2ends.containsItem(-6));
    CHECK(s2ends.containsItem(18));
    
    CHECK(s2ends.str() == "[ 8 18 ]");
  }
}

