#ifndef PROPERTY_H
#define PROPERTY_H

#include "sldnode.h"

#include <vector>
#include <map>
#include <string>

const char* BinaryComparisonOpType[9] = {
    "PropertyIsEqualTo",
    "PropertyIsNotEqualTo",
    "PropertyIsLessThan",
    "PropertyIsGreaterThan",
    "PropertyIsLessThanOrEqualTo",
    "PropertyIsGreaterThanOrEqualTo",
    "PropertyIsLike",
    "PropertyIsNull",
    "PropertyIsBetween"
};

const char* LogicOpsType[3] = {
    "And",
    "Or",
    "Not"
};

namespace automap {
    
class Property : public SLDNode {
public:
    Property(xmlNode*);
    ~Property();
    
    std::string propertyName();
    std::string literal();
    
    std::vector<Property> properties();
    
private:
    enum PropertyType {
        Comparison,
        Logic
    };
    
    std::vector<Property> _properties;
    
    PropertyType _type;
    std::vector<std::string> _binaryCamparations;
    std::vector<std::string> _logicOperations;
    std::string _propertyName;
    std::string _literal;

    void _parseNode();
    void _parseComaparison();
    void _parseLogic();
};
    
}

#endif // PROPERTY_H