/*************************************************************************
	> File Name: MPI_quer.c
	> Author: 
	> Mail: 
	> Created Time: 2017年01月22日 星期日 22时23分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#include<math.h>

const double a = 0.0;
const double b = 3.14;

int n  = 100;

double sum_quer(double a,double b,int n,double h){
    
    double *x = (double *)malloc(sizeof(double) * (n + 1));
    double *f = (double *)malloc(sizeof(double) * (n + 1));
    double inte = (sin(a) + sin(b)) /2;
    for(int i = 0;i < (n+1);i++){
        x[i] = x[i-1] + h;
        f[i] = sin(x[i]);
        inte += f[i];
    }
    inte = inte*h;
    return 0;
}

int main(int argc,char **argv){

    int myid,nprocs;
    int local_n;
    double local_a;
    double local_b;
    double total_inte;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    MPI_Comm_size(MPI_COMM_WORLD,&nprocs);

    local_n = n / nprocs;
    int h = (b - a)/n;
    local_a = a + myid *local_n*h;
    local_b = local_a + local_n * h;

    double local_inte = sum_quer(local_a,local_b,local_n,h);

    MPI_Reduce(&local_inte,&total_inte,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);

    if(myid == 0){
        
        printf("integral out put is %d",total_inte);
    }
    
    MPI_Finalize();

    return 0;



}
