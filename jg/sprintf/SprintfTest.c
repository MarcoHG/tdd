#include "unity/src/unity.h"
#include "SprintfTest.h"
#include <stdio.h>

void Test_sprintf_NoFormatOperation(void)
{
  char output[5];
  TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
  TEST_ASSERT_EQUAL_STRING("hey", output);
}