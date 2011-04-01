#include<wof.h>

int main() {
	int i;
	int maxLength, addNum=0, puzzNum, catNum, loop, cat, length;
	char* string;
	FILE* fp = fopen("newlist", "r");
	fscanf(fp, "%3d %2d %2d", &puzzNum, &maxLength, &catNum);
	
	fp = fopen("newlist", "a");
	
	printf("Add a puzzle? ");
	scanf("%d", &loop);
	getchar();
	string = malloc(sizeof(char));
	
	while(loop) {
		string=realloc(string, sizeof(char));
		scanf("%c", &string[0]);
		length=0;
		while(string[length]!=10) {
			string = realloc(string, (length+2) * sizeof(char));
			scanf("%c", &string[++length]);
		}
		for(i=0; i<length; i++) {
			if(string[i]>96) {
				if(string[i]<123) {
					string[i] -= 32;
				}
			}
		}
		if(length>maxLength) {
			maxLength = length;
		}
		printf("%sWhat category for this? ", string);		
		scanf("%d", &cat);
		if(cat >= catNum) {
			catNum = cat+1;
		}
		while(cat>99) {
			printf("%sWhat category for this? ", string);		
			scanf("%d", &cat);
			if(cat >= catNum) {
				catNum = cat+1;
			}
			printf("Too high...\n");
		}
		fprintf(fp, "%2d %2d ",cat, length);
		for(i=0; i<length; i++) {
			fprintf(fp, "%c", string[i]);
		}
		fprintf(fp, "\n");
		++addNum;
		printf("Another? ");
		scanf("%d", &loop);
		getchar();
	}
	
	fp = fopen("newlist", "r+");
	
	puzzNum += addNum;
	
	fprintf(fp, "%3d %2d %2d\n", puzzNum, maxLength, catNum);
	
	return 0;
}
