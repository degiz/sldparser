#ifndef SYMBOLIZER_H
#define SYMBOLIZER_H

#include "sldnode.h"
#include "csscollection.h"

namespace automap {
    
class Symbolizer : public SLDNode {
public:
    
    #define NUM_OF_SYMBOLIZERS 5

    Symbolizer(XmlIterator);
    ~Symbolizer();
    
    static bool isSymbolizer(std::string);
private:

    std::vector<std::string> _symbolizerTypes;
    std::vector<CssCollection> _fill;
    std::vector<CssCollection> _stroke;
    
    static const char* _symbolizerType[];
    
    void _parseNode();
    void _parsePolygon();
    void _parsePoint();
    void _parseText();
    void _parseRaster();
    void _parseLine();
};
    
};

#endif // SYMBOLIZER_H