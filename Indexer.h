/*****************************************
** File: Indexer.h
** Project: CSCE 221 Project 2, Summer 2019
** Author: Aurelio Melendez
** Date: 7/9/19
** Section: 700
** E-mail: alejandro_8321@tamu.edu
**
** This file declares the indexer class
** which indexes all the words in a data file.
***********************************************/
#ifndef INDEXER_H
#define INDEXER_H


#include "Word.h"
#include "BinarySearchTree.h"
#include "Exceptions.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;



class Indexer{
public:

    //Index Constructor
    //Passes in filenames and initializes members
    Indexer(string filterName, string dataName);
    
    //Builds BSTs
    //shows output
    void DoIndex();



private:

    BinarySearchTree<Word> filteredBST;
    BinarySearchTree<Word> indexedBST;
    string filterFile;
    string dataFile;


    //METHODS
    bool FileExists(string filename);
    void FileFilterReader(string filename);
    void FileWordReader(string filename);
    void OutputResults();

};

#endif