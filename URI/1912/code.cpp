#include <bits/stdc++.h>
#include <algorithm> 

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
int MAX;
const double EPS = 0.000001;

double C[100001];        

double calc_areas(int N, double meio)
{
    double soma = 0.0;

    for(int i = 0; i < N;i++)
    {   
        if((double)C[i] > meio) soma += (double)C[i] - meio;
        else break;
    }

    return soma;
}

bool cmp(int a, int b) {return a > b;}

int main()
{
    double N,A;

    while(cin >> N >> A)
    {
        if(!N && !A) break;

        // printf("N %d e A %d\n",N,A);
        memset(C,0.0    ,sizeof N);

        int maior = 0;
        int soma = 0;
        for0(i,(int)N)
        {
            cin >>   C[i];
            soma += C[i];
            if(C[i] > C[maior]) maior = i ;
        }
        if(soma == (int)A)
        {
            printf(":D\n");
        } else if(soma < (int)A){
            printf("-.-\n");
        } else 
        {
            maior = C[maior];

            double inicio = 0;

            int encontrou = 0;

            double fim = maior;

            double soma_cortes = 0;

            double meio = 0;


            sort(C,C+(int)N,cmp);
            // printf("N =  %lf e A  = %lf\n",N,A);
            // printf("inicio = %lf e fim = %lf\n",inicio,fim);

            while(inicio + EPS < fim)
            {
                // printf("inicio = %lf e fim = %lf\n",inicio,fim);
                meio = (inicio + fim)/2.0; 
                soma_cortes = calc_areas(N,meio);
                // printf("soma_cortes = %lf (meio = %lf)\n",soma_cortes,meio);
                // printf("%lf + %lf + %lfim\n",soma_cortes,EPS,A);
                if((soma_cortes - EPS) <= A && A <= (EPS + soma_cortes))
                {
                    break;
                } else 
                if(A < soma_cortes )
                {
                    inicio = meio;
                } else if(A > soma_cortes)
                {
                    fim = meio ;
                }
            }
            double meiof = meio;
           
            printf("%.4lf\n",meiof);
        }

    }
}