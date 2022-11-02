double statboostmult(char statboost) {
  if (statboost >= 0) {
    return (statboost*0.5)+1;
  } else {
    return (double)1/(1+(statboost*-1*0.5));
  }
}
/*
This function takes in a char and returns what the stat should be multiplyed by
*/

float ppboostmult(char ppboost) {
  return 1 + (0.2 * ppboost);
}
/* 
Takes in a a num from 0-3 and returns the a multiples 0.2 from 1-1.6
*/

unsigned int map(unsigned int num,unsigned int newmax,unsigned int currentmax) {
  if (currentmax==0) currentmax = RAND_MAX;
  return num/((double)currentmax/newmax);
}

unsigned int map2(unsigned int num,unsigned int newmax,unsigned int currentmax) {
  if (currentmax==0) currentmax = RAND_MAX;
  if (num > (currentmax-(currentmax % newmax))) return map2(rand(),newmax,currentmax);
  else return (num % newmax);
}
/*
these map function are now obsolete but they used to make random number into a more uniform distribution
*/

unsigned int power2(char num) {
  if (num < 0) return 0;
  unsigned int total = 1;
  for (int i = 0;i < num;i++) {
    total *= 2;
  }
  return total;
}
/*
Gives a power of 2 for a number >= 0 else gives a 0
*/

double tt(bool condition,double ifcon,double elsecon) {
  if (condition) return ifcon;
  else return elsecon;
}
/*
This is to make conditional logic availble within a single statement
*/

double tt2(bool condition,double ifcon,double elsecon,double* var) {
  if (condition) {
    *var = ifcon;
    return ifcon;
    }
  else {
    *var = elsecon;
    return elsecon;
    }
}
/*
Same as tt but makes var = the return value before returning
*/

double never0(double num) {
  if (num > 0 && num < 1) num = 1;
  return num;
}