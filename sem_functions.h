#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int init_sem(int sem_id, int init_value);
int del_sem(int sem_id);
int sem_p(int sem_id);
int sem_v(int sem_id);

union semun{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};
