#include <iostream>
#include <string.h>
using namespace std;
unsigned char S[256]; // S-BOX
unsigned char T[256]; // 임시 벡터
unsigned char C[256]; // 암호문
unsigned char P[256] = "songjong"; // 평문
void key_scheduling(char *key)
{
	int i = 0;
	for(i = 0; i < 256; i++)
	{
		S[i] = i;
	}
	int key_size = strlen(key);
	for(int v = 0, k = 0; v < 256; v++, k++)
	{
		if(k == key_size) k = 0;
		T[v] = key[k];
	}

	int j = 0;
	for(i = 0; i < 256; i++)
	{
		j = (j + S[i] + T[i]) % 256;
		swap(S[i], S[j]);
	}
	return;
}

void pseudo_random_generation(int d)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int t = 0;
	unsigned int Key = 0;
	for(int cnt = 0; cnt < 8; cnt++) //평문길이가 256자라고 가정
	{
		i = (i + 1) % 256;
		j = (j + S[i]) % 256;
		swap(S[i],S[j]);

		t = (S[i] + S[j]) % 256;
		Key = S[t];
	
		if(d == 0) C[cnt] = P[cnt]^S[Key];
		else P[cnt] = C[cnt]^S[Key];
	}
	return;
}
int main()
{
	char key[8];
	memset(C,0,256);
	memset(T,0,256);
	memcpy(key, "SSONGTA",7);

	cout<<"원래 평문"<<endl;
	for(int i = 0; i < 8; i++)
		cout<< P[i];
	cout<<endl;

	key_scheduling(key);  // 키 스케쥴링 알고리즘
	pseudo_random_generation(0);

	cout<<"암호화된 암호문"<<endl;
	for(int i = 0; i < 8; i++)
		cout<< C[i];
	cout<<endl;

	key_scheduling(key);  // 키 스케쥴링 알고리즘
	pseudo_random_generation(1);
	cout<<"복호화된 평 문"<<endl;
	for(int i = 0; i < 8; i++)
		cout<< P[i];
	cout<<endl;
	return 0;
}
