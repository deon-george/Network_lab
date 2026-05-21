#include<stdio.h>
#include<math.h>

int main(){
  int remainder, num, sum=0, n=0, i, result;
  printf("Enter a number: ");
  scanf("%d",&num);
  
  int temp=num;
  

  while(temp>0){
  temp = temp / 10;
  ++n;
  }  
  temp = num;
  while(temp>0){
  remainder = temp % 10;
  result = pow(remainder,n);
  sum = sum + result;
  temp = temp / 10;
  }
  if (sum == num){
  printf("The number %d is an Armstrong number\n",num); 
  }
  else{
  printf("The number %d is not an Armstrong number\n",num);
  }
  
  return 0;
  
  
  }


