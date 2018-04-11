//그레고리안 알고리즘

#include <iostream>
using namespace std;
typedef enum
{
	MON = 0,
	TUE,
	WEN,
	THU,
	FRI,
	SAT,
	SUN,
}WEEK;

#define PRINT(x) #x
bool check_leapYear(int year)
{
	bool leapYear = false;
	if(year % 4 == 0)
	{
		leapYear = true;
		if(year % 100 == 0)
		{
			leapYear = false;
			if(year % 400 == 0)
			{
				leapYear = true;
			}
		}
	}
	return leapYear;
}

WEEK check_DoomsDay(int year, int refDay)
{
	int tmp = (year % 100); // 0~ 99구하기(2008년이면 8을 구하기)
	int mok = (tmp / 12);  // 12로 나눈 몫 구하기
	int q = (tmp % 12);    // 12로 나눈 나머지 구하기
	int mok2 = (q / 4);     // 구한 나머지를 4로 나눈 몫 구하기
    int output_q = ((mok + q + mok2) % 7);  // mok + q + mok2를 더해서 1주일을 의미하는 7로 나눈 나머지구하기
	
	return (WEEK)((refDay + output_q) % 7); //기준 Doomsday(reqDay)에 output_q를 더하면 내가 입력한 year의 둠스데이가 나온다.
}

WEEK check_ReferenceDay(int year)
{
	year -= (year % 100);
	int q = year % 400; // 금, 수, 화, 일로 반복되는데, 2000(Y-Tue-K)니 400의 배수년도는 무조건 화요일
	switch(q)
	{
		case 0:	return TUE;
		case 100 : return SUN;
		case 200 : return FRI;
		case 300 : return WEN;
		default:
			break;
	}
}
WEEK calculate(int leapYear, int month, int day, int DoomsDay)
{
	int febday = 0;             //2월 날짜
	if(leapYear) febday = 29;   //윤년이면 2월날짜 29일
	else		 febday = 28;   //윤년이 아니면 2월날짜 28일
	int allMonth[12] = {31,febday,31,30,31,30,31,31,30,31,30,31};  //1년 변수

//  내가 입력한 month/day로부터 총 Day를 구하는 logic
	int inputday = 0;
	for(int i = 0; i < month-1; i++)
	{
		inputday += allMonth[i];
	}
	inputday += day;

//  DoomsDay에 여러개가 있으나 그 중 6월6일 DoomsDay를 구하는 logic
	int defaultDay = 0;
	for(int j = 0; j < 5; j++)
	{
		defaultDay += allMonth[j];
	}
	defaultDay += 6;

//  diffDay를 구하는 logic
	int diffDay = abs(defaultDay - inputday) % 7;
	return (WEEK)(DoomsDay + diffDay);
}
int main()
{
	int year,month,day;
	cout<<"년도를 적으시오";
	cin >> year;
	cout<<"월을  적으시오";
	cin >> month;
	cout<<"일을  적으시오";
	cin >> day;

	int ReferenceDay = check_ReferenceDay(year);        //1800,1900,2000,2100년 등 기준데이를 잡는 API
	int DoomsDay = check_DoomsDay(year, ReferenceDay); //기준데이로부터 입력된year의 DoomsDay를 잡는 API
	bool leapYear = check_leapYear(year);              //해당 년도가 윤년인지 확인하는 API

	if(!leapYear && day > 28)                          //방어 코드
	{
		cout<<"존재하지 않는 Day!!"<<endl;
		return 0;
	}
	WEEK output = calculate(leapYear,month,day,DoomsDay);  //계산 API

	cout<< endl << "해당 요일은 :";                        //출력
	switch(output)
	{
		case 0:
			cout<<"월요일"<<endl;
			break;
		case 1:
			cout<<"화요일"<<endl;
			break;
		case 2:
			cout<<"수요일"<<endl;
			break;
		case 3:
			cout<<"목요일"<<endl;
			break;
		case 4:
			cout<<"금요일"<<endl;
			break;
		case 5:
			cout<<"토요일"<<endl;
			break;
		case 6:
			cout<<"일요일"<<endl;
			break;
		default:
			break;
	}
	return 0;
}
