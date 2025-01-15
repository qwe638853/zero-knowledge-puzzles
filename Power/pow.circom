pragma circom 2.1.4;

// Create a circuit which takes an input 'a',(array of length 2 ) , then  implement power modulo 
// and return it using output 'c'.

// HINT: Non Quadratic constraints are not allowed. 
include "../node_modules/circomlib/circuits/bitify.circom";
template Pow(bits) {
   
   
   signal input a[2]; //a[0]^a[1]
   signal output c;
   //Transfer a[1] to 2bits 
   component exp2bits = Num2Bits(bits);
   exp2bits.in <== a[1];

   signal base[bits+1];
   signal res[bits+1];
   signal factor[bits+1];

   base[0] <== a[0];
   res[0] <== 1;

   //use Binary Exponentiation
   for(var i=0;i<bits;i++){
      factor[i] <== 1 + (base[i] - 1) * exp2bits.out[i]; //if 2bit==1,Multiply by base
      res[i+1] <== res[i] * factor[i];
      base[i+1] <== base[i] * base[i]; // Multiply by self
   }

   c <== res[bits];

}

component main = Pow(20);

