/* FIXME: Implement! */
#include <stdio.h>
int max(int a, int b){
	return (a>b)? a : b;
}

int _maxSubArray(int A[], int left, int right){
	if(right==left) return A[0];
	int mid = (left+right)/2;
	int left_ans = _maxSubArray(A, left, mid);
	int right_ans = _maxSubArray(A, mid+1, right);
	int leftmax = A[mid];
	int rightmax = A[mid+1];
	int tmp = 0;
	for(int i=mid; i>=left; i--){
		tmp = tmp + A[i];
		if(tmp>leftmax) leftmax=tmp;
	}
	tmp = 0;
	for(int i=mid+1; i<=right; i++){
		tmp = tmp + A[i];
		if(tmp>rightmax) rightmax=tmp;
	}
	return max(max(left_ans, right_ans), leftmax+rightmax);
}

int maxSubArray(int A[], int n){
	if(n==0) return 0;
	return _maxSubArray(A, 0, n-1);
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
