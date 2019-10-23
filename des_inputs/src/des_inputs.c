#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv) {
	char* input = NULL;
	char rplyMsg[200];
	if (argc != 2){
	fprintf(stderr, "Invalid number of arguments, please enter the des_controller pid\n");
	exit(EXIT_FAILURE);
	}
	pid_t des_controller_pid = atoi(argv[1]);
	if (des_controller_pid == 0){
		fprintf(stderr, "Invalid input, exiting\n");
		exit(EXIT_FAILURE);
	}
	int coid;
	
	coid = ConnectAttach(ND_LOCAL_NODE, des_controller_pid, 1, _NTO_SIDE_CHANNEL, 0);
	
	if (coid == -1) {
		perror("Channel could not be attached\n");
		exit(EXIT_FAILURE);
	}
	while(strcmp(input,"exit") != 0){
		scanf("%s",input);
		if(MsgSend(coid, input, strlen(input) + 1, rplyMsg, sizeof (rplyMsg)) == -1{
			fprintf(stderr, "Unable to send message\n");
			perror(NULL);
			exit(EXIT_FAILURE);
		}
		
		if(strlen (rplyMsg > 0) {
			printf("%s\n", rplyMsg);
		}
	}
	ConnectDetach(coid);
	return EXIT_SUCCESS;
}
