#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define    f(x)    x*x*x-7*x*x+14*x-6 //burayi düzenle f(x)

void yarilamaMetodu(){
    float a = 0,b = 1; //burayi duzenle
    float fa, fp,p;
    int N = 100,i=1;
    fa = f(a);
    float TOL = 0.001;
    int status =0;
	if( fa * f(b) > 0.0)
    {
        printf("Hata: Fa ve Fb isaretleri birbirinden farkli olmalidir.\n");
        exit(1);
    }
	printf("i\t\ta\t\tb\t\tp\t\tf(p)\n");
	while(i<=N){
        p = (a+b)/2;
        fp = f(p);
        printf("%d\t\t%f\t%f\t%f\t%f\n",i, a, b,p, fp);
        if(fp ==0 || (b-a)/2<TOL){
            status = 1;
            break;
        }
        i++;
        if(fa*fp>0){
            a = p;
            fa = fp;
        }
        else{
            b = p;
        }
	}
	if(status){
        printf("\nBulunan Kok: %f\n", p);
	}
	else{
        printf("Method basarisiz! N = %d kere denendi\n",N);
	}
}


void main()
{
	 yarilamaMetodu();
}
