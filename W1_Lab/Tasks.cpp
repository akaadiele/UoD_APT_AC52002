#include <iostream>
using namespace std;

int main() {

	////1. Write a program to input two numbers and output the larger of the two.
	//int number1, number2;
	//cout << "Please enter two numbers: " << endl << endl;
	////cin >> number1 >> number2;
	//cout << "Enter first number: ";
	//cin >> number1;

	//cout << "Enter second number: ";
	//cin >> number2;
	//cout << endl;

	//if (number1 > number2) {
	//	cout << "The larger number is: " << number1 << endl;
	//}
	//else if (number2 > number1) {
	//	cout << "The larger number is: " << number2 << endl;
	//}
	//else {
	//	cout << "Both numbers are equal." << endl;
	//}

	// ------------------------------------------------------------------------
	//2. Write a program to decide how much a person pays to go to the cinema. 
	// The program should request an age and then decide on the following basis :
	/*	• under 5, free
		• aged 5 to 12, half price
		• aged 13 to 54, full price
		• aged 55 or over, free
		*/

		//int age;
		//cout << "Please enter your age \n";
		//cin >> age;

		//if (age < 5) {
		//	cout << "Your cinema fee is 'free'" << endl;
		//}
		//else if (age >= 5 && age <= 12) {
		//	cout << "Your cinema fee is 'Half Price'" << endl;
		//}
		//else if (age > 13 && age < 54) {
		//	cout << "Your cinema fee is 'Full Price'" << endl;
		//}
		//else if (age >= 55) {
		//	cout << "Your cinema fee is 'free'" << endl;
		//}
		//else {
		//	cout << "Invalid input" << endl;
		//}


	// ------------------------------------------------------------------------
	//3. Write a program that uses a while loop to display the numbers 1 to 100. 
	//	Repeat this exercise using a do while loop.Finally, repeat it using a for loop.

	//int count = 1;
	
	/*while (count <= 100) {
		cout << count << " ";
		
		if (count % 10 == 0) {
			cout << endl;
		}
		count++;
	}*/

	
	/*do {
		cout << count << " ";

		if (count % 10 == 0) {
			cout << endl;
		}
		count++;
	} while (count <= 100);*/

	/*for (count = 1; count <= 100; count++) {
		cout << count << " ";
		if (count % 10 == 0) {
			cout << endl;
		}
	}*/

	// ------------------------------------------------------------------------
	//4. Write a program to input 8 numbers and display their sum.
		/*Use(i) a while loop;
		(ii)a for loop*/

	//cout << "Please enter 8 numbers: " << endl;
	//int number = 0, count, sum = 0;
	//for (count = 1; count <= 8; count++) {
	//	cin >> number;
	//	sum += number;
	//}
	//cout << "The sum of the numbers is: " << sum << endl;

	// ------------------------------------------------------------------------

	//5. Write a program that asks the user to type in the number of numbers that will follow, 
	//	and then asks the user for the numbers and displays the sum.
	//	You may use any kind of loop you like to achieve this

	//int number = 0, count, sum = 0, countMax = 0;
	//
	//cout << "Please enter how many numbers to be added: \n";
	//cin >> countMax;

	//cout << "Please enter the " << countMax << " numbers: " << endl;
	//
	//for (count = 1; count <= countMax; count++) {
	//	cin >> number;
	//	sum += number;
	//}
	//cout << "The sum of the " << countMax << " numbers is : " << sum << endl;

	// ------------------------------------------------------------------------
	//6. Write a program that adds up the numbers 0 to 39 using a for loop.
	//You should then check the result by using the formula for the sum of numbers from 0 to n, which is n(n +1) / 2

	int count = 0, sum = 0, countMax = 39;

	//do {
	//	cout << "count is: " << count << endl;
	//	sum += count;

	//	count++;
	//} while (count <= countMax);

	//cout << "\nThe sum of the numbers from 0 to " << countMax << " is: " << sum << endl;

	//sum = countMax * (countMax + 1) / 2;
	//cout << "\nThe sum of the numbers from 0 to " << countMax << " is: " << sum << endl;

// ------------------------------------------------------------------------

	//for (int length = 0, width = 0; (length < 4) && (width < 3); length++, width++)
	//{
	//	//cout << “length, width” << length << “, ” << width << endl;
	//	cout << "s";
	//}

	for (int width = 0; width < 3; width++)
	{
		for (int length = 0; length < 4; length++) {
		cout << "s";
		}
		cout << endl;
	}

	// ------------------------------------------------------------------------


	// ------------------------------------------------------------------------

	// ------------------------------------------------------------------------


	return 0;
}