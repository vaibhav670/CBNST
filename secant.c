#include <stdio.h>
#include <conio.h>
#include <math.h>
#define f(x) x*x*x-3*x-5
void secant(float x0,float x1,float f0,float f1,float e);
int main()
{
float x0, x1, f0, f1,  e;
up:
printf("Enter two initial guesses for the interval:\n");
scanf("%f %f", &x0, &x1);
printf("Enter tolerable error:\n");
scanf("%f", &e);
f0= f(x0);
f1 = f(x1);
if(f0*f1> 0.0)
{
printf("Incorrect Initial Guesses\n");
goto up;
}
secant(x0,x1,f0,f1,e);
}
void secant(float x0,float x1,float f0,float f1,float e)
{
    float x2;
    int itr = 1;
do
{
    x2=(x0*f1-x1*f0)/(f1-f0);
    x0=x1;
    x1=x2;
    f0=f(x0);
    f1=f(x1);
    itr = itr+1;
}while(fabs(f1)>e);
printf("\nThe root is %f at %d iteration",x2,itr);
}
