#include<stdio.h>

void mergesort(int *num, int start,int end);
void merge(int *num, int start,int mid,int end);
void show(int *num, int size);
void print(int *num );

#define SWAP(a, b) ( int tmp; tmp = a; a = b; b = tmp; )

static int g = 0;
const SIZE = 3;

int main(void){


// int array[10]={30,20,40,35,5,50,45,10,25,15};
// int array[5]={10,8,6,5,4};
int array[3]={10,8,6};
int size=3;
mergesort(array,0,size-1);


}
void mergesort(int *num,int start,int end){
  int mid=(start+end)/2;
  if(start<end){
    mergesort(num,start,mid);
    mergesort(num,mid+1,end);
    merge(num,start,mid,end);
    //printf("start:%d\n",start);
    //printf("mid:%d\n",mid);
    //printf("end:%d\n",end);

  }
}

void merge(int *num, int start,int mid,int end){
  int i=start;
  int j;
  int k;

  while( i < end )
   {
     printf("####################");
     printf("\n G : %d", g++);
     printf("\n start : %d", start);
     printf("\n mid : %d", mid);
     printf("\n end : %d", end);
     printf("\n####################\n");

     print(num);

     if( num[i] > num[mid] ) {
      //  SWAP( num[i], num[mid] );
     }
     i++;
   }

}


void print(int *num){
  printf("\nPrint\n");
  int i;
  for(i=0; i < 3; i++)
  {
    printf("%2d", num[i]);
  }
  printf("\n\n");

}
