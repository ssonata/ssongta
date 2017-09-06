#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>A;								//원래 벡터
void counting_sort(vector<int> &B, vector<int> &C, int maxvalue)
{
	for(int i = 0; i < A.size(); i++)		// 이렇게 하면 C벡터에 A벡터의 counting된 수가 들어가게 된다.
	{
		C[A[i] - 1] += 1;
	}
	for(int j = 1; j < maxvalue; j++)		// C벡터의 값은 A벡터 값을 정렬한 누적값이이다.
	{
		C[j] += C[j-1];
	}
	for(int k = A.size() - 1; k >= 0; k--)
	{
		B[C[A[k] - 1] - 1] = A[k];                 //C벡터(누적값)을 새로운 B벡터에 A벡터 실제값을 넣는다.
		                                          //A배열에서 가장 큰 값을
												  //크기로 갖는 걸 가지고
												  //배열을 만들었으니, B와
												  //C배열을 모두 -1씩 해준다.
		C[A[k] - 1] -= 1;                      //counting배열의 값을 -1씩 해준다.
	}
	return;
}
int main()
{
	A.push_back(3);
	A.push_back(6);
	A.push_back(4);
	A.push_back(1);
	A.push_back(3);
	A.push_back(4);
	A.push_back(1);
	A.push_back(4);
 
	int maxvalue = *max_element(A.begin(),A.end()); //A배열에서 가장 큰 값을 크기로 갖는 C벡터를 생성한다.
	vector<int>B(A.size(), 0);				//정렬한 벡터
	vector<int>C(maxvalue, 0);              //counting sort 벡터

	counting_sort(B, C, maxvalue);

	vector<int>::iterator iter = B.begin();	//출력 결과
	for(;iter != B.end(); ++iter)
		cout<<*iter<<" ";
	cout<<endl;
	return 0;
}
