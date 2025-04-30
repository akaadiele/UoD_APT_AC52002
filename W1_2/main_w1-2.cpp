/*
* Part 1: Practice with functions

#include <iostream>
using namespace std;


//Function Declarations: 
void task_1();
void task_02();
void task_2(int countMax);
void task_3(int width, int length);
void five_stars();
void print_stars(int count);
void print_char(char displayChar, int count);


int main() {


	////Task 2
	//int numOfNumbers;
	//cout << "Please enter how many numbers to be added: \n";
	//cin >> numOfNumbers;
	//task_2(numOfNumbers);
	//cout << endl;

	////Task 3
	//int l=0,w=0;
	//cout << "Please enter length: \n";
	//cin >> l;

	//cout << "Please enter width: \n";
	//cin >> w;
	//task_3(w,l);
	//cout << endl;


	////Task 4
	//five_stars();
	//cout << endl;


	////Task 5
	//int starsCount = 0;
	//cout << "Please enter how many stars to be displayed: \n";
	//cin >> starsCount;

	//print_stars(starsCount);
	//cout << endl;


	////Task 6
	//char charDis; int starsCount = 0;
	//cout << "Please enter character to be displayed: \n";
	//cin >> charDis;
	//
	//cout << "Please enter how many stars to be displayed: \n";
	//cin >> starsCount;

	//
	//print_char(charDis, starsCount);
	//cout << endl;


	//Task 7
	int l=0,w=0;
	cout << "Please enter length: \n";
	cin >> l;

	cout << "Please enter width: \n";
	cin >> w;
	task_3(w,l);
	cout << endl;


	return 0;
}


//Function definitions: 


void print_char(char displayChar, int count) {
	for (int i = 0; i < count; i++) {
		cout << displayChar;
	}
}


void print_stars(int count) {
	for (int i = 0; i < count; i++) {
		cout << "*";
	}
}


void five_stars() {
	cout << "*****";
}

void task_3(int width, int length) {
	//7. Write a program that uses a loop to draw a rectangle with the letter ‘s’, of length 4 and
		//width 3, i.e.
		//ssss
		//ssss
		//ssss

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++) {
			cout << "s";
		}
		cout << endl;
	}
}


void task_2(int countMax) {
	//5. Write a program that asks the user to type in the number of numbers that will follow, 
	//	and then asks the user for the numbers and displays the sum.
	//	You may use any kind of loop you like to achieve this

	int number = 0, count = 0, sum = 0;

	cout << "Please enter the " << countMax << " numbers: " << endl;

	for (count = 1; count <= countMax; count++) {
		cin >> number;
		sum += number;
	}
	cout << "The sum of the " << countMax << " numbers is : " << sum << endl;
}

void task_02() {
	//4. Write a program to input 8 numbers and display their sum.
	//Use (i) a while loop; (ii)a for loop

	cout << "Please enter 8 numbers: " << endl;
	int number = 0, count, sum = 0;
	for (count = 1; count <= 8; count++) {
		cin >> number;
		sum += number;
	}
	cout << "The sum of the numbers is: " << sum << endl;
}

void task_1() {
	//1. Write a program to input two numbers and output the larger of the two.
	int number1, number2;
	//cout << "Please enter two numbers: " << endl << endl;
	//cin >> number1 >> number2;

	cout << "Enter first number: ";
	cin >> number1;

	cout << "Enter second number: ";
	cin >> number2;
	cout << endl;

	if (number1 > number2) {
		cout << "The larger number is: " << number1 << endl;
	}
	else if (number2 > number1) {
		cout << "The larger number is: " << number2 << endl;
	}
	else {
		cout << "Both numbers are equal." << endl;
	}

}

*/

// ------------------------------------------------------------------------

//double milToKm(double milesValue);
//
//int main() {
//
//	//Write a function to convert a distance in miles tothe equivalent distance in kilometres. 
//	//(To do this you multiply the miles figure by 8 / 5).
//
//	cout.setf(ios::fixed);
//	cout.setf(ios::showpoint);
//	cout.precision(2);
//
//	double milesInput = 0;
//
//	cout << "Please enter the distance in miles: ";
//	cin >> milesInput;
//
//	cout << "The distance in miles is: " << milToKm(milesInput) << endl;
//	
//	return 0;
//}
//
//double milToKm(double milesValue) {
//	return (milesValue * 8 / 5);
//}
//


// ------------------------------------------------------------------------
//Part 2: Files in C++

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const string rootDirectory = "C:\\Users\\Akaad\\OneDrive\\Documents\\VS_Projects\\UoD_APT_AC52002\\W1_2\\files\\";

int main() {

	/*
	//9. Write a program that will read a file of text, remove all the vowels, and write the output to a second file
	ifstream q9File;
	q9File.open(rootDirectory + "Q9.txt");

	ofstream q9FileOut;
	q9FileOut.open(rootDirectory + "Q9_Out.txt");


	char currentChar = q9File.get();
	
	char tempChar;
	string fullText, textNoVowel;

	if (q9File.is_open()) {

		while ( !q9File.eof() ) {
			cout << currentChar << endl;
			
			tempChar = currentChar;
			tempChar = tolower(tempChar);
			if ( !( (tempChar == 'a') || (tempChar == 'e') || (tempChar == 'i') || (tempChar == 'o') || (tempChar == 'u') ) ) {
				textNoVowel += tempChar;
				q9FileOut.put(tempChar);
			}

			fullText += currentChar;

			currentChar = q9File.get();
		}
	}

	q9File.close();

	cout << "Old content is: " << fullText << endl;
	cout << "New content without vowel is: " << textNoVowel << endl;

	*/
	


	/*
	//8. Write a program that will search a file of numbers of type int and write the largest and the smallest numbers to the screen
	ifstream q8File;
	q8File.open(rootDirectory + "Q8.txt");

	if (q8File.is_open()) {
		int numInFile, largest = 0, smallest;

		//largest = smallest = numInFile;
		q8File >> numInFile;
		smallest = numInFile;
		largest = numInFile;
		cout << numInFile << endl;

		while ((q8File >> numInFile)) {
			cout << numInFile << endl;

			if (numInFile > largest) {
				largest = numInFile;
			}

			
			if (numInFile < smallest) {
				smallest = numInFile;
			}
		}

		cout << endl;
		cout << "The smallest number is: " << smallest << endl; 
		cout << "The largest number is: " << largest << endl;
	}

	q8File.close();
	*/

	return 0;
}
