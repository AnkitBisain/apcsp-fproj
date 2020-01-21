#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(int n, char c[]){
  char d[128];
  sprintf(d, "%d", n);
  strcat(c, d);
}
int smallestDiv(int n){
  for(int i = 2; i < n+1; i++){
    if(n % i == 0){
      return i;
    }
  }
  return n;
}
int sumOfSquaresS(int n){
  for(int i = 1; i*i < n; i++){
    for(int j = 1; j*j <= n-i*i; j++){
      if(i*i+j*j == n){
	return i;
      }
    }
  }
}
int sumOfSquaresL(int n){
  for(int i = 1; i*i < n; i++){
    for(int j = 1; j*j <= n-i*i; j++){
      if(i*i+j*j == n){
	return j;
      }
    }
  }
}
void GaussianFactor(int a, int b, char c[]){
  int p;
  char d[128];
  while(a*a+b*b > 1){
    memset(d, 0, 128);
    p = smallestDiv(a*a+b*b);
    if(p % 4 == 3){
      add(p, c);
      strcat(c, " * ");
      a = a/p;
      b = b/p;
    }
    if(p % 4 == 1 || p == 2){
      char e = '\0';
      int x;
      x = sumOfSquaresS(p);
      int y;
      y = sumOfSquaresL(p);
      if((a*x+b*y)%(x*x+y*y) == 0){
        strcat(d, "(");
	add(x, d);
	strcat(d, " + ");
	add(y,d);
	strcat(d,"i) * ");
	int q = x*x+y*y;
	int r = a*x+b*y;
	int s = b*x-a*y;
	a = r/q;
	b = s/q;
      }
      else{
        strcat(d, "(");
	add(y, d);
	strcat(d, " + ");
	add(x,d);
	strcat(d,"i) * ");
	int q = x*x+y*y;
	int r = a*y+b*x;
	int s = b*y-a*x;
	a = r/q;
	b = s/q;
      }
    strncat(d, &e, 1);
    strcat(c,d);
    }
  }
  if(a*a == 1){
    add(a,c);
  }
  if(b == 1){
    strcat(c, "i");
  }
  if(b == -1){
    strcat(c, "-i");
  }
}
int main(int argc, char* argv[]){
  int a;
  int b;
  a = atoi(argv[1]);
  b = atoi(argv[2]);
  char c[128];
  GaussianFactor(a, b, c);
  char d = '\0';
  strncat(c, &d, 1);
  printf("%s\n", c);
}
