
/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 *
 * 2015-18525
 * SEHOON KIM
 *
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
 		
	return ~((~x)|(~y));
	
}


/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {

	int moveRight = n<<3; // 8*n
	int x_norm = x>>moveRight;

	return x_norm & 255;
}


/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  

	int mask =( (1<<31)>>n)<<1;
	int x_shift = x>>n;
	mask = ~mask;
	
	return mask & x_shift;
}


/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  	
	int n1 = 85;
	int n2 = 51;
	int mask;
	
	int x1;
	int x2;

	mask = n1 + (n1<<8);
	mask = mask + (mask<<16);
	
	x1 = x & mask;
	x2 = (x>>1) & mask;
	x = x1 + x2;


	mask = n2 + (n2<<8);
	mask = mask + (mask<<16);


	x1 = x & mask;
	x2 = (x>>2) & mask;
	x = x1 + x2;


	mask = 255 + (255<<8);

	x1 = (x>>16) & mask;
	x = x & mask;

	x = x1 + x;

	mask = 15 + (15<<8);
	x1 = (x>>4) & mask;
	x = x & mask;
	x = x + x1;

	x1 = (x>>8) & 255;
	x = x & 255;


	return x1+x;
}


/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
	
	int x_neg = ~x;
	int x_neg_sign = x_neg>>31;
	int x_neg_add = x_neg+1;
	int x_neg_add_sign = x_neg_add>>31;

	int cond = x_neg_sign & (~x_neg_add_sign);

	return cond&1;
}


/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
 
	return 1<<31;

}


/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  
	int n_neg;
	int x_mod;

	n_neg = ~n+33; //32-n
	x_mod = (x<<n_neg)>>n_neg;

	return !(x^x_mod);
}


/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
	
	int sign = !(x>>31);
	int x_mod = (x>>n)<<n;
	int offset = !(x_mod^x);

	return (x>>n)+!(sign|offset);
}


/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
	
	return (~x+1);
}


/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  
	int isPos = !(x>>31);
	int isZero = (!x);
	
	return (isPos & !isZero);
}


/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  	
	int x_sign_n = !(x>>31); // 1-pos, 0-neg		
	int y_sign_n = !(y>>31); // 1-pos, 0-neg	
	
	int x_sign = !x_sign_n; //0-pos, 1-neg
	int y_sign = !y_sign_n; //0-pos, 1-neg

	int x_neg_only = x_sign & y_sign_n; // always true
	int y_neg_only = x_sign_n & y_sign; // alwats false
	
	int to_be_compared = !(x_neg_only | y_neg_only);
	int cond;
	
	//make x-y
 
	int y_neg = ~y+1;
	int x_y = x+y_neg;
	int x_y_Zero = !!x_y; // 0-zero 1-nonZero
	int x_y_pos = !(x_y>>31); //1-pos

	cond = !(x_y_pos&x_y_Zero);

	return x_neg_only | ((!y_neg_only) & (to_be_compared & cond));
}


/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
	
	int sum = 0; 
	
	int temp;
	int temp_bit;

	temp = (x>>16);
	temp_bit = ((!!temp)<<31)>>31;

	sum = sum+(16&temp_bit);
	
	x = (x&(~temp_bit))+(temp&(temp_bit));


	temp = (x>>8);
	temp_bit = ((!!temp)<<31)>>31;

	sum = sum+(8&temp_bit);
	
	x = (x&(~temp_bit))+(temp&(temp_bit));


	temp = (x>>4);
	temp_bit = ((!!temp)<<31)>>31;

	sum = sum+(4&temp_bit);
	
	x = (x&(~temp_bit))+(temp&(temp_bit));


	temp = (x>>2);
	temp_bit = ((!!temp)<<31)>>31;

	sum = sum+(2&temp_bit);
	
	x = (x&(~temp_bit))+(temp&(temp_bit));


	temp = (x>>1);
	temp_bit = ((!!temp)<<31)>>31;

	sum = sum+((1)&temp_bit);

	
	return sum;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
	
	int frac = uf & 8388607;
	int exp = (uf>>23) & 255;
	

	if(exp==255){
		if(frac) return uf;
	}

	return uf + (1<<31);
}


/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  	
	unsigned result = 0;

	int exp = -1;
	int sign = 0;
	int temp;

	int mult = 4194304; // 2^22

	int frac_temp = 0;

	int cond = 0;

	//exception for 0
	if(x==0) return 0;

	//sign	
	if(x<0){
		sign = 1;
	}

	//fraction and exponenets
	while(x){

		temp = x%2;
		if(temp<0) temp = temp+2;

		frac_temp = frac_temp*2 + temp;
		exp++;
		x = x/2;
	}

	exp = exp+127;

	result = result + sign*2147483648 + exp*8388608;
	

	frac_temp = frac_temp/2;

	while(frac_temp){
		
		temp = frac_temp%2;

		//round
		if(mult==0){
			
			if(temp){
				do{
					frac_temp = frac_temp/2;
					cond = cond+ frac_temp%2;
				}while(frac_temp);
				
				//tie condition -> make as even
				if(!cond){
					if(result%2)
						result = result+temp;
					break;
				}
			}
			result = result + temp;
			break;
		}

		result = result + mult*temp;
		frac_temp = frac_temp/2;
		mult = mult/2;

	}
	
	return result;
}


/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
 	
	int frac = uf & 8388607;
	int exp = (uf>>23) & 255;
	 	
	unsigned result = uf;
	
	
	//exceptions
	if(exp==255){
		return uf;
	}	
	if(uf==0) return uf;
	if(uf==0x80000000) return uf;
	
	//denormalized
	if(exp==0){
		return uf + frac;
	}
	
	//normalized
	result = result + 8388608;
	
	return result;
}
