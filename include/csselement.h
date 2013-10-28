#ifndef CSSELEMENT_H
#define CSSELEMENT_H

#include "sldnode.h"
#include "property.h"
#include "variant.h"

namespace automap {
    
class CssElement : public SLDNode {
public:
    CssElement(XmlIterator);
    ~CssElement();
    
    std::string name();
    Variant value();
    
private:
    std::string _name;
    Variant _value;
    
    void _parseNode();
};
    
};

#endif // CSSELEMENT_H