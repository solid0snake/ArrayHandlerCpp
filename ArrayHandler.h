/*
* ArrayHandler.h
* By Pedro Garate on 11/23/2014
* Description: ADT that contains a fixed-size array of integers (1000).
*			   It gets the input from the user. Has a function to print the
*              array in reverse order, a function to search the largest
*              number in the array, another function to find the k-th
*              largest number and a quickSort function.
*/
#ifndef _ARRAY_HANDLER_H
#define _ARRAY_HANDLER_H

#include <iostream>

class ArrayHandler
{
private:
	static const int CAP = 1000; // capacity of the array.
	int numbers[CAP]; // array
	struct largest
	{
		int maxNum; // value of largest number
		int index; // index maxNum in the array
	};

public:
	int size; // size of array
	ArrayHandler();// default constructor. all are zero
	void getFromUser();// gets elements from user
	void reversePrint(int elementNum);//prints out array in reverse order
	largest largestNum(int elementNum);//returns value of largest number and its index
	int kThLargest(int start, int end, int k);// finds the k-th largest number in array
	void swap(int a, int b);//swaps items located in a and b in the array
	int* quickSort(int start, int end);//sorts and returns an array
	friend std::ostream& operator<<(std::ostream& os, const ArrayHandler& nums);
	//outputs array.
};// end ArrayHandler

int validPositiveInput(); //checks if input is a positive int
int validInput(); //checks if input is an int
int validK(int top); // checks for an incorrect value for k to be used in kThLargest

#endif
