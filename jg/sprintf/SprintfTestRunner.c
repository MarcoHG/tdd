#include "unity/src/unity.h"
#include "SprintfTest.h"

void setUp() {}
void tearDown() {}

int main(void)
{
  UNITY_BEGIN();
  RUN_TEST(Test_sprintf_NoFormatOperation);
  return UNITY_END();
}
