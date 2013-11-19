#ifndef ANDOPERATION_H
#define ANDOPERATION_H

#include "logicoperation.h"
#include "feature.h"

namespace automap {

class AndOperation : public LogicOperation {
public:
    bool check(IFeature&);
};

}

#endif // ANDOPERATION_H

