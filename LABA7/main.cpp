#include "functions.h"


int main() {
    int task;
    void(*Menu_Task[3])() = { firstTask, secondTask, thirdTask };
    do {
        system("cls");
        printf("Input Task number \n");
        task = correctInputTask();
        rewind(stdin);
        Menu_Task[task]();
        printf("\nWant see another task?\n");
    } while (contCheck() != 1);

    return 0;
}