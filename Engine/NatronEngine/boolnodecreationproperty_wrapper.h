#ifndef SBK_BOOLNODECREATIONPROPERTYWRAPPER_H
#define SBK_BOOLNODECREATIONPROPERTYWRAPPER_H

#include <shiboken.h>

#include <PyAppInstance.h>

namespace Natron { namespace Python {
class BoolNodeCreationPropertyWrapper : public BoolNodeCreationProperty
{
public:
    BoolNodeCreationPropertyWrapper(bool value);
    BoolNodeCreationPropertyWrapper(const std::vector<bool > & values = std::vector< bool >());
    virtual ~BoolNodeCreationPropertyWrapper();
    static void pysideInitQtMetaTypes();
};
} }

#endif // SBK_BOOLNODECREATIONPROPERTYWRAPPER_H

