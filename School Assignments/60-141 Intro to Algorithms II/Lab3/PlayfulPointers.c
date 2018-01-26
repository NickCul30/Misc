
#include <stdio.h>
#include <stdbool.h>

void swap(float *X, float *Y);
void sort(float a[], int l);

int main(){
	/*float N1 = 1.2, N2 = 4.3;
	float *fPtr, *fPtr2;
	fPtr = &N1;
	printf("%f\n", *fPtr);
	*fPtr = N2;
	printf("%f\n", *fPtr);*/

	/*float a[] = {1,5,2,6,3,88,0};
	for(int i=0;i<7;i++){
		printf("%f ", a[i]);
	}
	printf("\n");
	sort(a,7);

	for(int i=0;i<7;i++){
		printf("%f ", a[i]);
	}*/


	float a = 1,b = 2;
	printf("%f %f", a,b);
	swap(&a,&b);
	printf("\n%f %f", a,b);
	return 0;
}

void sort(float a[], int l){
	bool sorting = true;
	while(sorting){
		sorting = false;
		for(int i=1;i<l;i++){
			if(a[i] < a[i-1]){
				float tmp = a[i-1];
				a[i-1] = a[i];
				a[i] = tmp;
				sorting = true;
			}
		}
	}
}

void swap(float *X, float *Y){
	//printf("%p %d %p %d\n", X, *X, Y, *Y);
	float tmp = *Y;
	*Y = *X;
	*X = tmp;
	//printf("%p %d %p %d\n", X, *X, Y, *Y);
}