/* FIXME: Implement! */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct __node {
    int value;
    struct __node *left;
    struct __node *right;
} TreeNode;

void flatten(TreeNode *root);

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

int main()
{
	struct timespec start, end;
	double cpu_time;
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

	clock_gettime(CLOCK_REALTIME, &start);
	flatten(root);
	clock_gettime(CLOCK_REALTIME, &end);

	cpu_time = diff_in_second(start, end);
	printf("execution time of flatten() : %lf sec\n", cpu_time);

	for(int i=0; i<6; i++){
		free(node[i]);
	}

	return 0;
}

void flatten(TreeNode *root){
	TreeNode *tmp;
	while(root){
		if(root->left){
			tmp = root->left;
			while(tmp->right) tmp=tmp->right;
			tmp->right = root->right;
			root->right = root->left;
			root->left = NULL;
		}
		root = root->right;
	}
}
