#include "rule.h"

#include <sstream>

namespace automap {
    
Rule::Rule(XmlIterator iterator) :
    SLDNode(iterator)
{
    _parseNode();
}

Rule::~Rule()
{
    
}

std::string Rule::name()
{
    return _name;
}

std::string Rule::title()
{
    return _title;
}

std::string Rule::abstract()
{
    return _abstract;
}

double Rule::minScaleDenominator()
{
    return _minScaleDenominator;
}

double Rule::maxScaleDenominator()
{
    return _maxScaleDenominator;
}

std::vector<Filter> Rule::filters()
{
    return _filters;
}

std::vector<Symbolizer> Rule::symbolizers()
{
    return  _symbolizers;
}

void Rule::_parseNode()
{
    // _iterator.moveToChildNode();
   
    while (_iterator.moveToNextNode()) {
    
        if (_iterator.name() == "Name") {
        
            _name = _iterator.value();
            
        } else if (_iterator.name() == "Title") {
        
            _title = _iterator.value();
            
        } else if (_iterator.name() == "Abstract") {
        
            _abstract = _iterator.value();
            
        } else if (_iterator.name() == "MinScaleDenominator") {
        
            std::istringstream scale(_iterator.value());
            scale >> _minScaleDenominator;
            
        } else if (_iterator.name() == "MaxScaleDenominator") {
        
            std::istringstream scale(_iterator.value());
            scale >> _maxScaleDenominator;
            
        } else if (_iterator.name() == "Filter") {
        
            Filter filter(_iterator);
            _filters.push_back(filter);
            
        } else {
        
            std::string name = _iterator.name();
            if (Symbolizer::isSymbolizer(name)) {
                Symbolizer symbolizer(_iterator);
                _symbolizers.push_back(symbolizer);
            }
            
        }
    }
}

}