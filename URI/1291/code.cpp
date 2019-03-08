#include <bits/stdc++.h>
#include <math.h>

using namespace std;

/*
 * usar setor circular
 *
 * trinangul oretangulo no pnto de encontro entre dois arcos
 *
 * */

double z(double a) {
    return a*a*(1 - M_PI/6.0 - sqrt(3)/4.0);
}

double y(double a,double z) {
    double part = a*a - M_PI*a*a/4.0;

    return part - 2*z;
}

double x(double a, double z, double y) {
    return  a*a - 4*y - 4*z;
}

int main() {
    double a;
    while(scanf("%lf",&a)==1) {
        double four_z = 4*z(a);
        double four_y = 4*y(a,z(a));
        double final_x = x(a,z(a),y(a,z(a)));

        printf("%.3f %.3f %.3f\n", final_x,four_y,four_z);
    }
}
