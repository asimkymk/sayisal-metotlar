#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>


float f(float t,float y){
    return (t-y)/2;

}
float eulerFonksiyon(float y0, float h, float t0){
   return y0 + h * f(t0,y0);

}


void eulerMethod(){
   float x0,xn,h,yk;
   int i = 0;
   printf("x0 aralik baslangic degerini girin : \n");
   scanf("%f",&x0);
   printf("xn aralik bitis degerini girin : \n");
   scanf("%f",&xn);
   printf("Hangi araliklarla method uygulansin ? (h):\n");
   scanf("%f",&h);
   printf("y(x0) degerini girin :\n");
   scanf("%f",&yk);
   printf("tk\t\tyk\n");
  while(x0<=xn){
    printf("%f\t%f\n",x0,yk);

    yk = eulerFonksiyon(yk,h, x0);
    x0+=h;
  }

}


void main()
{
	eulerMethod();
}
