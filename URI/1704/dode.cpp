#include <bits/stdc++.h>
#include <algorithm>
 
using namespace std;
 
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("   HEY\n");
#define HEY3 printf("       HEY\n");
#define END ("\n")
#define for0(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define for1(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)
#define forab(i,a,b)for(__typeof(b)i = a ; i <= (b) ; i++)
 
#define pm(mat,n,m) \
    for0(i,n)       \
    {               \
        for0(j,m)   \
        {           \
            cout << "[" << mat[i][j] << "]";    \
        }ENDLINE    \
    }   \
 
#define pa(array,n) \
    {               \
    for0(i,n)       \
    {               \
        cout << "[" << array[i] << "]"; \
    }               \
    ENDLINE;        \
    }               \
 
#define ps(s) printf("%s\n",s);

// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
 
// A structure to represent a job
struct Job
{
   int dead;    // Deadline of job
   int profit;  // Profit if job is over before or on deadline
};
bool slot[1005];  // To keep track of free time slots  
int result[1005]; // To store result (Sequence of jobs)
Job jobs[1005];
// This function is used for sorting all jobs according to profit
bool comparison(Job a, Job b)
{
     return (a.profit > b.profit);
}
 
// Returns minimum number of platforms reqquired
void printJobScheduling(Job arr[], int n, int h)
{
    // Sort all jobs according to decreasing order of prfit
    sort(arr, arr+n, comparison);
  
    // Iterate through all given jobs
    for (int i=0; i<n; i++)
    {
       // Find a free slot for this job (Note that we start
       // from the last possible slot)
       for (int j=min(h, arr[i].dead)-1; j>=0; j--)
       {
          // Free slot found
          if (slot[j]==false)
          {
             result[j] = i;  // Add this job to result
             slot[j] = true; // Make this slot occupied
             break;
          }
       }
    }
 
    // Print the result
  /*  for (int i=0; i<n; i++)
       if (slot[i])
         cout << arr[result[i]].id << " ";*/
}
 
// Driver program to test methods
int main()
{

    ios_base :: sync_with_stdio(0);
    cin.tie(0);


    int N,H;

    while(cin >> N >> H)
    {
        int lucro = 0;
        memset(result,0,sizeof result  );
        memset(slot,0,sizeof slot);
        memset(jobs,0,sizeof jobs);
        
        for0(i,N)
        {
            cin >> jobs[i].profit;  cin >> jobs[i].dead;
            lucro += jobs[i].profit;
        }

        printJobScheduling(jobs, N,H);
        int acum = 0;
        for (int i=0; i<H; i++)
            if (slot[i]) acum += jobs[result[i]].profit;
        
        cout << lucro - acum << '\n';

    }


    return 0;
}