#include<stdio.h>
float dydx(float x, float y)
{
//Write the function here
    return((-2*y/(1+x)));
}
float rungeKutta(float x0, float y0, float x, float h)
{
    int n = ((x - x0) / h);
    float k1, k2, k3, k4, k5;
    float y = y0;
    for (int i=0; i<=n; i++)
    {
        k1 = dydx(x0, y);
        k2 = dydx(x0 + 0.5*h, y + 0.5*k1*h);
        k3 = dydx(x0 + 0.5*h, y + 0.5*k2*h);
        k4 = dydx(x0 + h, y + k3*h);
        y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4)*h;
        printf("Y = %f \n ",y);
        x0 = x0 + h;
    }
    return y;
}
int main()
{
    float  x0 , y , x , h ;
    printf("x0 = ");
    scanf(" %f",&x0);
    printf("y = ");
    scanf(" %f",&y);
    printf("x = ");
    scanf("%f",&x);
    printf("h = ");
    scanf(" %f",&h);
    printf("\nThe value of y at x is : %f",rungeKutta(x0, y, x, h));
    return 0;
}