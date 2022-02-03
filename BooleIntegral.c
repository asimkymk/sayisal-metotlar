#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define    f(x) 1/x //burayi düzenle f(x)

float booleFonksiyon(float x0, float x4){
    float h = (x4-x0)/4;
    float x1 = x0 + (x4-x0)/4;
    float x2 = x0 + 2*(x4-x0)/4;
    float x3 = x0 + 3*(x4-x0)/4;
    return (2*h/45) * (7*f(x0)+ 32 * f(x1) +12*f(x2) +32*f(x3)+7*f(x4));

}


void booleKurali(){
   float x0,x1,N,step,toplam = 0;
   int i = 0;
   printf("x0 integral alt sinirini girin : \n");
   scanf("%f",&x0);
   printf("x1 integral ust sinirini girin : \n");
   scanf("%f",&x1);
   printf("Integrali kac parcaya boleceksin?:\n");
   scanf("%f",&N);
   step = (x1 - x0)/N;
   printf("i\t\tx0\t\tx1\t\tBoole\n");
    float first = x0;
   while(first<x1-step){
    toplam+= booleFonksiyon(first,first+step);
    i++;

    printf("%d\t\t%f\t%f\t%f\n",i, first, first+step,booleFonksiyon(first,first+step));

    first += step;
   }
   printf("\n\nParcalanan integrallerin sonuclarina gore :\n");
   printf("x0\t\tx1\t\Boole\n");
   printf("%f\t%f\t%f\n", x0, x1,toplam);

}


void main()
{
	booleKurali();
}
