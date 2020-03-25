# GSOC_OPT_DEMO
this is a simple demo for the Embedded Optimization module of MBDyn Project of GSOC
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

- algorithm:      gradient descent
