#ifndef NAMEDLAYER_PRIVATE_H
#define NAMEDLAYER_PRIVATE_H

#include "sldnode.h"
#include "userstyle.h"

#include <vector>
#include <map>
#include <string>
#include <iostream>

namespace SldParser {
    
class NamedLayerPrivate : public SLDNode {
public:
    NamedLayerPrivate(XmlIterator);
    ~NamedLayerPrivate();
    
    const std::string name() const;
    const std::vector<UserStyle>& userStyles() const;

private:
    std::string _layerName;
    std::vector<UserStyle> _userStyles;
    
    void _parseNode();
    
    
};
    
};

#endif // NAMEDLAYER_PRIVATE_H