    #include <ctype.h>
    #include <math.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include "lib/lib_calc_trans.h"
    #include "lib/lib_main_chek.h"

    int main()
    {
    int max = 30;
    char str1[max];
    char str2[max];
    char* mark1 = str1;
    char* mark2 = str1;
    double d1[4], d2[4];
    char wr[] = {"circle"};

    printf("For first circle: ");
    fgets(str1, max, stdin);
    if (isalpha(*mark1) != 0) {
    while (isalpha(*mark2) != 0)
    mark2++;
    } 
    if (mainchek(mark1, wr) == 1)
    return 0;
    else
    mark1 = mark2;
    translate(mark1, d1);
    calculation(d1);

    printf("\n");
    printf("For second circle: ");
    char* mark3 = str2;
    char* mark4 = str2;
    fgets(str2, max, stdin);
    if (isalpha(*mark3) != 0) {
    while (isalpha(*mark4) != 0)
    mark4++;
    } 
    if (mainchek(mark3, wr) == 1)
    return 0;
    else
    mark3 = mark4;
    translate(mark3, d2);
    calculation(d2);

    figure_chek(d1, d2);
    printf("\n");
    system("pause");
    return 0;
    }

