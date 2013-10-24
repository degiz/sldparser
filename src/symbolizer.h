#ifndef SYMBOLIZER_H
#define SYMBOLIZER_H

#include "sldnode.h"
#include "csscollection.h"

#include <vector>
#include <map>
#include <string>

const char* SymbolizerType[5] = {
    "PolygonSymbolizer",
    "LineSymbolizer",
    "PointSymbolizer",
    "TextSymbolizer",
    "RasterSymbolizer"
};

namespace automap {
    
class Symbolizer : public SLDNode {
public:
    Symbolizer(xmlNode*);
    ~Symbolizer();
    
private:
    std::vector<std::string> _symbolizerTypes;
    std::vector<CssCollection> _fill;
    std::vector<CssCollection> _stroke;
    
    void _parseNode();
    void _parsePolygon();
    void _parsePoint();
    void _parseText();
    void _parseRaster();
    void _parseLine();
};
    
};

#endif // SYMBOLIZER_H