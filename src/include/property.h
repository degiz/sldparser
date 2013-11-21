#ifndef PROPERTY_H
#define PROPERTY_H

#include "sldnode.h"
#include "variant.h"

#include <vector>
#include <iostream>

namespace SldParser {
    
class Property : public SLDNode {
public:
    Property();
    Property(XmlIterator);
    ~Property();
    
    std::string name();
    Variant literal();
    
    std::vector<Property> properties();
   
private:
    std::vector<Property> _properties;
    
    std::string _propertyName;
    Variant _literal;

    void _parseNode();
};
    
}

#endif // PROPERTY_H