#include<stdio.h>

// #define SWAP(a, b) (
//   int tmp;
//   tmp = a;
//   a = b;
//   b = tmp;
// )

void mergeSort(int *arr, int start, int end);



int main(void)
{
  int arr[10] = {30,20,40,35,5,50,45,10,25,15};
  int size = 10;

  mergeSort( arr, 0, size-1 );

  return 0;
}


void mergeSort(int *arr, int start, int end)
{
  int mid = (start + end) / 2;
  if( start < end ){
    mergeSort( arr, start, mid );
    mergeSort( arr, mid+1, end );

    merge( arr, start, mid, end );

  }

}

void merge( int *arr, int start, int mid, int end )
{
  int i, j;

  i = start
  // printf(arr)
  while( i < end )
  {
    printf("####################\n");
    printf("\n start : %d", start);
    printf("\n mid : %d", mid);
    printf("\n end : %d", end);
    printf("####################\n");

    // if()
    // {
    //
    // }
    // swap
  }
}
