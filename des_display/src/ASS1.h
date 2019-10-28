/*************************************
Filename: ASS1.h
Author : Cory Chenier & Vicknesh Babu
Assignment : 1
Date : November 6th 2019
Professor : Gerry Hurdle
**************************************/

struct Person {
	int ID;
	int Weight;
	int currentState;
	int side;
}typedef Person_T;

struct display_response {
	char   msg[128];
	char   errorMsg[128];
} typedef display_response_t;


#define STATES 13;
typedef enum {
	START_STATE = 0,
	LEFT_SCAN = 1,
	RIGHT_SCAN = 2,
	GLU_STATE = 3,
	GRU_STATE = 4,
	LO_STATE = 5,
	RO_STATE = 6,
	WEIGHT_STATE = 7,
	LEFT_CLOSE_STATE = 8,
	RIGHT_CLOSE_STATE = 9,
	GL_LOCK_STATE = 10,
	GR_LOCK_STATE = 11,
	EXIT = 12
} States;

#define NUM_INPUTS 12
const char *entrance[NUM_INPUTS] = {
	"ls",
	"rs",
	"glu",
	"gru",
	"lo"
	"ro",
	"ws",
	"lc",
	"rc",
	"gll",
	"grl",
	"exit"
};

void(*STATE_HANDLER)(char*);

void SCAN_FUNC(char* input);
void UNLOCK_FUNC(char* input);
void OPEN_FUNC(char* input);
void WEIGHT_FUNC(char* input);
void CLOSE_FUNC(char* input);
void GUARD_EXIT_UNL_FUNC(char* input);
void GUARD_EXIT_OPEN_FUNC(char* input);
void EXIT_CLOSE_FUNC(char* input);
void GUARD_EXIT_LOCK_FUNC(char* input);
void EXIT_FUNC(char* input);

STATE_HANDLER state_table[] = {
*scan_func, *unlock_func, *open_func, *weight_func,
*close_func, *guard_exit_unl_func, *guard_exit_open_func,
*exit_close_func, *guard_exit_lock_func, *exit_func
};
