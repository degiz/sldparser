#ifndef USERSTYLE_H
#define USERSTYLE_H

#include "sldnode.h"
#include "featuretypestyle.h"

#include <vector>
#include <map>
#include <string>

namespace automap {
    
class UserStyle : public SLDNode {
public:
    UserStyle(XmlIterator);
    ~UserStyle();
    
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

#endif // USERSTYLE_H