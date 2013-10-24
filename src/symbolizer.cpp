#include "symbolizer.h"

namespace automap {
    
Symbolizer::Symbolizer(xmlNode* node) :
    SLDNode(node)
{
    _symbolizerTypes.assign(&SymbolizerType[0], &SymbolizerType[0]+5);
    _parseNode();
}

Symbolizer::~Symbolizer()
{
    
}

void Symbolizer::_parseNode()
{
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
    xmlNode* currentElement = _node->children;
    
    while (currentElement != NULL) {
        if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"Fill"))) {
            CssCollection css(currentElement);
            _fill.push_back(css);
        } else  if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"Stroke"))) {
            CssCollection css(currentElement);
            _stroke.push_back(css);
        }
        currentElement = currentElement->next;
    }

}

void Symbolizer::_parseLine()
{
    xmlNode* currentElement = _node->children;
    
    while (currentElement != NULL) {
        if ((!xmlStrcmp(currentElement->name, (const xmlChar *)"Stroke"))) {
            CssCollection css(currentElement);
            _stroke.push_back(css);
        }
        currentElement = currentElement->next;
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