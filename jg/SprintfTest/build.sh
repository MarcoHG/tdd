#!/bin/bash
PROJECT=/home/marco/Documents/edu/tdd/gitTDD/jg
FIXTURE_SRC=$PROJECT/code/unity.framework/extras/fixture/src
UNITY_SRC=$PROJECT/code/unity.framework/src
gcc AllTests.c SprintfTest.c SprintfTestRunner.c -I$FIXTURE_SRC -I$UNITY_SRC $FIXTURE_SRC/unity_fixture.c $UNITY_SRC/unity.c -o testRun

