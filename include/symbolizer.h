#ifndef SYMBOLIZER_H
#define SYMBOLIZER_H

#include "sldnode.h"
#include "csscollection.h"
#include "mark.h"

namespace automap {

enum SymbolizerTypes {
        PolygonSymbolizer = 0,
        PointSymbolizer,
        TextSymbolizer,
        RasterSymbolizer,
        LineSymbolizer
};
    
class Symbolizer : public SLDNode {
public:
    
    #define NUM_OF_SYMBOLIZERS 5

    Symbolizer(XmlIterator);
    ~Symbolizer();
    
    SymbolizerTypes type();
    
    std::string color();
    std::string wellKnownName();
    double opacity();
    double width();
    std::string linecap();
    std::string linejoin();
    double dashoffset();
    unsigned int size();
    unsigned int rotation();
    
    static bool isSymbolizer(std::string);
private:

    std::vector<std::string> _symbolizerTypes;
    CssCollection _fill;
    CssCollection _stroke;
    CssCollection _graphic;
    Mark _mark;
    
    std::string _color;
    double _width;
    std::string _linecap;
    std::string _linejoin;
    double _dashoffset;
    double _opacity;
    unsigned int _rotation;
    unsigned int _size;
    std::string _wellKnownName;
    
    SymbolizerTypes _type;
    
    static const char* _symbolizerType[];
    
    void _parseNode();
    void _parsePolygon();
    void _parsePoint();
    void _parseText();
    void _parseRaster();
    void _parseLine();
    
    void _prepareStroke();
    void _prepareFill();
};
    
};

#endif // SYMBOLIZER_H