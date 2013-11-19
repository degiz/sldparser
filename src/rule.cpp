#include "rule.h"

#include <sstream>

namespace automap {
    
Rule::Rule(XmlIterator iterator) :
    _hasElseFilter(false),
    SLDNode(iterator)
{
    _parseNode();
}

Rule::~Rule()
{
    
}

bool Rule::check(FeatureProperty& feature) const
{
    return _filter.check(feature);
}

bool Rule::check(std::vector<FeatureProperty>& features) const
{
    for (auto i = features.begin(); i != features.end(); i++) {
        if (!check(*i)) {
            return false;
        }
    }
    return true;
}

bool Rule::check(IFeature& feature) const
{
    return _filter.check(feature);
}

std::string Rule::name() const
{
    return _name;
}

std::string Rule::title() const
{
    return _title;
}

std::string Rule::abstract() const
{
    return _abstract;
}

double Rule::minScaleDenominator() const
{
    return _minScaleDenominator;
}

double Rule::maxScaleDenominator() const
{
    return _maxScaleDenominator;
}

const std::vector<Symbolizer>& Rule::symbolizers() const
{
    return  _symbolizers;
}

bool Rule::hasElseFilter() const
{
    return _hasElseFilter;
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
            _filter = filter;
            
        } else if (_iterator.name() == "ElseFilter") {
            
            Filter filter(_iterator);
            _filter = filter;
            _hasElseFilter = true;
        
        } else  if (Symbolizer::isSymbolizer(_iterator.name())) {
            
            Symbolizer symbolizer(_iterator);
            _symbolizers.push_back(symbolizer);
            
        }
    }
}

}