//2251730 –≈07 ¡ı Á“«
#include<iostream>
using namespace std;

int main()
{
	int light[101] = { 0 };
	int i, j, is_first = 1;
	for (i = 1; i < 101; i++) {
		for (j = i; j < 101; j++) {
			light [j]++;/*if (j % i == 0)
				light[j] += 1;
			else
				;*/
		}
	}
	for (i = 1; i < 101; i++) {
		if (light[i] % 2 ==1) {
			if (is_first)
			{
				cout << i;
				is_first = 0;
			}
			else
				cout << ' ' << i;
		}
	}
	cout << endl;
	return 0;
}