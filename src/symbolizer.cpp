#include "symbolizer.h"

namespace automap {
    
Symbolizer::Symbolizer(XmlIterator iterator) :
    SLDNode(iterator)
{
    _symbolizerTypes.assign(&SymbolizerType[0], &SymbolizerType[0]+5);
    _parseNode();
}

Symbolizer::~Symbolizer()
{
    
}

void Symbolizer::_parseNode()
{
   // _iterator.moveToChildNode();
    
    if (_nodeName == "PolygonSymbolizer") {
        _parsePolygon();
    } else if (_nodeName == "PointSymbolizer") {
        _parsePoint();
    } else if (_nodeName == "TextSymbolizer") {
        _parseText();
    } else if (_nodeName == "RasterSymbolizer") {
        _parseRaster();
    } else if (_nodeName == "LineSymbolizer") {
        _parseLine();
    }
}

void Symbolizer::_parsePolygon()
{
    while (_iterator.moveToNextNode()) {
        if (_iterator.name() == "Fill") {
            CssCollection css(_iterator);
            _fill.push_back(css);
        } else if (_iterator.name() == "Stroke") {
            CssCollection css(_iterator);
            _stroke.push_back(css);
        }
    }
}

void Symbolizer::_parseLine()
{
    while (_iterator.moveToNextNode()) {
        if (_iterator.name() == "Stroke") {
            CssCollection css(_iterator);
            _stroke.push_back(css);
        }
    }
}

void Symbolizer::_parsePoint()
{
    
}

void Symbolizer::_parseText()
{
    
}

void Symbolizer::_parseRaster()
{
    
}
    
}