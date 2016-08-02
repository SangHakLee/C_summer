#include <stdio.h>

void Heapify(int *array);
void HeapSort(int *array);

#define LEFT(index) ( (index*2) + 1 )
#define RIGHT(index) ( (index*2) + 2 )
#define PARENT(index) ( (index/2) )
#define SWAP(a, b) (
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
)

int main(void)
{
  int array[9] = {8,7,1,2,6,9,4,3,5};
  // int size = sizeof(array);
  int size = 9;
  printf("%d\n", size);
  return 0;
}

void Heapify(int *array, size){
  int i, now;
  int left, right; // index 값
  int parent; // index
  for( i = 0 ; i < size ; i++ ){
    now = i; // now : 0
    left = LEFT(now); // left : 1

    while( size > 0 ){
      parent = PARENT(now);

      if( array[left] > array[parent] ){ // 바꾸는 경우
        SWAP( array[left], array[parent] ) ;
        now = parent;
      }



    }


  }
}

void HeapSort(int *array){

}
