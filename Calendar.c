/*
http://cocooa.tistory.com/175
http://tansanc.tistory.com/entry/C-%EB%8B%AC%EB%A0%A5-%EC%86%8C%EC%8A%A4%EC%BD%94%EB%93%9C
http://wgkang80.tistory.com/156

1. 기본적으로 4의 배수가 되는 해는 윤년.
2. 100의 배수가 되는 해는 윤년이 아니다.
3. 그중에서 또 400의 배수가 되는 해는 윤년.
*/

#include <stdio.h>

#define leapyear(year) ( (year)%4==0 && ( (year)%100!=0 || (year)%400==0 ) ) //윤년판정 매크로

int main(void)

{

  int year, month, day, weekday, i, date;
  int DAYS_OF_MONTH;

  printf("년도 입력 : ");

  scanf("%d", &year);

  printf("월 입력 : ");

  scanf("%d", &month);



  weekday=1;

  for( i=1900; i < year; i++)
  {
    weekday = (weekday+365)%7;

    if( leapyear(i) ) // 윤년일 때
      weekday=(weekday+1)%7;

  }

  for( i=1; i < month; i++) // 1 ~ 입력받은 월까지
  {

    switch(i)
    {
      case 2:
      if( leapyear(year) )
        DAYS_OF_MONTH=29;
      else
        DAYS_OF_MONTH=28;
      break;

      case 4:
      case 6:
      case 9:
      case 11:
      DAYS_OF_MONTH=30;
      break;

      default:
      DAYS_OF_MONTH=31;
      break;
    }

    weekday = (weekday+DAYS_OF_MONTH%7)%7;

  }

  switch (month)
  {
    case 2:
    if( leapyear(year) )
      DAYS_OF_MONTH=29;
    else
      DAYS_OF_MONTH=28;
    break;

    case 4:
    case 6:
    case 9:
    case 11:
    DAYS_OF_MONTH=30;
    break;

    default:
    DAYS_OF_MONTH=31;
    break;

  }

  printf("일 월 화 수 목 금 토\n");
  printf("=====================\n");


  for( day=0; day < weekday; day++ )
    printf("   "); // 비는 요일


  for( date=1; date <= DAYS_OF_MONTH; date++)
  {
    if(day==7) // 1주일 끝
    {
      day=0;
      printf("\n");
    }

    day++;
    printf("%2d ", date);

  }

  return 0;
}
