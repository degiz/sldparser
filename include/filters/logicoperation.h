#ifndef LOGIC_OPERATION_H
#define LOGIC_OPERATION_H

#include "filteroperation.h"
#include "feature.h"

#include <vector>
#include <memory>

namespace automap {

class LogicOperation : public FilterOperation {
public:

    void add(std::shared_ptr<FilterOperation>);
    
protected:
    std::vector<std::shared_ptr<FilterOperation> > _operations;
};

}

#endif // LOGIC_OPERATION_H