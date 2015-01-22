/*
* ArrayHandlerTest.cpp
* By Pedro Garate on 11/23/2014
* Description: Program that test the ADT ArrayHandler.
*/
#include "ArrayHandler.h"

using namespace std;

int main()
{
	cout << "ARRAY HANDLER PROGRAM:\n";
	cout << "Let's create 3 arrays.\nRemember that the arrays cannot " <<
		"be empty\nand that it cannot have more than 1000 elements.\n\n";

	//************** default constructor ******************
	ArrayHandler array1, array2, array3;

	//************** getFromUser()*************************
	cout << "ARRAY #1:\n";
	array1.getFromUser();

	cout << "ARRAY #2:\n";
	array2.getFromUser();

	cout << "ARRAY #3:\n";
	array3.getFromUser();
	//*****************************************************

	//*************** overloaded << ***********************
	cout << "Array #1:\n" << array1 << endl;
	cout << "Array #2:\n" << array2 << endl;
	cout << "Array #3:\n" << array3 << endl << endl;
	//*****************************************************

	//************** reversePrint *************************
	cout << "Array #1 in reverse order:\n";
	array1.reversePrint(array1.size);
	cout << endl;
	//*****************************************************

	//************** largestNum ***************************
	cout << "\nThe largest number in Array #2 is: " <<
		array2.largestNum(array2.size).maxNum <<
		" and its index is: " <<
		array2.largestNum(array2.size).index << endl;
	//*****************************************************

	//************* k-th largest number *******************
	cout << "\nLet's find the k-th largest number in Array #3"
		<< "\nRemember that \"k\" cannot be less than 1 or "
		<< "greater than " << array3.size << endl
		<< "Please input \"k\": ";
	int k = validK(array3.size);
	cout << "The " << k << "-th largest number in Array #3 is: "
		<< array3.kThLargest(0, array3.size - 1, k) << endl;
	cout << array3 << endl;
	//*****************************************************

	//************* quickSort *****************************
	cout << "\nNow let's sort array #1 using quickSort:\n";
	cout << "Array #1 before sorting:\n" << array1 << endl;
	cout << "\nArray #1 after sorting:\n";
	array1.quickSort(0, array1.size - 1);
	cout << array1 << endl;
	//*****************************************************

	return EXIT_SUCCESS;
}//end main
