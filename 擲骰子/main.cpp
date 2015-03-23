#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> // contains prototype for function time
/*
請修改下列程式，以While迴圈重複擲兩個骰子，每擲一次就印出兩個骰子擲出的結果
如果出現兩個不同的數字，繼續擲骰子。
如果擲骰子擲15次還沒擲出對子，我們就不要再玩下去，直接印出「你今天的手氣很背哦！」
如果出現兩個相同的數字，印出[恭喜你（妳）在擲？次骰子後擲出了對子！]並停止擲骰子
*/
int main()
{
	int sum; // sum of rolled dice
	int die1; // first die
	int die2; // second die
	srand(time(NULL));// randomize random number generator using current time
	
	int count = 15;
	while (count)
	{
		die1 = 1 + (rand() % 6); // pick random die1 value
		die2 = 1 + (rand() % 6); // pick random die2 value
		sum = die1 + die2; // sum die1 and die2
		count --;
		if (die1 == die2) break;
	}
	
	if (count) printf( "恭喜你（妳）在擲%d次骰子後擲出了對子！\n", (15 - count));
	else printf( "你今天的手氣很背哦！\n");
		
	// display results of this roll
	printf( "Player rolled %d + %d = %d\n", die1, die2, sum );
	system("pause");
	return 0;
} 
