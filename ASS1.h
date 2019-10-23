/*************************************
Filename: ASS1.h
Author : Cory Chenier & Vicknesh Babu
Assignment : 1
Date : November 6th 2019
Professor : Gerry Hurdle
**************************************/
//person struct, holding all information about the person including:
//ID, weight, currentState, startStare ( we will be using this to check
//Which door they entered from) 
struct Person {
	int ID;
	int Weight;
	int currentState;
	int startState;
}typedef Person_T
//list of states
typedef enum {
	START = 0;
	SCAN = 1;
	UNLOCK = 2;
	OPEN = 3;
	WEIGHT_SCAN = 4;
	CLOSE = 5;
	LOCK = 6;
	GUARD_EXIT_UNLOCK = 7;
	GUARD_EXIT_OPEN = 8;
	EXIT_CLOSE = 9;
	GUARD_EXIT_LOCK = 10;
	EXIT = 11;
} States
//A list of inputs used if entered from the left, we will use the current state
//to check if the NEXT input is valid
NUM_INPUTS 10
const char *leftEnter[NUM_INPUTS] = {
	"ls",
	"glu",
	"lo",
	"ws",
	"lc",
	"gll",
	"gru",
	"ro",
	"rc",
	"grl"
}
//A list of inputs used if entered from the right, we will use the current state
//to check if the NEXT input is valid
const char *rightEnter[NUM_INPUTS] = {
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
}

//Array of function pointers syntax: *returntype (*pf)(*argument)

void(*STATE_HANDLER)(char*)

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


