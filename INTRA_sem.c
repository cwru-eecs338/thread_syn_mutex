
     /*
          INTRA process main (multiple threads - one process space)
         Compile: g++  p11.5.PC.cxx  p11.5.INTRA.cxx  -lpthread -o INTRA
       */
#include "local_mutex.h"
#include "sem_functions.h"

pthread_mutex_t LOCK,   *m_LOCK = &LOCK;
int setup, *s_shm  = &setup,
        current,*c_shm  = &current;
int sem_id;

int main(int argc, char *argv[]) {
	 int  i, n;
//	int sem_id;
	sem_id=semget(ftok(".",'a'),1,0666|IPC_CREAT); //create a new semaphore
	init_sem(sem_id,1); //initialize the semaphore with1
         pthread_t worker[MAX];                 // worker TID's
         if ( argc != 2) {
      		printf("Usage: %d n_workers \n",*argv);
	     	return 1;
         }
         pthread_mutex_init(&LOCK,  NULL);
         *s_shm = 0;                            // Start as NOT setup
         *c_shm = 0;                            // current index (offset)
       	 n = atoi(argv[1]) < MAX ? atoi(argv[1]) : MAX;
                                                // # of threads to create
       	 for( i=0; i < n; ++i)                  // create each thread
           	pthread_create( &worker[i], NULL,(void *(*)(void *))do_work, (void *)NULL );
                                                // wait for all to finish
         for(i=0; i < n; ++i )
          	pthread_join(worker[i], (void **) NULL);
                                                // show contents of buffer
       	 printf("Contents of %s negative values were 'consumed'.\n ",BUFFER);
	 FILE * fptr;

         int done = 0;

	 fptr=fopen(BUFFER, "r");
    	 while ( !done ) {
          	fread(&n,sizeof(int),1,fptr);
		if(feof(fptr)==1)
			done = 1;
           	else

			printf("%d\n",n);
	}
        fclose(fptr);

	return 0;
       }
