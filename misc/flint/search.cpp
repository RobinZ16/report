/**
 * search.cpp
 *
 * Created by Zhiming Wang on 07/29/2014.
 * --------------------------------------
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>

#include "fmpqxx.h"
#include "fmpzxx.h"
#include "ulong_extras.h"

using namespace flint;

// constant coefficients
fmpqxx c1(1, 1u);
fmpqxx c5(5, 1u);
fmpqxx c6(6, 1u);
fmpqxx c8(8, 1u);
fmpqxx c10(10, 1u);
fmpqxx c15(15, 1u);
fmpqxx c20(20, 1u);
fmpqxx c22(22, 1u);
fmpqxx c40(40, 1u);
fmpqxx c66(66, 1u);
fmpqxx c80(80, 1u);
fmpqxx c88(88, 1u);
fmpqxx c132(132, 1u);

inline fmpqxx rational_part(fmpqxx a, fmpqxx b, fmpqxx d)
{
    return fmpqxx(pow(d,3) * pow(b,6) +                                 \
                                                                        \
                  pow(d,2) * (c22 * pow(b,4) + c40 * a * pow(b,4) +     \
                              c15 * pow(a,2) * pow(b,4)) +              \
                                                                        \
                  d * (c5 * pow(b,2) + c66 * a *pow(b,2) +              \
                       c132 * pow(a,2) * pow(b,2) +                     \
                       c80 * pow(a,3) * pow(b,2) +                      \
                       c15 * pow(a,4) * pow(b,2)) +                     \
                                                                        \
                  (c1 + c6 * a + c5 * pow(a,2) + c22 * pow(a,3) +       \
                   c22 * pow(a,4) + c8 * pow(a,5) + pow(a,6)));
}

inline fmpqxx irrational_part(fmpqxx a, fmpqxx b, fmpqxx d)
{
    return fmpqxx(pow(d,2) * (c8 * pow(b,5) + c6 * a * pow(b,5)) +      \
                                                                        \
                  d * (c22 * pow(b,3) + c88 * a * pow(b,3) +            \
                       c80 * pow(a,2) * pow(b,3) +                      \
                       c20 * pow(a,3) * pow(b,3)) +                     \
                                                                        \
                  (c6 * b + c10 * a * b + c66 * pow(a,2) * b +          \
                   c88 * pow(a,3) * b + c40 * pow(a,4) * b +            \
                   c6 * pow(a,5) * b));
}

inline bool is_square(fmpzxx n)
{
    // if negative, not square
    if (n < 0) {
        return false;
    }
    fmpzxx sqrtn(sqrt(n));
    return (sqrtn * sqrtn == n);
}

inline void test_x(fmpqxx d, slong p1, ulong q1, slong p2, ulong q2)
{
    // x = a + b sqrt(d), where a = p1/q1, b = p2/q2
    fmpqxx a(p1, q1);
    fmpqxx b(p2, q2);
    // f(x) = fx1 + fx2 sqrt(d)
    fmpqxx fx1(rational_part(a, b, d));
    fmpqxx fx2(irrational_part(a, b, d));

    // test if norm of f(x) is a rational square
    fmpqxx norm(fx1 * fx1 - d * fx2 * fx2);
    fmpzxx norm_num(norm.num());
    fmpzxx norm_den(norm.den());
    if (! is_square(norm_num) || ! is_square(norm_den)) {
        return;
    }

    // print d, a, and b on one line, separated by a comma
    std::cout << d << "," << a << ", " << b << std::endl;
}

int main(int argc, const char *argv[]) {
    slong MAX_HEIGHT = atoi(argv[1]);
    ulong UMAX_HEIGHT = MAX_HEIGHT;
    slong MAX_D = atoi(argv[2]);

    time_t start_time = time(NULL);

    for (long d = 2; d <= MAX_D; ++d) {
        // make sure squarefree
        if (! n_is_squarefree(d)) {
            continue;
        }

        std::cerr << "starting d = " << d << ", "                       \
                  << "height <= " << MAX_HEIGHT << std::endl;

        fmpqxx d_rat(d, 1u); // convert d to fmpqxx
        for (slong p1 = -MAX_HEIGHT; p1 <= MAX_HEIGHT; ++p1) {
            for (ulong q1 = 1; q1 <= UMAX_HEIGHT; ++q1) {
                // make sure p1 and q1 are coprime
                if (n_gcd_full(abs(p1), q1) > 1) {
                    continue;
                }
                for (slong p2 = -MAX_HEIGHT; p2 <= MAX_HEIGHT; ++p2) {
                    // make sure p2 is nonzero, i.e., x is irrational
                    if (p2 == 0) {
                        continue;
                    }
                    for (ulong q2 = 1; q2 <= UMAX_HEIGHT; ++q2) {
                        // make sure p2 and q2 are coprime
                        if (n_gcd_full(abs(p2), q2) > 1) {
                            continue;
                        }
                        test_x(d_rat, p1, q1, p2, q2);
                    }
                }
            }
        }

        std::cerr << "finished d = " << d << "  ("                      \
                  << difftime(time(NULL), start_time)                   \
                  << " seconds elapsed)" << std::endl;
    }
    return 0;
}
