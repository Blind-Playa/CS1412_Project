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
	char filename[31];
	int ans = 0; // Had to change this line to make it work in visual studio

	srand(time(0));

	printf("Welcome to the PUZZLE game!\n");

	// Get the puzzle file.
	printf("Enter the file storing all of the puzzle configurations.\n");
	scanf_s("%s", filename, sizeof(filename));

	while (ans != 2) {

		FILE *fin;
		errno_t file = fopen_s(&fin, filename, "r"); // Had to change this line to make it work in visual studio

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
	int numOfPuzzles, selectedPuzzle, i = 0, j, x, y, number;
	int *ptr = NULL;

	// Read in the file if it doesn't exist, exit
	if (fin != NULL) {
		// Read the first line in the file
		fscanf_s(fin, "%d", &numOfPuzzles);
		selectedPuzzle = rand() % numOfPuzzles;
		
		// Read all ints after until you the selected puzzle is reached then start storing them in the puzzle array
		while (!feof (fin)) {
			fscanf_s(fin, "%d", &number);
			i++;
			if (i == selectedPuzzle * (PUZZLE_SIDE * PUZZLE_SIDE)) {
				for (x = 0; x < PUZZLE_SIDE; x++) {
					for (y = 0; y < PUZZLE_SIDE; y++) {
						fscanf_s(fin, "%d", &number);
						puzzle[x][y] = number;
					}
				}
			}
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
	int move;
	printf("\nWhich piece would you like to slide into the open slot?\nNote, answering 0 means you quit the game without winning\n");
	scanf_s("%d", &move);
	return move;
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
	int i, j;
	for (i = 0; i < PUZZLE_SIDE; i++) {
		for (j = 0; j < PUZZLE_SIDE; j++) {
			if (puzzle[i][j] == 0) {

			}
		}
	}
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
	int i, j, temp = -1;
	for (i = 0; i < PUZZLE_SIDE; i++) {
		for (j = 0; j < PUZZLE_SIDE; j++) {
			if (temp > puzzle[i][j]) {
				return 0;
			}
			temp = puzzle[i][j];
		}
	}
	return 1;
}
