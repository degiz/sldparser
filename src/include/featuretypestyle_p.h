#ifndef FEATURE_STYLE_TYPE_PRIVATE_H
#define FEATURE_STYLE_TYPE_PRIVATE_H

#include "sldnode.h"
#include "rule.h"

namespace SldParser {
    
class FeatureStyleTypePrivate : public SLDNode {
public:
    FeatureStyleTypePrivate(XmlIterator);
    ~FeatureStyleTypePrivate();
    
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

#endif // FEATURE_STYLE_TYPE_PRIVATE_H