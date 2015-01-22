/*
* ArrayHandler.cpp
* By Pedro Garate on 11/23/2014
* Description: ADT that contains a fixed-size array of integers (1000).
*			   It gets the input from the user. Has a function to print the
*              array in reverse order, a function to search the largest
*              number in the array, another function to find the k-th
*              largest number and a quickSort function.
*/
#include "ArrayHandler.h"
#include <iostream>

using namespace std;

//default constructor. all items are zero.
ArrayHandler::ArrayHandler()
{
}//end of default constructor

//gets elementNum numbers from user
void ArrayHandler::getFromUser()
{
	cout << "How many items will your array have?\n";
	size = validPositiveInput();

	cout << "Let's fill the array.\nPlease enter the numbers to " <<
		"fill the array.\n";
	for (int i = 0; i < size; i++)
		numbers[i] = validInput();//put input into array

	// clear input and ignore what was entered
	// no matter the size to delete extras.
	cin.clear();
	cin.ignore(std::numeric_limits<int>::max(), '\n');
	cout << endl;
}//end of getFromUser

//prints out array in reverse order
void ArrayHandler::reversePrint(int elementNum)
{
	if (elementNum == 0) // array is empty
		return;
	else
	{
		cout << numbers[elementNum - 1] << " ";
		//prints out last item and
		//calls function with one less total number of items
		reversePrint(elementNum - 1);
	}
}//end of reversePrint

//returns value of largest number and its index (not position)
ArrayHandler::largest ArrayHandler::largestNum(int elementNum)
{
	largest max;
	max.index = elementNum - 1;
	max.maxNum = numbers[max.index];

	if (elementNum > 1)
	{
		//check maxNum against previous items in numbers[]
		if (max.maxNum < largestNum(elementNum - 1).maxNum)
		{
			max.maxNum = largestNum(elementNum - 1).maxNum;
			max.index = largestNum(elementNum - 1).index;
		}
	}

	return max; // base case when elementNum == 1
}//end of largestNum

//finds the k-th largest number in array
int ArrayHandler::kThLargest(int start, int end, int k)
{
	int pivot = start;
	int left = start;
	int right = end;

	//partition
	while (left <= right)
	{
		while (left <= right && numbers[left] >= numbers[pivot])
			++left;
		while (left <= right && numbers[right] <= numbers[pivot])
			--right;
		if (left < right)
			swap(left, right);
	}
	swap(pivot, right);

	//recursion
	if (k - 1 == right)
		return numbers[right];
	else if (k - 1>right)
		return kThLargest(right + 1, end, k);
	else
		return kThLargest(start, right - 1, k);
}//end of kThLargest

//sorts and returns an array
int* ArrayHandler::quickSort(int start, int end)
{
	int left = start;
	int right = end;
	int pivot = numbers[(left + right) / 2];

	// partition
	while (left <= right)
	{
		while (numbers[left] < pivot)
			++left;
		while (numbers[right] > pivot)
			--right;

		if (left <= right)
		{
			swap(left, right);
			left++;
			right--;
		}
	}

	/* recursion */
	if (start < right)
		quickSort(start, right);

	if (left < end)
		quickSort(left, end);

	return numbers;
}//end quickSort

// output an array
std::ostream& operator<<(std::ostream& os, const ArrayHandler& arr)
{
	for (int i = 0; i<arr.size; i++)
	{
		os << arr.numbers[i] << " "; // show array
	}
	return os;
}// end of operator<<

//swaps items located in a and b in the array
void ArrayHandler::swap(int a, int b)
{
	int temp = numbers[a];
	numbers[a] = numbers[b];
	numbers[b] = temp;
}//end of swap

//checks if input is a positive int from 1 to 1000
int validPositiveInput()
{
	int num;
	cin >> num;
	//detect if input isn't an int or less than 1 or greater than 1000.
	while (cin.fail() || num < 1 || num > 1000)
	{
		// clear input and ignore what was entered
		// no matter the size.
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cout << "Bad entry.  Enter POSITIVE INTEGERS (1 to 1000, inclusive):\n";
		// get new input
		cin >> num;
	}
	return num;
}//end validPositiveInput

// checks for an incorrect value for k to be used in kThLargest
int validK(int top)
{
	int num;
	cin >> num;
	//detect if input isn't an int or less than 1 or greater than 1000.
	while (cin.fail() || num < 1 || num > top)
	{
		// clear input and ignore what was entered
		// no matter the size.
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cout << "Bad entry.  Enter POSITIVE INTEGERS (1 to "
			<< top << ", inclusive):\n";
		// get new input
		cin >> num;
	}
	return num;
}//end validK

//checks if input is an int
int validInput()
{
	int num;
	cin >> num;
	// detect if input isn't an int.
	while (std::cin.fail())
	{
		// clear input and ignore what was entered
		// no matter the size.
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cout << "Bad entry.  Enter INTEGERS:\n";
		// get new input
		cin >> num;
	}
	return num;
}//end validInput
