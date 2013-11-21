#ifndef USERSTYLE_H
#define USERSTYLE_H

#include "featuretypestyle.h"

#include <memory>
#include <vector>

namespace SldParser {

class UserStylePrivate;
class XmlIterator;

class UserStyle {
public:
    explicit UserStyle(XmlIterator iterator);
    ~UserStyle();
    
    UserStyle(const UserStyle&);
    
    std::string nodeName();
    
    std::string name() const;
    std::string title() const;
    std::string abstract() const;
    bool isDefault() const;
    const std::vector<FeatureStyleType>& featureStyleTypes() const;
private:
    std::unique_ptr<UserStylePrivate> _p;
};


}


#endif // USERSTYLE_H