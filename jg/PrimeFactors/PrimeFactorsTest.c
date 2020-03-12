/***
 * Excerpted from "Test-Driven Development for Embedded C",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/jgade for more book information.
***/
/*- ------------------------------------------------------------------ -*/
/*-    Copyright (c) James W. Grenning -- All Rights Reserved          -*/
/*-    For use by owners of Test-Driven Development for Embedded C,    -*/
/*-    and attendees of Renaissance Software Consulting, Co. training  -*/
/*-    classes.                                                        -*/
/*-                                                                    -*/
/*-    Available at http://pragprog.com/titles/jgade/                  -*/
/*-        ISBN 1-934356-62-X, ISBN13 978-1-934356-62-3                -*/
/*-                                                                    -*/
/*-    Authorized users may use this source code in your own           -*/
/*-    projects, however the source code may not be used to            -*/
/*-    create training material, courses, books, articles, and         -*/
/*-    the like. We make no guarantees that this source code is        -*/
/*-    fit for any purpose.                                            -*/
/*-                                                                    -*/
/*-    www.renaissancesoftware.net james@renaissancesoftware.net       -*/
/*- ------------------------------------------------------------------ -*/

#include "unity_fixture.h"
#include <stdio.h>
#include <memory.h>

TEST_GROUP(primefactor);

TEST_SETUP(primefactor)
{
}

TEST_TEAR_DOWN(primefactor)
{
}

static char factor_string[80] = "";

static int primes[] = {
    2, 3, 5, 7};

static char *primefactor(int number)
{
  if (number < 3)
  {
    sprintf(factor_string, "%d", number);
    return factor_string;
  }

  int item = 0;
  int maxIndex = sizeof(primes) / sizeof(primes[0]);
  int num = number;

  factor_string[0] = 0;
  for (item = 0; item < maxIndex; item++)
  {
    if (primes[item] <= (num >> 1))
    {
      while ((num % primes[item]) == 0)
      {
        char num_string[10];

        sprintf(num_string, "%d", primes[item]);
        if (strlen(factor_string) > 0)
        {
          strcat(factor_string, ",");
        }
        strcat(factor_string, num_string);
        num = num / primes[item];
      }
    }
  }
  printf("%s\n", factor_string);

  return factor_string;
}

TEST(primefactor, TestSimpleCases1And2)
{
  TEST_ASSERT_EQUAL_STRING("1", primefactor(1));
  TEST_ASSERT_EQUAL_STRING("2", primefactor(2));
}

TEST(primefactor, TestNumberWith2Primes)
{
  TEST_ASSERT_EQUAL_STRING("2,2", primefactor(4));
  TEST_ASSERT_EQUAL_STRING("2,3", primefactor(6));
}
