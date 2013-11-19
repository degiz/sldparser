#ifndef FEATURE_H
#define FEATURE_H

#include "variant.h"

#include <string>

namespace automap {

class IFeature {
public:
    virtual Variant getFieldValue(std::string fieldName) = 0;
};

}

#endif // FEATURE_H