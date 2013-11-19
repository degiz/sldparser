#ifndef FEATURE_H
#define FEATURE_H

#include "variant.h"

#include <string>
#include <map>

namespace automap {

template<class T>
class Feature {
    Feature(T feature) {
        _feature = feature;
    }
    virtual Variant getFieldValue(std::string fieldName) = 0;
protected:
    T _feature;
};

template<class T>
class FeatureMap : public Feature<std::map<std::string, std::string> > {
    Variant getFieldValue(std::string fieldName) {
        std::string value = _feature.find(fieldName);
        return Variant::fromString(value);
    }
};

}

#endif // FEATURE_H