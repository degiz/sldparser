#include "featuretypestyle.h"

namespace automap {

FeatureStyleType::FeatureStyleType(XmlIterator iterator) :
    SLDNode(iterator)
{
    _parseNode();
}

FeatureStyleType::~FeatureStyleType()
{
    
}

std::string FeatureStyleType::name()
{
    return _name;
}

std::string FeatureStyleType::title()
{
    return _title;
}

std::string FeatureStyleType::abstract()
{
    return _abstract;
}

std::string FeatureStyleType::featureTypeName()
{
    return _featureTypeName;
}

std::vector<std::string> FeatureStyleType::semanticTypeIdentifiers()
{
    return _semanticTypeIdentifiers;
}

std::vector<Rule>& FeatureStyleType::Rules()
{
    return _rules;
}

void FeatureStyleType::_parseNode()
{
    // _iterator.moveToChildNode();
    
    while (_iterator.moveToNextNode()) {
    
        if (_iterator.name() == "Name") {
        
            _name = _iterator.value();
            
        } else if (_iterator.name() == "Title") {
        
            _title = _iterator.value();
            
        } else if (_iterator.name() == "Abstract") {
        
            _abstract = _iterator.value();;
            
        } else if (_iterator.name() == "FeatureTypeName") {
        
           _featureTypeName = _iterator.value();;
           
        } else if (_iterator.name() == "SemanticTypeIdentifier") {
        
            std::string semanticTypeIdentifier = _iterator.value();
            _semanticTypeIdentifiers.push_back(semanticTypeIdentifier);
            
        } else if (_iterator.name() == "Rule") {
        
            Rule rule(_iterator);
            _rules.push_back(rule);
            
        }
    }
}
    
}