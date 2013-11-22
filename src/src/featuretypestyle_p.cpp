#include "featuretypestyle_p.h"

#include "rule_p.h"

namespace SldParser {

FeatureStyleTypePrivate::FeatureStyleTypePrivate(XmlIterator iterator) :
    SLDNode(iterator)
{
    _parseNode();
}

FeatureStyleTypePrivate::~FeatureStyleTypePrivate()
{
    
}

std::string FeatureStyleTypePrivate::name() const
{
    return _name;
}

std::string FeatureStyleTypePrivate::title() const
{
    return _title;
}

std::string FeatureStyleTypePrivate::abstract() const
{
    return _abstract;
}

std::string FeatureStyleTypePrivate::featureTypeName() const
{
    return _featureTypeName;
}

std::vector<std::string> FeatureStyleTypePrivate::semanticTypeIdentifiers() const
{
    return _semanticTypeIdentifiers;
}

const std::vector<Rule>& FeatureStyleTypePrivate::rules() const
{
    return _rules;
}

void FeatureStyleTypePrivate::_parseNode()
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
        
            RulePrivate rule(_iterator);
            Rule pub(rule);
            _rules.push_back(pub);
            
        }
    }
}
    
}