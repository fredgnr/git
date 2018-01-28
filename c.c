#include <stdio.h>
#define MAX_DIGITS 10
const bool segments[10][7]={
	{true,true,true,true,true,true,false},
	{false,true,true,false,false,false,false},
	{true,true,false,true,true,false,true},
	{true,true,true,true,false,false,true},
	{false,true,true,false,false,true,true},
	{true,false,true,true,false,true,true},
	{true,false,true,true,true,true,true},
	{true,true,true,false,false,false,false},
	{true,true,true,true,true,true,true},
	{true,true,true,true,false,true,true}
};
char digits[3][MAX_DIGITS*3];
void clear_digits_array(void);
void process_digit(int digit,int position);
void print_digits_array(void);
void main()
{
	char ch;
	int position;
	clear_digits_array();
	for(position=0;position<MAX_DIGITS;)
	{
		if((ch=getchar())!='\n')
		{
			switch(ch)
			{
				case '0':process_digit(0,position);position++;break;
				case '1':process_digit(1,position);position++;break;
				case '2':process_digit(2,position);position++;break;
				case '3':process_digit(3,position);position++;break;
				case '4':process_digit(4,position);position++;break;
				case '5':process_digit(5,position);position++;break;
				case '6':process_digit(6,position);position++;break;
				case '7':process_digit(7,position);position++;break;
				case '8':process_digit(8,position);position++;break;
				case '9':process_digit(9,position);position++;break;
				default: break;
			}
		}
		else break;
	}
	print_digits_array();
}
void clear_digits_array(void)
{
	int i,x;
	for(x=0;x<3;x++)
		for(i=0;i<MAX_DIGITS*3;i++)
			digits[x][i]=' ';
}
void process_digit(int digit,int position)
{
	int i;
	for(i=0;i<7;i++)
	{
		if(segments[digit][i]&&i%3==0)
		{
			if(i==0)           digits[0][1+4*position]='-';
			else if(i==6)      digits[1][1+4*position]='-';
			else if(i==3)      digits[2][1+4*position]='-';
			else ;
		}
		else if(segments[digit][i])
		{
			if(i==1)       digits[1][2+4*position]='|';
			else if(i==5)  digits[1][4*position]='|'  ;
			else if(i==2)  digits[2][2+4*position]='|';
			else if(i==4)  digits[2][4*position]='|';
		}
	}

}
void print_digits_array()
{
	int i,j;
	for(i=0;i<3;i++)
		{
			for(j=0;j<4*MAX_DIGITS;j++)
			printf("%c",digits[i][j]);
		printf("\n");
        }
    printf("\n");
}