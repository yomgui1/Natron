#ifndef SBK_INT2DPARAMWRAPPER_H
#define SBK_INT2DPARAMWRAPPER_H

#include <PyParameter.h>

class Int2DParamWrapper : public Natron::Python::Int2DParam
{
public:
    inline void _addAsDependencyOf_protected(Natron::Python::Param * param, int fromExprDimension, int thisDimension, const QString & fromExprView, const QString & thisView) { Natron::Python::Int2DParam::_addAsDependencyOf(param, fromExprDimension, thisDimension, fromExprView, thisView); }
    ~Int2DParamWrapper();
    static void pysideInitQtMetaTypes();
};

#  ifndef SBK_INTPARAMWRAPPER_H
#  define SBK_INTPARAMWRAPPER_H

// Inherited base class:
class IntParamWrapper : public Natron::Python::IntParam
{
public:
    inline void _addAsDependencyOf_protected(Natron::Python::Param * param, int fromExprDimension, int thisDimension, const QString & fromExprView, const QString & thisView) { Natron::Python::IntParam::_addAsDependencyOf(param, fromExprDimension, thisDimension, fromExprView, thisView); }
    ~IntParamWrapper();
    static void pysideInitQtMetaTypes();
};

#  endif // SBK_INTPARAMWRAPPER_H

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

#endif // SBK_INT2DPARAMWRAPPER_H

