#include<stdio.h>

// http://proneer.tistory.com/entry/Sort-%ED%95%A9%EB%B3%91-%EC%A0%95%EB%A0%ACMerge-Sort

void mergesort(int *num, int start,int end);
void merge(int *num, int start,int mid,int end);
void show(int *num, int size);
void print(int *num );

void Swap(int *parm_a, int *parm_b)
{
    int ex = *parm_a;
    *parm_a = *parm_b;
    *parm_b = ex;
}

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
  int i = start; // left
  int j = mid+1;
  int k = end;

  int tmp_i = 0;

  int *tmp =(int*)malloc(sizeof(int)*(end-start+1));

  printf("\n i : %d", i);
  printf("\n j : %d", j);
  printf("\n end : %d\n", end);

  // 왼쪽 오른쪽 둘다
  while( i <= j && j <= end ) // end = right
   {
     printf("####################");
     printf("\n G : %d", g++);
     printf("\n start : %d", start);
     printf("\n mid : %d", mid);
     printf("\n end : %d", end);
     printf("\n####################\n");


     if( num[i] < num[j] ) {
       tmp[tmp_i] = num[i];
       i++;
     }else{
       tmp[tmp_i] = num[j];
       j++;
     }
     tmp_i++;

     print(num);
    //  print(tmp);

   }

   free(tmp);

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
