#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#define ACCURACY pow(10, -8) // accuracy that we want during operations

void Hello() {
    printf("## Bobkov Artemy - Square Equations \n");
    printf("## v.1.7 \n");
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

int signum(double a)
    {    //signum is a sigh of a number
    assert (isfinite(a));

    if (a > ACCURACY)
        {
        return 1;
        }

    if (a < -ACCURACY)
        {
        return -1;
        }

    if (a >= -ACCURACY && a <= ACCURACY)
        {
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

int LinearSols(double b, double c, double* x1)
    {
    assert (x1 != NULL);
    assert (isfinite(b));
    assert (isfinite(c));
    assert (isfinite(*x1));

    if (signum(b) == 0)
        {    // if b == 0 & c == 0

        if (signum(c) == 0)
            {
            return INF_SOLS;
            }

        else
            {    // c != 0, b = 0
            return 0;
            }
    }

    else
        {    // b != 0
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

int SquareSols(double a, double  b, double  c, double* x1, double* x2)
    {
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));
    assert (isfinite(*x1));
    assert (isfinite(*x2));
    assert (x1 != x2);

    if (signum(a) < ACCURACY)
        {
        return LinearSols(b, c, x1);
        }

    else
        {    // a != 0
        double D = b*b - 4*a*c;

        switch (signum(D))
            {
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

void Sol_Out(double a, double b, double c, double x1, double x2)
    {
    int sol_nums = SquareSols(a, b, c, &x1, &x2);

    switch (sol_nums)
        {
        case        0:
                      printf("No solutions :( \n");
                      break;

        case        1:
                      printf("x = %lg \n", x1);
                      break;

        case        2:
                      printf("x1 = %lg, x2 = %lg \n", x1, x2);
                      break;

        case INF_SOLS:
                      printf("Infinite number of solutions \n");
                      break;

        default:
                      printf("ERROR main(): \n");
                      printf("U vas uravnenie reshaetsa krivo \n");
        }
    }

//-----------------------------------------------------------------------------
//! Tests SquareSols
//!
//! @note Tests #1-8 are for bool table: a(0/1) b(0/1) c(0/1)
//! @note Tests #9: a = 1, b = 2, c = 1; #10: a = 1, b = 0, c = -1; #11: a = 2, b = 5, c = 2
//!
//! @return 0 if there is no errors, else 1
//!
//-----------------------------------------------------------------------------

int unit_testst()
    {
    int IsRight = 1;
    double x1 = 0, x2 = 0;
    if (SquareSols(0, 0, 0, &x1, &x2) != INF_SOLS || x1 != 0 || x2 != 0)
        {
        printf("ERROR: Failed unit_test #1 \n");
        IsRight = 0;
        }
    if (SquareSols(0, 0, 1, &x1, &x2) != 0 || x1 != 0 || x2 != 0)
        {
        printf("ERROR: Failed unit_test #2 \n");
        IsRight = 0;
        }
    if (SquareSols(0, 1, 0, &x1, &x2) != 1 || x1 != 0 || x2 != 0)
        {
        printf("ERROR: Failed unit_test #3 \n");
        IsRight = 0;
        }
    if (SquareSols(0, 1, 1, &x1, &x2) != 1 || x1 != -1 || x2 != 0)
        {
        printf("ERROR: Failed unit_test #4 \n");
        IsRight = 0;
        }
    if (SquareSols(1, 0, 0, &x1, &x2) != 1 || x1 != 0 || x2 != 0)
        {
        printf("ERROR: Failed unit_test #5 \n");
        IsRight = 0;
        }
    if (SquareSols(1, 0, 1, &x1, &x2) != 0 || x1 != 0 || x2 != 0)
        {
        printf("ERROR: Failed unit_test #6 \n");
        IsRight = 0;
        }
    if (SquareSols(1, 1, 0, &x1, &x2) != 2 || x1 != -1 || x2 != 0)
        {
        printf("ERROR: Failed unit_test #7 \n");
        IsRight = 0;
        }
    if (SquareSols(1, 1, 1, &x1, &x2) != 0 || x1 != 0 || x2 != 0)
        {
        printf("ERROR: Failed unit_test #8 \n");
        IsRight = 0;
        }
    if (SquareSols(1, 2, 1, &x1, &x2) != 1 || x1 != -1 || x2 != -1)
        {
        printf("ERROR: Failed unit_test #9 \n");
        IsRight = 0;
        }
    if (SquareSols(1, 0, -1, &x1, &x2) != 2 || x1 != -1 || x2 != 1)
        {
        printf("ERROR: Failed unit_test #10 \n");
        IsRight = 0;
        }
    if (SquareSols(2, 5, 2, &x1, &x2) != 2 || x1 != -2 || x2 != -0.5)
        {
        printf("ERROR: Failed unit_test #11 \n");
        IsRight = 0;
        }
    if (IsRight)
        {
        return 0;
        }
    else
        {
        return 1;
        }
    }

main ()
    {
    Hello();
    printf("Enter equation coefficients: \n");
    double a = 0, b = 0, c = 0;
    int read_good = 0;
    do
        {
        fflush(stdin);
        read_good = scanf("%lg %lg %lg", &a, &b, &c);

        if (read_good != 3)
            {
            printf("You've entered wrong coefficients. Please, repeat. \n");
            }
        }
    while (read_good != 3);

    double x1 = 0, x2 = 0;
    Sol_Out(a, b, c, x1, x2);
    unit_testst();
    }


