#ifndef CSSELEMENT_H
#define CSSELEMENT_H

#include "sldnode.h"
#include "property.h"

namespace automap {
    
class CssElement : public SLDNode {
public:
    CssElement(XmlIterator);
    ~CssElement(); 
    
private:
    std::string _name;
    std::string _value;
    
    void _parseNode();
};
    
};

#endif // CSSELEMENT_H