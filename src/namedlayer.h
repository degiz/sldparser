#ifndef NAMEDLAYER_H
#define NAMEDLAYER_H

#include "sldnode.h"
#include "userstyle.h"

#include <vector>
#include <map>
#include <string>
#include <iostream>

namespace automap {
    
class NamedLayer :public SLDNode {
public:
    NamedLayer(XmlIterator);
    ~NamedLayer();
    
    std::string name();
    std::vector<UserStyle> userStyles();

private:
    std::string _layerName;
    std::vector<UserStyle> _userStyles;
    
    void _parseNode();
    
    
};
    
};

#endif // NAMEDLAYER_H