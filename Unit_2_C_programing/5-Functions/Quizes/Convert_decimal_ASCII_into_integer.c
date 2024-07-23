#include "stdio.h"

unsigned int asciiToUnsignedInt(char arr[100]);

int main()
{
	char arr_nums[5];
	printf("Enter decimal numbers : ")
	scanf ("%c",&arr_nums);
	unsigned int int_value= asciiToUnsignedInt (arr_num);
	printf("converted value : %u\t",int_value);
	return 0;
}
unsigned int asciiToUnsignedInt(char ascii_arr[100])
{
	unsigned int result = 0;
	int i = 0;
	
	for(i=0;ascii_arr[i]>='0' && ascii_arr[i]<='9';i++)
	{
		result*= 10 + (ascii_arr[i]-'0');
		
	}
	return result ;
}