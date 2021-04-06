/** \file bugExample.cpp
 *  \brief     A little with logical bugs in it
 *  \details   This program is littered with logical bugs. Your task is the
 *              following:
 *                1) Compile and run the program.
 *                2) For each bug you find you must fix the bug then Check In
 *                   the code with a comment on the fix you did
 *                3) There are a three functions that are not completed, you need to
 *                   complete them and also update the menu and the main function
 *  \author    Harald Gjermundrod
 *  \version   0.1
 *  \date      2017-2017
 *  \bug       Many logical bugs
 *  \copyright University of Nicosia.
 */

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes
int printMenu();
void fillInArray(int[], const int);
void multArrays(const int[], const int[], int[], const int);
void displayArray(const int[], const int);
int sumOddArray(const int[], const int);
bool isAllPositive(const int[], const int);
void avgOddArray(const int[], const int, int&);

/**
 * <code>main</code> is the main function of this program.
 * <BR>
 * @return Returns 0 if success, any other value otherwise.
 */
int main() {
	int choice;
	const int SIZE = 10;

	// Initialize array price
	int price[SIZE];
	// Declare array quantity and total
	int quantity[SIZE], total[SIZE];

	//Initialise average for option 6
	int average = 0;

	//Seeding random number generator
	srand(time(0));

	//Initialising price array with random numbers
	for (int i = 0; i < SIZE; i++)
		price[i] = rand() % 100;

	// Interactive menu
	do {
		choice = printMenu();

		switch (choice){
			// Enter quantity
			case 1:
				fillInArray(quantity, SIZE);
				break;
			// Calculate total
			case 2:
				multArrays(quantity, price, total, SIZE);
				break;
			// Print total
			case 3:
				displayArray(total, SIZE);
				break;
			case 4:
				cout << "The sum of odd numbers is: " << sumOddArray(quantity, SIZE);
				break;
			case 5:
				if (isAllPositive(quantity, SIZE) == 1)
					cout << "All numbers are positive";
				else
					cout << "Not all numbers are positive";
				break;
			case 6: 
				avgOddArray(quantity, SIZE, average);
				cout << "The average of odd numbers is: " << average;
				break;
			// Exit
			case 7:
				// No code needed
				break;
			default:
				assert(true);
		}
	} while (choice != 7);

	cout << "\nHave a nice day:)" << endl;
	return 0;
}

/**
 * <code>printMenu</code> shows a menu and accepts the choice
 * from the user which is returned.
 * <BR>
 * @return Returns the menu choice
 */
int printMenu(){
	int choice;

	do {
		cout << "\n == MENU ==";
		cout << "\n1) Enter quantity";
		cout << "\n2) Calculate total";
		cout << "\n3) Print total";
		cout << "\n4) Sum of odd quantity";
		cout << "\n5) All positive check";
		cout << "\n6) Find average of odd numbers";
		cout << "\n7) Exit";

		cout << "\nEnter the choice: ";
		cin >> choice;

		if (choice < 1 || choice > 7){
			cout << "\nWrong choice, try again.";
		}
	} while (choice < 1 || choice > 8);
	return choice;
}

/**
 * <code>fillInArray</code> is a function that will
 * fill in the elements of an array.
 * <BR>
 * @param arr The array to be filled in.
 * @param size The size of the array.
 */
void fillInArray(int arr[], const int size){
	assert (size > 1);

	for (int i = 0; i < size; ++i){
		cout << "\nEnter an element for the array at " << i << ": ";
		cin >> arr[i];
	}
}

/**
 * <code>multArrays</code> multiplies the value of elements of the quantity array
 * to the corresponding value at the price array. NOTE: precondition
 * is that the arrays have the same size.
 * <BR>
 * @param arrQuantity The array containing the source elements.
 * @param arrPrice The array containing price values
 * @param arrTotal The array containing the destination elements.
 * @param size The size of the arrays.
 */
void multArrays(const int arrQuantity[], const int arrPrice[], int arrTotal[], const int size){
	assert (size > 0);

	for (int i = 0; i < size; ++i){
		arrTotal[i] = arrQuantity[i] * arrPrice[i];
	}
}

/**
 * <code>displayArray</code> prints the value of each of the elements of the
 * array. In addition the function sums up the value of all the elements and
 * print the total.
 * <BR>
 * @param ar The array containing the values
 * @param size The size of the array.
 */
void displayArray(const int arr[], const int size){
	int sum = 0; //initialised sum

	for (int i = 0; i < size; ++i){
		cout << "\nValue at " << i << ": " << arr[i];
		sum += arr[i];
	}

	cout << "\nThe total is: " << sum;
}

/**
 * <code>sumOddArray</code> sums all the odd values in the array and
 * returns the total.
 * <BR>
 * @param arr The array containing the values
 * @param size The size of the array.
 * @return sum Sum of all odd numbers in the array
 */
int sumOddArray(const int arr[], const int size){
	int sum = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 == 1)
			sum += arr[i];
	}
	return sum;
}

/**
 * <code>isAllPositive</code> checks if all the values in the array
 * are positive and return true or false.
 * <BR>
 * @param arr The array containing the values
 * @param size The size of the array.
 * @return true/false
 */
bool isAllPositive(const int arr[], const int size){
	for(int i = 0; i < size; i++) {
		if (arr[i] < 0)
			return false;
	}
  return true;
}

/**
 * <code>avgOddArray</code> computes the average of all odd numbers in the array
 * by calling the sumOddArray and dividing it by the size variable.
 * <BR>
 * @param arr The array containing the values
 * @param size The size of the array.
 * @param avgOdd Holds average of all the odd numbers in the array
 */
// Finds the average of all the odd numbers in the array and stores this in the last argument
void avgOddArray(const int arr[], const int size, int& avgOdd){
	int count = 0; //To keep track of all odd numbers in the array
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 == 1)
			count++;
	}
	avgOdd = sumOddArray(arr, size) / count;
}
