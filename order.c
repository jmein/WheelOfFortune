#include<wof.h>

void sample(puzzle* list, int puzzCount);
int i;
int main() {
	
	srand(time(0));
	FILE* rw;
	int maxLength, puzzNum, maxCat, j, k;
	puzzle *list0, *list1;
	
	rw = fopen("new.list", "r");
	
	fscanf(rw, "%3d %2d %2d ", &puzzNum, &maxLength, &maxCat);
	list0 = malloc(puzzNum*sizeof(puzzle));
	list1 = malloc(puzzNum*sizeof(puzzle));
	
	for(i=0; i<puzzNum; i++) {
		fscanf(rw, "%2d %2d ", &list0[i].cat, &list0[i].length);
		if(list0[i].length>maxLength) {
			maxLength=list0[i].length;
			printf("max length is %d\n", maxLength);
		}
		list0[i].words = malloc(list0[i].length*sizeof(char));
		for(j=0; j<list0[i].length; j++) {
			fscanf(rw, "%c", &list0[i].words[j]);
		}
	}
	
	int count=0, catcount, catstart=0;
	
	for(i=1; i<=maxLength; i++) {
		for(j=0; j<puzzNum; j++) {
			if(list0[j].length==i) {
				list1[count]=list0[j];
				++count;
			}
		}
	}
	
	count=0;
	for(i=0; i<maxCat; i++) {
		for(j=0; j<puzzNum; j++) {
			if(list1[j].cat == i) {
				list0[count]=list1[j];
				++count;
			}
		}
	}
	
	fclose(rw);
	rw = fopen("newlist", "w");
	fprintf(rw, "%3d %2d %2d", puzzNum, maxLength, maxCat);
	for(i=0; i<puzzNum; i++) {
		fprintf(rw, "\n%2d %2d ", list0[i].cat, list0[i].length);
		fprintf(rw, "%s", list0[i].words);
	}
	
	return 0;
}

void sample(puzzle* list, int puzzCount) {
	int i=0, j, minj = 0;
	printf("#%d is %s (%d)\n", 0, list[0].words, list[0].length);
	printf("#%d is %s (%d)\n", puzzCount-1, list[puzzCount-1].words, list[puzzCount-1].length);
	while(i<20) {
		j=rand()%puzzCount;
		if(j>minj) {
			printf("#%d is %s (%d)\n", j, list[j].words, list[j].length);
			++i;
			minj=j;
		}
	}
}
