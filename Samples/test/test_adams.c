#include "vendor/unity.h"
#include "../src/adams.h"

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
int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(answer_to_life_is_42);
	return UNITY_END();
}