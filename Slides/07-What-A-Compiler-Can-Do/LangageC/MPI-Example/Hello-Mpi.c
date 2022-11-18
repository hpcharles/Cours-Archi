#include <mpi.h>                /* To be compiled with mpicc -g -o Hello-Mpi Hello-Mpi.c */
#include <stdio.h>              /* To be run with  mpiexec --hostfile hostfile -n 10 ./Hello-Mpi*/
#include <string.h>
#define MSGSIZE 80
int main(int argc, char ** argv)
{
  int rank, size;
  char msg[MSGSIZE];
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  printf("I'm process %d on %d\n", rank, size);
  if (rank == 0){               /* Node 0 */
    bcopy("Hello world", msg, MSGSIZE);
    printf("0:I'll send msg\n");    
    MPI_Send(msg, MSGSIZE, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
  } else if (rank < (size - 1)) { /* Other nodes */
    printf ("%d: waiting message from %d\n", rank, rank-1);
    MPI_Recv(msg, MSGSIZE, MPI_CHAR, rank-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf ("%d: Received message from %d: %s\n", rank, rank-1, msg);
    MPI_Send(msg, MSGSIZE, MPI_CHAR, rank+1, 0, MPI_COMM_WORLD);
  } else if (rank == (size - 1)) { /* Last node */
    printf ("%d: waiting message from %d\n", rank, rank-1);
    MPI_Recv(msg, MSGSIZE, MPI_CHAR, rank-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf ("%d: Received message from %d: %s\n", rank, rank-1, msg);
  }
  MPI_Finalize();
  return 0;
}
