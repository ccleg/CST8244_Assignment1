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
int setStartSide(char* side);
Person_T person;

char* display_msg;
int coid = 0;
int rcvid;

int main(int argc, char *argv[]) {

	if (argc != 2) {
		fprintf(stderr, "Invalid number of arguments.");
		exit(EXIT_FAILURE);
	}

	pid_t display_pid = atoi(argv[1]);
	int chid;
	int error;
	char input_msg[4];
	size_t len;
	printf("Controller pid: %d\n", getpid());

	chid = ChannelCreate(0);

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
		rcvid = MsgReceive(chid, input_msg, strlen(input_msg), NULL);
		len = strlen(input_msg);
		printf("%d\n", len);
		char *newInput = (char *)malloc(len);
		memcpy(newInput,input_msg,len);
		printf("%s\n", newInput);
		if (strcmp(input_msg, "exit") == 0) {
			break;
		} else {
			int side = setStartSide(newInput);
			if (side == -1) {
				error = 0;
				/*MsgReply(rcvid, EOK, error_msg[error],
						sizeof(error_msg[error]));*/
			}

		}
		(*STATE_HANDLER[person.currentState])(newInput);
	}
}
int setStartSide(char* side) {
	if(person.currentState == 0){
	if (strcmp(side, "ls") == 0) {
		person.side = LEFT;
		person.currentState = START;
		return 0;

	} else if (strcmp(side, "rs") == 0) {
		person.side = RIGHT;
		person.currentState = START;
		return 0;
	}
	return -1;
	}else{

	}
}
void SCAN_FUNC(char* input) {
	int id;
	/**if (MsgSend(coid, &person, sizeof(person), display_msg, sizeof(display_msg))
			== -1) {
		fprintf(stderr, "Unable to sendhhhh message\n");
		perror(NULL);
		exit(EXIT_FAILURE);
	}*/
	scanf("%d", id);
	printf("u wot\n");
	MsgReply(rcvid,EOK,input,sizeof(input));
	person.ID = id;
	person.currentState++;
}
void UNLOCK_FUNC(char* input) {

	if (person.side == LEFT) {
		if(input != left_side[person.currentState]){
			fprintf(stderr,"Invalid input for the person, you killed them\n");
			exit(1);
		}
			person.currentState++;
	} else if (person.side == RIGHT) {

	}
}
void OPEN_FUNC(char* input) {
	if (person.side == LEFT) {

	} else if (person.side == RIGHT) {

	}
}
void WEIGHT_FUNC(char* input) {
	if (person.side == LEFT) {

	} else if (person.side == RIGHT) {

	}
}
void CLOSE_FUNC(char* input) {
	if (person.side == LEFT) {

	} else if (person.side == RIGHT) {

	}
}
void GUARD_EXIT_UNL_FUNC(char* input) {
	if (person.side == LEFT) {

	} else if (person.side == RIGHT) {

	}
}
void GUARD_EXIT_OPEN_FUNC(char* input) {
	if (person.side == LEFT) {

	} else if (person.side == RIGHT) {

	}
}
void EXIT_CLOSE_FUNC(char* input) {
	if (person.side == LEFT) {

	} else if (person.side == RIGHT) {

	}
}
void GUARD_EXIT_LOCK_FUNC(char* input) {
	if (person.side == LEFT) {

	} else if (person.side == RIGHT) {

	}
}
void EXIT_FUNC(char* input) {
	person.currentState = START;
}
