from root_finding import *
from math import *

def f ( x ) :
    return tan(x)


print(" Algorithms for root of tan(x)")
print(" ------------------------------------------------")

print(" 1. Secant Method")
x0 = float ( input(" Enter initial guess x_0 : ") )
x1 = float ( input(" Enter final guess x_1 : ") )
acc = float ( input(" Enter accuracy : ") )
answer = root_secant(f, x0, x1, acc,1000,True)
print  str ( answer ) + "\n\n"

print(" 2. Bisection search")

answer = root_bisection(f, x0, x1, acc,1000,True)
print  str ( answer ) + "\n\n"
