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

#include "fmpqxx.h"

using namespace flint;

// constants
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

fmpqxx rational_part(fmpqxx a, fmpqxx b, fmpqxx d) {
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

fmpqxx irrational_part(fmpqxx a, fmpqxx b, fmpqxx d) {
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

int main(int argc, const char *argv[]) {
    return 0;
}
