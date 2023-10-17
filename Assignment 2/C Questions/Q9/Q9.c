// COMP 348 ASSIGNMENT 2 Q9 - C QUESTIONS

// Victoria Solodovnikova 40133650
// Sofiya Taver 40095050
// Laurent Cousineau 26773001

// Write a function in C that receives an array of integers and returns a pointer to its smallest element. The signature of the function as well as a short code on its usage are given in the following:
//
// int* findmin(int arr, int size);
// int arr[] = {1, 4, 5, 6, -1};
// int * m = findmin(arr, 5);
// printf("%d", *m); 
// -1


// ANSWER

int *findmin(int *arr, int size);

int *findmin(int *arr, int size) {
    int *min = arr;
    for (int i = 0; i < size; ++i) {
        if (*arr < *min)
            min = arr;
        arr++;
    }
    return min;
}
