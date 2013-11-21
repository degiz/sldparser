#include "symbolizer_p.h"

namespace SldParser {

std::vector<std::string> SymbolizerPrivate::_symbolizerTypes = {
    "PolygonSymbolizer",
    "LineSymbolizer",
    "PointSymbolizer",
    "TextSymbolizer",
    "RasterSymbolizer"
};
    
SymbolizerPrivate::SymbolizerPrivate(XmlIterator iterator) :
    SLDNode(iterator)
{
    _parseNode();
}

SymbolizerPrivate::~SymbolizerPrivate()
{
    
}

bool SymbolizerPrivate::isSymbolizer(std::string nodeName)
{
    return std::find(_symbolizerTypes.begin(), _symbolizerTypes.end(), nodeName) != _symbolizerTypes.end();
}

SymbolizerTypes SymbolizerPrivate::type() const
{
    return _type;
}

std::string SymbolizerPrivate::color() const
{
    return _color;
}

std::string SymbolizerPrivate::wellKnownName() const
{
    return _wellKnownName;
}

double SymbolizerPrivate::opacity() const
{
    return _opacity;
}

double SymbolizerPrivate::width() const
{
    return _width;
}

std::string SymbolizerPrivate::linecap() const
{
    return _linecap;
}

std::string SymbolizerPrivate::linejoin() const
{
    return _linejoin;
}

double SymbolizerPrivate::dashoffset() const
{
    return _dashoffset;
}

unsigned int SymbolizerPrivate::size() const
{
    return _size;
}

unsigned int SymbolizerPrivate::rotation() const
{
    return _rotation;
}

void SymbolizerPrivate::_parseNode()
{
    if (_nodeName == "PolygonSymbolizer") {
        _type = SymbolizerTypes::PolygonSymbolizer;
        _parsePolygon();
    } else if (_nodeName == "PointSymbolizer") {
        _type = SymbolizerTypes::PointSymbolizer;
        _parsePoint();
   } else if (_nodeName == "TextSymbolizer") {
        _type = SymbolizerTypes::TextSymbolizer;
        _parseText();
    } else if (_nodeName == "RasterSymbolizer") {
        _type = SymbolizerTypes::RasterSymbolizer;
        _parseRaster();
    } else if (_nodeName == "LineSymbolizer") {
        _type = SymbolizerTypes::LineSymbolizer;
        _parseLine();
    }
}

void SymbolizerPrivate::_parsePolygon()
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

void SymbolizerPrivate::_parseLine()
{
    while (_iterator.moveToNextNode()) {
        if (_iterator.name() == "Stroke") {
            CssCollection css(_iterator);
            _stroke = css;
        }
    }
    _prepareStroke();
}
	
void SymbolizerPrivate::_parsePoint()
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

void SymbolizerPrivate::_parseText()
{
    
}

void SymbolizerPrivate::_parseRaster()
{
    
}

void SymbolizerPrivate::_prepareStroke()
{
    for (size_t i = 0; i < _stroke.cssElements().size(); i++) {
    
        if (_stroke.cssElements()[i].name() == "stroke") {
        
            _color = _stroke.cssElements()[i].value().asString();
            
        } else if (_stroke.cssElements()[i].name() == "stroke-width") {
        
            _width = _stroke.cssElements()[i].value().asDouble();
            
        } else if (_stroke.cssElements()[i].name() == "stroke-linecap") {
        
            _linecap = _stroke.cssElements()[i].value().asString();
            
        } else if (_stroke.cssElements()[i].name() == "stroke-linejoin") {
        
            _linejoin = _stroke.cssElements()[i].value().asString();
            
        } else if (_stroke.cssElements()[i].name() == "stroke-dashoffset") {
        
            _dashoffset = _stroke.cssElements()[i].value().asDouble();
            
        } else if (_stroke.cssElements()[i].name() == "stroke-opacity") {
        
            _opacity = _stroke.cssElements()[i].value().asDouble();
            
        }
    }
}

void SymbolizerPrivate::_prepareFill()
{
    
    for (size_t i = 0; i < _fill.cssElements().size(); i++) {
    
        if (_fill.cssElements()[i].name() == "fill") {
        
            _color = _fill.cssElements()[i].value().asString();
            
        } else if (_fill.cssElements()[i].name() == "fill-opacity") {
        
            _opacity = _fill.cssElements()[i].value().asDouble();
            
        }
    }
}
    
}