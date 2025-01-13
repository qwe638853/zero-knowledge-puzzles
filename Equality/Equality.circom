pragma circom 2.1.4;

// Input 3 values using 'a'(array of length 3) and check if they all are equal.
// Return using signal 'c'.
include "../node_modules/circomlib/circuits/comparators.circom";
template Equality() {
   signal input a[3];
   signal output c;


   component isz1 = IsZero();
   component isz2 = IsZero();

   //if a[0] equals a[1], isz1.out would be zero
   isz1.in <== a[0] - a[1]; 
   //if a[1] equals a[2],isz2.out would be zero
   isz2.in <== a[1] - a[2]; 
   //if isz1.out and isz2.out equal one, c would be one 
   c <== isz1.out * isz2.out;
}

component main = Equality();