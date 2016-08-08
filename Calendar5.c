#include <stdio.h>
int LeapYear(int a); // 윤년 계산
void Calendar(int year);

// http://prosto.tistory.com/5

int main(void) {
  int year;
  while (1) {
    printf("yyyy ? : ");
    scanf("%d", & year);
    Calendar(year);
  }
  return 0;
}

int LeapYear(int a) {
  if ((0 == a % 4 && 0 != a % 100) || 0 == a % 400) {
    return 1; // 윤년
  }
  return 0; // 평년
}

void Calendar(int year) {
  int i, j, m, l;
  int dayCnt, leapYearCnt = 0;
  int lastMonth, thisMonth = 31;
  int month[12][6][7];
  int totalday[]={31,28,31,30,31,30,31,31,30,31,30,31};

  for (i = 1; i < year; i++)
    leapYearCnt += LeapYear(i);

  lastMonth = (year * 365 + leapYearCnt) % 7; //1월1일 구하기.
  // printf("%d lastMonth\n", lastMonth);
  for (m = 0; m < 12; m++) {
    dayCnt = 0;

    thisMonth = totalday[m];
    if( m == 1 && LeapYear(year) ){
      thisMonth = 29;
    }

    for (i = 0; i < 6; i++) {
      for (j = 0; j < 7; j++) {
        dayCnt++;
        month[m][i][j] = dayCnt - lastMonth;
        if (month[m][i][j] < 1 || month[m][i][j] > thisMonth)
          month[m][i][j] = 0;
      }
    }
    if ((m == 0) | (m == 2) | (m == 4) | (m == 6) | (m == 7) | (m == 9) | (m == 11)) {
      lastMonth = (lastMonth + 31) % 7;
    } else if ((m == 3) | (m == 5) | (m == 8) | (m == 10)) {
      lastMonth = (lastMonth + 30) % 7;
    } else if (m == 1) {
      if (LeapYear(year)) {
        lastMonth = (lastMonth + 29) % 7;
      } else {
        lastMonth = (lastMonth + 28) % 7;
      }
    }
  }

  for (l = 0; l < 4; l++) //4번(3달씩)
  {
    printf("----------%d--------- \t---------%d--------- \t----------%d--------- \n", l * 3 + 1, l * 3 + 2, l * 3 + 3);
    printf("Su Mo Tu We Th Fr Sa \tSu Mo Tu We Th Fr Sa \tSu Mo Tu We Th Fr Sa \n");
    for (m = 0; m < 6; m++) // 6번(한주를 여섯번)
    {
      for (j = 0; j < 3; j++) //3달씩
      {
        for (i = 0; i < 7; i++) //한주(하루 하루~)
        {
          if (month[(l * 3) + j][m][i] == 0) {
            printf("   ");
            continue;
          }
          printf("%2d ", month[(l * 3) + j][m][i]);
        }
        printf("\t");
      }
      printf("\n");
    }
    printf("\n\n");
  }
}
