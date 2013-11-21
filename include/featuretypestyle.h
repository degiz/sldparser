#ifndef FEATURE_STYLE_TYPE_H
#define FEATURE_STYLE_TYPE_H

#include <memory>
#include <vector>

#include "rule.h"

namespace SldParser {

class FeatureStyleTypePrivate;
class XmlIterator;
    
class FeatureStyleType {
public:
    explicit FeatureStyleType(XmlIterator iterator);
    ~FeatureStyleType();
    
    FeatureStyleType(const FeatureStyleType&);
    
    std::string nodeName() const;
    
    std::string name() const;
    std::string title() const;
    std::string abstract() const;
    std::string featureTypeName() const;
    std::vector<std::string> semanticTypeIdentifiers() const;
    const std::vector<Rule>& rules() const;
    
private:
    std::unique_ptr<FeatureStyleTypePrivate> _p;
};
    
};

#endif // FEATURE_STYLE_TYPE_H