#ifndef SBK_PARAMETRICPARAMWRAPPER_H
#define SBK_PARAMETRICPARAMWRAPPER_H

#include <shiboken.h>

#include <PyParameter.h>

namespace Natron { namespace Python {
class ParametricParamWrapper : public ParametricParam
{
public:
    inline void _addAsDependencyOf_protected(int fromExprDimension, Param * param, int thisDimension) { ParametricParam::_addAsDependencyOf(fromExprDimension, param, thisDimension); }
    virtual ~ParametricParamWrapper();
    static void pysideInitQtMetaTypes();
};
} }

#endif // SBK_PARAMETRICPARAMWRAPPER_H

