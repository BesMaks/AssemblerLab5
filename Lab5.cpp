#include <iostream>
#include <vector>
using namespace std;

float fraction() {
	vector<int> fr = { 2,1,3,4,2 };
	int size = fr.size();

	//������ ���
	int chislitel = fr[size - 1];
	int znamenatel = chislitel * fr[size - 2] + 1;

	for (int i = size - 3; i > 0; i--) {
		int tempChislitel = znamenatel;
		int tempZnamenatel = fr[i] * znamenatel + chislitel;

		chislitel = tempChislitel;
		znamenatel = tempZnamenatel;
	}

	//��������� ������������
	return (float)((float)fr[0] + (float)chislitel / (float)znamenatel);
}

void main() {
	// 2 1 3 4 2
	// 0 1 2 3 4

	short int chislitel = 0;
	short int znamenatel = 0;
	int counter = 0;
	float result = 0.0;

	cout << "enter the length of fraction: ";
	int sizee = 0; cin >> sizee; cout << endl;

	short int fraction[16] = { 0 };

	cout << "enter the fraction: ";
	for (int i = 0; i < sizee; i++) { cin >> fraction[i]; }
	sizee--;
	sizee *= 2;
	_asm {
		mov ebx, sizee
		; ��������� � ���������� � �������������� ��������
		mov ax, fraction[ebx]
		mov dx, fraction[ebx-2]

		; ������ ���
		mov chislitel, ax

		mul dx
		inc eax
		mov znamenatel, ax

		; ������ �����
		mov ecx, sizee
		sub ecx, 4
		CYCLE:
		mov ax, znamenatel

			mov dx, fraction[ecx]
			mul dx
			add ax, chislitel

			; �������� ��������� �������� ��������
			; ����� ������ �����
			mov dx, znamenatel
			mov chislitel, dx
			mov znamenatel, ax

			sub ecx, 2
			cmp ecx, 0
			jg CYCLE


			; �������� ����� �����
			mov cx, chislitel
			mov dx, znamenatel
			mov ax, fraction[0];����� ����� �����

			mul dx
			add ax, cx

			; FDIV dx
			mov chislitel, ax
	}
	float resultat = (float)chislitel / (float)znamenatel;
	cout <<	resultat;
	//cout << (float)chislitel << endl << (float)znamenatel;

	//cout << fraction();

	/*_asm {
		lea ebx, fraction
		add ebx, 2
		mov ax, [ebx]
		mov counter, ax

	}*/

	//cout << counter;
}