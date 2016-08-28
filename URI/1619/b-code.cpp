
#include <bits/stdc++.h>


using namespace std; 

#define MAX (1000000)
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("   HEY\n");
#define HEY3 printf("       HEY\n");
#define END ("\n")

struct Date
{
    int count;
    friend std::istream& operator>>(std::istream& s, Date& d)
    {
        int day_year;
        int day_month;
        int day_days;

        char c; 
        s >> day_year >> c >> day_month >> c >> day_days;

        // cout << day_year << " " << day_month <<  " " << day_days << END; 


        // calculate number of leap years.
        int leapyears    = day_year / 4;
        if (day_year % 4 == 0 && day_month < 3 && ( day_year % 100 != 0 || day_year % 400 == 0 ))
        {
            // If this is a leap year
            // And we have not passed Feburary then it does
            // not count.....
            leapyears   --;
        }
        // convert year/month/day into a day count
        d.count    = day_year * 365 + month_days[day_month-1] + day_days + leapyears; // numero de dias até o dia atual

        // return stream for chaining
        return s;
    }   
    friend int operator-(Date const& lhs, Date const& rhs)
    {
        // subtraction gives you the difference between two Dates objects.
        return lhs.count - rhs.count;
    }
    static int month_days[];
};

int Date::month_days[] = {0,31,59,90,120,151,181,212,243,273,304,334};

int main()
{
    int N;

    cin >> N;

    for(int i = 0; i < N;i++)
    {
        Date date1, date2;
        cin >> date1;
        cin >> date2;



        cout << abs(date1-date2) << END;
    }

}