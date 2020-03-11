CC=gcc
CFLAGS=-c -Wall -g
UNITY_DIR=/home/marco/Documents/edu/tdd/gitTDD/jg/sprintf/unity/src

all:  testRun

testRun:	SprintfTest.o SprintfTestRunner.o unity.o
	$(CC) $(CFLAGS) -o testRun SprintfTest.o SprintfTestRunner.o unity.o -o testRun

SprintfTest.o:	SprintfTest.c
	$(CC) $(CFLAGS) SprintfTest.c

SprintfTestRunner.o:	SprintfTestRunner.c 
	$(CC) $(CFLAGS) -I$(UNITY_DIR) SprintfTestRunner.c 

unity.o: $(UNITY_DIR)/unity.c
	$(CC) $(CFLAGS) -I$(UNITY_DIR) $(UNITY_DIR)/unity.c

clean:
	rm -fr *o testRun
