#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

long int test;

bool ct(int start, int end, int test){
    bool prime = true;
    while(start < end){
        if(test%start == 0){
            prime = false;
            //printf("Divisor is: %d", start);
            break;
        }
        start++;
        
    }
    if(prime){
        
        //printf("Prime number is: %d \n", test);
        
    }
    return prime;
}



int main(){
    
    test = 1000000;
    pid_t pid;
	int forknum = 0;
	int totalforks = 10;
    
    
    pid = getpid();
	//number of forks
	if (pid == getpid()) {

		for (int j = 0; j < totalforks; j++) {
			forknum++;
			fork();
			if (pid != getpid()) {
				break;
			}
		}
	}

	if (pid == getpid())
		{
			clock_t tstartf1 = clock();
			for (long int i = 2; i < test / totalforks; i++) {
				ct(2, (long int)i / 2, i);
			}
			printf("Time taken fork 1: %.2fs\n", (double)(clock() - tstartf1) / CLOCKS_PER_SEC);

			

		}

		

		if (pid != getpid()){
			clock_t tstartf1 = clock();
			for (long int i = (test / totalforks)*(forknum); i <= (test / totalforks) * (forknum+1); i++) {
			ct(2, (long int)i / 2, i);
		}

		printf("Time taken fork 2: %.2fs\n", (double)(clock() - tstartf1) / CLOCKS_PER_SEC);
		}

	
    
    
    
return 0;    
}
