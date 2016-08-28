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
        cout << "[" << array[i].profit << "]"; \
    }               \
    ENDLINE;        \
    }               \
 
#define ps(s) printf("%s\n",s);
 
typedef long long int ll;

// C++ program for weighted job scheduling using Dynamic Programming. 
// A job has start time, finish time and profit.
struct Job
{
    int day, start, finish, profit;
};
 
// A utility function that is used for sorting events
// according to finish time
bool jobComparataor(Job s1, Job s2)
{
    // if( s1.endhour != s2.endhour ) return s1.endhour < s2.endhour; else return s1.endmin < s2.endmin;
    return s1.finish < s2.finish;
}
 
// Find the latest job (in sorted array) that doesn't
// conflict with the job[i]
int latestNonConflict(vector<Job> &arr, int i)
{
    for (int j=i-1; j>=0; j--)
    {
        if(arr[j].finish <= arr[i].start)
        {
            return j;
        }    
    }
    return -1;
}
  
const int MAX = 500;

vector<Job> seg_jobs (MAX) ,ter_jobs(MAX) ,qua_jobs (MAX) ,qui_jobs(MAX) , sex_jobs(MAX) ;
vector<int> max_seg (MAX) ,max_ter (MAX) ,max_qua (MAX) ,max_qui(MAX) ,max_sex(MAX) ;

// The main function that returns the maximum possible
// profit from given array of jobs
void findMaxProfit(int n)
{
    // Sort jobs according to finish time
    // Create an array to store solutions of subproblems.  table[i]
    // stores the profit for jobs till arr[i] (including arr[i])
    // int *table = new int[n];
    // table[0] = arr[0].profit;
 
    // Fill entries in M[] using recursive property

    Job aux; aux.start = aux.finish = 0, aux.profit = 0;
    sort(seg_jobs.begin(), seg_jobs.end(), jobComparataor);
    sort(ter_jobs.begin(), ter_jobs.end(), jobComparataor);
    sort(qua_jobs.begin(), qua_jobs.end(), jobComparataor);
    sort(qui_jobs.begin(), qui_jobs.end(), jobComparataor);
    sort(sex_jobs.begin(), sex_jobs.end(), jobComparataor);

    if(seg_jobs.size() > 0) max_seg.push_back(seg_jobs[0].profit);
    if(ter_jobs.size() > 0) max_ter.push_back(ter_jobs[0].profit);
    if(qua_jobs.size() > 0) max_qua.push_back(qua_jobs[0].profit);
    if(qui_jobs.size() > 0) max_qui.push_back(qui_jobs[0].profit);
    if(sex_jobs.size() > 0) max_sex.push_back(sex_jobs[0].profit);

    for(int i = 1; i < seg_jobs.size(); i++)
    {
        // Find profit including the current job

        int inclProf = seg_jobs[i].profit;

        // printf("inclProf = %d\n",inclProf);

        int l = latestNonConflict(seg_jobs, i);
        if (l != -1)
        {
            inclProf += max_seg[l]; 
        }
        
        // Store maximum of including and excluding
        max_seg.push_back(max(inclProf,max_seg[i-1]));
    }

    // HEY2
    for(int i = 1; i < ter_jobs.size(); i++)
    {
        // Find profit including the current job
        int inclProf =  ter_jobs[i].profit;

        // printf("inclProf = %d\n",inclProf);

        int l = latestNonConflict(ter_jobs, i);
        if (l != -1)
        {
            inclProf += max_ter[l]; 
        }
        
        // Store maximum of including and excluding
        max_ter.push_back(max(inclProf,max_ter[i-1]));
    }
  
    // HEY2
    for(int i = 1; i < qua_jobs.size();i++)
    {
        // Find profit including the current job
        int inclProf =  qua_jobs[i].profit;

        // printf("inclProf = %d\n",inclProf);

        int l = latestNonConflict(qua_jobs, i);
        if (l != -1)
        {
            inclProf += max_qua[l]; 
        }
        // printf("inclProf after = %d\n",inclProf);

        
        // Store maximum of including and excluding
        max_qua.push_back(max(inclProf,max_qua[i-1]));
    }
   //
    // HEY2
    for(int i = 1; i < qui_jobs.size(); i++)
    {
        // Find profit including the current job
        int inclProf = qui_jobs[i].profit;

        // printf("inclProf = %d\n",inclProf);

        int l = latestNonConflict(qui_jobs, i);
        if (l != -1)
        {
            inclProf += max_qui[l]; 
        }
        
        // Store maximum of including and excluding
        max_qui.push_back(max(inclProf,max_qui[i-1]));
    }   
    // HEY2
    for(int i = 1; i < sex_jobs.size(); i++)
    {
        // Find profit including the current job
        int inclProf =  sex_jobs[i].profit;

        // printf("inclProf = %d\n",inclProf);

        int l = latestNonConflict(sex_jobs, i);
        if (l != -1)
        {
            inclProf += max_sex[l]; 
        }
        
        // Store maximum of including and excluding
        max_sex.push_back(max(inclProf,max_sex[i-1]));

    }      
    // Store result and free dynamic memory allocated for table[]
    // int result = table[n-1];
    // delete[] table;
    

    // return result;
}


// Driver program
int main()
{
    int N;

    while(cin >> N && N)
    {
        char day[3];

        max_seg.clear();
        max_ter.clear();
        max_qua.clear();
        max_qui.clear();
        max_sex.clear();

        seg_jobs.clear();
        ter_jobs.clear();
        qua_jobs.clear();
        qui_jobs.clear();
        sex_jobs.clear();


        for0(i,N)
        {

            Job aux;

            int codigo; cin >> codigo;

            char c; 


            cin >> aux.profit;

            cin >> day;

            int hour, min;

            cin >> hour; cin >> c; cin >> min;

            aux.start = hour*60 + min;

            cin >> hour; cin >> c; cin >> min; 

            aux.finish = hour*60 + min;

            if(strcmp(day,"Seg")==0) aux.day=1,seg_jobs.push_back(aux);
            if(strcmp(day,"Ter")==0) aux.day=2,ter_jobs.push_back(aux);
            if(strcmp(day,"Qua")==0) aux.day=3,qua_jobs.push_back(aux);
            if(strcmp(day,"Qui")==0) aux.day=4,qui_jobs.push_back(aux);
            if(strcmp(day,"Sex")==0) aux.day=5,sex_jobs.push_back(aux);
        }   

        findMaxProfit(N);

        int total = 0;

        int mseg = 0,mter = 0,mqua = 0,mqui = 0,msex = 0;

        if(!max_seg.empty()) mseg = max_seg.back();
        if(!max_ter.empty()) mter = max_ter.back();
        if(!max_qua.empty()) mqua = max_qua.back();
        if(!max_qui.empty()) mqui = max_qui.back();
        if(!max_sex.empty()) msex = max_sex.back();

        total = mseg + mter + mqua + mqui + msex;

        printf("Total de pontos: %d\n",total);
        printf("Seg: %d\n",mseg);
        printf("Ter: %d\n",mter);
        printf("Qua: %d\n",mqua);
        printf("Qui: %d\n",mqui);
        printf("Sex: %d\n",msex);
    }


    return 0;
}