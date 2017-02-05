/*************************************************************************
	> File Name: MPI_hello.c
	> Author: 
	> Mail: 
	> Created Time: 2017年01月19日 星期四 22时13分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"mpi.h"

#define MASTER     0

int main(int argc ,char **argv){

    int numtasks,taskid,len;
    char hostname[MPI_MAX_PROCESSOR_NAME];
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD,&taskid);
    MPI_Get_processor_name(hostname,&len);
    printf("Hello from task %d on %s \n",taskid,hostname);
    if(taskid == MASTER){
        printf("MASTER number of MPI task is %d\n",numtasks);
    }
    MPI_Finalize();

}
