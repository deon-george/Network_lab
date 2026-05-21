#include<stdio.h>
//#include<math.h>

int main(){
	int num,remainder;
	int sum=0;
	printf("enter the number (to check it is strong or not)\n");
	scanf("%d",&num);
	int temp = num;
	while(temp>0){
	remainder = temp % 10;
	int factorial=1;
	for (int i =1; i<=remainder; i++){
		factorial = factorial * i;
	}
	 sum = sum + factorial;
	 temp = temp / 10;
	}

	if (sum == num){
	printf("the given number %d is a strong number\n",num);}
	else{
	printf("the given number %d is not a strong number\n",num);
	}
	return 0;
	}
	
