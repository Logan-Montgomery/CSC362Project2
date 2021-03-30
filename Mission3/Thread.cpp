#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <process.h>
#include <time.h>

int test = 1000000;

bool ct(int start, int end, int test) {
	bool prime = true;

	


	while (start < end) {
		if (test % start == 0) {
			prime = false;
			//printf("Divisor is: %d\n", start);
			break;
		}
		start++;
	}

	return prime;
	
}


void thread1(void* data) {
	bool prime = true;
	for (int i = 2; i < (int) test / 2;i++) {
	prime = ct(2, (int)i / 2, i);
	
	}
	

	//printf("Thread 1 Prime?: %d\n", prime);

}

void thread2(void* data) {

	bool prime = true;

	for (int i = (int) test/2; i <= test; i++) {
		prime = ct(2, (int)i / 2, i);

	}
	//printf("Thread 2 Prime?: %d\n", prime);



}

int main(int argc, char* argv[]) {
	clock_t tStart = clock();

	bool prime = true;
	HANDLE t1h,t2h;
	
	t1h = (HANDLE)_beginthread(&thread1, 0, 0);
	t2h = (HANDLE)_beginthread(&thread2, 0, 0);
	WaitForSingleObject(t1h, INFINITE);
	WaitForSingleObject(t2h, INFINITE);
	//printf("%d\n", prime);
	
	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

}
