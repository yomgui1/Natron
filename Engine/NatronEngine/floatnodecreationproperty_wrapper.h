#ifndef SBK_FLOATNODECREATIONPROPERTYWRAPPER_H
#define SBK_FLOATNODECREATIONPROPERTYWRAPPER_H

#include <shiboken.h>

#include <PyAppInstance.h>

namespace Natron { namespace Python {
class FloatNodeCreationPropertyWrapper : public FloatNodeCreationProperty
{
public:
    FloatNodeCreationPropertyWrapper(const std::vector<double > & values = std::vector< double >());
    FloatNodeCreationPropertyWrapper(double value);
    virtual ~FloatNodeCreationPropertyWrapper();
    static void pysideInitQtMetaTypes();
};
} }

#endif // SBK_FLOATNODECREATIONPROPERTYWRAPPER_H

