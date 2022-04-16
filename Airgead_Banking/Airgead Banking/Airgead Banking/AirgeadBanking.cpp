/*
* Name: Anthony D'Angelo
* Date: 4/3/2022
* Project: Airgead Banking Project 2
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

#include "AirgeadBanking.h"

/*
* Initializes member variable
* Params: Initial investment amount set by user
*/
void AirgeadBanking::setInitInvAmount(double t_amount) {
	m_initInvAmount = t_amount;
}
/*
* Retrieves member variable
* Return Value: Initial investment amount
*/
double AirgeadBanking::getInitInvAmount() const {
	return m_initInvAmount;
}
/*
* Initializes member variable
* Params: Monthly deposit amount set by user
*/
void AirgeadBanking::setMonthlyDeposit(double t_deposit) {
	m_monthlyDeposit = t_deposit;
}
/*
* Retrieves member variable
* Return Value: Monthly deposit amount
*/
double AirgeadBanking::getMonthlyDeposit() const {
	return m_monthlyDeposit;
}
/*
* Initializes member variable
* Params: Annual interest amount set by user
*/
void AirgeadBanking::setAnnualInterest(int t_interest) {
	m_annualInterest = t_interest;
}
/*
* Retrieves member variable
* Return Value: Annual interest amount
*/
int AirgeadBanking::getAnnualInterest() const {
	return m_annualInterest;
}
/*
* Initializes member variables
* Note: This member function also allocates memory to
* the member variable m_balances (2-dimensional vector)
* depending on the number of years set by the user
* Params: Years set by user
*/
void AirgeadBanking::setYears(int t_years) {
	m_years = t_years;
	m_balances.resize(t_years, vector<double>(2));
}
/*
* Retrieves member variable
* Return Value: Years
*/
int AirgeadBanking::getYears() const {
	return m_years;
}
/*
* Calculates the yearly amount of money based on the
* initial investment, monthly deposit, interest, and
* number of years
* Params: boolean passed to indicate whether or not to 
* calculate with or without a monthly deposit
*/
void AirgeadBanking::calculateYearEndBalances(bool t_withDeposit) {
	int months = m_years * 12, monthCounter = 0, index;
	double total,
		closingBalance = 0,
		openingAmount = m_initInvAmount,
		depositedAmount,
		interest,
		accruedInterest = 0;

	if (t_withDeposit)
		depositedAmount = m_monthlyDeposit;
	else
		depositedAmount = 0;

	for (unsigned i = 0; i < months; ++i) {
		monthCounter++;

		total = openingAmount + depositedAmount;
		interest = (openingAmount + depositedAmount) * ((5.0 / 100) / 12);
		accruedInterest += interest;
		closingBalance = total + interest;
		openingAmount = closingBalance;

		if (monthCounter % 12 == 0) {
			index = (monthCounter / 12) - 1;
			m_balances[index][0] = closingBalance;
			m_balances[index][1] = accruedInterest;
			accruedInterest = 0;
		}
	}
}
/*
* Formats the dollar amounts and prints them to
* the console in a table
*/
void AirgeadBanking::printYearEndBalances() {
	string formattedMoney;
	
	// Iterates through 2d vector
	for (unsigned i = 0; i < m_balances.size(); ++i) {
		cout << i + 1;
		for (unsigned j = 0; j < m_balances[0].size(); ++j) {
			formattedMoney = "$" + to_string(round(m_balances[i][j]));
			formattedMoney = formattedMoney.substr(0, formattedMoney.find(".") + 3);
			cout << setw(25) << right << formattedMoney;
		}
		cout<< setw(4) << endl;
	}
}
/*
* Prints the table headers to the console based on
* parameter value
* Params: boolean value set by user to indicate which
* table header to print
*/
void AirgeadBanking::printHeaders(bool t_withDeposit) const {
	cout << endl;

	// Centers Table Title based on table
	if (t_withDeposit)
		cout << setw(27);
	else
		cout << setw(26);

	cout << "Balance and Interest ";

	if(t_withDeposit)
		cout << "With ";
	else
		cout << "Without ";

	cout << "Additional Monthly Deposits\n"
		<< "==================================================================\n"
		<< setw(5) << "Year" << setw(28)
		<< "Year End Balance" << setw(34)
		<< "Year End Earned Interest\n"
		<< "==================================================================\n"
		<< setw(4);
}
/*
* Takes in user input and calls member functions
* to initialize member variables
*/
void AirgeadBanking::setUserInput() {
	double initInvAmount, monthlyDeposit;
	int annualInterest, years;

	cout << "\n----------Data Input----------\n"
		<< "Initial Investment Amount: ";
	cin >> initInvAmount;
	cout << "Monthly Deposit: ";
	cin >> monthlyDeposit;
	cout << "Annual Interest: ";
	cin >> annualInterest;
	cout << "Number of Years: ";
	cin >> years;

	setInitInvAmount(initInvAmount);
	setMonthlyDeposit(monthlyDeposit);
	setAnnualInterest(annualInterest);
	setYears(years);
}
/*
* Prints user input to screen
*/
void AirgeadBanking::printUserInput() {
	cout << fixed << setprecision(2) << "\n----------Data Input----------\n"
		<< "Initial Investment Amount: $" << getInitInvAmount() << endl
		<< "Monthly Deposit: $" << getMonthlyDeposit() << endl
		<< "Annual Interest: %" << getAnnualInterest() << endl
		<< "Number of Years: " << getYears() << endl;
}
/*
* Rounds a double value to 2 decimal places
* Params: The number that needs to be rounded
*/
double AirgeadBanking::round(double num) const {
	double value = (int)(num * 100 + .5);

	return (double)value / 100;
}