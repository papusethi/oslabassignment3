// fork the process and create two child process 
// fork the child processes and create two child for each

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

int main() 
{ 
	int pid, pid1, pid2, pid3, pid4, pid5; 

	pid = fork(); 

	if (pid == 0) { 
		
		pid2 = fork(); 

		if (pid2 == 0) { 

			sleep(5); 
			printf("Child [1 - 1] --> pid = %d and ppid = %d\n", getpid(), getppid());
			
		} 

		else { 
			pid3 = fork(); 
			if (pid3 == 0) {
				sleep(4); 
				printf("Child [1 - 2] --> pid = %d and ppid = %d\n", getpid(), getppid()); 
			} 
			else { 
				sleep(6);
				printf("Child [1] --> pid = %d and ppid = %d\n", getpid(), getppid()); 
			
			} 
		} 
	} 

	else { 
		pid1 = fork(); 
		if (pid1 == 0) {

			pid4 = fork(); 

			if (pid4 == 0) { 

				sleep(2); 
				printf("Child [2 - 1] --> pid = %d and ppid = %d\n", getpid(), getppid());		
			} 
			else { 
				pid5 = fork(); 
				if (pid5 == 0) {
					sleep(1); 
					printf("Child [2 - 2] --> pid = %d and ppid = %d\n", getpid(), getppid()); 
				} 
				else { 
					sleep(3);
					printf("Child [2] --> pid = %d and ppid = %d\n", getpid(), getppid());		
				} 
			} 
			 
		} 
		else { 
			sleep(8);
			printf("Parent --> pid = %d\n", getpid()); 
		
		} 
	} 

	return 0; 
} 

