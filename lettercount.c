#include<wof.h>

int main() {
	FILE* in;
	int i, j, puzzNum, maxLength, maxCat, frequency[27], lettCount = 0;
	puzzle* list;
	
	in = fopen("puzz.list", "r");
	fscanf(in, "%d %d %d", &puzzNum, &maxLength, &maxCat);
	list = malloc(puzzNum*sizeof(puzzle));
	
	for(i=0; i<27; i++) {
		frequency[i]=0;
	}
	
	for(i=0; i<puzzNum; i++) {
		fscanf(in, "%d %d ", &list[i].cat, &list[i].length);
		lettCount += list[i].length;
		list[i].words = malloc(list[i].length*sizeof(char));
		for(j=0; j<list[i].length; j++) {
			fscanf(in, "%c", &list[i].words[j]);
			if( (list[i].words[j]>64) && (list[i].words[j]<91) ) {
				++frequency[list[i].words[j]-64];
				++frequency[0];
			}
			else {
				--lettCount;
			}
		}
	}
	
	printf("%d letters:\n", frequency[0]);
	for(i=1; i<27; i++) {
		printf("%d %c\n", frequency[i], i+64);
	}
	printf("%d letters\n", lettCount);
	
	return 0;
}
