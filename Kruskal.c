/*
http://web.skhu.ac.kr/~cyberci/program/view/view_19.htm
http://eehoeskrap.tistory.com/39

1. 크루스칼 알고리즘은 각 단계에서 가중치가 작은 간선부터 선택한다.
2. 선택하는 과정에서 사이클이 만들어질 경우 그 간선은 선택하지 않는다.
3. n개의 정점을 가질 때, 반드시 n-1개의 간선을 가지게 되어있으므로 간선이 n-1개가 되면 종료하면 된다.
*/

#include <stdio.h>
#include <malloc.h>

// 함수 선언
void Kruskal(int n, int *MST, int *F[2], int edge_count);
void Sort(int *MST, int *sortededge[2], int edge_count);
void PrintKruskal(int n, int *F[2]);

int *weight; // 가중치

//상수 값
const int SIZE = 5;
const int MST_ARR_SIZE = 25;  // si

int main(void)
{
  int n = SIZE; // n * n 행렬
  int edge_count = 7;

  int MST[25]=
  {
    0,1,2,0,0,
    1,0,2,3,0,
    2,2,0,6,4,
    0,3,6,0,1,
    0,0,4,1,0,
  };

  int *F[2]; // 간선을 저장

  F[0]=(int *)malloc(sizeof(int)*edge_count);
  F[1]=(int *)malloc(sizeof(int)*edge_count);

  Kruskal(n, MST, F, edge_count);
  PrintKruskal(n, F);
  return 0;
}

void PrintKruskal(int n, int *F[2]){
  printf("\n<kruskal's result>\n");
  int i;
  for(i=0; i < n-1; i++)
  {
    printf("%d -> (V%d , V%d)\n",i+1,F[0][i],F[1][i]);
  }
}


void Kruskal(int n, int *MST, int *F[2], int edge_count)
{
  int *sortededge[2];
  int e1, e2; //선택된 2개의 간선
  int i, j;
  int num_selected=0;
  int is_cycle; //서사이클인지 확인하는 flag

  sortededge[0]=(int *)malloc(sizeof(int)*edge_count);
  sortededge[1]=(int *)malloc(sizeof(int)*edge_count);

  Sort(MST, sortededge, edge_count); //간선 정렬

  printf("<Check kruskal is cyclic>\n");
  //다음 간선을 이미 선택된 간선들의 집합에
  //추가하때 사이클이 생성하는 지를 체크 하는것입니다.

  for( i=0; i < edge_count; i++ )
  {
    e1=sortededge[0][i];
    e2=sortededge[1][i]; //사이클인지 확인합니다.
    is_cycle=0; //사이클이면 =1, 사이클아니면 =0

    for( j=0;j<num_selected;j++)
    {
      if ((MST[e1*5+F[0][j]])>0&&(MST[e2*5+F[0][j]]>0))
      {
        is_cycle=1;
        break;
      }

    }

    if (is_cycle==0)
    {
      F[0][num_selected]=e1;
      F[1][num_selected]=e2;
      num_selected++;

      printf("(V%d, V%d) select\n",e1,e2);

    }
    else //(is_cycle==1)
    {
      F[0][num_selected]=e1;
      F[1][num_selected]=e2;
      num_selected++;

      printf("(V%d, V%d) already selected. cycle!! \n",e1,e2);
    }

  }
}


void Sort(int *MST,int *sortededge[2],int edge_count)
{
  int j,k;

  int num=0;
  int start, end;
  int tmp;

  weight = (int *)malloc(sizeof(int)*edge_count);
  //먼저 변을 구합니다.
  for( j=0; j<SIZE; j++)
  {
    for( k=j; k<SIZE; k++)
    {
      if (MST[j*SIZE+k]>0)
      {
        sortededge[0][num]=j;
        sortededge[1][num]=k;
        weight[num]=MST[j*SIZE+k];
        num++;
      }
    }
  }

  for(j=0; j<edge_count-1; j++)
  {
    for(k=0; k<edge_count-1; k++)
    {
      if (weight[k]>weight[k+1])
      {
        tmp = weight[k];
        weight[k] = weight[k+1];
        weight[k+1] = tmp;

        start=sortededge[0][k];
        sortededge[0][k] = sortededge[0][k+1];
        sortededge[0][k+1] = start;

        end=sortededge[1][k];

        sortededge[1][k] = sortededge[1][k+1];
        sortededge[1][k+1] = end;
      }
    }
  }
  printf("<sorted result>\n");

  for( j=0; j < edge_count; j++ )
  {
    printf("(V%d , V%d) Weight= %d\n", sortededge[0][j], sortededge[1][j], weight[j]);
  }
  printf("\n");
}
