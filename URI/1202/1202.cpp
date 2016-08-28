#include <cstdio>
#include <cstring>

void make_B(long long  int B[2][2]) // B = A*A; 
{
	B[0][0] = 2;
	B[0][1] = 1;
	B[1][0] = 1;
	B[1][1] = 1;
}

void make_I(long long int M[2][2])
{
	M[0][0] = 1;
	M[0][1] = 0;
	M[1][0] = 0;
	M[1][1] = 1;
}

void calculate_B_i(long long  B[2][2], int n, int *ptr_to_matrix[10000])
{
   long long ret[2][2]= {{1,0},{0,1}},tmp[2][2]= {{0,0},{0,0}};
    
    int i,j,k;
    
    while(n)
    {
        if(n&1) 
        {
            memset(tmp,0,sizeof tmp);
            for(i=0; i<2; i++) for(j=0; j<2; j++) for(k=0; k<2; k++) // tmp = tmp + ret * B
                        tmp[i][j]=(tmp[i][j]+ret[i][k]*B[k][j]);
            for(i=0; i<2; i++) for(j=0; j<2; j++) ret[i][j]=tmp[i][j];  // ret = tmp 
        }
        memset(tmp,0,sizeof tmp); // tmp = 0
        for(i=0; i<2; i++) for(j=0; j<2; j++) for(k=0; k<2; k++)  // tmp = tmp + B*B
                    tmp[i][j]=(tmp[i][j]+B[i][k]*B[k][j]); 
        for(i=0; i<2; i++) for(j=0; j<2; j++) B[i][j]=tmp[i][j]; // B = tmp
        n/=2;
    }




}

int main()
{
	int I; 

	scanf("%d",&I);

	char string[10000];

	for(int i = 0; i < I; i++)
	{
		scanf("%s",string);

		int B[2][2],RES[2][2];

		make_B(B); 
		make_I(RES); 

		int *ptr_to_matrix[10000]; 

		for(int j = 0; j < strlen(string); j++)
		{
			calculate_B_i(B,j,ptr_to_matrix);

			mult(RES,RES,B);
		}		
	}

	return 0;
}