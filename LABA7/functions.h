#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
char* getStr(char* s1);
void outStr(char* str);
int strLen(char* str);
void getWordNum(char* str);
void insert(char* str, int pos, char c);
void chooseSymbol(char* c);
void doubleC(char* str);
int checkDelimiter(char ch);
int wordAmount(char* string);
char* getStr2();
int compare(char* string);
void output(char** string, int i);
void getMatrixMem(char*** string, int* i);
void Quick(char** mas, int size);
void firstTask();
int correctInputTask(void);
void secondTask();
int contCheck();
void thirdTask();