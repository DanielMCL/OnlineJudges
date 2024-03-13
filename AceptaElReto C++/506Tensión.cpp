#include"stdio.h"
using namespace std;

int main() {
	int n, a, b;
	scanf_s("%d", &n);
	while (n--) {
		scanf_s("%d / %d", &a, &b);
		if (a >= b)printf("BIEN\n");
		else printf("MAL\n");
	}
	return 0;
}