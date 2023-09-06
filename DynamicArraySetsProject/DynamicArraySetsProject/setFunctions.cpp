/*
	Jayden Wehr
	setFunctions.cpp

*/

#include <iostream>
#include "setFunctions.h"
using namespace std;

// COMPLETE THIS FILE

bool containsElement(char* set, int size, char itemToCheck) {

	if (set != nullptr) {
		for (int i = 0; i < size; i++) {

			//If we found the item, return true
			if (itemToCheck == set[i]) {
				return true;
			}
		}
	}

	return false;
}

void display(char* set, int size) {

	if (set != nullptr) {
		cout << "{";
		for (int i = 0; i < size; i++) {
			
			//Check to see if we are at the last item in the set
			if (size - i == 1) {
				cout << set[i];
			}
			//If we are not at the last item in the set, insert a comma and a space
			else {
				cout << set[i] << ", ";
			}
			
		}
		cout << "}" << endl;
	}
	//If the set is a nullptr, then display an empty pair of brackets
	else {
		cout << "{}" << endl;
	}
}

char* addElement(char* set, int size, char itemToAdd, int& newSize) {

	//If size == 0, theres no need to worry about duplicate items
	if (size == 0) {
		newSize = size + 1;
		char* newSet = new char[newSize];
		newSet[0] = itemToAdd;

		return newSet;
	}

	//Check for a duplicate item first
	bool duplicateItemFound = false;
	for (int i = 0; i < size; i++) {
		if (itemToAdd == set[i]) {
			duplicateItemFound = true;
		}
	}

	
	if (duplicateItemFound) {
		//Put the contents of the original set into a new one
		newSize = size;
		char* newSet = new char[size];
		for (int i = 0; i < size; i++) {
				newSet[i] = set[i];
		}

		return newSet;

	}
	else {
		//If there is no duplicate item, then create a new array whose size +1 greater than the size of the original array
		newSize = size+1;
		char* newSet = new char[newSize];
		for (int i = 0; i < size; i++) {
			newSet[i] = set[i];
		}
		newSet[newSize - 1] = itemToAdd;
		
		return newSet;
	}
	
}

char* setUnion(char* set1, int setSize, char* set2, int set2Size, int& unionSize) {
	//Check to see if both sets are nullptrs
	if (set1 == nullptr && set2 == nullptr) {
		unionSize = 0;
		return nullptr;
	}
	

	//Set the unionSize
	unionSize = setSize + set2Size;

	/*Check for the number of duplicate items by taking each element in one set 
	and comparing it to all the elements in the other set*/
	int duplicateItemCount = 0;
	for (int i = 0; i < setSize; i++) {
		for (int j = 0; j < set2Size; j++) {
			if (set1[i] == set2[j]) {
				duplicateItemCount++;
			}
		}
	}

	//Update the unionSize
	unionSize -= duplicateItemCount;

	//Compare set1 with set2 and put elements from set1 that aren't duplicates into the newSet
	char* newSet = new char[unionSize];
	int currentElement = 0;
	for (int i = 0; i < setSize; i++) {
		bool duplicateItemFound = false;

		for (int j = 0; j < set2Size; j++) {
			if (set1[i] == set2[j]) {
				duplicateItemFound = true;
			}
		}

		if (!duplicateItemFound) {
			newSet[currentElement] = set1[i];
			currentElement++;
		}
	}

	//Go ahead and put the elements of set2 into the new set for we have already taken care of the duplicates
	for (int i = 0; i < set2Size; i++, currentElement++) {
		newSet[currentElement] = set2[i];
	}


	return newSet;

}

char* setIntersect(char* set1, int set1Size, char* set2, int set2Size, int& intersectSize) {
	//Determine the number of elements that set1 and set2 have in common
	int sameItems = 0;
	for (int i = 0; i < set1Size; i++) {
		for (int j = 0; j < set2Size; j++) {
			if (set1[i] == set2[j]) {
				sameItems++;
			}
		}
	}

	//If sameItems is still equal to 0, that means we did not find any common elements. Return nullptr
	if (sameItems == 0) {
		intersectSize = 0;
		return nullptr;
	}

	//Create the array now that we know the number of common elements
	intersectSize = sameItems;
	char* newSet = new char[sameItems];

	//Compare both sets again and throw in the common elements this time
	int currentElement = 0;
	for (int i = 0; i < set1Size; i++) {
		for (int j = 0; j < set2Size; j++) {
			if (set1[i] == set2[j]) {
				newSet[currentElement] = set1[i];
				currentElement++;
			}
		}
	}

	return newSet;
}