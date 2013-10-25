#ifndef PROPERTY_H
#define PROPERTY_H

#include "sldnode.h"

#include <vector>
#include <map>
#include <string>

namespace automap {
    
class Property : public SLDNode {
public:
    Property(XmlIterator);
    ~Property();
    
    std::string propertyName();
    std::string literal();
    
    std::vector<Property> properties();
   
private:
    std::vector<Property> _properties;
    
    std::string _propertyName;
    std::string _literal;

    void _parseNode();
};
    
}

#endif // PROPERTY_H