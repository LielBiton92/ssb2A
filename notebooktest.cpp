#include "notebooktest.hpp"
#include <iostream>
#include "stdexcept"
#include "vector"
#include "string"
using namespace std;
using namespace ariel;
const int row_limit = 100;
unsigned int i=0;

void ariel::Notebook2::write(unsigned int page , unsigned int row , unsigned int col , Direction state , std::string towrite){

      cout << " ";
      

}

string ariel::Notebook2::read(unsigned int page , unsigned int row , unsigned int col , Direction state ,unsigned int num){
    string s = "1";
    return s;
}

void ariel::Notebook2::erase(unsigned int page , unsigned int  row , unsigned int col , Direction state ,unsigned int num){
    cout << " ";

}

void ariel::Notebook2::show(unsigned int page){
    cout << " "<<endl;
}

ariel::Row::Row(){
        myrow = (char*)malloc(sizeof(char)*row_limit);
        for(int j = 0 ; j < row_limit ; j++){
                myrow[j]='_';
        }
}

void ariel::Row::write(unsigned int pos , string tw){
        for (i = 0;i< tw.size();i++){
                this->myrow[pos+i]=tw[i];
        }
}

void ariel::Row::writechar(unsigned int pos , char tw){
               this->myrow[pos]=tw;   
}

void ariel::Row::erase(unsigned int pos , unsigned len){
        for (i = 0 ; i< len;i++){
                this->myrow[pos+i]='~';
        }
}

string ariel::Row::read(unsigned int pos , unsigned int len){
        string ans;
        
        for(i = 0 ; i< len ; i++){
                ans += this->myrow[pos+i];
        }
        return ans;

}





char ariel::Row::readchar(unsigned int pos){
        return this->myrow[pos];
}

void ariel::Row::zevel(){
        cout << this->myrow << endl;
}
