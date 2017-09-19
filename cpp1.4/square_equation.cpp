#include <iostream>
#include <math.h>
using namespace std;

int WinMain()
{

    printf("enter a & b & c for 'ax^2+bx+c=0':");
    float a = 0, b = 0, c = 0;
    scanf("%f %f %f", &a, &b, &c);
    float D = pow(b, 2) - 4 * a * c;

    if (D >= 0)
    {

        float x1 = ((-b) + sqrt(D)) / (2 * a);
        float x2 = ((-b) - sqrt(D)) / (2 * a);

        if (D == 0)
        {
            printf("solutioin:  x1 = %f:", x1);
        }

        else
        {
            printf("solutioin:  x1 = %f  x2 = %f ", x1, x2);
        }
    }
    else
    {
        puts("the discriminant less then 0");
    }
}
