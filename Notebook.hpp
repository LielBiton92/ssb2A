#include "Direction.hpp"
using ariel::Direction;
const  int  limit = 100;

#include <string>
#include "vector"
using namespace std;
namespace ariel{
        void check_t(unsigned long num);
class Notebook;
class Page;
class Row;

class Notebook{
        private:
                 vector <Page> mynotebook;
 
        public:

          void check_pages_size( unsigned long page);

          void write( unsigned long page ,  unsigned long row ,  unsigned long col , Direction state ,const  std::string towrite);

          std::string read( unsigned long page ,  unsigned long row ,  unsigned long col , ariel::Direction state , unsigned long  );

          void erase( unsigned long page ,  unsigned long  row ,  unsigned long col , Direction state , unsigned long num);

          bool check_dirty(unsigned long page , unsigned long row , unsigned long col , Direction state , unsigned long numtocheck);

          void show( unsigned long page);

          void check_throws(unsigned long page , unsigned long row , unsigned long col ,Direction state , unsigned long numtocheck);




};


class Page{
        private:
                vector <Row> mypage;

        public:
        // ~page();
        void check_size_rows( unsigned long row);
        string print();
        void check_size_cols_toerase( unsigned long row , unsigned long numtodel);
        void check_size_cols( unsigned long row,  std::string const &tw);
        void write( unsigned long row , unsigned long pos , Direction state , std::string tw);
        void erase( unsigned long row ,  unsigned long pos , Direction state ,  unsigned long numtodel);
        void show_page();
        bool check_dirty(unsigned long row , unsigned long pos , Direction state , unsigned long numtocheck);
        std::string read( unsigned long row ,  unsigned long pos , Direction state ,  unsigned long numtoread);


};

class Row{
        private:
                // char *myrow ;
                vector <char> myrow;
                

        public:
                Row();
                // ~Row(); 
                void write( unsigned long pos , std::string tw );
                void erase( unsigned long pos ,  unsigned long len);
                char readchar( unsigned long pos);
                std::string read( unsigned long pos , unsigned long len);
                void writechar( unsigned long pos , char tw);
                bool check_dirty(unsigned long pos , unsigned long numtocheck);
                bool check_dirty_char(unsigned long pos );
                void zevel();
        
};







}
