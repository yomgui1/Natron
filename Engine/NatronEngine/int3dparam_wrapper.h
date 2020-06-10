#ifndef SBK_INT3DPARAMWRAPPER_H
#define SBK_INT3DPARAMWRAPPER_H

#include <shiboken.h>

#include <PyParameter.h>

namespace Natron { namespace Python {
class Int3DParamWrapper : public Int3DParam
{
public:
    inline void _addAsDependencyOf_protected(int fromExprDimension, Param * param, int thisDimension) { Int3DParam::_addAsDependencyOf(fromExprDimension, param, thisDimension); }
    virtual ~Int3DParamWrapper();
    static void pysideInitQtMetaTypes();
};
} }

#endif // SBK_INT3DPARAMWRAPPER_H

