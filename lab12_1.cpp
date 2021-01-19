#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}
void stat (const double x[],int y,double z[]){
    double sum=0;
    for(int i=0;i<y;i++){
        sum+=x[i];
    }
    double sd=0;
    for(int i=0;i<y;i++){
        sd+=pow((x[i]-(sum/y)),2);
    }
   double gm;
	for (int i = 0; i < y; i++) 
        gm = gm + log(x[i]); 
    gm = gm / y;
    double hm=0;
    for(int i=0;i<y;i++){
        hm+=1/x[i];
	}
	for(int i=0;i<y;i++){
        if (x[i] > z[4]) 
        z[4] = x[i];
	}
	z[5]=x[0];
	for(int i=0;i<y;i++){
        if (z[5]>x[i]  ) 
        z[5] = x[i];
	}
    z[0]=sum/y;
    z[1]=pow(sd/y,0.5);
    z[2]=exp(gm);
    z[3]=y/hm;
}