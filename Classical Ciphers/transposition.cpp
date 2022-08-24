/*
Transposition Cipher (��ġ ��ȣ)
:�� ������ ������ � ��Ģ�� ���� �ٲ۰�!
�� ��Ģ�� ��� �����ϴ��İ� ����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BLOCK_SIZE 6
#include <string>


void insertKey(int key[BLOCK_SIZE]) {
	for (int i = 0; i < BLOCK_SIZE; i++) {
		printf("Enter your key array\n (each element must be different from each other) (%d/%d) :", i + 1, BLOCK_SIZE);
		scanf("%d", &key[i]);
		for (int j = 0; j < i; j++) {
			if (key[j] == key[i]) {
				printf("Element duplicated!");
				i--;
			}
		}
	}
}

void padding(char pt[]) {
	int r = strlen(pt) % BLOCK_SIZE; //�е� ������� �κ�
	if (r == 0) {
	}
	else {
		for (int i = 0; i < BLOCK_SIZE - r; i++) {
			strcat(pt, "x");
		} //pt=59 r=5
	}
	printf("After Padding : %s\n", pt);
}

char* encrypt(int key[], char pt[]) {
	//int key[64] = {3,5,1,6,4,2};
	padding(pt);
	char* c=(char*)malloc(sizeof(char)*strlen(pt)+1); //null���� �ڸ� �߰�..
	int BLOCK_NUM = strlen(pt) / BLOCK_SIZE;


	for (int i = 0; i < BLOCK_NUM; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {
			*(c+(i * BLOCK_SIZE + j)) = pt[i * BLOCK_SIZE + (key[j]-1)];
			//key[j]���� 1�� ���� ����? key[j]=3�̸� 3��°��� ���ε�, 
			//��������δ� 4��°�� �ǹǷΤ̤�
			//i=0,j=0 -> c[0]=pt[key[0]]=pt[key[3]]
		}
	}
	c[strlen(pt)] = 0;
	return c;
}

int main() {

	int key[BLOCK_SIZE] = { 0 };
	char p_text[64];
	char* c_text=(char*)malloc(sizeof(char)*64);
	insertKey(key);
	//key array�� ct�� ��ġ�� pt�� ��ġ�� ������Ų��
	//ex) (1,3),(2,5) ...

	printf("Enter a plaintext:");
	scanf("%s", p_text);
	//�Ұ���->c_text(���� ���� �迭�̾��� ��)=encrypt(key, p_text);(�����͸� �迭�� �Ҵ��� �� ����. ����?)
	c_text = encrypt(key,p_text);
	printf("%s",c_text);
	return 0;

}
