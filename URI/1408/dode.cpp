// Author: Erick Leonardo de Sousa Monteiro<erick.san.monteiro@gmail.com>
// Name: Mario
// Level: 6
// Category: PARADIGMS
// URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1408

#include<bits/stdc++.h>

using namespace std;

int vet[100001];

int main()
{
	int i, K, N, c;
	while(scanf("%d %d", &K, &N) == 2 && (N || K))
    {
        for(i = 0; i < N; i++)
            scanf("%d", &vet[i]);
        sort(vet, vet+N);
        c = 999999;
        for(i = 0; i < N; i++) {
            printf("when i = %d\n",i);
            int upper_base = upper_bound(vet, vet+N, vet[i] + K - 1) - vet - 1;
            int upper = upper_bound(vet, vet+N, vet[i] + K - 1) -vet;
            printf("upper_base = %d\n",(int) upper_base);
            printf("upper = %d\n",(int) upper);
            printf("value = %d\n",(int)K-1-(upper - i) );
            c = min(c, (int)(K-1-((upper_bound(vet, vet+N, vet[i] + K - 1) - vet - 1) - i)));

        }
        printf("%d\n", c);
    }
    return 0;
}
