#include <cstdio>

int OPS,B;
int FATHER[100001];

int find(int x) {
    if (FATHER[x] == x) {
        return x;
    }

    return FATHER[x] =  find(FATHER[x]);
}

void join(int a, int b) {
    FATHER[ find(a) ] = find(b);
}

int main(){

    char op;
    int a,b;

    scanf("%d %d",&B,&OPS);

    for(int i = 1; i <= B;i++) {
        FATHER[i] = i;
    }

    for(int i = 0; i < OPS;i++) {
        scanf(" %c %d %d",&op,&a,&b);

        if(op == 'F') {
            join(a,b);
        } else if(op == 'C'){

            char res = (find(a) == find(b)) ? 'S' : 'N';

            printf("%c\n",res);
        }
    }


    return 0;
}
