#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <conio.h>
struct Person {

	char name[20];
	char phone[20];

};

void Swap(Person& a, Person& b) {
	Person t = a;
	a = b;
	b = t;
}

void Sort(Person list[], int size) {

	for (int idx = 1; idx < size; ++idx)
	{

		Person value = list[idx];

		int i;
		for (i = idx - 1; 0 <= i; --i) {
			if (strcmp(value.name, list[i].name) < 0)//strcmp �� �Ű������� ũ�� -1 ��ȯ
				list[i + 1] = list[i];
			else
				break;
		}
		list[i + 1] = value;

	}

}
class PersonArray {
	Person* perArray;
	int perSize;
	int perCapacity;

public:
	void AddPerson() {
		printf("�̸�, ��ȭ��ȣ �Է�:\n");
		scanf_s("%s", perArray[perSize].name, 20);
		scanf_s("%s", perArray[perSize].phone, 20);
		++perSize;
	}
	void PrintPerson() {
		for (int i = 0; i < perSize; ++i) {
			printf("[%d]: name:%s, phone:%s\n", i, perArray[i].name, perArray[i].phone);
		}
	}
	void SearchPerson() {
		char name[20];
		printf("ã�� �̸� �Է�:");
		scanf_s("%s", name, 20);

		for (int i = 0; i < perSize; ++i) {
			if (strcmp(name, perArray[i].name) == 0) { //strcmp�� �� ���ڿ��� ������ 0 ��ȯ
				printf("[%d] : name:%s, phone:%s\n", i,
					perArray[i].name, perArray[i].phone);
			}
		}

	}
	void RemovePerson() {
		char name[20];
		printf("���� �̸� �Է�:");
		scanf_s("%s", name, 20);

		for (int i = 0; i < perSize; ++i) {
			if (strcmp(name, perArray[i].name) == 0) { //strcmp�� �� ���ڿ��� ������ 0 ��ȯ
				for (int j = i; j < perSize - 1; ++j)
					perArray[j] = perArray[j + 1];
				--perSize;
			}
		}
	}
	void SortPerson() {

		Sort(perArray, perSize);

	}
	PersonArray(int cap = 100) { //������ �ʱ�ȭ�� ���� �ڵ� ȣ��, Ŭ������ �̸��� �����ϰ� ������� // �������ϸ� 100��  �����ϸ� ������ ������ŭ

		perArray = new Person[cap];
		perSize = 0;
		perCapacity = cap;

	}
	~PersonArray() { //�Ҹ��� main�Լ� ����� �ڵ� ȣ��
		delete[] perArray;
	}
};

/////////////////////////////////////////////
void Menu() {


	printf("\n\n=====================\n");
	printf("1. ��ȭ��ȣ ���\n");
	printf("2. ��ȭ��ȣ ���\n");
	printf("3. ��ȭ��ȣ �˻�\n");
	printf("4. ��ȭ��ȣ ����\n");
	printf("5. ��ȭ��ȣ ����\n");
	printf("0. ���α׷� ����\n");
	printf("=====================\n\n");
}
int main() {
	bool bRun = true;
	PersonArray pArray(10000);

	while (bRun) {

		Menu();
		switch (_getch()) { //_getch() �����Ʃ��� �����Լ�
		case '1':
			pArray.AddPerson();
			break;
		case '2':
			pArray.PrintPerson();
			break;
		case '3':
			pArray.SearchPerson();
			break;
		case '4':
			pArray.RemovePerson();
			break;
		case '5':
			pArray.SortPerson();
			break;
		case '0':
			bRun = false;
			break;
		}
	}

	system("pause");
}