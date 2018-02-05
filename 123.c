#include<stdio.h>
#include<string.h>
#include<ctype.h>
int compute_vowel_count(char *word);
int main(void)
{
	char word[128];
	printf("Enter a word: ");
	scanf("%s", word);
	printf("Scrabble value : %d", compute_vowel_count(word));
	return 0;
}
int compute_vowel_count(char *word)
{
	int i, value = 0;
	int N = strlen(word);
	for (int i = 0; i < N; i++)
	{
		word[i] = toupper(word[i]);
	}
	for (int i = 0; i < N; i++)
	{
		switch (word[i])
		{
		case 'A': value += 1; break;
		case 'B': value += 3; break;
		case 'C': value += 3; break;
		case 'D': value += 2; break;
		case 'E': value += 1; break;
		case 'F': value += 4; break;
		case 'G': value += 2; break;
		case 'H': value += 4; break;
		case 'I': value += 1; break;
		case 'J': value += 8; break;
		case 'K': value += 5; break;
		case 'L': value += 1; break;
		case 'M': value += 3; break;
		case 'N': value += 1; break;
		case 'O': value += 1; break;
		case 'P': value += 3; break;
		case 'Q': value += 10; break;
		case 'R': value += 1; break;
		case 'S': value += 1; break;
		case 'T': value += 1; break;
		case 'U': value += 1; break;
		case 'V': value += 4; break;
		case 'W': value += 4; break;
		case 'X': value += 8; break;
		case 'Y': value += 4; break;
		case 'Z': value += 10; break;
		default:;
		}
	}
	return value;
}
