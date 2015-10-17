/* FIXME: Implement! */
#include <stdio.h>
int maxSubArray(int A[], int n){
	if(n!=0){
		int max_so_far = A[0];
		int curr_max = A[0];
		for(int i=1; i<n; i++){
			curr_max = (A[i]>curr_max+A[i])? A[i] : curr_max+A[i];
			max_so_far = (max_so_far>curr_max)? max_so_far : curr_max;
		}
		return max_so_far;
	}
	else
		return 0;
}

int main()
{
	int in[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int length = sizeof(in) / sizeof(int);
	int out;

	out = maxSubArray(in, length);

	printf("largest sum: %d\n", out);

	return 0;
}
