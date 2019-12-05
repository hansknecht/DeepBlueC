#include "vendor/unity.h"
#include "../src/tic-tac-toe.h"

void setUp(void)
{

}
void tearDown(void)
{

}

static void answer_to_life_is_42(void)
{
	int response = answerToLife();
	TEST_MESSAGE("Starting my testing");
	TEST_ASSERT_EQUAL_INT(42, response);
}
static void showPrintedBoard(void)
{
	printBoard();
}
static void playGameTest(void)
{
	playGame();
}
int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(answer_to_life_is_42);
	RUN_TEST(showPrintedBoard);
	RUN_TEST(playGameTest);
	return UNITY_END();
}