#include "functions.h"

char* getStr(char* s1)
{
    char temp;
    int i = 0;
    int size = 256;
    while ((temp = getchar()) != EOF && temp != '\n')
    {
        s1[i] = temp;
        i++;
        if (i > 255)
        {
            size += 2;
            s1 = (char*)realloc(s1, size * sizeof(char));
        }
    }
    s1[i] = '\0';

    return s1;
}

void outStr(char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        printf("%c", str[i]);
        i++;
    }
    printf("\n");
}

int strLen(char* str)
{
    int k = 0;
    while (str[k] != '\0')
    {
        k++;
    }
    return k;
}

void getWordNum(char* str) {
    int count = 0, i = 0, word = 0;
    while (str[i] == ' ' || str[i] == '\t' && str[i] != '\0')
        i++;
    while (str[i] != '\0') {
        if (str[i] != ' ' && word == 0)
        {
            word = 1;
            count++;
        }
        else if (str[i] == ' ')
            word = 0;
        i++;
    }
    printf("Amount of words in string %d", count);

}

void insert(char* str, int pos, char c) {
    for (int i = strLen(str) + 1; i > pos; i--) {
        str[i] = str[i - 1];
        str[pos] = c;
    }
}


char chooseSymbol()
{
    char* charr = (char*)malloc(1);
    while (1)
    {
        charr = getStr(charr);
        if (strLen(charr) > 1)
        {
            rewind(stdin);
            printf("wrong input\n");
        }
        else
        {
            return charr[0];
        }
    }
}

void doubleC(char* str) {
    char c;
    c = chooseSymbol();
    for (int i = 0; i < strLen(str); i++) {
        if (c == str[i]) {
            insert(str, i,c);
            i++;
        }
    }
}

int checkDelimiter(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 1;
    return 0;
}

int wordAmount(char* string) {
    int amount = 0;
    int j = 0;
    while (string[j] != '\0')
    {
        if ((j == 0 && checkDelimiter(string[j]) == 1) || (checkDelimiter(string[j - 1]) == 0 && checkDelimiter(string[j]) == 1))
            amount++;
        j++;
    }
    return amount;
}

char* setString() {
    char* str = (char*)malloc(1);
    str[0] = '\0';
    int i = 1, c;
    while ((c = getchar()) != EOF && c != '\n')
    {
        i++;
        str = (char*)realloc(str, i * sizeof(char));
        if (str != NULL)
        {
            str[i - 2] = c;
            str[i - 1] = '\0';
        }
    }
    return str;
}

int compare(char* string)
{
    int i = 0;
    char stop[3] = { 'E','N','D' };
    while (i != 3)
    {
        if (string[i] != stop[i])
            return 0;
        i++;
    }
    return 3;
}

void output(char** string, int i)
{

    for (int k = 0; k < i; k++)
        printf("%s\n", string[k]);
}

void getMatrixMem(char*** string, int* i)
{
    int flag = 0;
    (*i) = 0;
    while (flag != 3)
    {
        int temp = (*i) + 1;
        (*string) = (char**)realloc((*string), temp * sizeof(char*));
        (*string)[(*i)] = setString();
        flag = compare((*string)[(*i)]);
        if (flag == 3)
        {
            (*string) = (char**)realloc((*string), (*i) * sizeof(char*));
            (*i) = (*i) - 1;
        }
        (*i) = (*i) + 1;
    }
}

void Quick(char** mas, int size) {
    int i = 0;
    int j = size - 1;
    int mid = wordAmount(mas[size / 2]);
    do {
        while (wordAmount(mas[i]) < mid) {
            i++;
        }
        while (wordAmount(mas[j]) > mid) {
            j--;
        }
        if (i <= j) {

            char* tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        Quick(mas, j + 1);
    }
    if (i < size) {
        Quick(&mas[i], size - i);
    }
}

int correctInputTask(void) {
    int N;
    printf(">");
    while (scanf_s("%d", &N) != 1 || N > 2 || N < 0)
    {
        printf("Incorrect input.Try again!\n");
        printf(">");
        rewind(stdin);
    }
    return N;
}

int contCheck() {
    int CHECK = 0;
    printf("\n<Yes(Y)>\t");
    printf("<No(N)>\n");
    printf(">");
    char temp = 0;
    temp = (char)getchar();
    while ((temp = (char)getchar()) != '\n') {
        CHECK = 0;
        while (temp != 'N' && temp != 'n' && temp != 'Y' && temp != 'y')
        {

            rewind(stdin);
            printf("Wrong input\n");
            printf(">");
            break;
        }
        if (temp == 'n' || temp == 'N')
        {
            CHECK = 1;

        }
    }
    return CHECK;
}


void firstTask() {
    int i = 0;
    printf("Input a line: ");
    char* string = (char*)malloc(1); 
    getStr(string);   
    printf("Your line: ");
    outStr(string);
    getWordNum(string);
}

void secondTask() {
    int i = 0;
    char* string1 = (char*)malloc(1);
    printf("Input a line: ");
    getStr(string1);
    printf("Choose a letter to double: ");
    doubleC(string1);
    outStr(string1);
}

void thirdTask()
{
    printf("Enter a line, if you want to stop type : <END> (IN DISCRETE ROW)\n");
    int i = 0;
    char** string2 = (char**)malloc(1);
    getMatrixMem(&string2, &i);
    printf("\n");
    Quick(string2, i);
    printf("The Result array:\n");
    if (i == 0)printf("array does not exist\n");
    else output(string2, i);
}


