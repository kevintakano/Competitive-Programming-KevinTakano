#include <bits/stdc++.h>

using namespace std;

int arr[100100];

int main() {

    int K,N;

    while(cin >> K >> N and N and K) {
        for(int n = 0; n < N;n++){
            cin >> arr[n];
        }

        int res = 99999;
        //printf("oi %d %d\n",K,N);
        for(int i = 0;i< N;i++) {
            int upper_base_pos = (upper_bound(arr,arr+N,arr[i] + K - 1) - arr) - 1;
            printf("i %d\n",i);
            printf("\tupper_base %d\n",upper_base_pos);
            printf("\tupper_base limit %d\n",arr[i] + K - 1);
            printf("\tK %d\n",K);
            printf("\tres = %d\n", K-1 -(upper_base_pos - i));
            res = min(res, (K-1) - (upper_base_pos - i));
        }

        printf("%d\n",res);
    }

}
