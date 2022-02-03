#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define    f(x)    x*x*x-7*x*x+14*x-6 //burayi düzenle f(x)
void secantMetodu(){


    int i = 1, N = 100;
    float p0 = 0, p1 = 1; //burayi duzenle
    float TOL = 0.001;
    float p;
    float q0 = f(p0), q1 = f(p1);
    int status = 0;
	 printf("i\t\tp0\t\tp1\t\tp\n");
	 while(i<=N){
        p = p1 - q1*(p1-p0)/(q1-q0);
        printf("%d\t\t%f\t%f\t%f\n",i,p0,p1,p);
        if(fabs(p-p1)<TOL){
            status = 1;
            break;
        }
        i++;
        p0 = p1;
        q0 = q1;
        p1 = p;
        q1 = f(p);
	 }

	 if(status){
        printf("\nBulunan Kok: %f\n", p);
	 }
	 else{
        printf("Method basarisiz. N kere denendi. %d\n",N);
        return;
	 }

}


void main()
{
	 secantMetodu();
}
