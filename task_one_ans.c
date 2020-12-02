
// WAP to fork a process into parent and child.
// Further fork the child process and create its child.

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>

int main() { 
	int fpid, fpid1; 

	fpid = fork(); 

	if (fpid == 0) { 

		// Now make its child
		fpid1 = fork(); 
		if (fpid1 == 0) { 
			sleep(1);
			printf("Child of Child --> PID = %d and PPID = %d\n", getpid(), getppid()); 
		}
		else {
			sleep(2);
			printf("Child [1] --> PID = %d and PPID = %d\n", getpid(), getppid()); 	
		}

	} 
	else { 
		sleep(3);
		printf("Parent --> PID = %d\n", getpid()); 		
	} 

	return 0; 
} 

