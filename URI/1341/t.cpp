#include <bits/stdc++.h>
#include <algorithm>
 
 
 
 
using namespace std;
 
int t,n,m,comum,maximo;
int movimentos, a, b;
string matriz, str1, str2, aux;
 
vector<int> pd;
 
void imprimir_pd(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout << pd[i*m+j] << " ";
        }   
        cout << "\n";
    }
    cout << "\n\n";
}
 
 
void caminhar1(){
    int i;
    string mov;
    str1.clear();
    str1 += matriz[a*m+b];
     
    if(!movimentos) return;
    cin >> mov;
     
 
    for(i=0;i<mov.size();i++){
        if(mov[i] == 'N'){
            a--;
        }
        else if(mov[i] == 'E'){
            b++;
        }
        else if(mov[i] == 'W'){
            b--;
        }
        else if(mov[i] == 'S'){
            a++;
        }
        str1 += matriz[a*m+b];
    }
}
 
 
 
void caminhar2(){
    int i;
    string mov;
    str2.clear();
    str2 += matriz[a*m+b];
     
    if(!movimentos) return;
    cin >> mov;
     
     
    for(i=0;i<mov.size();i++){
        if(mov[i] == 'N'){
            a--;
        }
        else if(mov[i] == 'E'){
            b++;
        }
        else if(mov[i] == 'W'){
            b--;
        }
        else if(mov[i] == 'S'){
            a++;
        }
        str2 += matriz[a*m+b];
    }
}
 
int main(){
    int i,j,k,l;
    int cont = 1;
     
    cin >> t;
    for(k=0; k<t; k++){
        cin >> n >> m;
        matriz.clear();
        for(j=0;j<n;j++){
            cin >> aux;
            matriz+=aux;
        }
        cin >> movimentos >> a >> b;  
        a--;  b--;
        caminhar1();
         
        cin >> movimentos >> a >> b;
        a--;  b--;  
        caminhar2();
         
        n = str1.size();
        m = str2.size();
         
        pd.resize(n*m);
         
        if(str1[0]==str2[0]){
            pd[0] = 1;
        }
        else{
            pd[0] = 0;
        }
         
         
        for(j=1;j<m;j++){
            maximo = pd[j-1];
            if(str2[j] == str1[0] && !maximo){
                pd[j] = 1;
            }   
            else{
                pd[j] = maximo;
            }       
        }
         
        for(i=1; i<n; i++){
            maximo = pd[(i-1)*m];
            if(str1[i] == str2[0] && !maximo){
                pd[i*m] = 1;
            }
            else{
                pd[i*m] = maximo;
            }
        }
         
        for(i=1;i<n;i++){
            for(j=1;j<m;j++){
                maximo = max(pd[i*m+(j-1)],pd[(i-1)*m+j]);
                if(str1[i] == str2[j]){
                    pd[i*m+j] = 1+pd[(i-1)*m+(j-1)];
                }
                else{
                    pd[i*m+j] = maximo;
                }
            }
        }
         
         
         
        comum = pd[(n-1)*m+(m-1)];
        cout << "Case " << cont++ << ": " << n-comum << " " << m-comum << "\n";
         
        cout << str1 << " " << str2 << "\n";
        imprimir_pd();
         
         
         
         
         
         
    }
     
     
     
}