    #include "lib_calc_trans.h"

    void translate(char* mark, double* d)
    {
    int i = 0, a = 0;
    char ch[12];
    while ((int)*mark != 41) {
    while ((int)*mark < 48 || (int)*mark > 57) {
    mark++;
    }
    while ((int)*mark != 32 && (int)*mark != 44 && (int)*mark != 41) {
    ch[i] = *mark;
    i++;
    mark++;
    }

    d[a] = atoi(ch);
    i = 0;
    a++;
    }
    } 

    void calculation(double* d)
    {
    float pi = 3.1415;
    float s;
    float p;
    p = 2 * pi * d[2];
    s = pi * pow(d[2], 2);
    printf("Perimetr = %f\n", p);
    printf("Area = %f\n", s);
    } 

    int figure_chek(double* d1, double* d2)
    {
    double dist;
    dist = sqrt(pow(d2[0] - d1[0], 2) + pow(d2[1] - d1[1], 2));
    if (d1[2] < d2[2]) {
    if (dist + d1[2] == d2[2]) {
    printf("The smaller circle lies completely inside the larger "
    "circle, touching each other.");
    return 0;
    }
    if (dist + d1[2] < d2[2]) {
    printf("The smaller circle is completely inside the bigger circle "
    "without touching each other at a point of circumference.");
    return 0;
    }
    if (dist + d1[2] > d2[2]) {
    printf("the smaller circle does not completely lie inside the "
    "circle.");
    return 0;
    }
    } else {
    if (dist + d2[2] == d1[2]) {
    printf("The smaller circle lies completely inside the larger "
    "circle, touching each other.");
    return 0;
    }
    if (dist + d2[2] < d1[2]) {
    printf("The smaller circle is completely inside the bigger circle "
    "without touching each other at a point of circumference.");
    return 0;
    }
    if (dist + d2[2] > d1[2]) {
    printf("the smaller circle does not completely lie inside the "
    "circle.");
    return 0;
    }
    }

    if (d1[0] == d2[1] && d1[1] == d2[1] && d1[2] == d2[2]) {
    printf("the circles have the same coordinates, and the same "
    "radius\n");
    return 0;
    }
    if (dist == (d1[2] + d2[2])) {
    printf("the circles intersect at the same point");
    return 0;
    }

    return 0;
    }


