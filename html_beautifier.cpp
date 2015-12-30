#include "html_beautifier.h"

html_beautifier::html_beautifier(const char* filename)
    : _tab("    "),
      _new_file(filename)
{
    int n = _new_file.find(".") ;
    _new_file.insert(n-1, "_pretty") ;
    beautify(filename) ;
}

void html_beautifier::beautify(const char *filename)
{
    std::ifstream in(filename) ;
    std::ofstream out(_new_file.c_str()) ;
}

