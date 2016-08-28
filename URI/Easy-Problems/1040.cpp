
#include <bits/stdc++.h>


using namespace std; 

#define MAX (1000000)
#define ENDLINE printf("\n");
#define HEY printf("HEY\n");
#define HEYA printf("HEY_A\n");
#define HEYB printf("HEY_B\n");
#define HEY2 printf("	HEY\n");
#define HEY3 printf("		HEY\n");
#define END ("\n")

int main()
{
	float a,b,c,d;
 	float e;

	cin >> a >> b >> c >> d;

	float media = (a*2 + 3*b + 4*c + d)/10;

	// cout << "Media: " <<  setprecision(2) << media << END;

	printf("Media: %.1f\n",media);

	if(media >= 7.0)
	{
		cout << "Aluno aprovado." << END;
	} else if(media < 5.0)
	{
		cout << "Aluno reprovado." << END;
	}else 
	{
 		cout << "Aluno em exame." << END;

 		cin >> e;

 		media = (media + e)/2.0;

 		// cout << "Nota do exame: " <<  setprecision(2) << e << END;
 		printf("Nota do exame: %.1f\n",e);

 		if(media >= 5.0)
 		{
			cout << "Aluno aprovado." << END;
 		} else 
 		{
			cout << "Aluno reprovado." << END;
 		}

 		// cout << "Media final: " <<  setprecision(2) << media ;
 		printf("Media final: %.1f\n",media);

	}



	return 0;
}