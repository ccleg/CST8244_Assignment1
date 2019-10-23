struct Person {
	int ID;
	int Weight;
	int currentState;
	int startState;
}typedef Person_T

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
NUM_INPUTS 11
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
	"grl",
	"exit"
}
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
	"gll",
	"exit"
}