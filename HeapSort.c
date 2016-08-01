#include <stdio.h>

// 함수 선언
void InitHeap(int *base, int n);
void MakeHeap(int *base, int n);
void HeapSort(int *base, int n);
void PrintInput(int *arr, int n);
int GetMaxIndex(int *base, int n, int now);

// 상수 값
const int SIZE = 10; // 정렬데이터 크기

// 매크로 함수
#define LEFT_CHILD(x)    (2*x + 1)
#define RIGHT_CHILD(x) (2*x + 2)
#define PARENT(x)        ((x-1)/2)
#define SWAP(a,b)  {int tmp; tmp = a; a=b; b=tmp;}//a와 b를 교환


/*
http://ehclub.net/76
http://createcode.tistory.com/entry/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%ED%9E%99-%EA%B5%AC%EC%A1%B0-%ED%9E%99-%EC%A0%95%EB%A0%AC

1. 먼저 최대힙을 구성한다. InitHeap
2. 최대힙의 최상위루트값(최대값)을 수열의 맨뒤로 보내고 수열의 길이를 하나 줄인다. n--
3. 과정2로 인해 수열이 변경되었으므로, 변경된 수열에 대해서 다시 최대힙을 구성한다. MakeHeap
4. 과정1 ~ 과정3 을 수열의 길이가 1이 될 때 까지 반복한다.
*/

int main(void)
{
    int arr[SIZE] = { 9,4,3,10,5,8,7,6,2,1 };
    printf("%s : ", "초기 배열 값 ");
    PrintInput(arr, SIZE);

    HeapSort(arr, SIZE);

    printf("%s : ", "정렬 후 배열 값 ");
    PrintInput(arr, SIZE);
    return 0;
}

// 힙 정렬 수행 부분
void HeapSort(int *base, int n)
{
    // printf("초기 힙 생성 과정\n");
    InitHeap(base, n);
    n--;
    SWAP(base[0], base[n]); // 힘 정렬에서 마지막 값을 맨위로


    // printf("정렬 과정\n");
    while (n > 1) // n이 끝에 갈 때 까지
    {
        MakeHeap(base, n); // 다시 힙 구조 만들고
        // PrintInput(base, n + 1);
        n--; // 마지막 값 떼고
        SWAP(base[0], base[n]); // 루트랑 바꾸고
    }
    // PrintInput(base, n + 1);
}

// 힙 구조 만들기
void InitHeap(int *base, int n)
{
    int parent = 0;
    int now;
    int i;
    for (i = 1; i < n; i++)//순차적으로 힙에 구성
    {
        now = i;
        while (now > 0)//now의 인덱스가 0이 아니면(힙의 루트가 아니면)
        {
            parent = PARENT(now);//부모 인덱스 구함
            if (base[now]>base[parent])//부모보다 더 크면
            {
                SWAP(base[now], base[parent]);//부모와 교환
                now = parent;//인덱스를 부모로 설정
            }
            else//아니면 자리를 찾은 것임
            {
                break;
            }
        }
        // PrintInput(base, i + 1); // 힙 구조 만드는 과정
    }
}


// 다시 힙을 만드는 과정
void MakeHeap(int *base, int n)
{
    int now = 0; // 현재 인덱스
    int max = 0;
    //루트에 있는 요소를 힙 트리에 맞게 자리를 찾는 과정
    while ( LEFT_CHILD(now) < n)//왼쪽 자식이 있다면
    {
        int max = GetMaxIndex(base, n, now);//now와 왼쪽, 오른쪽 자식 중에 큰 값의 위치 찾음
        if (max == now)//max와 now가 같으면
        {
            break;//자리를 찾은 것임
        }
        SWAP(base[max], base[now]);//now와 큰 값의 자리 교환
        now = max;//큰 값의 위치를 now로 설정
    }
}


int GetMaxIndex(int *base, int n, int now)
{
    int left_child = LEFT_CHILD(now);//왼쪽 자식
    int right_child = RIGHT_CHILD(now);//오른쪽 자식

    if (right_child >= n) // 오른쪽 자식이 없을 때, max 보단 크거나 같다면
    {
        if (base[now] < base[left_child])
        {
            return left_child; // 왼쪽 값이 더 크다
        }
        return now;
    }
    if (base[left_child] < base[right_child])
    {
        return right_child;
    }
    return left_child;
}
void PrintInput(int *arr, int n)
{
    for (int i = 0; i<n; i++)
    {
        printf("%2d ", arr[i]);
    }
    printf("\n");
}
