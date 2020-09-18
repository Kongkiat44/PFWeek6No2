#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int ptcomp(int, int);
void text1(void);

int main() {
	int k = 1, numin[5] = { 0,0,0,0,0 }, one = 0, two = 0, three = 0, ans = 0, num = 0, count = 0;
	for (int i = 0; i < 5; i++) {
		char input[100];
		int l = 0, inp = 0;
		gets_s(input);
		l = strlen(input);
		for (int j = 0; j < l; j++) {
			char num[2];
			int change = 0;
			if (isdigit(input[j]) || input[j] == ' ') {
				if (isdigit(input[j])) {
					if (input[j] > 48 && input[j] < 54 && count < 4) {
						num[0] = input[j];
						change = atoi(num);
						numin[i] += change;
						count++;
					}
					else if (count >= 4) {
						printf("Enter 4 numbers only\n");
						return 0;
					}
					else {
						printf("Enter the numbers between 1-5 only\n");
						return 0;
					}
				}
				else if (input[j] == ' ') continue;
			}
			else {
				text1();
				return 0;
			}
		}
		count = 0;
	}
	one = ptcomp(numin[0], numin[1]);
	two = ptcomp(numin[2], numin[3]);
	three = ptcomp(one, two);
	ans = ptcomp(three, numin[4]);
	if (ans == three) {
		if (three == one) {
			if (one == numin[0]) num = 1;
			else if (one == numin[1]) num = 2;
		}
		else if (three == two) {
			if (two == numin[2]) num = 3;
			else if (two == numin[3]) num = 4;
		}

	}
	else if (ans == numin[4]) num = 5;
	printf("\n%d %d\n", num, ans);

	return 0;
}
int ptcomp(int one, int two)
{
	if (one > two) return one;
	else if (one < two) return two;
	else if (one == two) return one;
}
void text1(void)
{
	printf("Enter the numbers between 1-5 or space only\n");
}