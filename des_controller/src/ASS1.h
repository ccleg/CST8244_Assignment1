/*************************************
Filename: ASS1.h
Author : Cory Chenier & Vicknesh Babu
Assignment : 1
Date : November 6th 2019
Professor : Gerry Hurdle
**************************************/
#define LEFT 1
#define RIGHT 2
struct Person {
	int ID;
	int Weight;
	int currentState;
	int side;
}typedef Person_T;

#define STATES 13;
typedef enum {
	START = 0,
	UNLOCK = 1,
	OPEN = 2,
	WEIGHT = 3,
	ENTER_CLOSE = 4,
	ENTER_LOCK = 5,
	EXIT_UNLOCK = 6,
	EXIT_OPEN = 7,
	EXIT_CLOSE = 8,
	EXIT_LOCK = 9
} States;

#define NUM_INPUTS 10
const char *left_side[NUM_INPUTS] = {
	"ls",
	"glu",
	"lo",
	"ws",
	"lc"
	"gll",
	"gru",
	"ro",
	"rc",
	"grl"
};
const char *right_side[NUM_INPUTS] = {
	"rs",
	"gru",
	"ro",
	"ws",
	"rc",
	"grl",
	"glu",
	"lo",
	"lc",
	"gll"
};
#define NUM_REPLY 2
const char *reply_msg[NUM_REPLY] = {
		"Enter the person's id: \n",
		"Enter the person's weight: \n"
};

#define NUM_ERRORS 1
const char *error_msg[NUM_ERRORS] = {
		"Invalid start state\n"


};
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

void(*STATE_HANDLER[10])(char* input)= {SCAN_FUNC, UNLOCK_FUNC, OPEN_FUNC,WEIGHT_FUNC,CLOSE_FUNC, GUARD_EXIT_UNL_FUNC,EXIT_CLOSE_FUNC,GUARD_EXIT_LOCK_FUNC,EXIT_FUNC} ;


