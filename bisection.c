#include <stdio.h>
#include <conio.h>
#include <math.h>
#define f(x) x*x*x-3*x-5
void bisection(float x0,float x1,float x2,float f0,float f1,float f2,float e);
int main()
{
float x0, x1, x2, f0, f1, f2, e;
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
bisection(x0,x1,x2,f0,f1,f2,e);
}
void bisection(float x0,float x1,float x2,float f0,float f1,float f2,float e)
{
    int itr=1;
do
{
x2 = (x0+x1)/2;
f2= f(x2);
if(f0*f2<0)
{
    x1=x2;
    f1=f2;
}
else
{
    x0=x2;
    f0=f2;
}
itr=itr+1;
}while(fabs(f2)>e);
printf("\nThe root is %f at %d iteration",x2,itr);
}
