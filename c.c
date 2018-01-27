#include <stdio.h>
#include <stdlib.h>
#define NUM_RANK 13
#define NUM_SUIT 4
#define NUM_CARD 5
bool straight,flush,four,three;
int pairs;
char hand[NUM_CARD][2];
void read_cards(char hand[NUM_CARD][2]);
void analyze_hand(char hand[NUM_CARD][2]);
void print_result(void);
int main()
{
	for(;;)
	{
		read_cards(hand[NUM_CARD][2]);
		analyze_hand(hand[NUM_CARD][2]);
		void print_result(void);
	}
}
void read_cards(void)
{
     int ncards=0,i;
     bool bad_card,Delicate=false,judge[NUM_CARD]={false};
     char ch_rank,ch_suit,ch;
     while(ncards<NUM_CARD)
     {
     	bad_card=false;
     	printf("Enter a card:");
     	ch_rank=getchar();
     	switch(ch_rank)
		{
		case '0':         exit(EXIT_SUCCESS);
		case '2':         ch_rank='2';break;
		case '3':         ch_rank='3';break;
		case '4':         ch_rank='4';break;
		case '5':         ch_rank='5';break;
		case '6':         ch_rank='6';break;
		case '7':         ch_rank='7';break;
		case '8':         ch_rank='8';break;
		case '9':         ch_rank='9';break;
		case 't':case 'T':ch_rank='t';break;
		case 'j':case 'J':ch_rank='j';break;
		case 'q':case 'Q':ch_rank='q';break;
		case 'k':case 'K':ch_rank='k';break;
		case 'a':case 'A':ch_rank='a';break;
		default:          bad_card=true;
		}    
		ch_suit=getchar(); 
		switch(ch_suit)
		{
		case 'c':case 'C':ch_suit='c';break;
		case 'd':case 'D':ch_suit='d';break;
		case 'h':case 'H':ch_suit='h';break;
		case 's':case 'S':ch_suit='s';break;
		default:          bad_card=true;
		}
		while((ch=getchar())!='\n')
			if(ch!=' ') bad_card=true;
	    if(bad_card)
	    	printf("Bad cards;ignored.\n");
	    for(i=0;i<ncards;i++)
	    {
	    	if(hand[i][0]==ch_rank&&hand[i][1]==ch_suit)
	    		{
	    			Delicate=true;
	    			printf("Dulicate card; ignored.\n");
	    	        break;
	            }
	    }
	    if(!Delicate&&!bad_card)
	    {
            hand[ncards][0]=ch_rank;
            hand[ncards][1]=ch_suit;
	    }
        ncards++;
	}
}
void analyze_hand(void)
{
	int ncards,n,times;
	char ch,i;
	three=four=flush=straight=false;
	pairs=0;
	//flush
	for(ncards=1,ch=hand[0][1];ncards<NUM_CARD;ncards++)
		{
			if(hand[ncards][1]!=ch)
				break;
			else flush=true;
        }
    //straight
    for(ncards=1,i=hand[0][0];ncards<NUM_CARD;ncards++)
    {
    	if(hand[ncards][0]!=++i)
    		break;
    	else straight=true;
    }
    //4—of-a-kind
    for(ncards=0;ncards<NUM_CARD-4;ncards++)
    {
    	ch=hand[ncards][0];
        for(n=0;n<NUM_CARD;n++)
        {
        	if(hand[n][0]==ch&&n!=ncards)
        		times++;
        }
    }
    
}