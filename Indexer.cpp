/*****************************************
** File: Indexer.cpp
** Project: CSCE 221 Project 2, Summer 2019
** Author: Aurelio Melendez
** Date: 7/9/19
** Section: 700
** E-mail: alejandro_8321@tamu.edu
**
** This file defines the functions of the indexer class.
** It defines the constructors and verifies input files.
** This file creates two BSTs, one for filtered words
** and another for index words. It then outputs
** the words alphabetically into a filter file
** and index file. 
***********************************************/
#include "Indexer.h"
#include "Exceptions.h"
#include <sstream>
#include <iostream>

using namespace std;


//Index Constructor
//Passes in filenames and initializes members
Indexer::Indexer(string filterName, string dataName): filterFile(filterName), dataFile(dataName){

    //validate filter file
    if(!FileExists(filterFile)){
        Exceptions file("Filter file does NOT exist");
        throw file;
    }

    //validate data file
    if(!FileExists(dataFile)){
        Exceptions file("Data file does NOT exist");
        throw file;
    }
    

};

//Builds BSTs and shows output
void Indexer::DoIndex(){

    //build filtered BST
    FileFilterReader(filterFile);
   

    //build indexed BST
    FileWordReader(dataFile);

    //output results
    OutputResults();

}

//check if files are valid
bool Indexer::FileExists(string filename){

    ifstream inFS;

    inFS.open(filename);

    if(!inFS.is_open()){
        
        return 0;
    }


    inFS.close();
    return 1;   
}

//create the index BST
void Indexer::FileFilterReader(string filename){
    ifstream inFS;
    inFS.open(filename);
    
    string temp;
    while(inFS >> temp){
        Word *t = new Word();
        t->setWord(temp);
        filteredBST.insert(*t);
    }

    inFS.close();
    
}

//takes data file and sorts words into proper BST
void Indexer::FileWordReader(string filename){
    //open filestream and file
    ifstream inFS;
    inFS.open(filename);

    int lineNum = 0;
    string line;
    string temp;

    //process a line of text
    while(getline(inFS,line)){
        
        //track line #
        lineNum++;

        //remove punctuation from line
        for(int i = 0, len = line.length(); i < len; i++){
            
            //character is punctuation
            if( ispunct(line[i]) ){

                //replace character with space
                if((line[i] != '\'') && (line[i] != '-') ){
                    line[i] = ' ';
                }
            }

            len = line.length();
        }

        
        //break the line into tokens
        stringstream ss(line);

        //add to respective BST
        while(ss >> temp){
            

            //remove ' or - infront if word, to inser in BST
            while( ispunct( temp.front() )){
                temp.erase(0,1);
            }

            //remove ' or - in back of word,
            while(ispunct(temp.back()) ){
                temp.pop_back();
            }

            //if empty skip
            if(temp.empty()){
                continue;
            }

            //skip numbers
            if(!isalpha(temp.front())){
                continue;
            }
        
            //create new word
            Word* w = new Word(temp, lineNum);

            //belongs in filtered words
            if(filteredBST.contains(*w)){
                //skip indexing
                continue;
                
            }
            else{//not in filter, must be index word

                //word already in index
                if(indexedBST.contains(*w)){
                    //update count
                    indexedBST.find(*w).CountWord(lineNum);
                    
                }
                else{//word is new, insert in index BST
                   
                    indexedBST.insert(*w);
                   
                }
            }
            
        }

        //clear stringstream for new line
        ss.clear();
    }
}

//output BSTs to respective files
void Indexer::OutputResults(){

    ofstream ofs;
    stringstream ss;
    stringstream ss2;
    
    //output filter results to file
    ofs.open("filterResults.txt");
    filteredBST.printTree(ss);
    ofs << ss.str();
    ss.clear();
    ofs.close();

    //output index results to file
    ofs.open("indexResults.txt");
    indexedBST.printTree(ss2);
    ofs << ss2.str();
    ss2.clear();
    ofs.close();
   

    
}