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
void display(Person_T);

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
	coid = ConnectAttach(ND_LOCAL_NODE, display_pid, 1, _NTO_SIDE_CHANNEL, 0);
	if (coid == -1) {
		perror("Channel could not be attached\n");
		exit(EXIT_FAILURE);
	}
	Person_T person;
	STATE stateFunc = &SCAN_FUNC;
	while (1) {
		rcvid = MsgReceive(chid, &person, sizeof(person), NULL);
		stateFunc = (*stateFunc)(person);
		MsgReply(rcvid, EOK, NULL,0);
		if (strcmp(person.msg, "exit") == 0) {
			break;
		}
	}
}

void *SCAN_FUNC(Person_T person) {
	if (person.side == LEFT) {
		if (strcmp(person.msg, left_side[START]) == 0) {
			person.currentState = START;
			display(person);
			return UNLOCK_FUNC;
		}
	} else if (person.side == RIGHT) {
		if (strcmp(person.msg, right_side[START]) == 0) {
			person.currentState = START;
			display(person);
			return UNLOCK_FUNC;
		}
	}
	display(person);
	return SCAN_FUNC;
}

void *UNLOCK_FUNC(Person_T person) {
	if (person.side == LEFT) {
		if (strcmp(person.msg, left_side[UNLOCK]) == 0) {
			person.currentState = UNLOCK;
			display(person);
			return OPEN_FUNC;
		}
	} else if (person.side == RIGHT) {
		if (strcmp(person.msg, right_side[UNLOCK]) == 0) {
			person.currentState = UNLOCK;
			display(person);
			return OPEN_FUNC;
		}
	}
	display(person);
	return UNLOCK_FUNC;
}

void *OPEN_FUNC(Person_T person) {
	if (person.side == LEFT) {
		if (strcmp(person.msg, left_side[OPEN]) == 0) {
			person.currentState = OPEN;
			display(person);
			return WEIGHT_FUNC;
		}
	} else if (person.side == RIGHT) {
		if (strcmp(person.msg, right_side[OPEN]) == 0) {
			person.currentState = OPEN;
			display(person);
			return WEIGHT_FUNC;
		}
	}
	display(person);
	return OPEN_FUNC;
}

void *WEIGHT_FUNC(Person_T person) {
	if (person.side == LEFT) {
		if (strcmp(person.msg, left_side[WEIGHT]) == 0) {
			person.currentState = WEIGHT;
			display(person);
			return CLOSE_FUNC;
		}
	} else if (person.side == RIGHT) {
		if (strcmp(person.msg, right_side[WEIGHT]) == 0) {
			person.currentState = WEIGHT;
			display(person);
			return CLOSE_FUNC;
		}
	}
	display(person);
	return WEIGHT_FUNC;
}

void *CLOSE_FUNC(Person_T person) {
	if (person.side == LEFT) {
		if (strcmp(person.msg, left_side[ENTER_CLOSE]) == 0) {
			person.currentState = ENTER_CLOSE;
			display(person);
			return GUARD_OPEN_LOC_FUNC;
		}
	} else if (person.side == RIGHT) {
		if (strcmp(person.msg, right_side[ENTER_CLOSE]) == 0) {
			person.currentState = ENTER_CLOSE;
			display(person);
			return GUARD_OPEN_LOC_FUNC;
		}
	}
	display(person);
	return CLOSE_FUNC;
}
void *GUARD_OPEN_LOC_FUNC(Person_T person){
	if (person.side == LEFT) {
			if (strcmp(person.msg, left_side[ENTER_LOCK]) == 0) {
				person.currentState = ENTER_LOCK;
				display(person);
				return GUARD_EXIT_UNL_FUNC;
			}
		} else if (person.side == RIGHT) {
			if (strcmp(person.msg, right_side[ENTER_LOCK]) == 0) {
				person.currentState = ENTER_LOCK;
				display(person);
				return GUARD_EXIT_UNL_FUNC;
			}
		}
	display(person);
	return GUARD_OPEN_LOC_FUNC;
}


void *GUARD_EXIT_UNL_FUNC(Person_T person) {
	if (person.side == LEFT) {
		if (strcmp(person.msg, left_side[EXIT_UNLOCK]) == 0) {
			person.currentState = EXIT_UNLOCK;
			display(person);
			return GUARD_EXIT_OPEN_FUNC;
		}
	} else if (person.side == RIGHT) {
		if (strcmp(person.msg, right_side[EXIT_UNLOCK]) == 0) {
			person.currentState = EXIT_UNLOCK;
			display(person);
			return GUARD_EXIT_OPEN_FUNC;
		}
	}
	display(person);
	return GUARD_EXIT_UNL_FUNC;
}

void *GUARD_EXIT_OPEN_FUNC(Person_T person) {
	if (person.side == LEFT) {
		if (strcmp(person.msg, left_side[EXIT_OPEN]) == 0) {
			person.currentState = EXIT_OPEN;
			display(person);
			return EXIT_CLOSE_FUNC;
		}
	} else if (person.side == RIGHT) {
		if (strcmp(person.msg, right_side[EXIT_OPEN]) == 0) {
			person.currentState = EXIT_OPEN;
			display(person);
			return EXIT_CLOSE_FUNC;
		}
	}
	display(person);
	return GUARD_EXIT_OPEN_FUNC;
}

void *EXIT_CLOSE_FUNC(Person_T person) {
	if (person.side == LEFT) {
		if (strcmp(person.msg, left_side[EXIT_CLOSE]) == 0) {
			person.currentState = EXIT_CLOSE;
			display(person);
			return GUARD_EXIT_LOCK_FUNC;
		}
	} else if (person.side == RIGHT) {
		if (strcmp(person.msg, right_side[EXIT_CLOSE]) == 0) {
			person.currentState = EXIT_CLOSE;
			display(person);
			return GUARD_EXIT_LOCK_FUNC;
		}
	}
	display(person);
	return EXIT_CLOSE_FUNC;
}

void *GUARD_EXIT_LOCK_FUNC(Person_T person) {
	if (person.side == LEFT) {
		if (strcmp(person.msg, left_side[EXIT_LOCK]) == 0) {
			person.currentState = EXIT_LOCK;
			display(person);
			return SCAN_FUNC;
		}
	} else if (person.side == RIGHT) {
		if (strcmp(person.msg, right_side[EXIT_LOCK]) == 0) {
			person.currentState = EXIT_LOCK;
			display(person);
			return SCAN_FUNC;
		}
	}
	display(person);
	return GUARD_EXIT_LOCK_FUNC;
}
//Do we have to have a function pointer for the exit state?
//Can we exit the program, or just go back to the start state
void *EXIT_FUNC(Person_T person) {
	person.currentState = EXIT;
	return EXIT_FUNC;

}
void display(Person_T person){
	//send the struct to display, use Null as a return message
	MsgSend(coid,&person,sizeof(person),NULL,0);
}
