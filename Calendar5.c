#include <stdio.h>
int LeapYear(int a); // 윤년 계산
void Calendar(int year, int line);

// http://prosto.tistory.com/5

static int WEEK = 7;



int main(void) {
  int year;
  int line;
  while (1) {
    printf("yyyy ? : ");
    scanf("%d", & year);

    printf("Line_of_Month ? ( ex) 2, 3, 4): ");
    scanf("%d", & line);
    // if( line !== 2 | line !== 3 | line !== 4){
    //   printf("yyyy ? : ");
    // }
    Calendar(year, line);
  }
  return 0;
}

int LeapYear(int year) {
  if ((0 == year % 4 && 0 != year % 100) || 0 == year % 400) {
    return 1; // 윤년
  }
  return 0; // 평년
}

void Calendar(int year, int line) {
  int i, j, m, l;
  int dayCnt, leapYearCnt = 0;
  int lastMonth, thisMonth;
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
      for (j = 0; j < WEEK; j++) {
        dayCnt++;
        month[m][i][j] = dayCnt - lastMonth;
        if (month[m][i][j] < 1 || month[m][i][j] > thisMonth)
          month[m][i][j] = 0;

      }
    }

    if ((m == 0) | (m == 2) | (m == 4) | (m == 6) | (m == 7) | (m == 9) | (m == 11)) {
      lastMonth = (lastMonth + 31) % WEEK;
    } else if ((m == 3) | (m == 5) | (m == 8) | (m == 10)) {
      lastMonth = (lastMonth + 30) % WEEK;
    } else if (m == 1) {
      if (LeapYear(year)) {
        lastMonth = (lastMonth + 29) % WEEK;
      } else {
        lastMonth = (lastMonth + 28) % WEEK;
      }
    }

  }

  int BASE = 12, LINE_OF_MONTH = line, LINE = BASE / LINE_OF_MONTH;


  for (l = 0; l < LINE; l++) //4번(3달씩)
  {
    switch (LINE_OF_MONTH) {
      case 2: printf("----------%d--------- \t---------%d--------- \n", l * LINE_OF_MONTH + 1, l * LINE_OF_MONTH + 2);   printf("Su Mo Tu We Th Fr Sa \tSu Mo Tu We Th Fr Sa \n"); break;
      case 3: printf("----------%d--------- \t---------%d--------- \t---------%d---------\n", l * LINE_OF_MONTH + 1, l * LINE_OF_MONTH + 2, l * LINE_OF_MONTH + 3);   printf("Su Mo Tu We Th Fr Sa \tSu Mo Tu We Th Fr Sa \tSu Mo Tu We Th Fr Sa \n"); break;
      case 4: printf("----------%d--------- \t---------%d--------- \t----------%d--------- \t----------%d---------\n", l * 4 + 1, l * 4 + 2, l * 4 + 3, l * 4 + 4); printf("Su Mo Tu We Th Fr Sa \tSu Mo Tu We Th Fr Sa \tSu Mo Tu We Th Fr Sa \tSu Mo Tu We Th Fr Sa\n"); break;
      default: break;
    };
    // printf("----------%d--------- \t---------%d--------- \t----------%d--------- \t----------%d---------\n", l * 4 + 1, l * 4 + 2, l * 4 + 3, l * 4 + 4);
    // printf("Su Mo Tu We Th Fr Sa \tSu Mo Tu We Th Fr Sa \tSu Mo Tu We Th Fr Sa \tSu Mo Tu We Th Fr Sa\n");

    // printf("----------%d--------- \t---------%d--------- \n", l * LINE_OF_MONTH + 1, l * LINE_OF_MONTH + 2);
    // printf("Su Mo Tu We Th Fr Sa \tSu Mo Tu We Th Fr Sa \n");

    for (m = 0; m < 6; m++) // 6번(한주를 여섯번)
    {
      for (j = 0; j < LINE_OF_MONTH; j++) //3달씩
      {
        for (i = 0; i < WEEK; i++) //한주(하루 하루~)
        {
          int s = (l * LINE_OF_MONTH) + j;
          if (month[s][m][i] == 0) {
            printf("   ");
          }else
            printf("%2d ", month[s][m][i]);
        }
        printf("\t");
      }
      printf("\n");
    }
    printf("\n\n");
  }

}
