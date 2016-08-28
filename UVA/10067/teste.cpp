#include <iostream>
using namespace std;

struct coord {
 int x;
 int y;
  bool operator== (const coord &c1) {
   return (x == c1.x && y == c1.y);
  }
};

int main() {
 coord xy1 = {12, 20};
 coord xy2 = {12, 20};
 cout << (xy1 == xy2) << endl;
 return 0;
}