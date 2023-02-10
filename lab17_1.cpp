#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}
void randData(double *a,int n,int m){
	for (int i = 0; i < n*m; i++)
	{
		*(a+i) =(rand()%101)/100.0;
	}
	
}

void showData(double *a,int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout <<*(a+i);
        if(i%M == M-1) cout << endl;
        else cout << " ";
    }
}
void findRowSum(const double *a,double *an,int n,int m){
	double s = 0;
	int i = 0;
	for (int p = 0; p < n*m; p++)
	{
		s += *(a+p);
		if (p%m == m-1)
		{
			an[i] = s;
			i++;
			s = 0;
		}
		
    }
	
}
void findColSum(const double *a,double *am,int n,int m){
	for (int i = 0; i < n*m; i++)
	{
		am[i%m] = 0;
	}
	
	for (int p = 0; p < n*m; p++)
	{
		am[p%m] += *(a+p); 
		
    }
	
}