#!/usr/bin/env sage

import sys

def f(x):
    return x^6 + 8 * x^5 + 22 * x^4 + 22 * x^3 + 5 * x^2 + 6 * x + 1

while True:
    # extract d and x from output of ./search
    line = sys.stdin.readline()
    if not(line):
        break
    args = line.split(',')
    d = sage_eval(args[0]);
    a = sage_eval(args[1]);
    b = sage_eval(args[2]);

    # before evaluating x, construct field K = Q(sqrt(d)) and
    # polynomial ring R = K[t], so that sqrtd is recognized
    z = var('z')
    K.<sqrtd> = QQ.extension(z^2 - d)
    R.<t> = K['t']

    # evaluate x
    x = a + b * sqrtd

    # test if f(x) is a square in K by trying to factor the polynomial
    #     t^2 - f(x)
    # in R = K[t]
    fx = f(x)
    if len(list(factor(t^2 - fx))) > 1:
        # positive y
        y = sqrt(fx)
        p0 = - 9 - 24*x - 95*x^2 - 104*x^3 - 46*x^4 - 10*x^5 - x^6
        p1 = - 9 + 3*x + 6*x^2 + x^3
        numerator = 64 + 110*x + 325*x^2 + 452*x^3 + 271*x^4 + \
                    74*x^5 + 8*x^6
        denominator = 2 * (p0 - p1 * y)
        c = numerator / denominator
        print "d = " + str(d) + ",  " + \
            "x = " + str(x) + ",  " + \
            "y = " + str(y) + ",  " + \
            "c = " + str(c)
        sys.stdout.flush()
        # negative y
        # update as necessary
        y = -y
        denominator = 2 * (p0 - p1 * y)
        c = numerator / denominator
        print "d = " + str(d) + ",  " + \
            "x = " + str(x) + ",  " + \
            "y = " + str(y) + ",  " + \
            "c = " + str(c)
        sys.stdout.flush()
