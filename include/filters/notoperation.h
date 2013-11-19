#ifndef NOTOPERATION_H
#define NOTOPERATION_H

#include "logicoperation.h"
#include "feature.h"

namespace automap {
    
class NotOperation : public LogicOperation {
public:
    bool check(IFeature&) const;
};

}

#endif // NOTOPERATION_H

