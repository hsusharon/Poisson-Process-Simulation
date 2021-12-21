#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


double gen_exp(double lambda){
	double rdnum, x;
	rdnum = (rand()%10000)+1;
	rdnum = rdnum/10000;
	rdnum = (-log(1-rdnum))/lambda;
	return rdnum;
}
 

int main(){
	int i, j, x, y, Ntotal;
	static double lambda, a=0.0, b=0.0, t=0.0;    
	static double T, Ttotal;
	static double Taverage, Naverage;
	static double ta[6000], ts[6000];
	ta[0]=0.0;
	
	printf("Input lambda: ");
	scanf("%lf", &lambda);
	
	for(i=1;i<6000;i++){
		a=gen_exp(lambda)+a;
		ta[i]=a;
		//printf("ta[%d]=%lf \n", i, ta[i]); 
	}                          ///Now I get all the arrival time
	for(j=0;j<6000;j++){
		ts[j]=gen_exp(1.0);
		//printf("ts[%d]=%lf \n", j, ts[j]);
	}                         ///Now I get all the service time
	
	for(x=0;x<6000;x++){
		if(ta[x]>=t){
			Ttotal= ts[x]+Ttotal;
			t=ta[x]+ts[x];
			for(y=x;y<6000;y++){
				if(ta[y]>t){
					break;
				}
			}
			Ntotal=y-x-1+Ntotal;
			//printf("n[%d]=%d \n", x, y-x);
		}
		else{
			Ttotal=t-ta[x]+ts[x]+Ttotal;
			t=t+ts[x];
			for(y=x;y<6000;y++){
				if(ta[y]>t){
					break;
				}
			}
			Ntotal=y-x-1+Ntotal;
			//printf("n[%d]=%d\n", x, y-x);
		}
	}
	Naverage=(double)Ntotal/6000.0;
	Taverage=Ttotal/6000.0;
	
	printf("N=%lf      T=%lf\n", Naverage, Taverage);
	
	
	return 0;
}
