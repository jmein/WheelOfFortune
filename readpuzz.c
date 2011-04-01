#include<wof.h>

int main() {
	puzzle* list;
	int puzzNum, maxLength, maxCat;
	int i, j;
	//int loop;
	FILE* in;
	/*char* filename = malloc(sizeof(char));
	
	printf("What is the input file? ");
	scanf("%c", &filename[0]);
	for(i=1; filename[i-1] != 10; i++) {
		filename = realloc(filename, (i+1)*sizeof(char) );
		scanf("%c", &filename[i]);
	}
	in = fopen(filename, "r");
	*/
	in=fopen("puzz.list", "r");
	
	fscanf(in, "%d %d %d", &puzzNum, &maxLength, &maxCat);
	printf("%d %d %d", puzzNum, maxLength, maxCat);
	list = malloc(puzzNum*sizeof(puzzle));
	
	for(i=0; i<puzzNum; i++) {
		fscanf(in, "%d %d ", &list[i].cat, &list[i].length);
		printf("\n%d %d ", list[i].cat, list[i].length);
		list[i].words = malloc(list[i].length*sizeof(char));
		for(j=0; j<list[i].length; j++) {
			fscanf(in, "%c", &list[i].words[j]);
			printf("%c", list[i].words[j]);
		}
	}
	/*
	printf("\n");
	scanf("%d", &loop);
	while(loop >= 0) {
		if(loop<puzzNum) {
			printf("Category: %d\n", list[loop].cat);
			printf("Length: %d\n", list[loop].length);
			printf("%s\n", list[loop].words);
		}
		scanf("%d", &loop);
	}
	return 0;
	*/
	//return list;
	return 0;
}
