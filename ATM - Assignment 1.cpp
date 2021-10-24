/*
Programmer's Name: Dave Smalling
ID#: 1300112201
Year of Study: 2
Assignment: Assignment 1
Teacher: Mr. Doron Williams
*/

#include <iostream>
#include <iomanip>
#include "passwordMask.cpp"

#define INITIAL_AMOUNT 1000

using namespace std;

void gotoxy(short x, short y);

class Account
{
	public:
		Account();
		void setBalance();
		double getBalance();
		double deposit(double);
		bool withdraw(double);
		int menu();
		//int process(int);
	
	private:
		double balance;
};

Account::Account()
{
	double amt;
	
	system("cls");
	
	gotoxy(20,12);
	cout<<"Please enter inital amount: $";
	cin>>amt;
	
	if(amt >=INITIAL_AMOUNT)
		balance = amt;
	else
	{
		balance = 0;
		
		gotoxy(5,14);
		cout<<"Invalid amount entered for initialization. Balance set to $" <<getBalance();
		
		gotoxy(20,16);
		cout<<"Press any key to continue...";
		getch();
	}
}
		
int main()
{
  	double amt = 0.0;
	
	Account myAcc;
	
	int choice;
	   
	if(getpin())
	{
		choice = myAcc.menu();
	
		while(choice != 4)
		{
			switch(choice)
			{	
				case 1:
					cout<<"\nEnter Deposit Amount: $";
					cin>>amt;
					myAcc.deposit(amt);
				break;
		
				case 2:
					cout<<"\nEnter Withdrawal Amount: $";
					cin>>amt;
					myAcc.withdraw(amt);
				break;
		
				case 3:
					cout<<fixed << setprecision(2)<<"\n\nYour Account Balance is: $" << myAcc.getBalance();
					cout<<"\n\nPress any key to continue...";
					getch();
				break;
		
				case 4:
					exit(1);
				break;
		
				default:
					cout<<"\n\nError. Invalid option";
					cout<<"\nPress any key to continue...";
					getch();
				break;
			}
			choice = myAcc.menu();
		}
	}
	else
	{
		gotoxy(25,14);
		cout<<"PIN INVALID";
		
		gotoxy(25,16);
		cout<<"Press any key to exit";
		
		getch();
	}
}

int Account::menu()
{
	int choice=0;
	
	system("cls");
	
	designScreen();
	
	cout<<"\n\nPress 1 to Deposit";
	cout<<"\n\nPress 2 to Withdraw";
	cout<<"\n\nPress 3 to View Balance";
	cout<<"\n\nPress 4 to Exit";
	cout<<"\n\nPlease enter choice: ";
	cin>>choice;
	
	return choice;
}

double Account::deposit(double amt)
{
	balance += amt;
	
	cout<<"\n\nDeposit Complete...Press any to continue";
	getch();	
	
	return 0;
}

bool Account::withdraw(double amt)
{
	if(amt > balance)
	{
		cout<<"\n\nInsuffcient Balance";
		
		cout<<"\n\nPress any key to continue...";
		getch();
	}
	else
	{
		balance -=amt;
		cout<<"\n\nWithdrawal Complete...Press any to continue";
		getch();
	}
	return 0;
}

double Account::getBalance()
{
	return balance;
}


