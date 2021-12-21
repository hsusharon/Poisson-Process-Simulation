#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double gen_exp(double lambda){
	double rdnum, x;
	rdnum = (rand()%10000)+1;
	rdnum = rdnum/10000;
	x = (-log(1-rdnum))/lambda;
	return x;	
}

int main(){
int i;	
double	sample[100000];
double x;
int num=01;
double F;

srand(time(NULL));
for(i=1; i<=100000; i++)
	sample[i]=gen_exp((double)1);

printf("Input x: ");
scanf("%lf",&x);

for(i=1; i<=100000; i++){
	if(sample[i]<=x)
		num=num+1;
}
	
F=num/(double)100000;

printf("Output: %lf\n",F);

}
