#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define    f(x)    x*x*x-7*x*x+14*x-6 //burayi düzenle f(x)
#define    g(x)    3*x*x - 14*x + 14      //burayi düzenle f'(x)
void newtonRaphsonMetodu(){


    int i = 1, N = 100;
    float TOL = 0.001;
    float p0 = 0.5; // burayi duzenle
    float f0,g0;
    float p;
	 printf("\ni\t\tp\t\tf(p)\t\tp1(Newton)\n");
	 int status =0;
	 while(i<=N){

       f0 = f(p0);
       g0 = g(p0);

        p = p0 - f0 / g0;
        printf("%d\t\t%f\t%f\t%f\n",i,p0,f(p0),p);
        if(fabs(p-p0)<TOL){

            status = 1;
            break;
        }
        i++;
        p0 = p;
	 }

    if(status){
        printf("\nBulunan Kok: %f\n", p);
    }
    else{
        printf("Metod basarisiz oldu. N kere deneme yapildi. N = %d",N);
    }

}


void main()
{
	 newtonRaphsonMetodu();
}
