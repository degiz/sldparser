#include "userstyle.h"

#include "userstyle_p.h"

namespace SldParser {

UserStyle::UserStyle(XmlIterator iterator) :
    _p(new UserStylePrivate(iterator))
{

}

UserStyle::~UserStyle()
{

}

UserStyle::UserStyle(const UserStyle& other) :
    _p(new UserStylePrivate(*other._p))
{

}

std::string UserStyle::nodeName()
{
    return _p->nodeName();
}

std::string UserStyle::name() const
{
    return _p->name();
}

std::string UserStyle::title() const
{
    return _p->title();
}

std::string UserStyle::abstract() const
{
    return _p->abstract();
}

bool UserStyle::isDefault() const
{
    return _p->isDefault();
}

const std::vector<FeatureStyleType>& UserStyle::featureStyleTypes() const
{
    return _p->featureStyleTypes();
}


}