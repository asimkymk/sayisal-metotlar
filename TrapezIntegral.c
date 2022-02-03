#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define    f(x) 2/sqrt(x*x-3) //burayi düzenle f(x)

float trapezFonksiyon(float x0, float x1){
    float h = (x1-x0);
    return (h/2) *  (f(x0)+f(x1));

}


void trapezKurali(){
   float x0,x1,N,step,toplam = 0;
   int i = 0;
   printf("x0 integral alt sinirini girin : \n");
   scanf("%f",&x0);
   printf("x1 integral ust sinirini girin : \n");
   scanf("%f",&x1);
   printf("Integrali kac parcaya boleceksin?:\n");
   scanf("%f",&N);
   step = (x1 - x0)/N;
   printf("i\t\tx0\t\tx1\t\tTrapez\n");
    float first = x0;
   while(first<x1-step){
    toplam+= trapezFonksiyon(first,first+step);
    i++;

    printf("%d\t\t%f\t%f\t%f\n",i, first, first+step,trapezFonksiyon(first,first+step));

    first += step;
   }
   printf("\n\nParcalanan integrallerin sonuclarina gore :\n");
   printf("x0\t\tx1\t\tTrapez\n");
   printf("%f\t%f\t%f\n", x0, x1,toplam);

}


void main()
{
	trapezKurali();
}
