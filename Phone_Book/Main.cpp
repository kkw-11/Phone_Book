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
			if (strcmp(value.name, list[i].name) < 0)//strcmp 뒤 매개변수가 크면 -1 반환
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
		printf("이름, 전화번호 입력:\n");
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
		printf("찾는 이름 입력:");
		scanf_s("%s", name, 20);

		for (int i = 0; i < perSize; ++i) {
			if (strcmp(name, perArray[i].name) == 0) { //strcmp는 두 문자열이 같으면 0 반환
				printf("[%d] : name:%s, phone:%s\n", i,
					perArray[i].name, perArray[i].phone);
			}
		}

	}
	void RemovePerson() {
		char name[20];
		printf("삭제 이름 입력:");
		scanf_s("%s", name, 20);

		for (int i = 0; i < perSize; ++i) {
			if (strcmp(name, perArray[i].name) == 0) { //strcmp는 두 문자열이 같으면 0 반환
				for (int j = i; j < perSize - 1; ++j)
					perArray[j] = perArray[j + 1];
				--perSize;
			}
		}
	}
	void SortPerson() {

		Sort(perArray, perSize);

	}
	PersonArray(int cap = 100) { //생성자 초기화를 위해 자동 호출, 클래스의 이름과 동일하게 만들어줌 // 지정안하면 100개  지정하면 지정한 개수만큼

		perArray = new Person[cap];
		perSize = 0;
		perCapacity = cap;

	}
	~PersonArray() { //소멸자 main함수 종료시 자동 호출
		delete[] perArray;
	}
};

/////////////////////////////////////////////
void Menu() {


	printf("\n\n=====================\n");
	printf("1. 전화번호 등록\n");
	printf("2. 전화번호 출력\n");
	printf("3. 전화번호 검색\n");
	printf("4. 전화번호 삭제\n");
	printf("5. 전화번호 정렬\n");
	printf("0. 프로그램 종료\n");
	printf("=====================\n\n");
}
int main() {
	bool bRun = true;
	PersonArray pArray(10000);

	while (bRun) {

		Menu();
		switch (_getch()) { //_getch() 비쥬얼스튜디오 내장함수
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