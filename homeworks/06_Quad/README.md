For task B - a Python comparison

We see that the Clenshaw-Curtis variable transformation has significantly fewer calls 
for integrals with integrable divergencies at the end-point of the intervals (1/sqrt(x)
and ln(x)/sqrt(x)) than the integrator without variable transformation and the Python
implementation for these two integrals.

C++:

Integral 1/sqrt(x), exact = 2
normal result = 1.99999738796403, calls = 17140
Clenshaw-Curtis result = 1.9999998903107, calls = 52

Integral ln(x)/sqrt(x), exact = -4
normal result = -3.99999834899021, calls = 29972
Clenshaw-Curtis result = -3.99999813339603, calls = 272

Integral exp(-x*x) from -inf to inf
result = 1.77245382993893
exact = 1.77245385090552
calls = 1128

Integral 1/(1+x*x) from -inf to inf
result = 3.14159289344387
exact = 3.14159265358979
calls = 936

Python:

1/sqrt(x)
result = 1.9999999999999993
exact  = 2
error  = 6.661338147750939e-16
calls  = 231

log(x)/sqrt(x)
result = -3.9999999999999827
exact  = -4
error  = 1.7319479184152442e-14
calls  = 315

exp(-x*x)
result = 1.7724538509067373
exact  = 1.7724538509055159
error  = 1.2214673716925972e-12
calls  = 150

1/(1+x*x)
result = 3.141592653589793
exact  = 3.141592653589793
error  = 0.0
calls  = 90
