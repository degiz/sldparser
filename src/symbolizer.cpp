#include "symbolizer.h"

namespace automap {

const char* Symbolizer::_symbolizerType[] = {
    "PolygonSymbolizer",
    "LineSymbolizer",
    "PointSymbolizer",
    "TextSymbolizer",
    "RasterSymbolizer"
};
    
Symbolizer::Symbolizer(XmlIterator iterator) :
    SLDNode(iterator)
{
    _parseNode();
}

Symbolizer::~Symbolizer()
{
    
}

bool Symbolizer::isSymbolizer(std::string nodeName)
{
    static std::vector<std::string> symbolizers;
    symbolizers.assign(&_symbolizerType[0], &_symbolizerType[0] + NUM_OF_SYMBOLIZERS);
    return std::find(symbolizers.begin(), symbolizers.end(), nodeName) != symbolizers.end();
}

SymbolizerTypes Symbolizer::type()
{
    return _type;
}

std::string Symbolizer::color()
{
    return _color;
}

std::string Symbolizer::WellKnownName()
{
    return _wellKnownName;
}

double Symbolizer::opacity()
{
    return _opacity;
}

double Symbolizer::width()
{
    return _width;
}

std::string Symbolizer::linecap()
{
    return _linecap;
}

std::string Symbolizer::linejoin()
{
    return _linejoin;
}

double Symbolizer::dashoffset()
{
    return _dashoffset;
}

unsigned int Symbolizer::size()
{
    return _size;
}

unsigned int Symbolizer::rotation()
{
    return _rotation;
}

void Symbolizer::_parseNode()
{
    if (_nodeName == "PolygonSymbolizer") {
        _type = PolygonSymbolizer;
        _parsePolygon();
    } else if (_nodeName == "PointSymbolizer") {
        _type = PointSymbolizer;
        _parsePoint();
   } else if (_nodeName == "TextSymbolizer") {
        _type = TextSymbolizer;
        _parseText();
    } else if (_nodeName == "RasterSymbolizer") {
        _type = RasterSymbolizer;
        _parseRaster();
    } else if (_nodeName == "LineSymbolizer") {
        _type = LineSymbolizer;
        _parseLine();
    }
}

void Symbolizer::_parsePolygon()
{
    while (_iterator.moveToNextNode()) {
        if (_iterator.name() == "Fill") {
            CssCollection css(_iterator);
            _fill = css;
        } else if (_iterator.name() == "Stroke") {
            CssCollection css(_iterator);
            _stroke = css;
        }
    }
    _prepareStroke();
    _prepareFill();
}

void Symbolizer::_parseLine()
{
    while (_iterator.moveToNextNode()) {
        if (_iterator.name() == "Stroke") {
            CssCollection css(_iterator);
            _stroke = css;
        }
    }
    _prepareStroke();
}
	
void Symbolizer::_parsePoint()
{
    while (_iterator.moveToNextNode()) {
        if (_iterator.name() == "Graphic") {
            
            XmlIterator it(_iterator);
            it.moveToChildNode();
            
            while (it.moveToNextNode()) {
                
                if (it.name() == "Mark") {
                    
                     Mark mark(it);
                     _wellKnownName = mark.name();
                     _fill = mark.fill();
                     _mark = mark;
                    
                } else if (it.name() == "Rotation") {
                
                    _rotation = Variant(it.value()).asUInt();
                    
                } else if (it.name() == "Size") {
                
                    _size = Variant(it.value()).asUInt();
                    
                }
            }
            
            //CssCollection css(_iterator);
            //_graphic = css;
        }
    }
    _prepareFill();
}

void Symbolizer::_parseText()
{
    
}

void Symbolizer::_parseRaster()
{
    
}

void Symbolizer::_prepareStroke()
{
    for (size_t i = 0; i < _stroke.csselements().size(); i++) {
    
        if (_stroke.csselements()[i].name() == "stroke") {
        
            _color = _stroke.csselements()[i].value().asString();
            
        } else if (_stroke.csselements()[i].name() == "stroke-width") {
        
            _width = _stroke.csselements()[i].value().asDouble();
            
        } else if (_stroke.csselements()[i].name() == "stroke-linecap") {
        
            _linecap = _stroke.csselements()[i].value().asString();
            
        } else if (_stroke.csselements()[i].name() == "stroke-linejoin") {
        
            _linejoin = _stroke.csselements()[i].value().asString();
            
        } else if (_stroke.csselements()[i].name() == "stroke-dashoffset") {
        
            _dashoffset = _stroke.csselements()[i].value().asDouble();
            
        } else if (_stroke.csselements()[i].name() == "stroke-opacity") {
        
            _opacity = _stroke.csselements()[i].value().asDouble();
            
        }
    }
}

void Symbolizer::_prepareFill()
{
    
    for (size_t i = 0; i < _fill.csselements().size(); i++) {
    
        if (_fill.csselements()[i].name() == "fill") {
        
            _color = _fill.csselements()[i].value().asString();
            
        } else if (_fill.csselements()[i].name() == "fill-opacity") {
        
            _opacity = _fill.csselements()[i].value().asDouble();
            
        }
    }
}
    
}