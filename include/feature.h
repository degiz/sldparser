#ifndef FEATURE_H
#define FEATURE_H

#include "variant.h"

#include <string>

namespace SldParser {

class IFeature {
public:
    virtual Variant getFieldValue(std::string fieldName) = 0;
};

struct FeatureProperty {
    FeatureProperty(std::string inName, Variant inValue) :
    name(inName),
    value(inValue)
    {}
    std::string name;
    Variant value;
};

}

#endif // FEATURE_H