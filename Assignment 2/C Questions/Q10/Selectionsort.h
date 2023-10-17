// October 2020
// Victoria Solodovnikova 40133650
// Sofiya Taver 40095050
// Laurent Cousineau 26773001

#ifndef SELECTIONSORT_H_INCLUDED
#define SELECTIONSORT_H_INCLUDED

int *findmin(int *, int);

void selectionsort(int arr[],int size){

   for(int i=0; i<size; i++){
       int min;
       int minIndex;
       int* tempmin=findmin(arr+i,size-i);
       min= *tempmin;
        for(int j=i; j<size; j++){
            if(arr[j]== min){
                minIndex=j;
            }
        }

       int temp=arr[i];
       arr[i]=arr[minIndex];
       arr[minIndex]=temp;
   }

}

#endif // SELECTIONSORT_H_INCLUDED
