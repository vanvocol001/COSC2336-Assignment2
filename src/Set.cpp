/** @file Set.cpp
 * @brief Implementation file for Assignment 02 classes defining
 *   user-defined data types.
 *
 * @author Jane Programmer
 * @note   cwid : 123 45 678
 * @note   class: COSC 2336, Summer 2020
 * @note   ide  : VS Code 1.48 / build package / GNU gcc tools
 * @note   assg : Assignment 02
 * @date   August 1, 2020
 *
 * Set class.  This is the class implementation file. It contains the
 * implementation of all of the member functions declared in the header file.
 * Since implementation is separated from the declaration of each member
 * function, you must indicate each function is a member of the Set
 * class by prepending member function name with Set::
 */
#include "Set.hpp"
#include <string>
#include <sstream>


using namespace std;


/** Set default constructor
 * Default constructor for set class. By default we construct
 * an empty set.
 */
Set::Set()
{
  setSize = 0;
  // doesn't matter if we initialize setItems or what is in it initally,
  // we will simply replace any values when we add items to the set.
}


/** check if set is empty
 * Check if the set is empty or not.  Return true for a currently empty
 * set and false if the set is not empty.
 *
 * @returns bool True when the set is empty, false when it is not empty.
 */
bool Set::isEmpty() const
{
  if (setSize == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

/** contains item
 * Check whether an item is present in the set or not.
 *
 * @param item The item that we want to check to see if in the set.
 *
 * @returns bool True if the item is currently in this set, false
 *   if it is not in this set.
 */

bool Set::containsItem(int item) const
{
  for (int index = 0; index < setSize; index++)
  {
    if (setItem[index] == item)
    {
      return true;
    }
  }
  return false;
}

/** convert to string
 * Create and return a string representation of the current set items.
 * It might be nice to return the items in sorted order, to make it easier
 * on the class user to understand the items in and not in the set.  However,
 * we leave this as an exercise for the student for now (see the
 * standard template libary STL)
 *
 * @returns string Returns a new string created with a representation of the
 *   set items we currently have.
 */


string Set::str() const
{
  ostringstream output;
  output << "[ ";
  for (int index = 0; index < setSize; index++)
  {
    output << setItem[index] << " ";
  }
  output << "]";
  return output.str();
}

/** get set size
 * Return the current size of the set, e.g. the number of items currently
 * present in this set.
 *
 * @returns int Returns the count of the number of items currently in the
 *   set.
 */


int Set::getSetSize() const
{
  return setSize;
}

/** add item to set
 * Add a new item given as a parameter to our set of items.  This is a set,
 * So we do nothing if the item is already in the set.
 *
 * @param item The integer item to be added into the current set of items.
 */

void Set::addItem(int addition)
{
  if (containsItem(addition))
  {

  }
  else
  {
    setItem[setSize] = addition;
    setSize = setSize + 1;
  }
}

/** remove item from set
 * Remove the indicated item.  If the item is not in the set, this method
 * ignores the request and silently does nothing.  Otherwise if the item
 * is present, we remove it and update our array of items, shifting items
 * down to fill in the hole if one was made.
 *
 * @param item The item that we should search for and remove from the set.
 */

void Set::removeItem(int redaction)
{
  if (containsItem(redaction) == false)
  {
    
  }
  else
  {
    for (int index = 0; index < setSize; index++)
    {
      if (redaction == setItem[index])
      {
        int temp = setItem[index + 1];
        setItem[index + 1] = setItem[index];
        setItem[index] = temp;
      }
    }
    setSize = setSize - 1;
  }
}

/** set union operation
 * Calculate the union of this set with an otherSet.  The union of two setns
 * contains all values found in either this set or the other set (or in
 * both).  In many ways the set union is the
 * easier opertion of the two operations. Given that our add addItem() member
 * function will do nothing for items already in the set, the union can
 * be done simply by adding all of the items of the otherSet given to this
 * set.
 *
 * @param otherSet The other set to perform the union with.
 *
 * @returns void No result is returned explicitly.  But implicitly this set
 *   is modified and on return it will now contain the union of the two
 *   sets.
 */
void Set::operatorUnion(const Set& other)
{
  for (int index = 0; index < other.setSize; index++)
  {
    addItem(other.setItem[index]);
  }
}

/** set intersection operation
 * Calculate the intersection of this set with the otherSet we
 * are given.  The intersection of two sets are the values that are present
 * in both this set and the otherSet.  We would normally create a new
 * Set dynamically and retrun the result of the operation as a newly created
 * set, but we have not reviewed dynamic memory allocation yet.  So instead
 * the result of the intersection causes this set to be modified to have
 * the resulting intersection.
 *
 * There are a lot of potential algorithms here.  We could create a
 * temporary array, put the values we find in both in there, then copy
 * this array into our setItem[] array.  Here instead we iterate through
 * our setItem array in reverse, removing each item we find in our set that is
 * not also in the other set.  We iterate in reverse so we can call
 * removeItem() to do the actual remove of items that are not intersection.
 *
 * @param otherSet The other set to perform intersection with.
 *
 * @returns void No result is returned explicitly.  But implicitly the set
 *   is modified and on return it will now contain the intersection of
 *   the two sets.
 */

void Set::operatorIntersect(const Set& other)
{
  for (int index = setSize - 1; index >= 0; index--)
  {
    if (other.containsItem(setItem[index]) == false)
    {
      removeItem(setItem[index]);
    }
  }
}