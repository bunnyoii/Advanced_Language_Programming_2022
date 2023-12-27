#include <iostream>
#include <fstream>
using namespace std;

typedef struct StudentInformation {
	int no;			// ѧ�ţ�������0��ͷ
	char name[9];	// ��������ĸ�����
	int score;		// �ɼ���������С����
	int rank;		// ����
}SI;

void bubble_sort(int grade[], int n, char number[][8], char name[][9])
{
	int i, j, t;
	char Tnum[1][128] = { 0 };
	char Tname[1][128] = { 0 };
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - (i + 1); j++)
			if (strcmp(number[j], number[j + 1]) < 0) {
				t = grade[j];
				strcpy(Tnum[0], number[j]);
				strcpy(Tname[0], name[j]);

				grade[j] = grade[j + 1];
				strcpy(number[j], number[j + 1]);
				strcpy(name[j], name[j + 1]);

				grade[j + 1] = t;
				strcpy(number[j + 1], Tnum[0]);
				strcpy(name[j + 1], Tname[0]);
			}
}

int main()
{
	ifstream StuList("student.txt");
	if (!StuList.is_open()) {
		cout << "���ļ�ʧ�ܣ�" << endl;
		return -1;
	}

	SI* student = nullptr;
	int arraysize = 0;

	SI StudentInformation;
	int currentIndex = 0;
	while (StuList >> StudentInformation.no >> StudentInformation.name >>
		StudentInformation.score >> StudentInformation.rank) {
		++arraysize;

		SI* newArray = new(nothrow) SI[arraysize];

		for (int i = 0; i < currentIndex; i++)
			newArray[i] = student[i];
		newArray[currentIndex] = StudentInformation;

		delete[] student;

		student = newArray;
		++currentIndex;
	}
	StuList.close();
	return 0;
}