#ifndef USERSTYLE_PRIVATE_H
#define USERSTYLE_PRIVATE_H

#include "sldnode.h"
#include "featuretypestyle.h"

#include <vector>
#include <map>
#include <string>

namespace SldParser {
    
class UserStylePrivate : public SLDNode {
public:
    UserStylePrivate(XmlIterator);
    ~UserStylePrivate();
    
    std::string name() const;
    std::string title() const;
    std::string abstract() const;
    bool isDefault() const;
    const std::vector<FeatureStyleType>& featureStyleTypes() const;
    
    
private:
    std::string _name;
    std::string _title;
    std::string _abstract;
    bool _isDefault;
    std::vector<FeatureStyleType> _features;
    
    xmlNode* _node;
    
    void _parseNode();
};
    
};

#endif // USERSTYLE_PRIVATE_H