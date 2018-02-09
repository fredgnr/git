#ifndef WORD_H
#define WORD_H
/************************************************************
    read_word:Reads the next word from the input and        *
              stroes it in word.Makes word empty if no      *
              word could be read because of end_of_file.    *
              Truncates the word if its length exceeds      *
              len.                                          *
************************************************************/
void read_word(char *word,int len);
#endif