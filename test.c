#include <stdio.h>
#include <stdlib.h>

void main(){
	FILE * fptr;
	fptr=fopen("./test_file.txt","w");
	fclose(fptr);
	fptr=fopen("./test_file.txt","r+");
	int *n;
	printf("feof: %d\n",feof(fptr));
	n=(int *)malloc(sizeof(int));
	fread(n,sizeof(int),1,fptr);
	printf("the number is\n%d\n",*n );
	printf("feof: %d\n",feof(fptr));

	fread(n,sizeof(int),1,fptr);
	printf("the number is\n%d\n",*n );
	printf("feof: %d\n",feof(fptr));
	


//	printf("random number is %d\n",my_rand(1,3));
}
