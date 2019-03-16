
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

int main()
{
    int N, L, C;

    while(cin >> N >> L >> C) {
        string input;

        cin.ignore();
        getline(cin,input);

        int lines = 1;

       for(int i = 0; i < input.size();) {

           while(i > 0 and input[i] != ' ' and input[i] != '\n') {
               i -= 1;
           }

           if(input[i] == ' ') {
               input[i] = '$';
               lines += 1;
           }
           i = i + C + 1;
       }

       cout << input << endl;
        cout << ceil((double)lines/(double) L) << endl;
    }

	return 0;
}
