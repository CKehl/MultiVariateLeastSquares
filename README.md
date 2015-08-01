# MultiVariateLeastSquares
sample program for showing least-squares regression on image example. Requires Eigen-library.

Testing:
1. Import the source code in your IDE
2. setup the project to use and compile against Eigen library
3. run the program
   parameters: --input_pmat: Source Nx4 Matrix with train values X0 ... X3, X0 being [1]
               --input_vec : Source Nx1 Vector with result values Y
               --output    : Output Nx1 Vector of parameters a, to solve Y = aX for the given training model
