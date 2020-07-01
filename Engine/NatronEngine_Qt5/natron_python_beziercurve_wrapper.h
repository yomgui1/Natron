#ifndef SBK_BEZIERCURVEWRAPPER_H
#define SBK_BEZIERCURVEWRAPPER_H

#include <PyRoto.h>

class BezierCurveWrapper : public Natron::Python::BezierCurve
{
public:
    ~BezierCurveWrapper();
    static void pysideInitQtMetaTypes();
};

#  ifndef SBK_ITEMBASEWRAPPER_H
#  define SBK_ITEMBASEWRAPPER_H

// Inherited base class:
class ItemBaseWrapper : public Natron::Python::ItemBase
{
public:
    ~ItemBaseWrapper();
    static void pysideInitQtMetaTypes();
};

#  endif // SBK_ITEMBASEWRAPPER_H

#endif // SBK_BEZIERCURVEWRAPPER_H

