#include <stdio.h>
#include <STDLIB.H>
void exChange(char *pStr)
{
	int len = strlen(pStr);
	int vLoop=1;
	char ch;
	for (vLoop=1;vLoop<=len/2;vLoop++)
	{
		ch = pStr[vLoop-1];
		pStr[vLoop-1]=pStr[len+1-vLoop-1];
		pStr[len+1-vLoop-1]  = ch;
	}
}
char *padd(char *add1,char *add2)
{
	int len1,len2,len=0,flag=0,maxLen=0,absLen=0,vLoop=0,nResult=0;
	int p1=0,p2=0,piEnd=0;
	int result = 0;
	char *pAdd1,*pAdd2,*pCEnd,*rEsult=0;
	len1 = strlen(add1);
	len2 = strlen(add2);
	maxLen = len1>len2?len1:len2;
	absLen = abs(len1-len2);
	rEsult = malloc(maxLen+2);
	if(len1>len2)
		pCEnd = add1;
	else
		pCEnd = add2;
	
	pAdd1 = &add1[len1-1];
	pAdd2 = &add2[len2-1];

	p1 = len1-1;
	p2 = len2 - 1;

	flag= 0;
	while(p1>=0 && p2>=0)
	{
		result = add1[p1]-'0' + add2[p2] - '0';
		if(flag==1)
		{
			result +=1;
			flag = 0;
		}
		if(result >=10)
		{
			flag = 1;
			result  = result%10;
		}
		
	//	printf("%c",result+'0');
		rEsult[nResult++] = result+'0';
		p1--;
		p2--;
		result = 0;
	}
	
	//piEnd = p1<0?p2:p1;
	result = 0;
	for (vLoop=1;vLoop<=absLen;vLoop++)
	{
		result = pCEnd[vLoop-1]-'0';
		if(1==flag)
		{
			result++;
		}
		if(result>=10)
		{
			flag=1;
			result=result%10;
		}
		else
		{
			flag=0;
		}
	//	printf("%c",result+'0');
		rEsult[nResult++] = result+'0';
	}
	if(1==flag)
	{
		rEsult[nResult++] = '1';
	}
	rEsult[nResult] = 0;
	exChange(rEsult);
	return rEsult;
}
int main()
{
 
    printf("Big number add is :%s",padd("55555555555555555555555555555555555555555555555555555","11111111111111111111"));
	return 0;
}
