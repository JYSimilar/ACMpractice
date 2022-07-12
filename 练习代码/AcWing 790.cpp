#include <iostream>
using namespace std;

//牛顿迭代法，函数y=x^3+n求根
double cubic (double num) {
    int t = num;
    for (int i = 0; i < 100; ++i) {
        t = (2*t*t*t + num) / (3*t*t);
    }
    return t;
}

int main() {
    double num;
    scanf("%lf", &num);
    printf("%lf", cubic(num));
    return 0;
}