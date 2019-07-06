#include <stdio.h>

int main(){

	printf("\nEnter the array size: ");
	int size,i,last=0,has =0,j,total=0;

	scanf("%d",&size);
	
	int arr[size],checked[size],count=0;

	for (i = 0; i < size; ++i){
		printf("Enter element %d: ", i);
		scanf("%d",&arr[i]);
	}

	for (i = 0; i < size; ++i){
		total+=arr[i];

		for(j=0;j<last;j++){
			if(arr[i]==checked[j]){
				has=1;
				break;
			} else has = 0;
			
		}

		if(has==0){

			checked[last++] = arr[i];

			for (int j = 0; j < size; ++j){
				if(arr[i]==arr[j]) {
					count++;
				}
			}

			printf("%d number is repealty %d times.\n", arr[i],count);
		}
		count=0;
	}

	printf("Mean = %f\n", (float) total/size);
	return 0;
}