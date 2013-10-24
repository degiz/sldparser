#ifndef CSSCOLLECTION_H
#define CSSCOLLECTION_H

#include "sldnode.h"
#include "property.h"

namespace automap {
    
class CssCollection : public SLDNode {
public:
    CssCollection(XmlIterator);
    ~CssCollection();
    
    std::map<std::string, std::string> cssParametrs();
    
private:
    void _parseNode();
    std::vector<Property> _properties;
    std::string _name;
    
    std::map<std::string, std::string> _css;

};
    
};

#endif // CSSCOLLECTION_H