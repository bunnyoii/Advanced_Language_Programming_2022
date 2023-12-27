/* 2251730 ��07 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

/* �˴�������ӱ���Ķ����������������ȫ�ֱ����� */
class Teacher;
/* Student ��Ķ��壨��Ա��������������ʵ�֣� */
class Student {
private:
	int num;	//ѧ��
	char name[16];	//����
	char sex;	//�Ա�ֻ���� F/M ���֣���Сд������
	char addr[64];	//��ͥסַ
	//˽�в��ֲ���������κ�����
public:
	Student();
	Student(const int num1, const char* name1, const char sex1, const char* addr1);
	friend ostream& operator<<(ostream& out, const Student& stu);
	friend Teacher;
	//���в��ֲ���������κ�����
};

/* ----����Student���Ա��������Ԫ����������ʵ��---- */
Student::Student()
{
	num = 1950000;
	sscanf("<ѧ��S>", "%s", name);
	sex = 'M';
	sscanf("��ƽ·1239��", "%s", addr);
}

Student::Student(const int num1, const char* name1, const char sex1, const char* addr1)
{
	num = num1;
	sscanf(name1, "%s", name);
	sex = sex1;
	sscanf(addr1, "%s", addr);
}

ostream& operator<<(ostream& out, const Student& stu)
{
	out << stu.num << " " << stu.name << " " << stu.sex << " " << stu.addr;
	return out;
}
/* Teacher ��Ķ��壨��Ա��������������ʵ�֣� */
class Teacher {
private:
	int num;	//����
	char name[16];	//����
	char sex;	//�Ա�ֻ���� F/M ���֣���Сд������
	char addr[64];	//��ͥסַ
	//˽�в��ֲ���������κ�����
public:
	Teacher();
	Teacher(const int num1, const char* name1, const char sex1, const char* addr1);
	friend ostream& operator<<(ostream& out, const Teacher& te);
	//���в���������ӳ�Ա����������ʵ�֣���������������ݳ�Ա����Ԫ����
	Teacher operator=(const Student& a);
	operator Student();
};

/* ----����Teacher���Ա��������Ԫ����������ʵ��---- */
Teacher::Teacher()
{
	//ȱʡֵ - ���ţ�19000 ������<��ʦT> �Ա�M ��ַ����ƽ·1239���Ժ�¥
	num = 19000;
	sscanf("<��ʦT>", "%s", name);
	sex = 'M';
	sscanf("��ƽ·1239���Ժ�¥", "%s", addr);
}

Teacher::Teacher(const int num1, const char* name1, const char sex1, const char* addr1)
{
	num = num1;
	sscanf(name1, "%s", name);
	sex = sex1;
	sscanf(addr1, "%s", addr);
}

Teacher::operator Student()
{
	Student stu;
	stu.num = 1950 * 1000 + num - 19000;
	strncpy(stu.name, "ѧ��", 4);
	for (int i = 4; i < 6; i++)
		stu.name[i] = name[i];
	stu.name[6] = '\0';
	stu.sex = sex;
	strcpy(stu.addr, addr);
	strcat(stu.addr, "101��");
	return stu;
}

Teacher Teacher::operator=(const Student& a)
{
	num = 19 * 1000 + a.num - 1951000;
	strncpy(name, "��ʦ", 4);
	for (int i = 4; i < 6; i++)
		name[i] = a.name[i];
	name[6] = '\0';
	sex = a.sex;
	strcpy(addr, a.addr);
	strcat(addr, "����ѧԺ");
	return *this;
}

ostream& operator<<(ostream& out, const Teacher& te)
{
	out << te.num << " " << te.name << " " << te.sex << " " << te.addr;
	return out;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	Student s1;	//ȱʡֵ - ѧ�ţ�1950000 ������<ѧ��S> �Ա�M ��ַ����ƽ·1239��
	Student s2 = Student(1951234, "ѧ����", 'M', "�ܰ���·4800��");
	Teacher t1;	//ȱʡֵ - ���ţ�19000 ������<��ʦT> �Ա�M ��ַ����ƽ·1239���Ժ�¥
	Teacher t2 = Teacher(19123, "��ʦA", 'F', "�ܰ���·4800�����Ź�");

	/* ��ӡԭʼѧ����Ϣ */
	cout << "ѧ����Ϣ��" << s1 << endl;				//���������"ѧ����Ϣ��1950000 <ѧ��S> M ��ƽ·1239��"
	cout << "ѧ����Ϣ��" << s2 << endl;				//���������"ѧ����Ϣ��1951234 ѧ���� M �ܰ���·4800��"
	cout << endl;

	/* ��ӡԭʼ��ʦ��Ϣ */
	cout << "��ʦ��Ϣ��" << t1 << endl;				//���������"��ʦ��Ϣ��19000 <��ʦT> M ��ƽ·1239���Ժ�¥"
	cout << "��ʦ��Ϣ��" << t2 << endl;				//���������"��ʦ��Ϣ��19123 ��ʦA F �ܰ���·4800�����Ź�"
	cout << endl;

	/* ѧ��ת��ʦ���ԣ�
		ѧ��ת���Ź��򣺹��� = 19 + ѧ�ź���λ
		����ת������ǰ��������ת��Ϊ"��ʦ"�������ַ�����
		�Ա�ת������ԭ��ת��
		��ַת������ԭ��ַ���"����ѧԺ"(�������ַ���Խ��)    */
	t1 = s2;
	cout << "ѧ����Ϣ��" << s2 << endl;				//���������"ѧ����Ϣ��1951234 ѧ���� M �ܰ���·4800��"
	cout << "ת��Ϊ��ʦ����Ϣ��" << t1 << endl;			//���������"ת��Ϊ��ʦ����Ϣ��19234 ��ʦ�� M �ܰ���·4800�ŵ���ѧԺ"
	cout << endl;

	/* ��ʦתѧ�����ԣ�
		����תѧ�Ź���ѧ�� = 1950 + ���ź���λ
		����ת������ǰ��������ת��Ϊ"ѧ��"�������ַ�����
		�Ա�ת������ԭ��ת��
		��ַת������ԭ��ַ���"101��"(�������ַ���Խ��)    */
	s1 = t2;
	cout << "��ʦ��Ϣ��" << t2 << endl;				//���������"��ʦ��Ϣ��19123 ��ʦA F �ܰ���·4800�����Ź�"
	cout << "ת��Ϊѧ������Ϣ��" << s1 << endl;			//���������"ת��Ϊѧ������Ϣ��1950123 ѧ��A F �ܰ���·4800�����Ź�101��"
	cout << endl;

	return 0;
}