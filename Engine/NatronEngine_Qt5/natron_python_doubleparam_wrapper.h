#ifndef SBK_DOUBLEPARAMWRAPPER_H
#define SBK_DOUBLEPARAMWRAPPER_H

#include <PyParameter.h>

class DoubleParamWrapper : public Natron::Python::DoubleParam
{
public:
    inline void _addAsDependencyOf_protected(Natron::Python::Param * param, int fromExprDimension, int thisDimension, const QString & fromExprView, const QString & thisView) { Natron::Python::DoubleParam::_addAsDependencyOf(param, fromExprDimension, thisDimension, fromExprView, thisView); }
    ~DoubleParamWrapper();
    static void pysideInitQtMetaTypes();
};

#  ifndef SBK_ANIMATEDPARAMWRAPPER_H
#  define SBK_ANIMATEDPARAMWRAPPER_H

// Inherited base class:
class AnimatedParamWrapper : public Natron::Python::AnimatedParam
{
public:
    inline void _addAsDependencyOf_protected(Natron::Python::Param * param, int fromExprDimension, int thisDimension, const QString & fromExprView, const QString & thisView) { Natron::Python::AnimatedParam::_addAsDependencyOf(param, fromExprDimension, thisDimension, fromExprView, thisView); }
    ~AnimatedParamWrapper();
    static void pysideInitQtMetaTypes();
};

#  endif // SBK_ANIMATEDPARAMWRAPPER_H

#  ifndef SBK_PARAMWRAPPER_H
#  define SBK_PARAMWRAPPER_H

// Inherited base class:
class ParamWrapper : public Natron::Python::Param
{
public:
    inline void _addAsDependencyOf_protected(Natron::Python::Param * param, int fromExprDimension, int thisDimension, const QString & fromExprView, const QString & thisView) { Natron::Python::Param::_addAsDependencyOf(param, fromExprDimension, thisDimension, fromExprView, thisView); }
    ~ParamWrapper();
    static void pysideInitQtMetaTypes();
};

#  endif // SBK_PARAMWRAPPER_H

#endif // SBK_DOUBLEPARAMWRAPPER_H

