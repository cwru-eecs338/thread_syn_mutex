#include <time.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/time.h>

static char * BUFFER="./buffer.txt";
static int MAX=99;

void do_work(void);

