from cpt import *
from math import *



k1 = 149000 #k between carbon and oxygen molecule
k2 = 141500 #k between carbon and carbon molecule

K = [
     [    k1,      -k1,       0.0,     0.0,    0.0],
     [   -k1,   k1 + k2,      -k2,     0.0,    0.0],
     [   0.0,      -k2,       2*k2,    -k2,    0.0],
     [   0.0,      0.0,       -k2,     k2+k1,  -k1],
     [   0.0,      0.0,       0.0,     -k1,    k1]
     ]

print "K = "
Matrix_print(K)


MO = 16 
MC = 12 


M = Matrix(5,5)
M[0][0] = MO
M[1][1] = MC
M[2][2] = MC
M[3][3] = MC
M[4][4] = MO

print "M = "
Matrix_print(M)

[detM, Minv] = inverse(M)
print "Minv = "
Matrix_print(Minv)


[ eigenvalues, eigenvectors ] = solve_eigen_generalized(K, M)

print "Eigenvalues ="
print eigenvalues
print "Eigenvectors ="
Matrix_print(eigenvectors)
