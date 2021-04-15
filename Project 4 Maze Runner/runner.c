#include "runner.h"
#include "mazelib.h"

// The character that should be left behind under certain conditions
char valuesLeft[] = {'E', ' ', '.', 'o', 'O', '@'};

// The sstarting cords of the maze
int presentCords[] = {1, 1};

void runner_init(void){
  // Empty
}

// The runner solve requirement
void runner_solve(void){
    while(maze_get_char(presentCords[0], presentCords[1]) != 'E') {
        int newDirection = whereMazeWillGo(presentCords[0], presentCords[1]);
        char newCharacter;

        if (thePointvalue(maze_get_char(presentCords[0], presentCords[1])) + 1 > 5) {
            newCharacter = '@';
        }
        else {
            newCharacter = valuesLeft[thePointvalue(maze_get_char(presentCords[0], presentCords[1])) + 1];
        }
        maze_set_char(presentCords[0], presentCords[1], newCharacter);
        switch (newDirection) {
            case NORTH:
                presentCords[1] = presentCords[1] + 1;
                break;
            case SOUTH:
                presentCords[1] = presentCords[1] - 1;
                break;
            case EAST:
                presentCords[0] = presentCords[0] + 1;
                break;
            case WEST:
                presentCords[0] = presentCords[0] - 1;
                break;
        }
    }
}

// Determines the point value
int thePointvalue(char c) {
	for(int i = 0; i < 6; i++) {
		if(valuesLeft[i] == c) {
			return i;
		}
	}
	return 99999;
}

// This determines where will the point go next through the maze
int whereMazeWillGo(int x_c, int y_c){
	int theLowestValue = 999999;
	int theDirection = 0;
	for(int i = 0; i < 4; i++) {
		int val;
    // Used switch statement to cleaner look than nested if statements
		switch(i) {
			case NORTH:
				val = thePointvalue(maze_get_char(x_c, y_c + 1));
				if(val < theLowestValue) {
					theDirection= i;
					theLowestValue = val;
				}
				break;

      case EAST:
        val = thePointvalue(maze_get_char(x_c + 1, y_c));
        if(val < theLowestValue) {
          theDirection= i;
                    theLowestValue = val;
        }
      	break;
			case SOUTH:
				val = thePointvalue(maze_get_char(x_c, y_c - 1));
				if(val < theLowestValue) {
					theDirection= i;
                    theLowestValue = val;
				}
				break;

			case WEST:
				val = thePointvalue(maze_get_char(x_c - 1, y_c));
				if(val < theLowestValue) {
					theDirection= i;
                    theLowestValue = val;
				}
				break;
		}
	}
	return theDirection;
}
