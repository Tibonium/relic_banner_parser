#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <map>

class html_source_parser {
public:

    typedef std::string     string_type ;
    typedef std::list<string_type>  list_type ;
    typedef std::map<string_type,list_type>   map_type ;

    html_source_parser(const char* filename) ;

    void print_data() ;

    list_type* comments() {
        return &_comments ;
    }

    map_type* user_comments() {
        return &_user_comments ;
    }

private:

    void parse_html(const char* filename) ;

    const string_type _comment_beginner ;
    const string_type _user_name_line ;
    const string_type _user_text_header ;
    const string_type _division_starter ;
    const string_type _block_terminator ;

    list_type  _comments ;
    map_type _user_comments ;

};
