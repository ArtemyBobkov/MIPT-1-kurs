#include <stdio.h>
#include <math.h>
#include <assert.h>

bool IsFinite(double a) {

    if (a == a) {
        return 1;
    }
    else {
        return 0;
    }
}

int signum(double a) {

    assert (IsFinite(a));

    if (a > 0) {
        return 1;
    }
    if (a < 0) {
        return -1;
    }
    if (a > (-pow(10, -8)) && a < pow(10, -8)) {
        return 0;
    }
}

#define INF_SOLS -1

int SquareSols (double a, double  b, double  c, double *x1, double *x2) {

    assert (IsFinite(a));
    assert (IsFinite(b));
    assert (IsFinite(c));
    assert (IsFinite(*x1));
    assert (IsFinite(*x2));
    assert (x1 != x2);

    if (a*signum(a) < pow(10, -8)) {

        if (b*signum(b) < pow(10, -8)) {

            if (c*signum(c) < pow(10, -8)) {

                return INF_SOLS;

            } else {    // c != 0, a = b = 0

                return 0;
            }

        } else {    // b != 0, a = 0

            *x1 = -c/b;
            *x2 = *x1;
            return 1;
        }

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


main () {

    printf("## Bobkov Artemy - Square Equations \n");
    printf("## v.1.0 \n \n");

    printf("Enter equation coefficients: \n");
    double a = 0, b = 0, c = 0;
    scanf("%lg %lg %lg", &a, &b, &c);

    double x1 = 0, x2 = 0;
    int eqs = SquareSols (a, b, c, &x1, &x2);

    switch (eqs) {
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
                      return 1;

    }
}
