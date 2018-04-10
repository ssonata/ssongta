#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
static const char base64_set[] =//base 64 setting
{
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', '+', '/'
};
int encode_base64(char *org, char *dst, int len) //무조건 최소공배수인 24비트 기준으로 끊어서 처리해야 한다.
{
	unsigned char	input[3] = {0,0,0};    // 8비트로 들어오니 3개 설정
	unsigned char	output[4] = {0,0,0,0}; // 6비트로 나가야하니 4개 설정
	int		index, i, j;
	char	*p, *plen;

	plen = org + len - 1;   //org는 첫번째 문자값 , len-1은 문자열 길이
	j = 0;

	for( i = 0, p = org; p <= plen; i ++, p ++ ) //첫번째 문자값부터 끝 문자값까지 for루프돌기
	{
		index = i % 3;     //input의 인덱스 값
		input[index] = *p; //input에 문자열 값 넣기(상식적인 행동임)

		if( index == 2 || p == plen )
		{
			//    input[0]         input[1]            input[2]
		    //0 0 0 0 0 0 0 0 | 0 0 0 0 0 0 0 0 |  0 0 0 0 0 0 0 0 
			//0 0 0 0 0 0|0 0   0 0 0 0|0 0 0 0    0 0|0 0 0 0 0 0
			// output[0]    output[1]     output[2]     output[3]

			output[0] = ((input[0] & 0xFC) >> 2);  //11111100 -> 111111을 추출하기
			output[1] = ((input[0] & 0x03) << 4) | ((input[1] & 0xF0) >> 4);
			// 0000 0011의 값 추출해서 <<4 + 111100의 값 추출해서 >> 4
			output[2] = ((input[1] & 0x0F) << 2) | ((input[2] & 0xC0) >> 6);
			output[3] = (input[2] & 0x3F);

			//output[0]~output[3]까지의 값을 base64_set에 넣어줌.
			//참고로 문자가 1개이상 남을 수 있다.
			//input[0]이 무조건 들어가는 output[0]과 output[1]은 그대로 가고
			//output[2]와 output[3]의 경우 index값에 따라 패딩문자'='를
			//넣어준다.
			dst[j ++] = base64_set[output[0]];
			dst[j ++] = base64_set[output[1]];
			dst[j ++] = index == 0? '=': base64_set[output[2]];
			dst[j ++] = index < 2? '=': base64_set[output[3]];

			input[0] = input[1] = input[2] = 0;
		}
	}
	
	dst[j] = '\0';
	return	j;
}

int main()
{
	char src[24];
	char dst[24];

	memcpy(src, "song", 4);
	encode_base64(src, dst, 4);
	cout<<dst<<endl;
}
