/*************************************************************************
	> File Name: mpi_getin.c
	> Author: 
	> Mail: 
	> Created Time: 2017年01月25日 星期三 22时54分46秒
 ************************************************************************/

#include<stdio.h>
#include<mpi.h>


void Get_void(){

    int my_rank;
    int comm_sz;
    double * a_p;
    double * b_p;
    int *    n_p;

    if(my_rank == 0){
        scanf("%lf %lf %d\n",a_p,b_p,n_p);
    }
    MPI_Bcast(a_p,1,MPI_DOUBLE,0,MPI_COMM_WORLD);
    MPI_Bcast(b_p,1,MPI_DOUBLE,0,MPI_COMM_WORLD);
    MPI_Bcast(n_p,1,MPI_INT,0,MPI_COMM_WORLD);



}
