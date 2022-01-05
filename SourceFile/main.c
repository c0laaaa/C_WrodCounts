#include "head.h"

int main(void){
	char word[MAXWORD];
	struct tnode *root = NULL;

	while(getword(word, MAXWORD) != EOF)
		if(isalpha(word[0]))
			root = addtree(root, word);
	
	treeprint(root);
	return 0;
}