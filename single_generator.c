/* Typhoon 20210203 */
/* Generate Single-precision Floating Point Number */
/* We aussume sign bit as 1 or 0 and travers exponent bits from 0 to 255.
   All 0 and all 1 is meaningless so the acutual range is 1~254 .
   For fraction bits ,we travers first n bits("n" is defined by FRA_TRAVERSED_COUNT_SINGLE),
   and the rest bits can be either 1 or 0 */
/* Set the first bit of fraction as 1 to ensure the value ranging from 0.5 to 1 as
	normalized representation required by IEEE-754 */
 

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define FRA_TRAVERSED_COUNT_SINGLE 12
#define FRA_TRAVERSED_POW_SINGLE pow(2,FRA_TRAVERSED_COUNT_SINGLE)

int main(int argc,char *argv[]) 
{	
	int sign;  //we aussume it positive as it makes no difference
	int exponent;  //(-127~128)according to the bais,the actual range is 0~256 without all 0 and all 1
	unsigned long fraction;  //travers first n bits,and the rest bits can be either 1 or 0 
	long restMaxVal=pow(2,23- FRA_TRAVERSED_COUNT_SINGLE)-1;//FRA_TRAVERSED_COUNT_SINGLE=12
	long restFraction=0;
	long firstFraction=0;
	int sum=0;  
	FILE *stream;
	stream=fopen("single_samples.txt","w");
	
	/* generate float numbers */
	for (sign=0;sign<=1;sign++)
	{
		for(exponent=1;exponent<=255;exponent++)
		{
			/* produce fisrt fraction bits */
			long i=0;
			long j=0;
			long ii=0;
			for(i=0;i<FRA_TRAVERSED_POW_SINGLE;i++)//FRA_TRAVERSED_POW_SINGLE=pow(2,FRA_TRAVERSED_COUNT)=pow(2,12)
			{
				ii=i;
				for(j=0;j<FRA_TRAVERSED_COUNT_SINGLE-1;j++)
				{
					sum=ii & 1;
					if(sum==1)
					{
						firstFraction+=pow(2,23-(FRA_TRAVERSED_COUNT_SINGLE-j));
					}	
					ii=ii>>1;
				}
				firstFraction+=pow(2,23);	//the fisrt bit must be 1 as mentioned above
		
				/* generate the rest fraction bits */	
				restFraction=rand()%(restMaxVal+1);
					/* combine */
					fraction=firstFraction+restFraction;
				/* reset */
				firstFraction=0;
				/* write to file */
				fprintf(stream,"%d\t%d\t%ld\n",sign,exponent,fraction);
			}
		}
	}
	return 0;
}
