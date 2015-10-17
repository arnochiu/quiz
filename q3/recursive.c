/* FIXME: Implement! */
#include <stdlib.h>
typedef struct __node {
    int value;
    struct __node *left;
    struct __node *right;
} TreeNode;

void flatten(TreeNode *root);

int main()
{
	TreeNode *node[6];
	TreeNode *e, *root;

	for(int i=0; i<6; i++){
		node[i] = (TreeNode *) malloc(sizeof(TreeNode));
		e = node[i];
		e->value = i+1;
		e->left = NULL;
		e->right = NULL;
	}

	root = node[0];
	root->left = node[1];
	root->right = node[4];
	root->left->left = node[2];
	root->left->right = node[3];
	root->right->right = node[5];

	flatten(root);

	for(int i=0; i<6; i++){
		free(node[i]);
	}

	return 0;
}

void flatten(TreeNode *root){
	if(!root) return;
	if(root->left) flatten(root->left);
	if(root->right) flatten(root->right);
	TreeNode *tmp = root->right;
	root->right = root->left;
	root->left = NULL;
	while(root->right != NULL)
		root = root->right;
	root->right = tmp;
}
