#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <string.h>
#include <errno.h>

#include "../../des_controller/src/ASS1.h"

int main(int argc, char *argv[]) {

	Person_T person;
	person.currentState = START;

	if (argc != 2) {
		fprintf(stderr,
				"Invalid number of arguments, please enter the des_controller pid\n");
		exit(EXIT_FAILURE);
	}
	pid_t des_controller_pid = atoi(argv[1]);
	if (des_controller_pid == 0) {
		fprintf(stderr, "Invalid input, exiting\n");
		exit(EXIT_FAILURE);
	}
	int coid;

	coid = ConnectAttach(ND_LOCAL_NODE, des_controller_pid, 1,
			_NTO_SIDE_CHANNEL, 0);

	if (coid == -1) {
		perror("Channel could not be attached\n");
		exit(EXIT_FAILURE);
	}
	while (person.currentState != 10) {
		printf(
				"Enter the event type (ls = left scan, rs = right scan, ws = weight scan, lo = left open, \n"
						"ro = right open, lc = left close, rc = rights closed, gru = guard right unlock \n"
						"glu = guard left unlock, grl = guard right lock, gll = guard left lock\n");
		printf("Enter 'exit' to quit the program.\n");

		scanf("%s", &person.msg);
		if (strcmp(person.msg, "ls") == 0) {
			if (person.side == RIGHT) {
				//Do nothing
			} else {
				person.side = LEFT;
				printf("Enter your ID:\n");
				scanf("%d", &person.ID);
			}
		} else if (strcmp(person.msg, "rs") == 0) {
			if (person.side == LEFT) {
				//do nothing
			} else {
				person.side = RIGHT;
				printf("Enter your ID:\n");
				scanf("%d", &person.ID);
			}
		}

		if (strcmp(person.msg, "ws") == 0) {
			printf("Enter your weight:\n");
			scanf("%d", &person.Weight);
		}
		if (MsgSend(coid, &person, sizeof(person), NULL, 0) == -1) {
			fprintf(stderr, "Error during MsgSend\n");
			perror(NULL);
			exit(EXIT_FAILURE);
		}

	}
	ConnectDetach(coid);
	return EXIT_SUCCESS;
}
