#ifndef FEATURESTYLETYPE_H
#define FEATURESTYLETYPE_H

#include "sldnode.h"
#include "rule.h"

namespace automap {
    
class FeatureStyleType : public SLDNode {
public:
    FeatureStyleType(XmlIterator);
    ~FeatureStyleType();
    
    std::string name() const;
    std::string title() const;
    std::string abstract() const;
    std::string featureTypeName() const;
    std::vector<std::string> semanticTypeIdentifiers() const;
    const std::vector<Rule>& rules() const;
    
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