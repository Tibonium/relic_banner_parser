#include "html_source_parser.h"

html_source_parser::html_source_parser(const char* filename)
    : _comment_beginner("class=\"sitetable nestedlisting\""),
      _user_text_header("<div class=\"usertext-body may-blank-within md-container \">"),
      _division_starter("<div class=\"md\">"),
      _block_terminator("</div>")
{
    parse_html(filename) ;
}

void html_source_parser::parse_html(const char* filename)
{
    std::fstream fi(filename) ;
    string_type line ;
    bool _begin = false ;
    while( true ) {
        std::getline(fi, line) ;
        if( fi.eof() ) break ;
        if( line.find(_comment_beginner) != string_type::npos ) {
            _begin = true ;
            break ;
        }
    }
    if( _begin ) {
        while( true ) {
            std::getline(fi, line) ;
            if( fi.eof() ) break ;
            if( line.find(_user_text_header) != string_type::npos ) {
                std::getline(fi, line) ;
                if( line.find(_division_starter) != string_type::npos ) {
                    while( true ) {
                        std::getline(fi, line) ;
                        if( line.find(_block_terminator) != string_type::npos ) break ;
                        if( line.empty() ) continue ;
                        _comments.push_back( line ) ;
                    }
                }
            }
        }
    }
}
