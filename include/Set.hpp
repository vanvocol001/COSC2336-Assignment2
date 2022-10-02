/** @file Set.hpp
 * @brief Header file for Assignment 02 using classes defining user-defined
 *   data types.
 *
 * @author Jane Programmer
 * @note   cwid : 123 45 678
 * @note   class: COSC 2336, Summer 2020
 * @note   ide  : VS Code 1.48 / build package / GNU gcc tools
 * @note   assg : Assignment 02
 * @date   August 1, 2020
 *
 * Set class.  This is the class header file.  It contains the
 * declaration of the Set class.  It is included in other files that
 * want to use and create instances of Set objects.  The declaration of
 * a class is basically just a list of the prototypes of the member functions
 * for the class, as well as the private member variables/data that is
 * encapsulated in the class.
 */
#ifndef _SET_H_
#define _SET_H_
#include <string>

using namespace std;


/// @brief MAX_SET_SIZE We used a fixed size array, so we have to have an
///   upper limit on thE size of the sets we can represent.
const int MAX_SET_SIZE = 100;


/** Set class.
 * Represent a set of integer values.
 *
 * This class uses a simple fixed size array of integers to implement
 * the representation of a set.  Thus we can only handle sets up to
 * a certain size defined by MAX_SET_SIZE
 */
class Set
{
private:
  /// @brief setSize The number of items currently in the set.
  int setSize;
  /// @brief setItems The items currently in the set.
  int setItem[MAX_SET_SIZE];

public:
  // constructors and destructors
  Set();

  // declarations/prototypes of accessor methods for information go here
   bool isEmpty() const; 
   int getSetSize() const;
   bool containsItem(int set) const;
   std::string str() const;
   void addItem(int addition);
   void removeItem(int redaction);
   void operatorUnion(const Set& other);
   void operatorIntersect(const Set& other);
   // setters and getter declarations go here

   // actual work of the set, adding and removing items

   // set operations like set intersection and set union declared here
};

#endif // _SET_H_