#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define    f(x) 1/x //burayi düzenle f(x)

float simpsonFonksiyon(float x0, float x3){
    float h = (x3-x0)/3;
    float x1 = x0+(x3-x0)/3;
    float x2 = x0+ 2 *(x3-x0)/3;
    return (3*h/8) * (f(x0)+ 3 * f(x1) +3*f(x2) +f(x3));

}


void simpsonKurali(){
   float x0,x1,N,step,toplam = 0;
   int i = 0;
   printf("x0 integral alt sinirini girin : \n");
   scanf("%f",&x0);
   printf("x1 integral ust sinirini girin : \n");
   scanf("%f",&x1);
   printf("Integrali kac parcaya boleceksin?:\n");
   scanf("%f",&N);
   step = (x1 - x0)/N;
   printf("i\t\tx0\t\tx1\t\tSimpson 3/8\n");
    float first = x0;
   while(first<x1-step){
    toplam+= simpsonFonksiyon(first,first+step);
    i++;

    printf("%d\t\t%f\t%f\t%f\n",i, first, first+step,simpsonFonksiyon(first,first+step));

    first += step;
   }
   printf("\n\nParcalanan integrallerin sonuclarina gore :\n");
   printf("x0\t\tx1\t\tSimpson 3/8\n");
   printf("%f\t%f\t%f\n", x0, x1,toplam);

}


void main()
{
	simpsonKurali();
}
