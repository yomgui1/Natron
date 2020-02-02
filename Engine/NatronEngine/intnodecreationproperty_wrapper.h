#ifndef SBK_INTNODECREATIONPROPERTYWRAPPER_H
#define SBK_INTNODECREATIONPROPERTYWRAPPER_H

#include <shiboken.h>

#include <PyAppInstance.h>

namespace Natron { namespace Python {
class IntNodeCreationPropertyWrapper : public IntNodeCreationProperty
{
public:
    IntNodeCreationPropertyWrapper(const std::vector<int > & values = std::vector< int >());
    IntNodeCreationPropertyWrapper(int value);
    virtual ~IntNodeCreationPropertyWrapper();
    static void pysideInitQtMetaTypes();
};
} }

#endif // SBK_INTNODECREATIONPROPERTYWRAPPER_H

