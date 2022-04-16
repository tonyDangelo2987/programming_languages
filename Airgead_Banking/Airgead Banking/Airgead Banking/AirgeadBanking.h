/*
* Name: Anthony D'Angelo
* Date: 4/3/2022
* Project: Airgead Banking Project 2
*/

#ifndef AIRGEADBANKING_H
#define AIRGEADBANKING_H

class AirgeadBanking {
    public:
        void calculateYearEndBalances(bool t_withDeposit = true);
        void printYearEndBalances();
        void printHeaders(bool t_withDeposit = true) const;
        void setUserInput();
        void printUserInput();
    private:
        double m_initInvAmount = NULL;
        double m_monthlyDeposit = NULL;
        int m_annualInterest = NULL;
        int m_years = NULL;
        vector<vector<double>> m_balances;

        void setInitInvAmount(double t_amount);
        double getInitInvAmount() const;
        void setMonthlyDeposit(double t_deposit);
        double getMonthlyDeposit() const;
        void setAnnualInterest(int t_interest);
        int getAnnualInterest() const;
        void setYears(int t_years);
        int getYears() const;
        double round(double num) const;
};

#endif