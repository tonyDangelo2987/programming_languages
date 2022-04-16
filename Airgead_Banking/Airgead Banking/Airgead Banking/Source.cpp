/*
* Name: Anthony D'Angelo
* Date: 4/3/2022
* Project: Airgead Banking Project 2
*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#include "AirgeadBanking.h"

int main() {
	AirgeadBanking client;
	char rerun = ' ';

	do {
		system("cls");
		client.setUserInput();
		system("cls");
		client.printUserInput();

		system("pause");

		client.printHeaders(false);
		client.calculateYearEndBalances(false);
		client.printYearEndBalances();
		client.printHeaders();
		client.calculateYearEndBalances();
		client.printYearEndBalances();

		cout << "\nWould you like to test different values? (y/n): ";
		cin >> rerun;
	} while (rerun == 'y' || rerun == 'Y');

	return 0;
}