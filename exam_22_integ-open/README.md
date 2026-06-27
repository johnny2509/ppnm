This is the description for exam project number 22.
In order to implement an open 4-point recursive integrator with nodes {1/5, 2/5, 3/5, 4/5}, we start with a bit of numerical integration mathematics.

Let h=b-a be the height then we have four open nodes

x1=a+1/5h, x2=a+2/5h, x3=a+3/5h, and x4=a+4/5h.

Since the nodes are symmetric around 1/2 and we choose to work on the normalized [0, 1] then the Riemannian integral becomes

Af(1/5) + Bf(2/5) + Bf(3/5) + Af(4/5). [eq. 1]

By demanding that when f(x)=1 the quadrature gives us 

2A + 2B = 1 which implies A + B = 1/2.

For f(x)=x^2 we must have that the integral on this interval is equal to 1/3. We use equation 1. and find

17A + 13B = 25/3 which implies A = 11/24, B = 1/24.

Therefore do we have the weights w1=w4=11/24, and w2=w3=1/24.

