#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;
    if (largest != i) 
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }}
void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i >= 0; i--) 
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }}
void heapifyD(int arr[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2; 
    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapifyD(arr, n, smallest);
    }
}
void heapSortD(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapifyD(arr, N, i);
    for (int i = N - 1; i >= 0; i--) 
    {
        swap(&arr[0], &arr[i]);
        heapifyD(arr, i, 0);
    }}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
    printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    clock_t begin,end;
    int N,i;
    printf("Enter no. of elements: ");
    scanf("%d",&N);
    int arr[N];
    for(i=0;i<N;++i)
    {
        arr[i]=rand();
    }
    begin=clock();
    heapSort(arr,N);
    end=clock();
    printf("\nSorted array is\n");
    printArray(arr, N);
    float TT = (float)(end-begin)/CLOCKS_PER_SEC;
    printf("\nTime taken: %.10f s",TT);
    printf("\nSorting again...");
    begin=clock();
    heapSort(arr,N);
    end=clock();
    float TTS = (float)(end-begin)/CLOCKS_PER_SEC;
    printf("\nTime taken: %.10f s",TTS);
    printf("\nReversing elements...");
    begin=clock();
    heapSortD(arr,N);
    end=clock();
    printf("\nReversed array is\n");
    printArray(arr, N);
    float TTR = (float)(end-begin)/CLOCKS_PER_SEC;
    printf("\nTime taken: %.10f s",TTR);
    return 0;
}
