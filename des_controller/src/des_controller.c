#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <string.h>
#include <errno.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <limits.h>
#include <float.h>
/*
 * Remember: MsgReceive and reply in this file is involved with Des_inputs,
 * MsgSend will send to display
 */
#include "ASS1.h"
Person_T person;
Response_T response;

char* display_msg;
int coid = 0;
int rcvid;
int chid;

int main(int argc, char *argv[]) {

	if (argc != 2) {
		fprintf(stderr, "Invalid number of arguments.");
		exit(EXIT_FAILURE);
	}


	chid = ChannelCreate(0);
	pid_t display_pid = atoi(argv[1]);

	printf("Controller pid: %d\n", getpid());



	if (chid == -1) {
		fprintf(stderr, "Failed to create a channel");
		exit(EXIT_FAILURE);
	}
	//coid = ConnectAttach(ND_LOCAL_NODE, display_pid, 1, _NTO_SIDE_CHANNEL, 0);
	if (coid == -1) {
		perror("Channel could not be attached\n");
		exit(EXIT_FAILURE);
	}
	while (1) {
		rcvid = MsgReceive(chid, &person, sizeof(person), NULL);

		if (strcmp(person.msg, "exit") == 0) {
			break;
		}
		SCAN_FUNC(person.msg);
	}
}

void *SCAN_FUNC(char* input) {
	int id;
	/**if (MsgSend(coid, &person, sizeof(person), display_msg, sizeof(display_msg))
			== -1) {
		fprintf(stderr, "Unable to sendhhhh message\n");
		perror(NULL);
		exit(EXIT_FAILURE);
	}*/
	if(person.side == LEFT){
		if(strcmp(input, left_side[person.currentState])==0){
			person.currentState++;
			return UNLOCK_FUNC;
		}
	}else if(person.side == RIGHT){
		if(strcmp(input, right_side[person.currentState])==0){
			person.currentState++;
			return UNLOCK_FUNC;
		}
	}



}
void *UNLOCK_FUNC(char* input){
	if(person.side == LEFT){

	}
	else if(person.side == RIGHT){
	}
}
void *OPEN_FUNC(char* input){
	if(person.side == LEFT){
	}
	else if(person.side == RIGHT){
	}
}
void *WEIGHT_FUNC(char* input){
	if(person.side == LEFT){
	}
	else if(person.side == RIGHT){
	}
}
void *CLOSE_FUNC(char* input){
	if(person.side == LEFT){
	}
	else if(person.side == RIGHT){
	}
}
void *GUARD_EXIT_UNL_FUNC(char* input){
	if(person.side == LEFT){
	}
	else if(person.side == RIGHT){
	}
}
void *GUARD_EXIT_OPEN_FUNC(char* input){
	if(person.side == LEFT){
	}
	else if(person.side == RIGHT){
	}
}
void *EXIT_CLOSE_FUNC(char* input){
	if(person.side == LEFT){
	}
	else if(person.side == RIGHT){
	}
}
void *GUARD_EXIT_LOCK_FUNC(char* input){
	if(person.side == LEFT){
	}
	else if(person.side == RIGHT){
	}
}
void *EXIT_FUNC(char* input){
	person.currentState = START;
}
