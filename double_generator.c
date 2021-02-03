/* Typhoon 20190109 */
/* Generate Double-precision Floating Point Number */
/* We aussume sign bit as 0 and travers exponent bits from 0 to 2047.
   All 0 and all 1 is meaningless so the acutual range is 1~2046 .
   For fraction bits ,we travers first n bits("n" is defined in typh_const_num.h),
   and the rest bits can be either 1 or 0 */
/* Updated by Typhoon 20200412 */
/* We aussume sign bit can be either 1 or 0 */
/* Set the first bit of fraction as 1 to ensure the value ranging from 0.5 to 1 as
	normalized representation required by IEEE-754 */
 

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define FRA_TRAVERSED_COUNT_DOUBLE 12
#define FRA_TRAVERSED_POW_DOUBLE pow(2,FRA_TRAVERSED_COUNT_DOUBLE)

int main(int argc,char *argv[]) 
{
	//double input32;
	int sign;  //we aussume it positive as it makes no difference
	int exponent;  //(-1023~1024)according to the bais,the actual range is 0~2047 without all 0 and all 1
	unsigned long fraction;  //travers first n bits,and the rest bits can be either 1 or 0 
	long restMaxVal=pow(2,52- FRA_TRAVERSED_COUNT_DOUBLE)-1;//FRA_TRAVERSED_COUNT_DOUBLE=12
	long restFraction=0;
	long firstFraction=0;
	int sum=0;  
	FILE *stream;
	stream=fopen("double_samples.txt","w");
	
	/* generate float numbers */
	for (sign=0;sign<=1;sign++)
	{
		for(exponent=1;exponent<=2046;exponent++)
		{
			/* produce fisrt fraction bits */
			long i=0;
			long j=0;
			long ii=0;
			for(i=0;i<FRA_TRAVERSED_POW_DOUBLE;i++)//FRA_TRAVERSED_POW_DOUBLE=pow(2,FRA_TRAVERSED_COUNT)=pow(2,12)
			{
				ii=i;
				for(j=0;j<FRA_TRAVERSED_COUNT_DOUBLE-1;j++)
				{
					sum=ii & 1;
					if(sum==1)
					{
						firstFraction+=pow(2,52-(FRA_TRAVERSED_COUNT_DOUBLE-j));
					}	
					ii=ii>>1;
				}
				firstFraction+=pow(2,51);	//the fisrt bit must be 1 as metioned above
		
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
