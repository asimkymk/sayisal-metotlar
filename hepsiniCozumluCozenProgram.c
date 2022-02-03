

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define    f(x)    x*x*x-7*x*x+14*x-6 //burayý düzenle f(x)
#define    g(x)    3*x*x-14*x+14 //burayý düzenle f'(x)





void yarilamaMetodu(float x0,float x1,float e){
    printf("----------------------------------------------------------------------------------------------------------------\n\t\t\t\t\t\tYARILAMA METODU\n----------------------------------------------------------------------------------------------------------------\n");
    float x2, f0, f1, f2;
    int step = 1;
    e = 0.001;
    f0 = f(x0);
	f1 = f(x1);
	if( f0 * f1 > 0.0)
    {
        printf("Hatali araliklar\n");
        return;
    }
	printf("\ni\t\ta\t\tf(a)\t\tb\t\tf(b)\t\txort\t\tf(xort)\n");
    do
    {
        x2 = (x0 + x1)/2;
        f2 = f(x2);

        printf("%d\t\t%f\t%f\t%f\t%f\t%f\t%f\n",step-1, x0,f(x0), x1,f(x1), x2, f2);

        if( f0 * f2 < 0)
        {
            x1 = x2;
            f1 = f2;
        }
        else
        {
            x0 = x2;
            f0 = f2;
        }
        step = step + 1;
    }while(fabs(f2)>e);
    printf("\nBulunan Kok: %f\n", x2);

}
void secantMetodu(float x0,float x1,float e,float N){

    printf("----------------------------------------------------------------------------------------------------------------\n\t\t\t\t\t\tSECANT METODU\n----------------------------------------------------------------------------------------------------------------\n");

    float x2, f0, f1, f2;
	 int step = 1;
	 printf("\ni\t\tp0\t\tf(p0)\t\tp1\t\tf(p1)\t\tp\n");
	 do
	 {
		  f0 = f(x0);
		  f1 = f(x1);
		  if(f0 == f1)
		  {
			   printf("Mat. Hata.");
			   exit(0);
		  }

		  x2 = x1 - (x1 - x0) * f1/(f1-f0);
		  f2 = f(x2);

		  printf("%d\t\t%f\t%f\t%f\t%f\t%f\n",step,x0,f(x0),x1,f(x1),x2);

		  x0 = x1;
		  f0 = f1;
		  x1 = x2;
		  f1 = f2;

		  step = step + 1;

		  if(step > N)
		  {
			   printf("Yakýnsak degil.");
			   exit(0);
		  }
	 }while(fabs(f2)>e);

	 printf("\nBulunan Kok: %f\n", x2);



}

void regulaFalsiMetodu(float x0, float x1,float e){

    printf("----------------------------------------------------------------------------------------------------------------\n\t\t\t\t\t\tREGULA FALSI METODU\n----------------------------------------------------------------------------------------------------------------\n");

    float  x2, f0, f1, f2;
	 int step = 1;

	 f0 = f(x0);
	 f1 = f(x1);
	 if( f0*f1 > 0.0)
	 {
		  printf("Hatali durum.\n");
		  return;
	 }

	 printf("\nStep\t\tp0\t\tf(p0)\t\tp1\t\tf(p1)\t\tp\t\tf(p)\n");
	 do
	 {
		  x2 = x0 - (x0-x1) * f0/(f0-f1);
		  f2 = f(x2);
		  printf("%d\t\t%f\t%f\t%f\t%f\t%f\t%f\n",step, x0,f0, x1,f1, x2,f2);

		  if(f0*f2 < 0)
		  {
			   x1 = x2;
			   f1 = f2;
		  }
		  else
		  {
			   x0 = x2;
			   f0 = f2;
		  }
		  step = step + 1;

	 }while(fabs(f2)>e);

	 printf("\nBulunan Kok: %f\n", x2);
}
void newtonRaphsonMetodu(float x0,float e, int N){

    float x1, f0, f1, g0;
	 int step = 1;
     printf("----------------------------------------------------------------------------------------------------------------\n\t\t\t\t\t\tNEWTON-RAPHSON METODU\n----------------------------------------------------------------------------------------------------------------\n");

	 printf("\ni\t\tp\t\tf(p)\t\tf'(p)\t\tp1(Newton)\n");
	 do
	 {
		  g0 = g(x0);
		  f0 = f(x0);
		  if(g0 == 0.0)
		  {
			   printf("Mat. Hata.");
			   exit(0);
		  }


		  x1 = x0 - f0/g0;


		  printf("%d\t\t%f\t%f\t%f\t%f\n",step,x0,f0,g0,x1);
		  x0 = x1;

		  step = step+1;

		  if(step > N)
		  {
			   printf("Yakýnsak degil.");
			   exit(0);
		  }

		  f1 = f(x1);

	 }while(fabs(f1)>e);

	 printf("\nBulunan Kok: %f\n", x1);
}
void main()
{
	 float x0, x1, x2, f0, f1, f2, e,newtonStartPoint;
	 int step = 1, N;

	 printf("\nAraliklar (x0,x1): \n");
	 scanf("%f%f", &x0, &x1);
	 e = 0.0001;
	 printf("Max Iterasyon:\n");
	 scanf("%d", &N);
	 printf("Newton Raphson baslangic degeri : \n");
	 scanf("%f",&newtonStartPoint);
	 regulaFalsiMetodu(x0,x1,e);
	printf("\n\n");
    yarilamaMetodu(x0,x1,e);
    printf("\n\n");
	secantMetodu(x0,x1,e,N);
	printf("\n\n");

	newtonRaphsonMetodu(newtonStartPoint,e,N);

	 getch();
}
