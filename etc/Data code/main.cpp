#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;
int main()
{
	int account_number,minimum_balance,current_balance,i;
	i=0;
	double si,updated_balance;
	char n;
	ifstream in;
	in.open("bank.txt");
	ofstream out;
	out.open("updated_balance.txt");
	while (i<5)
	{
	in>>account_number>>n>>minimum_balance>>current_balance;
	if (n=='s'||n=='S')
	{
		if (current_balance<minimum_balance)
		{
			updated_balance=current_balance-10;
		}
		else if (current_balance>=minimum_balance)
		{
			si=(current_balance/100)*4;
			updated_balance=current_balance+si;
		}
	}
	else if (n=='c'||n=='C')
	{
		if (current_balance<minimum_balance)
		{
			updated_balance=current_balance-25;
		}
		else if (current_balance>=minimum_balance && current_balance<=(minimum_balance+5000))
		{
			si=(current_balance/100)*5;
			updated_balance=current_balance+si;
		}
		else if (current_balance>(minimum_balance+5000))
		{
			si=(current_balance/100)*3;
			updated_balance=current_balance+si;
		}
	}
	else
	{
		cout<<"Your pressed wrong key for account type"<<endl;
	}
	out<<account_number<<" "<<n<<" "<<minimum_balance<<" "<<current_balance<<" $"<<updated_balance<<endl;
	i++;
	}
	in.close();
	out.close();



	return 0;
}
