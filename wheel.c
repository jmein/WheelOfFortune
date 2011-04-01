//	Chris Barsoum
//	Jonathon Meinema
//	COP 3223H
//	Final Project: Wheel of Fortune
//	, 2011

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct aWheelOfFortunePuzzle {
	int cat;			//numerical representation of the category the puzzle 
								//is in
	char* words;	//the most important part, a string to hold puzzle
	int length;		//number of characters in the string
};

//so much better with typedefs
typedef struct aWheelOfFortunePuzzle puzzle;

void addPuzz(puzzle* list);
void settings(void);
puzzle* readPuzzles(FILE* read, int pNum);
int* letterCount(puzzle* puzzList, int pNum);
//void compTurn(int* freq, puzzle current, )

/*		i need to ask arup about global variables
int *frequency, *letCat, *letLength;
	int puzzNum, maxLength, catNum;
	int roundNum=5;	//number of rounds. 5 by default
*/

int main(void) {
	int i;	//index
	int *frequency, *letCat, *letLength;
	int puzzNum, maxLength, catNum;
	int roundNum=5;	//number of rounds. 5 by default
	int opt=1;	//loop variable, initially yes;
	
	FILE* in;
	in=fopen("puzz.list", "r");
	
	fscanf(in, "%d %d %d", &puzzNum, &maxLength, &catNum);
	
	puzzle* list = readPuzzles(in, puzzNum);
	
	frequency = letterCount(list, puzzNum);
	
	letCat = malloc(catNum*sizeof(int));
	for(i=0; i<catNum; i++) {		//by default, all categories are included,
		letCat[i]=1;						//so we initialize allowCat to all 1's.
	}
	
	letLength = malloc( (maxLength+1)*sizeof(int) );
	for(i=0; i<=maxLength; i++) {		//by default, all lengths are included,
		letLength[i]=1;							//so we intialize allowLength to all 1's
	}
	/*
	while (opt) {
		printf("1 Play a game\n2 Adjust settings\n3 Bonus options\n\n");
		scanf("%d", &opt);
		if (opt == 1){
			printf("broken\n\n");
		}
		else if(opt == 2) {
			settings();
		}
		else if(opt == 3) {
			printf("broken\n\n");
		}
		else if(opt) {
			printf("nice try, but never(probably)\n\n");
		}
	}*/
	
	return 0;
}

//		readPuzzles takes a file pointer and the number of puzzles in 
//		the file and returns a pointer to the list of puzzles in the
//		file
 
puzzle* readPuzzles(FILE* read, int pNum) {
	puzzle* list;		//will contain a list of puzzles
	int i, j;				//indices		
	
	list = malloc( (pNum)*sizeof(puzzle));		//allocate memory for list
	
	for(i=0; i<pNum; i++) {
		//easy input: category and length
		fscanf(read, "%d %d ", &list[i].cat, &list[i].length);
		
		//allocate memory for the string in the puzzle
		list[i].words = malloc(list[i].length * sizeof(char));
		
		for(j=0; j<list[i].length; j++) {			//scan in the string
			fscanf(read, "%c", &list[i].words[j]);	//one character at a time 
		}
		
		printf("%d: %s (%d)\n", list[i].cat, list[i].words, list[i].length);
	}
	
	return list;	//this is the list we want! :)
}

//		letterCount takes a puzzle pointer and the number of puzzles and returns
//		the total number of letters in frequency[0], the number of A's in 
//		frequency[1], B's in frequency[2]... and Z's in frequency[26].

int* letterCount(puzzle* puzzList, int pNum) {
	int i, j, *frequency;
	
	frequency = malloc(27*sizeof(int));
	for(i=0; i<27; i++) {
		frequency[i]=0;
	}
	
	for(i=0; i<pNum; i++) {
		for(j=0; j<puzzList[i].length; j++) {
			if( (puzzList[i].words[j]>64) && (puzzList[i].words[j]<91) ) {
				++frequency[puzzList[i].words[j]-64];
				++frequency[0];
			}
		}
	}
	
	for(i=0; i<27; i++) {
		printf("%4d %c's\n", frequency[i], i+64);
	}
	
	return frequency;
}

void settings(void) {
	int opt;
	while(opt) {
		printf("1 categories\n2 length\n3 rounds\n0 quit\n\n");
		scanf("%d", &opt);
		if(opt == 1) {
			printf("broken\n\n");
		}
		else if(opt == 2) {
			printf("broken\n\n");
		}
		else if(opt == 3) {
			printf("broken\n\n");
		}
		else if(opt) {
			printf("Not a valid choice. Try again?\n\n");
		}
	}
}

void addPuzz(puzzle* list) {
	int addNum=0;
	int loop;
}
