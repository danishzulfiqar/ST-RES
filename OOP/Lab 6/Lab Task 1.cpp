#include <bits/stdc++.h>
using namespace std;

class SavingsAccount
{
private:
    float savingsBalance;

public:
    SavingsAccount() {}
    
    SavingsAccount(int value)
    {
        savingsBalance = value;
    }
    static float annualInterestRate; // Static Type Function
    void calculateMonthlyInterest();

    static void modifyIntererestRate(float value); // Static Type Function
    float GetBalance() const
    {
        return savingsBalance;
    }
};

float SavingsAccount::annualInterestRate = 0;

void SavingsAccount::calculateMonthlyInterest()
{
    savingsBalance += ((savingsBalance * annualInterestRate) / 12);
}

void SavingsAccount::modifyIntererestRate(float value)
{
    annualInterestRate = value;
}

int main()
{
    SavingsAccount saver1(2000.00);
    SavingsAccount saver2(3000.00);

    SavingsAccount::modifyIntererestRate(3); // Static Function is called
    saver1.calculateMonthlyInterest();
    cout << fixed << setprecision(2) << "Saver 1 Savings Balance: $" << saver1.GetBalance() << endl;

    saver2.calculateMonthlyInterest();
    cout << fixed << setprecision(2) << "Saver 2 Savings Balance: $" << saver2.GetBalance() << endl;
    cout << endl;

    SavingsAccount::modifyIntererestRate(4); // Static Function is called
    saver1.calculateMonthlyInterest();
    cout << fixed << setprecision(2) << "Saver 1 Savings Balance: $" << saver1.GetBalance() << endl;

    saver2.calculateMonthlyInterest();
    cout << fixed << setprecision(2) << "Saver 2 Savings Balance: $" << saver2.GetBalance() << endl;
    cout << endl;
    return 0;
}