#ifndef SYMBOLIZER_PRIVATE_H
#define SYMBOLIZER_PRIVATE_H

#include "sldnode.h"
#include "csscollection.h"
#include "mark.h"

#include "symbolizer.h" 

namespace SldParser {
    
class SymbolizerPrivate : public SLDNode {
public:
    
    #define NUM_OF_SYMBOLIZERS 5

    SymbolizerPrivate(XmlIterator);
    ~SymbolizerPrivate();
    
    SymbolizerTypes type() const;
    
    std::string color() const;
    std::string wellKnownName() const;
    double opacity() const;
    double width() const;
    std::string linecap() const;
    std::string linejoin() const;
    double dashoffset() const;
    unsigned int size() const;
    unsigned int rotation() const;
    
    static bool isSymbolizer(std::string);
private:

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
    
    static std::vector<std::string> _symbolizerTypes;
    
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

#endif // SYMBOLIZER_PRIVATE_H