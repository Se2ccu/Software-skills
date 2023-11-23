
#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double x1 = (sqrt(b * b - 4 * a * c) - b) / 2 / a;
    double x2 = (-sqrt(b * b - 4 * a * c) - b) / 2 / a;
    printf("x1 = %lf, x2 = %lf\n", x1, x2);
    return 0;
}
