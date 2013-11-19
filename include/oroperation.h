#ifndef OROPERATION_H
#define OROPERATION_H

#include "logicoperation.h"
#include "feature.h"

namespace automap {
    
class OrOperation : public LogicOperation {
public:
    template<class T>
    bool check(Feature<T>);
};

}

#endif // OROPERATION_H

