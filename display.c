#include<stdio.h>
#include<stdlib.h>
#include<wof.h>

char* type(int sort) {
	if (sort==0) {
		return "before & after";
	}
	else if (sort==1) {
		return "computer science";
	}
	else if (sort==2) {
		return "drink";
	}
	else if (sort==3) {
		return "famous person";
	}
	else if (sort==4) {
		return "food";
	}
	else if (sort==5) {
		return "occupation";
	}
	else if (sort==6) {
		return "sports thing";
	}
	else if (sort==7) {
		return "ucf thing";
	}
	else if (sort==8) {
		return "video game";
	}
}

int main() {
	FILE* read = fopen("puzz.list", "r");
	int i, j, num, puzzNum, maxLength, catNum;
	puzzle* list = malloc(sizeof(puzzle));
	
	int hide[125];
	for(i=0; i<125; i++) {
		if(i>64) {
			if(i<91) {
				hide[i]=1;
			}
		}
		else if(i>96) {
			if(i<123) {
				hide[i]=1;
			}
		}
		else {
			hide[i]=0;
		}
	}
	
	/*
	scanf("%d", &list[0].cat);
	getchar();
	list[0].words = realloc(list[0].words, sizeof(char));
	scanf("%c", &list[0].words[0]);
	list[0].length=0;
	for(i=1; list[0].words[i-1] != 10; i++) {
		list[0].words = realloc(list[0].words, i*sizeof(char));
		scanf("%c", &list[0].words[i]);
		list[0].length++;
	}
	list[0].words = realloc(list[0].words, list[0].length*sizeof(char));
	*/
	
	fscanf(read, "%3d %2d %2d", &puzzNum, &maxLength, &catNum);
	printf("There are %d lights in %d groups!!\n", puzzNum, catNum);
	list = malloc(puzzNum*sizeof(puzzle));
	for(i=0; i<puzzNum; i++) {
		fscanf(read, "%2d %2d ", &list[i].cat, &list[i].length);
		list[i].words = malloc(list[i].length*sizeof(char));
		for(j=0; j<list[i].length; j++) {
			fscanf(read, "%c", &list[i].words[j]);			
		}
	}
	
	j=1;
	for(i=0; i<puzzNum; i++) {
		num=rand()%puzzNum;
		for(j=0; j<list[num].length; j++) {
			if(hide[list[num].words[j]]) {
				printf("_"/*, 22*/);
			}
			else {
				printf("%c", list[num].words[j]);
			}
		}
		printf(" is a %s!", type(list[num].cat) );
		getchar();
	}
	return 0;
}
