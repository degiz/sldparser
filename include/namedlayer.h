#ifndef NAMED_LAYER_H
#define NAMED_LAYER_H

#include "userstyle.h"

#include <memory>
#include <vector>

namespace SldParser {

class NamedLayerPrivate;
class XmlIterator;

class NamedLayer {
public:
    explicit NamedLayer(XmlIterator iterator);
    ~NamedLayer();
    
    std::string nodeName() const;
    
    NamedLayer(const NamedLayer& other);
    
    const std::string name() const;
    const std::vector<UserStyle>& userStyles() const;
private:
    std::unique_ptr<NamedLayerPrivate> _p;
};

}

#endif // NAMED_LAYER_H