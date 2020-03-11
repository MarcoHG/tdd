#!/bin/bash
# source this file -or- run as script 
PROJECT=$(pwd)
FIXTURE_SRC=$PROJECT/../code/unity.framework/extras/fixture/src
UNITY_SRC=$PROJECT/../code/unity.framework/src
FILES="AllTests.c SprintfTest.c SprintfTestRunner.c  $FIXTURE_SRC/unity_fixture.c $UNITY_SRC/unity.c"
gcc -I$FIXTURE_SRC -I$UNITY_SRC $FILES -o testRun

