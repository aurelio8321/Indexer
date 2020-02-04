/*****************************************
** File: Word.h
** Project: CSCE 221 Project 2, Summer 2019
** Author: Aurelio Melendez
** Date: 7/9/19
** Section: 700
** E-mail: alejandro_8321@tamu.edu
**
** This file declares the word class.
** 
***********************************************/
#ifndef WORD_H
#define WORD_H

#include <string>
#include <queue>
#include <bits/stdc++.h>


using namespace std;

class Word{
public:
    Word();
    Word(string inWord, int lineNumber);
    void CountWord(int lineNumber);
    void setWord(string);
    string GetWord();

    bool operator< (const Word& rhs) const;
    const Word& operator=(const Word& rhs);
    bool operator==(const Word& rhs) const;
    friend ostream& operator<<(ostream& os,  Word& inWord);


private:
    int count;
    queue<int> lineNumbers;
    string wordText;


};

#endif