
#include <bits/stdc++.h>

using namespace std; 

#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");
#define END ("\n")
#define for0(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define for1(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)
#define pm(mat,n,m) \
	for0(i,n)		\
	{				\
		for0(j,m)	\
		{			\
			cout << "[" << mat[i][j] << "]";	\
		}ENDLINE	\
	}	\

#define pa(array,n) \
	{				\
	for0(i,n)		\
	{				\
		cout << "[" << array[i] << "]";	\
	}				\
	ENDLINE; 		\
	}				\

#define ps(s) printf("%s\n",s);

#define MAX 1000000

typedef long long int ll; 

int power(int v,int n)
{
	int i = 1;
	for0(j,n)
	{
		i *= v; 
	}

	return i;
}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		double number; cin >> number;
		double integral;
		double double_part = modf(number,&integral);

		int count = 0;
		int integer_part = ceil(integral);
		int palindrome_integer = 0;
		int aux = integer_part;

		while(integer_part)
		{
			palindrome_integer = palindrome_integer*10 + (integer_part%10);
			integer_part /= 10;
			count++;
		}
		int digits_10 = power(10,count);	

		double palindrome_double = (double)palindrome_integer/(double)(digits_10);
		// printf("PI: %d %lf %d\n",palindrome_integer, (double)palindrome_integer/(double)power(10,count),(int)power(10,count));
		palindrome_double = round(palindrome_double*MAX)/MAX;
		double_part = round(double_part*MAX)/MAX;

		if(palindrome_integer == aux && double_part == 0)
		{	
			HEY
			printf("0\n"); 
		}else 
		if((int)digits_10 % aux == 0)
		{
			printf("%g\n",abs(palindrome_integer -  double_part));
		}else {
			// printf("%lf %lf\n",palindrome_double, double_part);
			double value = abs( (palindrome_double - double_part) );
			printf("%.g\n",value);
		}


	}


	return 0;
}