#include "namedlayer.h"

#include "namedlayer_p.h"

namespace SldParser {

NamedLayer::NamedLayer(NamedLayerPrivate& p) :
    _p(new NamedLayerPrivate(p))
{

}

NamedLayer::~NamedLayer()
{
    
}

std::string NamedLayer::nodeName() const
{
    return _p->nodeName();
}

NamedLayer::NamedLayer(const NamedLayer& other) :
    _p(new NamedLayerPrivate(*other._p))
{

}

const std::string NamedLayer::name() const
{
    return _p->name();
}

const std::vector<UserStyle>& NamedLayer::userStyles() const
{
    return _p->userStyles();
}


}