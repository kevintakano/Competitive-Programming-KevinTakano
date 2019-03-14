// A C++ program to check if a given point lies inside a given polygon
// Refer https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
// for explanation of functions onSegment(), orientation() and doIntersect()
#include <iostream>
#include <bits/stdc++.h>
#define D(x) printf("%d\n",n);
using namespace std;

struct Point
{
    int x;
    int y;
};

Point blacks[102];
Point whites[102];
/* A utility function to calculate area of triangle formed by (x1, y1),
   (x2, y2) and (x3, y3) */
double area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

/* A function to check whether point P(x, y) lies inside the triangle formed
   by A(x1, y1), B(x2, y2) and C(x3, y3) */
bool isInsideT(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{
   /* Calculate area of triangle ABC */
   double A = area (x1, y1, x2, y2, x3, y3);

   /* Calculate area of triangle PBC */
   double A1 = area (x, y, x2, y2, x3, y3);

   /* Calculate area of triangle PAC */
   double A2 = area (x1, y1, x, y, x3, y3);

   /* Calculate area of triangle PAB */
   double A3 = area (x1, y1, x2, y2, x, y);

   /* Check if sum of A1, A2 and A3 is same as A */
   return (A == A1 + A2 + A3);
}

// Driver program to test above functions
int main()
{
    int N,M;

    while(cin >> N >> M) {
        for(int i = 0; i < N;i++) {
            cin >> blacks[i].x >> blacks[i].y;
        }

        for(int i = 0; i < M;i++) {
            cin >> whites[i].x >> whites[i].y;
        }

        int s = 0;

        Point triangle[3];
        for(int i = 0;i < N;i++){
            for(int j = i+1; j < N;j++) {
                for(int k = j+1; k< N;k++) {
                    triangle[0] = blacks[i];
                    triangle[1] = blacks[j];
                    triangle[2] = blacks[k];
                    int n = 0;

                    //printf("%d %d %d\n",i,j,k);
                    for(int l = 0; l < M;l++) {
                        Point c = whites[l];
                        n += isInsideT(triangle[0].x,triangle[0].y, triangle[1].x, triangle[1].y, triangle[2].x,triangle[2].y, c.x,c.y);

                    }
                   // D(n)
                    s += n*n;
                }
            }
        }

        cout << s << endl;
    }

      return 0;
}

