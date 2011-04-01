#include<wof.h>

int main() {
	int i;
	int maxLength, addNum=0, puzzNum, catNum, loop, cat, length;
	char* string;
	FILE* old = fopen("newlist", "r");
	fscanf(old, "%3d %2d %2d", &puzzNum, &maxLength, &catNum);
	
	fclose(old);
	old = fopen("newlist", "a");
	
	FILE* new = fopen("puzz.in", "r");
	string = malloc(sizeof(char));
	while(!feof(new)) {
		fscanf(new, "%d ", &cat);
		if(cat >= catNum) {
			catNum = cat;
		}
		string=realloc(string, sizeof(char));
		fscanf(new, "%c", &string[0]);
		length=1;
		while(string[length-1] != 10) {
			string = realloc(string, (length+1)*sizeof(char) );
			fscanf(new, "%c", &string[length]);
			++length;
		}
		--length;
		for(i=0; i<length; i++) {
			if(string[i]>96) {
				if(string[i]<123) {
					string[i] -= 32;
				}
			}
		}
		fprintf(old, "\n%d %d %s", cat, length, string);
		++puzzNum;
	}
	
	fclose(old);
	old = fopen("newlist", "r+");
	
	fprintf(old, "%3d %2d %2d\n", puzzNum, maxLength, catNum);
	
	return 0;
}
