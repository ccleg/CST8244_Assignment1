#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	char* input_msg;
	char* rplyMsg;
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
	while(strcmp(input_msg,"exit") != 0){
		//scanf("%s\n",input);
		//printf("%s\n", input);
		input_msg = "ls";
		printf("%d\n",strlen(input_msg));
		if(MsgSend(coid, input_msg, strlen(input_msg), rplyMsg, sizeof (rplyMsg)) == -1){
			fprintf(stderr, "Unable to send message\n");
			perror(NULL);
			exit(EXIT_FAILURE);
		}
		
		if(strlen (rplyMsg > 0)) {
			printf("%s\n", rplyMsg);
		}
	}
	ConnectDetach(coid);
	return EXIT_SUCCESS;
}
