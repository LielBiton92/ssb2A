#include "Direction.hpp"
using ariel::Direction;
const  int  limit = 100;

#include <string>
#include "vector"
using namespace std;
namespace ariel{
        void check_t(unsigned int num);
class Notebook;
class Page;
class Row;

class Notebook{
        private:
                 vector <Page> mynotebook;
 
        public:

          void check_pages_size( unsigned int page);

          void write( unsigned int page ,  unsigned int row ,  unsigned int col , Direction state ,const  std::string towrite);

          std::string read( unsigned int page ,  unsigned int row ,  unsigned int col , ariel::Direction state , unsigned int  );

          void erase( unsigned int page ,  unsigned int  row ,  unsigned int col , Direction state , unsigned int num);

          bool check_dirty(unsigned int page , unsigned int row , unsigned int col , Direction state , unsigned int numtocheck);

          void show( unsigned int page);

          void check_throws(unsigned int page , unsigned int row , unsigned int col ,Direction state , unsigned int numtocheck);




};


class Page{
        private:
                vector <Row> mypage;

        public:
        // ~page();
        void check_size_rows( unsigned int row);
        string print();
        void check_size_cols_toerase( unsigned int row , unsigned int numtodel);
        void check_size_cols( unsigned int row,  std::string const &tw);
        void write( unsigned int row , unsigned int pos , Direction state , std::string tw);
        void erase( unsigned int row ,  unsigned int pos , Direction state ,  unsigned int numtodel);
        void show_page();
        bool check_dirty(unsigned int row , unsigned int pos , Direction state , unsigned int numtocheck);
        std::string read( unsigned int row ,  unsigned int pos , Direction state ,  unsigned int numtoread);


};

class Row{
        private:
                // char *myrow ;
                vector <char> myrow;
                

        public:
                Row();
                // ~Row(); 
                void write( unsigned int pos , std::string tw );
                void erase( unsigned int pos ,  unsigned int len);
                char readchar( unsigned int pos);
                std::string read( unsigned int pos , unsigned int len);
                void writechar( unsigned int pos , char tw);
                bool check_dirty(unsigned int pos , unsigned int numtocheck);
                bool check_dirty_char(unsigned int pos );
                void zevel();
        
};







}
