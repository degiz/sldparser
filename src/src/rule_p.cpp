#include "rule_p.h"

#include <sstream>

namespace SldParser {
    
RulePrivate::RulePrivate(XmlIterator iterator) :
    _hasElseFilter(false),
    SLDNode(iterator)
{
    _parseNode();
}

RulePrivate::~RulePrivate()
{
    
}

bool RulePrivate::check(FeatureProperty& feature) const
{
    return _filter.check(feature);
}

bool RulePrivate::check(std::vector<FeatureProperty>& features) const
{
    for (auto i = features.begin(); i != features.end(); i++) {
        if (!check(*i)) {
            return false;
        }
    }
    return true;
}

bool RulePrivate::check(IFeature& feature) const
{
    return _filter.check(feature);
}

std::string RulePrivate::name() const
{
    return _name;
}

std::string RulePrivate::title() const
{
    return _title;
}

std::string RulePrivate::abstract() const
{
    return _abstract;
}

double RulePrivate::minScaleDenominator() const
{
    return _minScaleDenominator;
}

double RulePrivate::maxScaleDenominator() const
{
    return _maxScaleDenominator;
}

const std::vector<Symbolizer>& RulePrivate::symbolizers() const
{
    return  _symbolizers;
}

bool RulePrivate::hasElseFilter() const
{
    return _hasElseFilter;
}

void RulePrivate::_parseNode()
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