/*****************************************
** File: Word.cpp
** Project: CSCE 221 Project 2, Summer 2019
** Author: Aurelio Melendez
** Date: 7/9/19
** Section: 700
** E-mail: alejandro_8321@tamu.edu
**
** This file defines the functions for the word class.
** It defines output, comparison operators(<, ==), setters,
** getters, and the constructors.
***********************************************/
#include "Word.h"
#include <queue>
#include <iomanip>


Word::Word(){
    count = 0;
    wordText = "";

}

Word::Word(string inWord, int lineNumber){
    count = 1;
    wordText = inWord;
    transform(wordText.begin(), wordText.end(), wordText.begin(), ::tolower);
    lineNumbers.push(lineNumber);
}

//tracks number of times a word appears and on which lines
void Word::CountWord(int lineNumber){
    
    //increment word ocurrence
    count++;
    
    //queue is empty add occurence line #
    if(lineNumbers.empty()){
        lineNumbers.push(lineNumber);
    }//add to queue if first ocurrence on line
    else if(lineNumber != lineNumbers.back()){
        
        lineNumbers.push(lineNumber);
  

    }
   
  
}

void Word::setWord(string word){
    wordText = word;
    transform(wordText.begin(), wordText.end(), wordText.begin(), ::tolower);
}

//returns the word itself
string Word::GetWord(){
    return wordText;
}
    
bool Word::operator<(const Word& rhs) const{
    
    if(this->wordText < rhs.wordText){
        return true;
    }
    
    return false;
    
}

const Word& Word::operator=(const Word& rhs){

}
    
bool Word::operator==(const Word& rhs) const{
    
    if(this->wordText == rhs.wordText){
        return true;
    }

    return false;
}

ostream& operator<<(ostream& os,  Word& inWord){

    //out filter word
    if(inWord.count == 0){
        os << inWord.wordText;
    }
    else{//out index word
        os << std::setfill('.') << std::setw(22);
        os << std::left << inWord.wordText  << std::right << inWord.count  << ": ";

        queue<int> temp;

        while(!inWord.lineNumbers.empty()){

            os << inWord.lineNumbers.front() << " ";

            temp.push(inWord.lineNumbers.front());

            inWord.lineNumbers.pop();

        }

        inWord.lineNumbers = temp;
    }
    

    return os;
}