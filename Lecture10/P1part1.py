from trapezoid import *
from simpson import *
from math import *



n1 = 1
n2 = 0

while n1 % 2 != 0 :
    n1 = int(raw_input( "Enter number of intervals desired for trapezoidal rule (must be even)" ))

# a = 0
# b = 2 * atan(1.0)
a = 0
b = log(e)  
c = exp
ans1 = trapezoid(c, a, b, n1)
print 'Trapezoidal rule = ' + str(ans1)


ans2 = simpson(c, a, b, n1)
print 'Simpson rule = ' + str(ans2)
