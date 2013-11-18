#ifndef FEATURESTYLETYPE_H
#define FEATURESTYLETYPE_H

#include "sldnode.h"
#include "rule.h"

namespace automap {
    
class FeatureStyleType : public SLDNode {
public:
    FeatureStyleType(XmlIterator);
    ~FeatureStyleType();
    
    std::string name();
    std::string title();
    std::string abstract();
    std::string featureTypeName();
    std::vector<std::string> semanticTypeIdentifiers();
    std::vector<Rule>& rules();
    
private:
    std::string _name;
    std::string _title;
    std::string _abstract;
    std::string _featureTypeName;
    std::vector<std::string> _semanticTypeIdentifiers;
    std::vector<Rule> _rules;

    void _parseNode();
};
    
};

#endif // FEATURESTYLETYPE_H