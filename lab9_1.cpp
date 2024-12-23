#include <iostream>
#include <iomanip>

using namespace std;

void PrintColum(int a, double b, double c, double d, double e, double f);

int main()
{
	double loan, interestRate, payment;

	cout << "Enter initial loan: ";
	cin >> loan;
	cout << "Enter interest rate per year (%): ";
	cin >> interestRate;
	cout << "Enter amount you can pay per year: ";
	cin >> payment;

	int year = 0;
	double PrevBalance = loan, Interest, Total, Payment, NewBalance = loan;
	cout << setw(13) << left << "EndOfYear#";
	cout << setw(13) << left << "PrevBalance";
	cout << setw(13) << left << "Interest";
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";

	while (NewBalance > 0)
	{
		year++;
		PrevBalance = NewBalance;
		Interest = PrevBalance * (interestRate / 100);
		Total = PrevBalance + Interest;
		Payment = Total <= payment ? Total : payment;
		NewBalance = Total - Payment;

		PrintColum(
			year,
			PrevBalance,
			Interest,
			Total,
			Payment,
			NewBalance);
	}

	return 0;
}

void PrintColum(int a, double b, double c, double d, double e, double f)
{
	cout << fixed << setprecision(2);
	cout << setw(13) << left << a;
	cout << setw(13) << left << b;
	cout << setw(13) << left << c;
	cout << setw(13) << left << d;
	cout << setw(13) << left << e;
	cout << setw(13) << left << f;
	cout << "\n";
}
