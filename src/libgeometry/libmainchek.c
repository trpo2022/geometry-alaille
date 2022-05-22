#include "libmainchek.h"

int mainchek(char* mark, char* wr)
{
    if (mass_chek(mark, wr) == 0) {
        printf("Correct\n");
        return 0;
    } else {
        printf("Uncorrect\n");
        system("pause");
        return 1;
    }
}

int mass_chek(char* mark, char* wr)
{
    int res = 0;
    if (search_breckets(mark) == 0) {
        res++;
    }
    if (search_comma(mark) == 0) {
        res++;
    }
    if (word_chek(wr, mark) == 0) {
        res++;
    }
    return res;
}

bool search_breckets(char* mark)
{
    char* mark2 = mark;
    int flag1 = 0, flag2 = 0;

    while (*mark2 != 10) {
        if (*mark2 == '(') {
            flag1 = 1;
            break;
        }
        mark2++;
    }
    while (*mark != 10) {
        if (*mark == ')') {
            flag2 = 1;
            break;
        }
        mark++;
    }
    if (flag1 == 0 && flag2 == 0) {
        printf("error: expected breckets\n");
        return false;
    }
    if (flag1 == 0 && flag2 == 1) {
        printf("error: expected ')'\n");
        return false;
    }
    if (flag1 == 1 && flag2 == 0) {
        printf("error: expected ')'\n");
        return false;
    }
    return true;
}

bool search_comma(char* mark)
{
    int flag = 0;

    while (*mark != 10) {
        if (*mark == ',') {
            flag = 1;
            break;
        }
        mark++;
    }
    if (flag == 0) {
        printf("expected ','\n");
        return false;
    }
    return true;
}

bool word_chek(char* wr, char* mark)
{
    int s = 6;
    if (strncmp(wr, mark, s) == 0) {
        return true;
    }
    printf("check the spelling of the word\n");
    return false;
}
