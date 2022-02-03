#include<stdio.h>
#include<conio.h>
#include<math.h>

#define   f(x)   x*x*x+4*x*x-10
#define   g(x)   x - (x*x*x+4*x*x-10)/(3*x*x+8*x)

void sabitNoktaMetodu(){

    int i = 1, N = 100;
	 float p0 = 1.5, TOL = 0.0001;
	 float p;
	 int status = 0;
	 printf("\ni\t(g)\n");
	 while(i<=N){
        p = g(p0);
        printf("%d\t%f\n",i,p);
        if(fabs(p-p0)<TOL){

            status = 1;
            break;
        }
        i++;
        p0 =p;
	 }
	 if(status){
        printf("Bulunan Kok : %f\n",p);
	 }
	 else{
        printf("Method basarisiz oldu. N = %d kere denendi",N);
        return;
	 }
}


int main()
{

    sabitNoktaMetodu();
	 return(0);
}
