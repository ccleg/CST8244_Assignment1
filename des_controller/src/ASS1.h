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
	char msg[5];
}typedef Person_T;
struct Response {
	int state;
	Person_T person;
}typedef Response_T;
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
	EXIT_LOCK = 9,
	EXIT = 10
} States;
#define NUM_INPUTS 10
const char *left_side[NUM_INPUTS] = {
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
#define NUM_REPLY 10
const char *left_msg[NUM_REPLY] = {
		"Person has scanned their Id, Id =",
		"Left door unlocked.\n",
		"Left door opened.\n",
		"Person Weighed. Weight =",
		"Left door closed.\n",
		"Left door locked Guard.\n",
		"Right door unlocked.\n",
		"Right door opened.\n",
		"Right door closed.\n",
		"Right door locked by GUard.\n"
};
const char *right_msg[NUM_REPLY] = {
		"Person has scanned their Id, Id = %d.\n",
		"Right door unlocked.\n",
		"Right door opened.\n",
		"Person Weighed. Weight = %d.\n",
		"Right door closed.\n",
		"Right door locked by Guard.\n",
		"Left door unlocked.\n",
		"Left door opened.\n",
		"Left door closed.\n",
		"Left door locked by Guard.\n"
};
typedef void *(*STATE)(Person_T);
void *SCAN_FUNC(Person_T);
void *UNLOCK_FUNC(Person_T);
void *OPEN_FUNC(Person_T);
void *WEIGHT_FUNC(Person_T);
void *CLOSE_FUNC(Person_T);
void *GUARD_OPEN_LOC_FUNC(Person_T);
void *GUARD_EXIT_UNL_FUNC(Person_T);
void *GUARD_EXIT_OPEN_FUNC(Person_T);
void *EXIT_CLOSE_FUNC(Person_T);
void *GUARD_EXIT_LOCK_FUNC(Person_T);
void *EXIT_FUNC(Person_T);




