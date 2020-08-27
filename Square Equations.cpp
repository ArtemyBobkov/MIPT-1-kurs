#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>


#define ACCURACY pow(10, -8) // �����������, ��� ������� �� ������� ����� ����

void Hello() {

    printf("## Bobkov Artemy - Square Equations \n");
    printf("## v.1.6 \n");
    printf("## All rights are Bla Bla Bla\n");

}

//-----------------------------------------------------------------------------
//! Finds sign of a number
//!
//! @param [in] a number (double)
//!
//! @return number sign
//!
//! @note Returns 0 if a == 0
//! @note signum(x)*x == abs(x)
//!
//-----------------------------------------------------------------------------

int signum(double a) {    //������ - ���� �����

    assert (isfinite(a));

    if (a > ACCURACY) {
        return 1;
    }
    if (a < -ACCURACY) {
        return -1;
    }
    if (a >= -ACCURACY && a <= ACCURACY) {
        return 0;
    }
}

#define INF_SOLS -1


//-----------------------------------------------------------------------------
//! Solves a linear equation bx + c = 0
//!
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] x1 Pointer to the 1st solution
//!
//! @return Number of roots
//!
//! @note In case of infinite solutions, returns INF_SOLS
//!
//-----------------------------------------------------------------------------

int LinearSols(double b, double c, double* x1) {

    assert (x1 != NULL);
    assert (isfinite(b));
    assert (isfinite(c));
    assert (isfinite(*x1));

    if (signum(b) == 0) {    // ��������� �� ���� ����� b � c
            if (signum(c) == 0) {
                return INF_SOLS;
            } else {    // c != 0, b = 0
                return 0;
            }

        } else {    // b != 0

            *x1 = -c/b;
            return 1;
        }
}


//-----------------------------------------------------------------------------
//! Solves a square equation ax^2 + bx + c = 0
//!
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] x1 Pointer to the 1st solution
//! @param [out] x2 Pointer to the 2nd solution
//!
//! @return Number of roots
//!
//! @note In case of infinite solutions, returns INF_SOLS
//!
//-----------------------------------------------------------------------------

int SquareSols(double a, double  b, double  c, double* x1, double* x2) {

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));
    assert (isfinite(*x1));
    assert (isfinite(*x2));
    assert (x1 != x2);

    if (signum(a) < ACCURACY) {

        return LinearSols(b, c, x1);

    } else {    // a != 0

        double D = b*b - 4*a*c;

        switch (signum(D)) {
            case  0:
                    *x1 = -b / (2*a);
                    *x2 = *x1;
                    return 1;
            case  1:
                    *x1 = (-b - sqrt(D)) / (2*a);
                    *x2 = (-b + sqrt(D)) / (2*a);
                    return 2;
            case -1:
                    return 0;
        }

    }

}

//-----------------------------------------------------------------------------
//! Prints solutions of a square equation ax^2 + bx + c = 0
//!
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] x1 First Solution
//! @param [out] x2 Second Solution
//!
//! @return 0 if there is no errors, else 1
//!
//-----------------------------------------------------------------------------

int Sol_Out(double a, double b, double c, double x1, double x2) {
    int sol_nums = SquareSols(a, b, c, &x1, &x2);
    switch (sol_nums) {
        case        0:
                      printf("No solutions :( \n");
                      return 0;

        case        1:
                      printf("x = %lg \n", x1);
                      return 0;

        case        2:
                      printf("x1 = %lg, x2 = %lg \n", x1, x2);
                      return 0;

        case INF_SOLS:
                      printf("Infinite number of solutions \n");
                      return 0;

        default:
                      printf("ERROR main(): \n");
                      printf("U vas uravnenie reshaetsa krivo \n");
                      return 1;

    }
}


int main () {

    Hello();

    printf("Enter equation coefficients: \n");
    double a = 0, b = 0, c = 0;
    int read_good = 0;
    do {
        fflush(stdin);
        read_good = scanf("%lg %lg %lg", &a, &b, &c);
        if (read_good != 3) {
            printf("You've entered wrong coefficients. Please, repeat. \n");
        }

    }
    while (read_good != 3);

    double x1 = 0, x2 = 0;
    Sol_Out(a, b, c, x1, x2);
    return 0;
}



