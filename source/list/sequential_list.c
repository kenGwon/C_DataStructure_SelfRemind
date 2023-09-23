/*
 - 자료구조: 순차 리스트(sequential list)
 - 코드내용: 다항식 더하기
*/
#include <stdio.h>
#define MAX(a, b) ((a>b) ? a : b)
#define MAX_DEGREE 50

typedef struct 
{
    int degree;
    double coef[MAX_DEGREE];
} Polinomial;

Polinomial addPoly(Polinomial, Polinomial);
void printPolinomial(Polinomial);

int main(void)
{
    Polinomial a = {3, {4, 3, 5, 0}};
    Polinomial b = {4, {3, 1, 0, 2, 1}};

    Polinomial c;
    c = addPoly(a, b);

    printf("다항식A(x) = "); printPolinomial(a);
    printf("다항식B(x) = "); printPolinomial(b);
    printf("다항식C(x) = "); printPolinomial(c);

    return 0;
}

Polinomial addPoly(Polinomial a, Polinomial b)
{
    Polinomial c;
    int a_index = 0, b_index = 0, c_index = 0;
    int a_degree = a.degree, b_degree = b.degree;
    c.degree = MAX(a_degree, b_degree);

    while (a_index <= a.degree && b_index <= b.degree)
    {
        if (a_degree > b_degree)
        {
            c.coef[c_index++] = a.coef[a_index++];
            a_degree--;
        }
        else if (a_degree == b_degree)
        {
            c.coef[c_index++] = a.coef[a_index++] + b.coef[b_index++];
            a_degree--;
            b_degree--;
        }
        else
        {
            c.coef[c_index++] = b.coef[b_index++];
            b_degree--;
        }
    }
 
    return c;
}

void printPolinomial(Polinomial result)
{
    int i, degree;
    degree = result.degree;

    for (i = 0; i <= result.degree; i++)
    {
        printf("%3.0fx^%d", result.coef[i], degree--);
        if (i < result.degree) printf(" +");
    }
    printf("\n");
}
