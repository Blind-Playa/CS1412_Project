// Scaffold for puzzle problem
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILE_LENGTH 30
#define PUZZLE_SIDE 4
#define EMPTY_SLOT 0

void loadPuzzle(int puzzle[][PUZZLE_SIDE], FILE *fin);
int getMove();
void printPuzzle(int puzzle[][PUZZLE_SIDE]);
int doMove(int puzzle[][PUZZLE_SIDE], int move);
void swap(int *a, int *b);
int solved(int puzzle[][PUZZLE_SIDE]);

int main() {

	int puzzle[PUZZLE_SIDE][PUZZLE_SIDE];
	char filename[MAX_FILE_LENGTH + 1];
	int ans;

	srand(time(0));

	printf("Welcome to the PUZZLE game!\n");

	// Get the puzzle file.
	printf("Enter the file storing all of the puzzle configurations.\n");
	scanf_s("%s", filename);

	while (ans != 2) {

		FILE *fin;
		fin = fopen(filename, "r");

		// Load the puzzle.
		loadPuzzle(puzzle, fin);
		fclose(fin);

		// Let's play!
		int move;

		printPuzzle(puzzle);
		move = getMove();

		// Keep on playing until the user gives up.
		while (move != 0) {

			// Execute this move, seeing if it's okay.
			int okay = doMove(puzzle, move);

			// Print an error message for an invalid move.
			if (!okay) {
				printf("Sorry, that is not a valid square to slide into ");
				printf(" the open slot.\nNo move has been executed.\n");
			}

			// Get out of the game for a winning move!
			else if (solved(puzzle))
				break;

			// Go get the next move.
			printPuzzle(puzzle);
			move = getMove();
		}

		// Output an appropriate puzzle ending message.
		if (move != 0)
			printf("Great, you solved the puzzle!!!\n");
		else
			printf("Sorry, looks like you gave up on the puzzle.\n");

		// Get their next selection.
		printf("Which selection would you like?\n");
		printf("1. Load a new puzzle.\n");
		printf("2. Quit.\n");
		scanf_s("%d", &ans);
	}

}

// Pre-conditions: fin is pointed to the beginning of a file with a valid
//                 file format for this problem.
// Post-conditions: A random puzzle from the file pointed to by fin will be
//                  stored in puzzle.
void loadPuzzle(int puzzle[][PUZZLE_SIDE], FILE *fin) {
	int i, j, x, y;
	char *str = malloc(13);
	char *stringarr[4];

	// Read in the file if it doesn't exist, exit
	if (fin != NULL) {

		// Read in the first line containing numOfPuzzles
		// Assign the string read in by fgets and check to see if there is anything on that line
		if (fgets(str, 13, fin) != NULL) {

			// Concatenate and convert the chars to make digits in an int then assign a random puzzle number
			int digit1 = str - 48;
			int digit2 = ++str - 48;
			unsigned pow = 10;
			while (digit1 >= pow) {
				pow *= 10;
			}
			int numOfPuzzles = digit2 * pow + digit1;
			int selected_PuzzleNum = rand() % numOfPuzzles;

			// read in the next numOfPuzzles * 5 lines until we hit selected_PuzzleNum
			for (i = 0; i < (numOfPuzzles * (PUZZLE_SIDE + 1)); i++) {
				fgets(str, 13, fin);
				if (i == (selected_PuzzleNum * (PUZZLE_SIDE + 1))) {

					// Read in the selected puzzle to store to an array
					for (j = 0; j < PUZZLE_SIDE; j++) {
						fgets(stringarr[j], 13, fin);
						for (x = 0; x < PUZZLE_SIDE; ) {

						}
					}
					break;
				}
			}
		}
		else {
			printf("first line of file does not contain an integer\n");
			exit(-1);
		}
	}
	else {
		printf("file error\n");
		exit(-1);
	}
}

// Pre-conditions: none.
// Post-conditions: A basic menu will be prompted and the user's result returned.
int getMove() {

}

// Pre-conditions: A valid puzzle is stored in puzzle.
// Post-conditions: A depiction of the puzzle will be printed out.
void printPuzzle(int puzzle[][PUZZLE_SIDE]) {
	int i, j;
	printf("\n");
	for (i = 0; i < PUZZLE_SIDE; i++) {
		for (j = 0; j < PUZZLE_SIDE; j++) {
			if (puzzle[i][j] == 0) {
				printf("_ ");
			}
			else
				printf("%d ", puzzle[i][j]);
		}
		printf("\n");
	}
}

// Pre-conditions: puzzle stores a valid puzzle configuration.
// Post-conditions: If move is a valid square to slide into the open slot,
//                  the move is executed and 1 is returned. Otherwise, 0
//                  is returned and no change is made to puzzle.
int doMove(int puzzle[][PUZZLE_SIDE], int move) {
	int *i;
	if ((sizeof(puzzle) / sizeof(puzzle[0][0])) == 16) {
		for (i = *puzzle; i != NULL; i++) {

		}
	}
	else
		printf("not a valid puzzle | too many integers");
}

// Pre-condition: none
// Post-condition: swaps the values in the variables pointed to by a and b.
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Pre-condition: puzzle stores a valid puzzle configuration.
// Post-condition: Returns 1 if puzzles is solved, 0 otherwise.
int solved(int puzzle[][PUZZLE_SIDE]) {

}
