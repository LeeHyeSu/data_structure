#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int midterm;
	int final;
}Score;

void printScore(Score *p)
{
	printf("�߰����� ������ %d\n", p->midterm);
	printf("�⸻���� ������ %d\n", p->final);
}

Score* biggerScore(Score *p1, Score *p2)
{
	if((p1->midterm + p1->final) >= (p2->midterm + p2->final))
		return p1;
	else
		return p2;
}

Score* totalScore(Score *p1, Score *p2)
{
	Score *total;

	total = (Score*)malloc(sizeof(Score));
	total->midterm = p1->midterm + p2->midterm;
	total->final = p1->final + p2->final;

	return total;
}

Score* createScore(int m, int f)
{
	Score *create;

	create = (Score*)malloc(sizeof(Score));
	create->midterm = m;
	create->final = f;

	return create;
}

int main(void)
{
	Score *p1, *p2, *p3;

	p1 = (Score*)malloc(sizeof(Score));
	p2 = (Score*)malloc(sizeof(Score));

	p1->midterm = 50;
	p1->final = 100;
	p2->midterm = 70;
	p2->final = 70;

	printScore(p1);
	printScore(p2);

	printf("-------------------------\n");
	printf("���� ������ ���� ����:\n");
	printScore(biggerScore(p1, p2));

	printf("-------------------------\n");
	printf("�� ������ �� ��:\n");
	printScore(totalScore(p1, p2));

	printf("-------------------------\n");
	p3 = createScore(100, 100);
	printScore(p3);

	free(p1);
	free(p2);
}