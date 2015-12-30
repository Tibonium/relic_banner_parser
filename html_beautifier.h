#pragma once

#include <fstream>
#include <string>

class html_beautifier {
public:
    typedef std::string     string_type ;

    html_beautifier(const char* filename) ;

    string_type filename() {
        return _new_file ;
    }

private:

    void beautify(const char* filename) ;

    const string_type _tab ;
    string_type _new_file ;
};
