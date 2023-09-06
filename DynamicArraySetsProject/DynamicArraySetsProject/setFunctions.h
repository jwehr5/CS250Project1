/*
	Jayden Wehr
	setFunctions.h

*/

#ifndef SETFUNCTIONS_H
#define SETFUNCTIONS_H

/**
* containsElement takes in a pointer array and checks to see if a certain element 
* is contained in that array.

* @param set This is an array of chars.
* @param size This is the size of the array, set.
* @param itemToCheck This is the item that we'll be looking for in the array, set.
* @return true if itemToCheck is found in the array.
* @return false if itemToCheck is not found in the array.
* @pre set must not be equal to nullptr
**/
bool containsElement(char* set, int size, char itemToCheck);


/**
* display takes in a pointer array and displays the contents of that array.

* @param set This is an array of chars.
* @param size This is the size of the array, set.
* @pre set must not be equal to nullptr.
**/
void display(char* set, int size);


/**
* addElement takes in a pointer array and adds an additional item to that array if it doesn't already exist.

* @param set This is an array of chars.
* @param size This is the size of the array, set.
* @param itemToAdd This is the item that will be added to the array, set.
* @param newSize This will be the size of the new array if a duplicate item is not found.
* @return A new pointer array will be returned containing all the orginal elements plus the item to be added.
		  Even if there is no item to be added, a new array pointer will still be returned that contains the original
		  contents of the array.
* @return The size of the new array is also returned.
* @pre itemToAdd must not already exist in the array, set.
**/
char* addElement(char* set, int size, char itemToAdd, int& newSize);


/**
* setUnion takes in 2 pointer arrays and creates a new pointer array that contains all the elements that are present
  in both sets.

* @param set1 This is the first array.
* @param set1Size This is the size of the array, set1.
* @param set2 This is the second array.
* @param set2Size This is the size of the array, set2.
* @param unionSize This will be the size of the new array.
* @return nullptr if set1 and set2 are both equal to nullptr.
* @return A new array pointer containing the elements that are in both in set1 and set2. Duplicate items will be checked
          so the new array will not have any duplicate items.
* @return The size of the new array is also returned.
* @pre set1 and set2 must not be equal to nullptr.
**/
char* setUnion(char* set1, int set1Size, char* set2, int set2Size, int& unionSize);


/**
* setIntersect takes in 2 pointer arrays and creates a new pointer array that contains the elements that both sets
  have in common.

* @param set1 This is the first array.
* @param set1Size This is the size of the array, set1.
* @param set2 This is the second array.
* @param set2Size This is the size of the array, set2.
* @param intersectSize This will be the size of the new array
* @return nullptr if set1 and set2 don't have any common elements.
* @return A new array pointer containing the elements that set1 and set2 have in common.
* @return The size of the new array is also returned.
* @pre set1 and set2 must have at least one element in common. 
**/
char* setIntersect(char* set1, int set1Size, char* set2, int set2Size, int& intersectSize);

#endif