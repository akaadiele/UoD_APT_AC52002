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

	//int count = 0, sum = 0, countMax = 39;

	//do {
	//	cout << "count is: " << count << endl;
	//	sum += count;

	//	count++;
	//} while (count <= countMax);

	//cout << "\nThe sum of the numbers from 0 to " << countMax << " is: " << sum << endl;

	//sum = countMax * (countMax + 1) / 2;
	//cout << "\nThe sum of the numbers from 0 to " << countMax << " is: " << sum << endl;

	// ------------------------------------------------------------------------
	//7. Write a program that uses a loop to draw a rectangle with the letter ‘s’, of length 4 and
	//width 3, i.e.
	//ssss
	//ssss
	//ssss

	/*for (int width = 0; width < 3; width++)
	{
		for (int length = 0; length < 4; length++) {
		cout << "s";
		}
		cout << endl;
	}*/

	// ------------------------------------------------------------------------

	//srand(time(0));
	//int randomNum;
	//for (int i = 1; i <= 3; i++) {
	//	randomNum = rand() % 7;
	//	cout << randomNum << endl;
	//}

	// ------------------------------------------------------------------------
	//8(a).A group of people are betting on the outcome of three throws of a single die.A person bets
	//£1 on predicting the outcome of three throws.Write a program that asks the user to input the
	//values of the three throws and displays the winnings according to the following rules :
	//• all 3 dice are sixes : win £20
	//• all three dice are the same(but not sixes) : win £10
	//• any two dice are the same : win £5
	//
	//Optional extras :
	//8(b)Read up about rand(, ) and try to generate the three dice numbers automatically.

	//int randomNum = 0, dice = 0, winCount = 0, sixCount = 0;
	//
	//for (int i = 1; i <= 3; i++) {
	//	cout << "Please enter a number between 1 and 6 for your dice throw: ";
	//	cin >> dice;

	//	randomNum = rand() % 7;
	//	cout << randomNum << endl;

	//	if (randomNum == dice) {
	//		cout << "You win!" << endl;
	//		winCount++;

	//		if (randomNum == 6) {
	//			sixCount++;
	//		}
	//	}
	//	else {
	//		cout << "You lose!" << endl;
	//	}
	//}

	//cout << "You have won " << winCount << " times." << endl;
	//cout << "You have rolled a 6 " << sixCount << " times." << endl;

	//if (sixCount == 3) {
	//	cout << "\nYou have won £20" << endl;
	//}
	//else {
	//	if ((sixCount == 0) && (winCount == 3)) {
	//		cout << "\nYou have won £10" << endl;
	//	}
	//	else {
	//		if (winCount == 2) {
	//			cout << "\nYou have won £5" << endl;
	//		}
	//	}
	//}

	// ------------------------------------------------------------------------
	//9. (Harder)Write a program to take in a year as an integer(e.g. 1989, 2007) and determine if the
	//year is a leap year.
	//(A leap year is one divisible by 4, unless it ends in 00, in which case it is only a leap year if it is divisible by 400, so 2000 was a leap year but 1900 was not.)


	int year = 0;
	cout << "Please enter a year: ";
	cin >> year;

	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				cout << year << " is a Leap year" << endl;
			}
			else {
				cout << year << " is not a leap year" << endl;
			}
		}
		else {
			cout << year << " is a Leap year" << endl;
		}
	}
	else {
		cout << year << " is a Leap year" << endl;
	}
	// ------------------------------------------------------------------------


	// ------------------------------------------------------------------------


	// ------------------------------------------------------------------------


	return 0;
}