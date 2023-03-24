// B3638 write by cn_ryh
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double a, b, c;
    a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    c = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double s = 0.5 * (a + b + c);
    double k = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("%.0lf", k);
    return 0;
}