#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <string.h>
#include <errno.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <limits.h>
#include <float.h>

#include "../../des_controller/src/ASS1.h"

int main (int argc, char* argv[])
{

	Person_T person;
	int rcvid;
	int person_state;

	int chid;
	char* response_msg;
    chid = ChannelCreate (0);
    if (chid == -1)
    {
    	perror("Failed to create the channel.");
    	exit (EXIT_FAILURE);
    }

    printf("Server PID is %d\n", getpid());


    while (1) {
        rcvid = MsgReceive (chid, &person, sizeof(person), NULL);

        person_state = person.currentState;

        if (rcvid == -1){
        	break;
        }
        if(person_state == START){
        	response_msg = "Enter the Person's ID:\n";
        }
        else if(person_state == UNLOCK){
        	if(person.side == LEFT){
				response_msg = "Left door unlocked\n";
        	}
        	else if(person.side == RIGHT){
        		response_msg = "Right door unlocked\n";
        	}
        }
        else if(person_state == OPEN){
        	if(person.side == LEFT){
				response_msg = "Left door opened\n";
        	}
        	else if(person.side == RIGHT){
        		response_msg = "Right door opened\n";
        	}
        }
        else if(person_state == WEIGHT){
			response_msg = "Enter the person' weight\n";
        }
        else if(person_state == ENTER_CLOSE){
        	if(person.side == LEFT){
				response_msg = "Left door closed.\n";
        	}
        	else if(person.side == RIGHT){
        		response_msg = "Right door closed.\n";
        	}
        }
        else if(person_state == ENTER_LOCK){
        	if(person.side == LEFT){
				response_msg = "Left door locked.\n";
        	}
        	else if(person.side == RIGHT){
        		response_msg = "Right door locked.\n";
        	}
        }
        else if(person_state == EXIT_UNLOCK){
        	if(person.side == LEFT){
				response_msg = "Right door unlocked.\n";
        	}
        	else if(person.side == RIGHT){
        		response_msg = "Left door unlocked.\n";
        	}
        }
        else if(person_state == EXIT_OPEN){
        	if(person.side == LEFT){
				response_msg = "Right door opened.\n";
        	}
        	else if(person.side == RIGHT){
        		response_msg = "Left door opened.\n";
        	}
        }
        else if(person_state == EXIT_CLOSE){
        	if(person.side == LEFT){
				response_msg = "Right door closed.\n";
        	}
        	else if(person.side == RIGHT){
        		response_msg = "Left door closed.\n";
        	}
        }
        else if(person_state == EXIT_LOCK){
        	if(person.side == LEFT){
				response_msg = "Left door locked.\n";
        	}
        	else if(person.side == RIGHT){
        		response_msg = "Right door locked.\n";
        	}
        }
        else{
        	response_msg ="Invalid input.\n";
        }
        MsgReply (rcvid, 1, &response_msg, sizeof (response_msg));
    }

   ChannelDestroy(chid);
   return EXIT_SUCCESS;
}
