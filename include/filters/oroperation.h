#ifndef OROPERATION_H
#define OROPERATION_H

#include "logicoperation.h"
#include "feature.h"

namespace automap {
    
class OrOperation : public LogicOperation {
public:
    bool check(IFeature&) const;
};

}

#endif // OROPERATION_H

