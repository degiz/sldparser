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
    UserStyle(xmlNode*);
    ~UserStyle();
    
    std::string name();
    std::string title();
    std::string abstract();
    bool isDefault();
    std::vector<FeatureStyleType> featureStyleTypes();
    
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