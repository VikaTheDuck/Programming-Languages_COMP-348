#include <stdio.h>
#include <stdlib.h>

int findmax(int arr[],int size){

   int max=0;

   for(int i=1;i<size;i++){
       if(arr[i]>arr[max])
           max=i;
   }
   return max;
}

int findmin(int arr[],int size){

   int min=0;

   for(int i=0;i<size;++i){
       if(arr[i]<arr[min])
           min=i;
   }
   return min;
}

int main()
{
    int n;
    int *values;
    int(*ptr)(int [], int) = &findmax;

    printf("Enter the number of integers in the array:");
    scanf("%d",&n);
    values= (int*)malloc(n*sizeof(int));
    printf("\nEnter %d", n);
    printf(" integers: ");
    for(int i=0;i<n;i++)
        scanf("%d",&values[i]);

    printf("\nBefore sorting the array: \n");
    for( int j = 0 ; j < n; j++ ) {
      printf("%d ", values[j]);
    }

    selectionsort(values, n);
    printf("\n\nAfter sorting the array in ascending order: \n");
    for(int i = 0; i < n; i++) printf("%d ", values[i]);

    descendingorder(values, n,ptr);
    printf("\n\nAfter sorting the array in descending order: \n");
    for(int i = 0; i < n; i++) printf("%d ", values[i]);

    int min = findmin(values, n);
    printf("\n\nThe minimum is:  %d", values[min]);

    int max = findmax(values, n);
    printf("\n\nThe maximum is:  %d", values[max]);

    printAverage(values, n);

    printsd(values, n);


}

void selectionsort(int arr[],int size){

   for(int i=0; i<size; i++){
       int min=findmin(arr+i,size-i);
       int temp=arr[i];
       arr[i]=arr[i+min];
       arr[i+min]=temp;
   }
}

void descendingorder(int arr[],int size,int (*ptr)(int [], int )){

   for(int i=0; i<size; i++){
       int max=ptr(arr+i,size-i);
       int temp=arr[i];
       arr[i]=arr[i+max];
       arr[i+max]=temp;
   }
}

void printAverage(int arr[],int size){
    float total=0;

    for(int i=0; i<size; i++){
        total=total+arr[i];
    }

    printf("\n\nThe average is:  %f", total/size);
}

void printsd(int arr[], int size) {
    float sum = 0.0;
    float mean;
    float sd = 0.0;

    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    mean = sum / size;

    for (int i = 0; i < size; ++i){
        sd += pow(arr[i] - mean, 2);
    }
    printf("\n\nThe standard deviation is:  %f", sqrt(sd / (size-1)));
}
