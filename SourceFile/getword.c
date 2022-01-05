#include "head.h"

int buff[MAXBUFF];
int bp = 0;

int getch(void){
	if(bp > 0)
		return buff[--bp];
	else
		return getchar();
}

void ungetch(int c){
	if(bp < MAXBUFF)
		buff[bp++] = c;
	else
		printf("buff full\n");
}

int getword(char *word, int lim){
	int c;
	char *w = word;

	while(isspace(c = getch()))
		;

	if(c != EOF)
		*w++ = c;
	if(!isalpha(c)){
		*w = '\0';
		return c;
	}

	for(; --lim > 0; w++)
		if(!isalnum(*w = getch())){
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}