# GSOC_OPT_DEMO
This is a simple demo for the Embedded Optimization module of MBDyn Project of GSOC.
Variable can be a vector, and it support more than one restraints. 
#### In this demo:                                            

- loss function:

  $$
  f(x_1,x_2) = x_1^2 + x_2^2
  $$

- restraints:

  $$
  f_1(x_1,x_2) = x_2 - x_1 - 1 > 0 \\
  f_2(x_1,x_2) = x_2 + x_1 - 1 > 0
  $$
                

- initial value:

  $$
  x_1 = 4\\
  x_2 = 5
  $$

- output:

  $$
  \min_{x_1,x_2}x_1^2 + x_2^2 = 1\\
  s.t. \space x_2 - x_1 - 1 > 0, \space x_2 + x_1 - 1 > 0
  $$

#### Algorithm details
given mininization problem and restraints:

$$
\min_x f(x)\\
s.t. \space f_i(x) > 0, for \space i =1,2,... 
$$

define the following function to combine loss function and restraint functions:

$$
L(x,\lambda) = f(x) - \sum_i \lambda_i \cdot f_i(x) 
$$

thus the problem is converted to:

$$
\min_x f(x) = \min_x \max_\lambda L(x,\lambda)
$$

then use gradient descent to perform minimize & maximize operation.
