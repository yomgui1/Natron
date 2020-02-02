#ifndef SBK_BEZIERCURVEWRAPPER_H
#define SBK_BEZIERCURVEWRAPPER_H

#include <shiboken.h>

#include <PyRoto.h>

namespace Natron { namespace Python {
class BezierCurveWrapper : public BezierCurve
{
public:
    virtual ~BezierCurveWrapper();
    static void pysideInitQtMetaTypes();
};
} }

#endif // SBK_BEZIERCURVEWRAPPER_H

