from cpt import *
from numpy import *
v0 = 6
R1 = 1
R2 = 1
R3 = 1
R4 = 1
R5 = 1
R6 = 1
R7 = 1
R8 = 1
R9 = 1
R10 = 1
R11 = 1
R12 = 1


V = Matrix(6,1)
V[0][0] = v0
V[1][0] = v0
V[2][0] = v0
V[3][0] = v0
V[4][0] = v0
V[5][0] = v0
print V

R = Matrix(6,6)
R[0][0] = 1+1+1
R[0][1] = 1
R[0][2] = 1

R[1][0] = 1
R[1][1] = 1+1+1
R[1][4] = 1

R[2][0] = 1
R[2][2] = 1+1+1
R[2][3] = 1

R[3][2] = 1
R[3][3] = 1+1+1
R[3][5] = 1

R[4][1] = 1
R[4][4] = 1+1+1
R[4][5] = 1

R[5][3] = 1
R[5][4] = 1
R[5][5] = 1+1+1


print R

R_save = Matrix_copy(R)
i = Matrix_copy(V)

solve_Gauss_Jordan(R, i)
print " Solution using Gauss-Jordan elimination"
print " i = "
print i
I =sum(i)
print 'Total current in the circuit is:'
print I
Re = v0/I
print "The effective resistance is " 
print Re
