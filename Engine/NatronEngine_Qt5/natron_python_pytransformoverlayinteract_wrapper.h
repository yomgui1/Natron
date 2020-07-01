#ifndef SBK_PYTRANSFORMOVERLAYINTERACTWRAPPER_H
#define SBK_PYTRANSFORMOVERLAYINTERACTWRAPPER_H

#include <PyOverlayInteract.h>

class PyTransformOverlayInteractWrapper : public Natron::Python::PyTransformOverlayInteract
{
public:
    PyTransformOverlayInteractWrapper();
    std::map<QString,Natron::Python::PyOverlayParamDesc > describeParameters() const override;
    void draw(double time, const Natron::Python::Double2DTuple & renderScale, QString view) override;
    inline Natron::Python::Param * fetchParameter_protected(const std::map<QString,QString > & params, const QString & role, const QString & type, int nDims, bool optional) const { return Natron::Python::PyTransformOverlayInteract::fetchParameter(params, role, type, nDims, optional); }
    void fetchParameters(const std::map<QString,QString > & params) override;
    bool focusGained(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view) override;
    bool focusLost(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view) override;
    inline void initInternalInteract_protected() { Natron::Python::PyTransformOverlayInteract::initInternalInteract(); }
    bool keyDown(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, Qt::Key key, const QFlags<Qt::KeyboardModifier> & modifiers) override;
    bool keyRepeat(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, Qt::Key key, const QFlags<Qt::KeyboardModifier> & modifiers) override;
    bool keyUp(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, Qt::Key key, const QFlags<Qt::KeyboardModifier> & modifiers) override;
    bool penDoubleClicked(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, const Natron::Python::Double2DTuple & viewportPos, const Natron::Python::Double2DTuple & pos) override;
    bool penDown(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, const Natron::Python::Double2DTuple & viewportPos, const Natron::Python::Double2DTuple & pos, double pressure, double timestamp, Natron::PenType pen) override;
    bool penMotion(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, const Natron::Python::Double2DTuple & viewportPos, const Natron::Python::Double2DTuple & pos, double pressure, double timestamp) override;
    bool penUp(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, const Natron::Python::Double2DTuple & viewportPos, const Natron::Python::Double2DTuple & pos, double pressure, double timestamp) override;
    ~PyTransformOverlayInteractWrapper();
    static void pysideInitQtMetaTypes();
};

#  ifndef SBK_PYOVERLAYINTERACTWRAPPER_H
#  define SBK_PYOVERLAYINTERACTWRAPPER_H

// Inherited base class:
class PyOverlayInteractWrapper : public Natron::Python::PyOverlayInteract
{
public:
    PyOverlayInteractWrapper();
    std::map<QString,Natron::Python::PyOverlayParamDesc > describeParameters() const override;
    void draw(double time, const Natron::Python::Double2DTuple & renderScale, QString view) override;
    inline Natron::Python::Param * fetchParameter_protected(const std::map<QString,QString > & params, const QString & role, const QString & type, int nDims, bool optional) const { return Natron::Python::PyOverlayInteract::fetchParameter(params, role, type, nDims, optional); }
    void fetchParameters(const std::map<QString,QString > & params) override;
    bool focusGained(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view) override;
    bool focusLost(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view) override;
    inline void initInternalInteract_protected() { Natron::Python::PyOverlayInteract::initInternalInteract(); }
    bool keyDown(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, Qt::Key key, const QFlags<Qt::KeyboardModifier> & modifiers) override;
    bool keyRepeat(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, Qt::Key key, const QFlags<Qt::KeyboardModifier> & modifiers) override;
    bool keyUp(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, Qt::Key key, const QFlags<Qt::KeyboardModifier> & modifiers) override;
    bool penDoubleClicked(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, const Natron::Python::Double2DTuple & viewportPos, const Natron::Python::Double2DTuple & pos) override;
    bool penDown(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, const Natron::Python::Double2DTuple & viewportPos, const Natron::Python::Double2DTuple & pos, double pressure, double timestamp, Natron::PenType pen) override;
    bool penMotion(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, const Natron::Python::Double2DTuple & viewportPos, const Natron::Python::Double2DTuple & pos, double pressure, double timestamp) override;
    bool penUp(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, const Natron::Python::Double2DTuple & viewportPos, const Natron::Python::Double2DTuple & pos, double pressure, double timestamp) override;
    ~PyOverlayInteractWrapper();
    static void pysideInitQtMetaTypes();
};

#  endif // SBK_PYOVERLAYINTERACTWRAPPER_H

#endif // SBK_PYTRANSFORMOVERLAYINTERACTWRAPPER_H

