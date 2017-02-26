#include <iostream>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	int galleon1, sickle1, knut1;
	int galleon2, sickle2, knut2;
	scanf("%d.%d.%d", &galleon1, &sickle1, &knut1);
	scanf("%d.%d.%d", &galleon2, &sickle2, &knut2);
	int carry = 0;
	int galleon3, sickle3, knut3;
	carry = (knut1 + knut2) / 29;
	knut3 = (knut1 + knut2) % 29;
	sickle3 = (sickle1 + sickle2 + carry) % 17;
	carry = (sickle1 + sickle2 + carry) / 17;
	sickle3 = (sickle1 + sickle2 + carry) % 17;
	carry = 0;
	galleon3 = galleon1 + galleon2 + carry;
	printf("%d.%d.%d", galleon3, sickle3, knut3);
}