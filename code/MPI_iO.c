/*************************************************************************
	> File Name: MPI_iO.c
	> Author: 
	> Mail: 
	> Created Time: 2017年01月24日 星期二 13时58分47秒
 ************************************************************************/

#include<stdio.h>
#include<mpi.h>


void get_data(){

    int my_rank;
    int comm_zz;
    double *a;
    double *b;
    int    *n;
    int  dest;

    if(my_rank == 0){
        scanf("%lf %lf %d",a,b,n);
        for(dest = 0;dest < comm_zz;dest++){
            MPI_Send(a,1,MPI_DOUBLE,dest,0,MPI_COMM_WORLD);
            MPI_Send(b,1,MPI_DOUBLE,dest,0,MPI_COMM_WORLD);
            MPI_Send(n,1,MPI_INT,dest,0,MPI_COMM_WORLD);
        }
    }else{
        MPI_Recv(a,1,MPI_DOUBLE,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        MPI_Recv(b,1,MPI_DOUBLE,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        MPI_Recv(n,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

    }


}
