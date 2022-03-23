#include "Notebook.hpp"
#include <iostream>
#include "stdexcept"
#include "vector"
#include "string"
using namespace std;
using namespace ariel;
const int row_limit = 100;
 unsigned long i=0;


void ariel::Notebook::check_pages_size(unsigned long page ){
        if(mynotebook.size()<=page){
                mynotebook.resize(page+1);
        }
}

bool ariel::Notebook::check_dirty(unsigned long page , unsigned long row , unsigned long col , Direction state , unsigned long numtocheck){
        bool ans = this->mynotebook[page].check_dirty(row , col , state , numtocheck);
        return ans ; 
}

void ariel::Notebook::write(unsigned long page ,unsigned long row ,unsigned long col , Direction state , std::string towrite){
        check_pages_size(page);
        mynotebook[page].write(row , col , state , std::move(towrite));
        

}

string ariel::Notebook::read(unsigned long page ,  unsigned long row ,  unsigned long col , Direction state , unsigned long num){
         check_pages_size(page);
        return mynotebook[page].read(row , col , state , num);

}

void ariel::Notebook::erase( unsigned long page ,  unsigned long  row ,  unsigned long col , Direction state , unsigned long num){
        check_pages_size(page);
        mynotebook[page].erase(row , col , state , num);
}

void ariel::Notebook::show( unsigned long page){
        check_pages_size(page);
        mynotebook[page].show_page();
}


ariel::Row::Row(){
        myrow = (char*)malloc(sizeof(char)*row_limit);
        for(unsigned long j = 0 ; j < row_limit ; j++){
                this->myrow[j]='_';
        }
}
// ariel::Row::~Row(){
//         delete[] myrow;
// }

void ariel::Row::write( unsigned long pos , string tw){
        for (i = 0;i< tw.size();i++){
                this->myrow[pos+i]=tw[i];
        }
}

void ariel::Row::writechar( unsigned long pos , char tw){
               this->myrow[pos]=tw;   
}

void ariel::Row::erase( unsigned long pos , unsigned long len){
        for (i = 0 ; i< len;i++){
                this->myrow[pos+i]='~';
        }
}

string ariel::Row::read( unsigned long pos ,  unsigned long len){
        string ans;
        
        for(i = 0 ; i< len ; i++){
                ans += this->myrow[pos+i];
        }
        return ans;

}





char ariel::Row::readchar( unsigned long pos){
        return this->myrow[pos];
}

bool ariel::Row::check_dirty(unsigned long pos , unsigned long numtocheck){
        for(i = 0 ; i < numtocheck ; i++){
                if(this->myrow[pos]!='_' and this->myrow[pos]!='~'){
                        return true ;
                }
                
        }
        return false;
}

bool ariel::Row::check_dirty_char(unsigned long pos ){
        bool ans = false;
        if(this->myrow[pos]!='_' and this->myrow[pos]!='~'){
                ans = true;
                return ans;
        }
        return ans;
}

void ariel::Row::zevel(){
         cout << this->myrow << endl;
}




void ariel::Page::check_size_rows( unsigned long row){
        if (this->mypage.size()<=row){
                this->mypage.resize(row+1);       
        }
}


void ariel::Page::check_size_cols( unsigned long row , string const &tw){
        if (mypage.size()<=row + tw.size()){
                mypage.resize(row+tw.size());

        }
}
void ariel::Page::check_size_cols_toerase( unsigned long row , unsigned long  numtodel){
        if(mypage.size()<=row+numtodel){
                mypage.resize(row+numtodel);
        }

}

void ariel::Page::write( unsigned long row ,  unsigned long pos , Direction state , std::string tw){
        check_size_rows(row);
        check_size_cols(row , tw);

        if(state == Direction::Horizontal){
                mypage[row].write(pos,tw);
}

        else if(state == Direction::Vertical){
                 unsigned long j = 0;
                cout << "to write is : ";
                 unsigned long k  = row;
                while(k < row+tw.size()){
                        cout << "k: "<< k <<endl;
                        cout << "need: "<< row+tw.size() <<endl;
                        this->mypage[row+j].writechar(pos ,tw.at(j));
                        cout<<"char is : "<<tw[k]<<endl;
                
                        k+=1;
                        j+=1;
                }
        

        }
}

void ariel::Page::erase( unsigned long row ,  unsigned long pos , Direction state , unsigned long numtodel){
        
        if (state == Direction::Horizontal){
                check_size_rows(row);
                mypage[row].erase(pos , numtodel);
        }
        else if (state == Direction::Vertical){
                check_size_cols_toerase(row , numtodel);
                 unsigned long j = 0 ;
                 unsigned long k = row ;
                while(k < row+numtodel){
                        cout << " row: "<< k <<endl;
                        cout << " row+numtodel: "<< row+numtodel <<endl;
                        mypage[row+j].erase(pos , 1);
                        k+=1;
                        j+=1;
                }
                
        }
}

string ariel::Page::read( unsigned long row ,  unsigned long pos , Direction state ,  unsigned long numtoread){
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
                 unsigned long j = 0 ; 
                i = row ; 
                while (i < row + numtoread){
                        res += mypage[row+j].readchar(pos);

                        i+= 1;
                        j+= 1;
                        
                        
                }
        }
        return res;
}

bool ariel::Page::check_dirty(unsigned long row , unsigned long pos , Direction state , unsigned long numtocheck){
        bool ans=false ;
        if( state == Direction::Horizontal){
              ans =   mypage[row].check_dirty(pos , numtocheck);
}

        else if(state == Direction::Vertical){
                unsigned long j = 0;
                cout << "to write is : ";
                unsigned long k  = row;
                while(k < row+numtocheck){
                   ans =   this->mypage[row+j].check_dirty_char(pos);
                        
        
                        k+=1;
                        j+=1;
                }
        

        }
        return ans;
        
}


void ariel::Page::show_page(){
        for(i = 0 ; i < this->mypage.size(); i++){
                this->mypage[i].zevel();
                
        }
}









        
        
        


