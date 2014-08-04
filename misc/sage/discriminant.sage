#!/usr/bin/env sage
x = var('x')
y = var('y')

K.<x> = FunctionField(QQ)
# K: Rational function field in x over Rational Field

R.<y> = K[]
# R: Univariate Polynomial Ring in y over Rational function field in x
# over Rational Field

L = K.extension(y^2 - x^6 - 8*x^5 - 22*x^4 - 22*x^3 - 5*x^2 - 6*x - 1)
# L: Function field in y defined by y^2 - x^6 - 8*x^5 - 22*x^4 -
# 22*x^3 - 5*x^2 - 6*x - 1

L.relative_discriminant()
# won't work -- relative_discriminant only works for relative number
# fields
# AttributeError: 'FunctionField_polymod_with_category' object has no
# attribute 'relative_discriminant'
