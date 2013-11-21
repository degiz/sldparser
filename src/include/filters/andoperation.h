#ifndef ANDOPERATION_H
#define ANDOPERATION_H

#include "logicoperation.h"
#include "feature.h"

namespace SldParser {

class AndOperation : public LogicOperation {
public:
    bool check(IFeature&) const;
};

}

#endif // ANDOPERATION_H

