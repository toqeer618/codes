#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

int main()
{
	double x, n, sum=0;
	cout << "Enter the Value of X: ";
	cin >> x;
	cout << "Enter the Value of N: ";
	cin >> n;
	for (int i=1, p=0; i<=n; i++,p=p+2)
	{
		if (i==1)
		{
			sum =1;
		    }
		else if (i%2==1)
		{
			sum -= pow(x,p);
	  	    }
		else if(i%2==0)
		{
			sum += pow(x,p);
		    } 
	}
	cout << "Sum of Series: " << sum;
	getch();
}
    
