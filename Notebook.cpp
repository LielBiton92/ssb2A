#include "Notebook.hpp"
#include <iostream>
#include "stdexcept"
#include "vector"
#include "string"
using namespace std;
using namespace ariel;
const int col_limit = 100;
 unsigned int i=0;

 void ariel::check_t(unsigned int num ){
         if (num > col_limit){
               throw std::invalid_argument("max col is 100"); 
         }
 }

void ariel::Notebook::check_throws(unsigned int page , unsigned int row , unsigned int col ,Direction state , unsigned int numtocheck){
        if(this->check_dirty(page , row , col , state , numtocheck)){
                throw std::invalid_argument("someone else wrote here");
        }
        if (state ==Direction::Horizontal){
                if(col+numtocheck > col_limit){
                throw std::invalid_argument("error ! cannot write after col number 100");
        }
        }
}

void ariel::Notebook::check_pages_size(unsigned int page ){
        if(mynotebook.size()<=page){
                mynotebook.resize(page+1);
        }
}

bool ariel::Notebook::check_dirty(unsigned int page , unsigned int row , unsigned int col , Direction state , unsigned int numtocheck){
        bool ans = this->mynotebook[page].check_dirty(row , col , state , numtocheck);
        return ans ; 
}

void ariel::Notebook::write(unsigned int page ,unsigned int row ,unsigned int col , Direction state , std::string towrite){
        check_t(col);
        check_pages_size(page);
    //    this->check_throws(page , row , col , state , (unsigned long)towrite.size());
        mynotebook[page].write(row , col , state , std::move(towrite));
        

}

string ariel::Notebook::read(unsigned int page ,  unsigned int row ,  unsigned int col , Direction state , unsigned int num){
        check_t(col);
        check_pages_size(page);
      //  this->check_throws(page , row , col , state , num);
        //          if(col+num > 100){
        //         throw std::invalid_argument("error ! cannot write after col number 100");
        // }
        return mynotebook[page].read(row , col , state , num);

}

void ariel::Notebook::erase( unsigned int page ,  unsigned int  row ,  unsigned int col , Direction state , unsigned int num){
        check_t(col);
        check_pages_size(page);
        mynotebook[page].erase(row , col , state , num);
}

void ariel::Notebook::show( unsigned int page){
        check_pages_size(page);
        mynotebook[page].show_page();
}


// ariel::Row::Row(){
//         myrow = (char*)malloc(sizeof(char)*row_limit);
//         for(unsigned long j = 0 ; j < row_limit ; j++){
//                 this->myrow[j]='_';
//         }
// }

ariel::Row::Row(){
        for(unsigned int j = 0 ; j < col_limit ; j++){
                this->myrow.push_back('_');
        }
}
// ariel::Row::~Row(){
//         delete[] myrow;
// }

void ariel::Row::write( unsigned int pos , string tw){
        for (i = 0;i< tw.size();i++){
                this->myrow[pos+i]=tw[i];
        }
}

void ariel::Row::writechar( unsigned int pos , char tw){
               this->myrow[pos]=tw;   
}

void ariel::Row::erase( unsigned int pos , unsigned int len){
        for (i = 0 ; i< len;i++){
                this->myrow[pos+i]='~';
        }
}

string ariel::Row::read( unsigned int pos ,  unsigned int len){
        string ans;
        
        for(i = 0 ; i< len ; i++){
                ans += this->myrow[pos+i];
        }
        return ans;

}





char ariel::Row::readchar( unsigned int pos){
        return this->myrow[pos];
}

bool ariel::Row::check_dirty(unsigned int pos , unsigned int numtocheck){
        for(i = 0 ; i < numtocheck ; i++){
                if(this->myrow[pos]!='_' and this->myrow[pos]!='~'){
                        return true ;
                }
                
        }
        return false;
}

bool ariel::Row::check_dirty_char(unsigned int pos ){
        bool ans = false;
        if(this->myrow[pos]!='_' and this->myrow[pos]!='~'){
                ans = true;
                return ans;
        }
        return ans;
}

void ariel::Row::zevel(){
         for(unsigned int i = 0 ; i < this->myrow.size(); i++){
                 cout << myrow[i] ;
         }
}




void ariel::Page::check_size_rows( unsigned int row){
        if (this->mypage.size()<=row){
                this->mypage.resize(row+1);       
        }
}


void ariel::Page::check_size_cols( unsigned int row , string const &tw){
        if (mypage.size()<=row + tw.size()){
                mypage.resize(row+tw.size());

        }
}
void ariel::Page::check_size_cols_toerase( unsigned int row , unsigned int  numtodel){
        if(mypage.size()<=row+numtodel){
                mypage.resize(row+numtodel);
        }

}

void ariel::Page::write( unsigned int row ,  unsigned int pos , Direction state , std::string tw){
        check_size_rows(row);
        check_size_cols(row , tw);

        if(state == Direction::Horizontal){
                mypage[row].write(pos,tw);
}

        else if(state == Direction::Vertical){
                 unsigned int j = 0;
                 unsigned int k  = row;
                while(k < row+tw.size()){
                        this->mypage[row+j].writechar(pos ,tw.at(j));
                
                        k+=1;
                        j+=1;
                }
        

        }
}

void ariel::Page::erase( unsigned int row ,  unsigned int pos , Direction state , unsigned int numtodel){
        
        if (state == Direction::Horizontal){
                check_size_rows(row);
                mypage[row].erase(pos , numtodel);
        }
        else if (state == Direction::Vertical){
                check_size_cols_toerase(row , numtodel);
                 unsigned int j = 0 ;
                 unsigned int k = row ;
                while(k < row+numtodel){
                        cout << " row: "<< k <<endl;
                        cout << " row+numtodel: "<< row+numtodel <<endl;
                        mypage[row+j].erase(pos , 1);
                        k+=1;
                        j+=1;
                }
                
        }
}

string ariel::Page::read( unsigned int row ,  unsigned int pos , Direction state ,  unsigned int numtoread){
        check_size_rows(row);
        check_size_cols_toerase(row , numtoread);
        string res;
        
        if (state == Direction::Horizontal){
                res = mypage[row].read(pos , numtoread);
        }
        else if(state == Direction::Vertical){
                if(mypage.size()<row+numtoread){
                        mypage.resize(row+numtoread);
                }
                 unsigned int j = 0 ; 
                i = row ; 
                while (i < row + numtoread){
                        res += mypage[row+j].readchar(pos);

                        i+= 1;
                        j+= 1;
                        
                        
                }
        }
        return res;
}

bool ariel::Page::check_dirty(unsigned int row , unsigned int pos , Direction state , unsigned int numtocheck){
        bool ans=false ;
        bool final_ans = false; 
        if( state == Direction::Horizontal){
              ans =   mypage[row].check_dirty(pos , numtocheck);
}

        else if(state == Direction::Vertical){
                unsigned int j = 0;
                cout << "to write is : ";
                unsigned int k  = row;
                while(k < row+numtocheck){
                   ans = this->mypage[row+j].check_dirty_char(pos);
                   if(ans){
                           final_ans = true;
                   }
                        
        
                        k+=1;
                        j+=1;
                }
        

        }
        if (final_ans){
                ans = true;
        }
        return ans;
        
}


void ariel::Page::show_page(){
        for(i = 0 ; i < this->mypage.size(); i++){
                this->mypage.at(i).zevel();
                
        }
}









        
        
        


