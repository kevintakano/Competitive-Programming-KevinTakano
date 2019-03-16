#include <bits/stdc++.h>

#define MAX 100000

using namespace std;

struct t {
    int init;
    int time;
};


t tasks[MAX+1];

bool compare(t t1, t t2) {

    if (t1.init != t2.init ){
        return t1.init < t2.init;
    } else {
        return t1.time < t2.time;
    }

}

int main() {
    int N;

    while(cin >> N) {

        int mini = 9999;

        list< pair<int,int> > to_process;

        for(int i=0;i<N;i++){
            int a,b;
            cin >> a >> b;
            mini = min(mini, a);
            to_process.push_back( make_pair(a,b));
        }

        to_process.sort();
        int c = mini;
        int total_to_process = 0;

        while(to_process.size() > 0) {
            pair<int,int> front = to_process.front();
            c = c + max(0, front.first - c) +  front.second;
            to_process.pop_front();
        }

        cout << c << endl;
    }

}
