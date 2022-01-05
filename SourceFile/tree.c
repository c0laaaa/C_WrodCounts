#include "head.h"

struct tnode *addtree(struct tnode *p, char *word){
	int cond;

	if(p == NULL){
		p = talloc();
		p->word = strdup(word);
		p->count = 1;
		p->left = NULL;
		p->right = NULL;
	}
	else if((cond = strcmp(word, p->word)) == 0)
		p->count++;
	else if(cond < 0)
		p->left = addtree(p->left, word);
	else
		p->right = addtree(p->right, word);

	return p;
}

struct tnode *talloc(void){
	return (struct tnode *) malloc(sizeof(struct tnode));
}

void treeprint(struct tnode *p){
	if(p != NULL){
		treeprint(p->left);
		printf("%4d, %s\n", p->count, p->word);
		treeprint(p->right);
	}
}