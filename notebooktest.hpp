#include "Direction.hpp"
using ariel::Direction;
const unsigned int  limit = 100;

#include <string>
#include "vector"
using namespace std;
namespace ariel{
    class Notebook2{
 
        public:


          void write(unsigned int page , unsigned int row , unsigned int col , Direction state ,const  std::string towrite);

          std::string read(unsigned int page , unsigned int row , unsigned int col , ariel::Direction state ,unsigned int  );

          void erase(unsigned int page , unsigned int  row , unsigned int col , Direction state ,unsigned int num);

          void show(unsigned int page);





};

class Row{
        private:
                 char *myrow ;

        public:
                Row();
                void write(unsigned int pos , std::string tw );
                void erase(unsigned int pos , unsigned len);
                char readchar(unsigned int pos);
                std::string read(unsigned int pos , unsigned len);
                void writechar(unsigned int pos , char tw);
                void zevel();
        
};

class Page{
        private:
                vector <Row> mypage;

        public:
        // ~page();
        void check_size_rows(unsigned int row);
        void check_size_cols_toerase(unsigned int row ,unsigned int numtodel);
        void check_size_cols(unsigned int row,  std::string const &tw);
        void write(unsigned int row ,unsigned int pos , Direction state , std::string tw);
        void erase(unsigned int row , unsigned int pos , Direction state , unsigned int numtodel);
        void show_page();
        bool check_dirty(unsigned int row , unsigned int pos ,Direction state ,unsigned int num );
        std::string read(unsigned int row , unsigned int pos , Direction state , unsigned int numtoread);


};
}