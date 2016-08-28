#include <cstdio>
#include <list> 
#include <set> 
#include <cmath> 
#include <iterator>
#include <cstring>
#include <iostream> 

using namespace std; 

#define MAX (1000000)
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");

int main()
{
	int number;

	float salary, receiving_by_hours, hours; 

	cin >> number >> hours >> receiving_by_hours;

	printf("NUMBER = %d\n",number);

	printf("SALARY = U$ %.2lf\n",hours * receiving_by_hours);



	return 0;
}