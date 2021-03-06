/* ***** BEGIN LICENSE BLOCK *****
 * This file is part of Natron <https://natrongithub.github.io/>,
 * (C) 2018-2020 The Natron developers
 * (C) 2013-2018 INRIA and Alexandre Gauthier-Foichat
 *
 * Natron is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Natron is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Natron.  If not, see <http://www.gnu.org/licenses/gpl-2.0.html>
 * ***** END LICENSE BLOCK ***** */

#ifndef Gui_NodeGraph_h
#define Gui_NodeGraph_h

// ***** BEGIN PYTHON BLOCK *****
// from <https://docs.python.org/3/c-api/intro.html#include-files>:
// "Since Python may define some pre-processor definitions which affect the standard headers on some systems, you must include Python.h before any standard headers are included."
#include <Python.h>
// ***** END PYTHON BLOCK *****

#include "Global/Macros.h"

#include <string>
#include <list>
#include <set>
#include <utility>
#include <istream>

#if !defined(Q_MOC_RUN) && !defined(SBK_RUN)
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#endif

CLANG_DIAG_OFF(deprecated)
CLANG_DIAG_OFF(uninitialized)
#include <QGraphicsView>
#include <QDialog>
CLANG_DIAG_ON(deprecated)
CLANG_DIAG_ON(uninitialized)

#include "Global/GlobalDefines.h"

#include "Engine/NodeGraphI.h"
#include "Engine/EngineFwd.h"
#include "Engine/TimeValue.h"

#include "Gui/PanelWidget.h"
#include "Gui/GuiFwd.h"

NATRON_NAMESPACE_ENTER

class NodeGraphPrivate;

class NodeGraph
    : public QGraphicsView, public NodeGraphI, public PanelWidget, public boost::noncopyable
{
GCC_DIAG_SUGGEST_OVERRIDE_OFF
    Q_OBJECT
GCC_DIAG_SUGGEST_OVERRIDE_ON

public:

    explicit NodeGraph(Gui* gui,
                       const NodeCollectionPtr& group,
                       const std::string& scriptName,
                       QGraphicsScene* scene = 0,
                       QWidget *parent = 0);

    virtual ~NodeGraph();

    static void makeFullyQualifiedLabel(const NodePtr& node, std::string* ret);
    NodeCollectionPtr getGroup() const;
    NodesGuiList getSelectedNodes() const;

    virtual void createNodeGui(const NodePtr& node, const CreateNodeArgs& args) OVERRIDE FINAL;

    void onNodeAboutToBeCreated(const NodePtr& node, const CreateNodeArgsPtr& args) ;

    void onNodeCreated(const NodePtr& node, const CreateNodeArgsPtr& args);

    void selectNode(const NodeGuiPtr & n, bool addToSelection);

    void deselectNode(const NodeGuiPtr& n);

    void setSelection(const NodesGuiList& nodes);

    void setSelection(const NodesList& nodes);

    void clearSelection();

    ///The visible portion of the graph, in scene coordinates.
    QRectF visibleSceneRect() const;
    QRect visibleWidgetRect() const;

    void deselect();

    QImage getFullSceneScreenShot();

    bool areAllNodesVisible();

    /**
     * @brief Repaint the navigator
     **/
    void updateNavigator();

    const NodesGuiList & getAllActiveNodes() const;
    NodesGuiList getAllActiveNodes_mt_safe() const;
    QGraphicsItem* getRootItem() const;
    virtual void notifyGuiClosing() OVERRIDE FINAL;
    void discardScenePointer();


    /**
     * @brief Removes the given node from the nodegraph, using the undo/redo stack.
     **/
    void removeNode(const NodeGuiPtr & node);

    void centerOnItem(QGraphicsItem* item);

    void setUndoRedoStackLimit(int limit);

    void deleteNodePermanantly(const NodeGuiPtr& n);

    NodesGuiList getNodesWithinBackdrop(const NodeGuiPtr& node) const;

    void selectAllNodes(bool onlyInVisiblePortion);

    /**
     * @brief Calls setParentItem(NULL) on all items of the scene to avoid Qt to double delete the nodes.
     **/
    void invalidateAllNodesParenting();

    bool areKnobLinksVisible() const;

    void refreshNodesKnobsAtTime(bool onlyTimeEvaluationKnobs, TimeValue time);

    bool areOptionalInputsAutoHidden() const;


    virtual void onNodesCleared() OVERRIDE FINAL;

    void setLastSelectedViewer(ViewerTab* tab);

    ViewerTab* getLastSelectedViewer() const;

    void moveNodeToCenterOfVisiblePortion(const NodeGuiPtr &n);

    void setNodeToDefaultPosition(const NodeGuiPtr& n, const NodesGuiList& selectedNodes, const CreateNodeArgs& args);

    void copyNodes(const NodesGuiList& nodes, SERIALIZATION_NAMESPACE::NodeClipBoard& clipboard);

    void duplicateSelectedNodes(const QPointF& pos);
    void cloneSelectedNodes(const QPointF& pos);
    
    bool tryReadClipboard(const QPointF& pos, std::istream& stream);

    QPointF getRootPos() const;

    bool isDoingNavigatorRender() const;

    virtual QIcon getIcon() const OVERRIDE FINAL;

    bool isNodeCloneLinked(const NodePtr& node);

    void refreshNodeLinksNow();

Q_SIGNALS:

    void mustRefreshNodeLinksLater();

public Q_SLOTS:

    void onMustRefreshNodeLinksLaterReceived();

    void refreshNodeLinksLater();
    
    bool pasteClipboard(const QPointF& pos = QPointF(INT_MIN, INT_MIN));

    void deleteSelection();

    void connectCurrentViewerToSelection(int inputNB, bool isASide);

    void updateCacheSizeText();

    void onRefreshNodesRenderStateTimerTimeout();

    void showMenu(const QPoint & pos);

    void toggleCacheInfo();

    void togglePreviewsForSelectedNodes();

    void showSelectedNodeSettingsPanel();

    void toggleAutoPreview();

    void toggleSelectedNodesEnabled();

    void forceRefreshAllPreviews();

    void toggleKnobLinksVisible();

    void switchInputs1and2ForSelectedNodes();

    void extractSelectedNode();

    void createGroupFromSelection();

    void expandSelectedGroups();

    ///All these actions also work for backdrops
    /////////////////////////////////////////////
    ///Copy selected nodes to the clipboard, wiping previous clipboard
    void copySelectedNodes();

    void cutSelectedNodes();
    void duplicateSelectedNodes();
    void cloneSelectedNodes();
    void decloneSelectedNodes();
    /////////////////////////////////////////////

    void centerOnAllNodes();

    void toggleAutoHideInputs(bool setSettings = true);

    void toggleHideInputs();

    void onNodeCreationDialogFinished(bool accepted);

    void popFindDialog( const QPoint& pos = QPoint(0, 0) );

    void renameNode();

    void onFindNodeDialogFinished();

    void refreshAllKnobsGui();

    void onNodeNameEditDialogFinished();

    void toggleAutoTurbo();

    void onGroupNameChanged(const QString& oldLabel, const QString& newLabel);
    void onGroupScriptNameChanged(const QString& name);


    void onAutoScrollTimerTriggered();

private:

    void showNodePanel(bool casIsCtrl, bool casIsShift, const NodeGuiPtr& nearbyNode);

    void checkForHints(bool shiftdown, bool controlDown, const NodeGuiPtr& selectedNode, const QRectF& visibleSceneR);

    void moveSelectedNodesBy(bool shiftdown, bool controlDown, const QPointF& lastMousePosScene, const QPointF& newPos, const QRectF& visibleSceneR, bool userEdit);

    void scrollViewIfNeeded(const QPointF& scenePos);

    void checkAndStartAutoScrollTimer(const QPointF& scenePos);

    bool isNearbyNavigator(const QPoint& widgetPos, QPointF& scenePos) const;

    virtual void enterEvent(QEvent* e) OVERRIDE FINAL;
    virtual void leaveEvent(QEvent* e) OVERRIDE FINAL;
    virtual void keyPressEvent(QKeyEvent* e) OVERRIDE FINAL;
    virtual void keyReleaseEvent(QKeyEvent* e) OVERRIDE FINAL;
    virtual bool event(QEvent* e) OVERRIDE FINAL;
    virtual void mousePressEvent(QMouseEvent* e) OVERRIDE FINAL;
    virtual void mouseReleaseEvent(QMouseEvent* e) OVERRIDE FINAL;
    virtual void mouseMoveEvent(QMouseEvent* e) OVERRIDE FINAL;
    virtual void mouseDoubleClickEvent(QMouseEvent* e) OVERRIDE FINAL;
    virtual void resizeEvent(QResizeEvent* e) OVERRIDE FINAL;
    virtual void paintEvent(QPaintEvent* e) OVERRIDE FINAL;
    virtual void wheelEvent(QWheelEvent* e) OVERRIDE FINAL;
    virtual void focusInEvent(QFocusEvent* e) OVERRIDE FINAL;
    virtual void focusOutEvent(QFocusEvent* e) OVERRIDE FINAL;
    virtual boost::shared_ptr<QUndoStack> getUndoStack() const OVERRIDE FINAL WARN_UNUSED_RETURN;

private:

    enum NearbyItemEnum
    {
        eNearbyItemNone = 0,
        eNearbyItemNode,
        eNearbyItemBackdropResizeHandle,
        eNearbyItemBackdropFrame,
        eNearbyItemNodeEdge,
        eNearbyItemEdgeBendPoint,
    };

    void getNodesWithinViewportRect(const QRect& rect, std::set<NodeGuiPtr>* nodes) const;

    NearbyItemEnum hasItemNearbyMouse(const QPoint& mousePosViewport,
                                      NodeGuiPtr* node,
                                      Edge** edge);

    void moveRootInternal(double dx, double dy);

    void wheelEventInternal(bool ctrlDown, double delta);

    boost::scoped_ptr<NodeGraphPrivate> _imp;
};


struct FindNodeDialogPrivate;
class FindNodeDialog
    : public QDialog
{
GCC_DIAG_SUGGEST_OVERRIDE_OFF
    Q_OBJECT
GCC_DIAG_SUGGEST_OVERRIDE_ON

public:

    FindNodeDialog(NodeGraph* graph,
                   QWidget* parent);

    virtual ~FindNodeDialog();

public Q_SLOTS:

    void onButtonClicked(QAbstractButton* button);

    void updateFindResults(const QString& filter);

    void updateFindResultsWithCurrentFilter();
    void forceUpdateFindResults();

private:


    void selectNextResult();

    virtual void changeEvent(QEvent* e) OVERRIDE FINAL;
    virtual void keyPressEvent(QKeyEvent* e) OVERRIDE FINAL;
    boost::scoped_ptr<FindNodeDialogPrivate> _imp;
};

struct EditNodeNameDialogPrivate;
class EditNodeNameDialog
    : public QDialog
{
GCC_DIAG_SUGGEST_OVERRIDE_OFF
    Q_OBJECT
GCC_DIAG_SUGGEST_OVERRIDE_ON

public:

    EditNodeNameDialog(const NodeGuiPtr& node,
                       QWidget* parent);

    virtual ~EditNodeNameDialog();

    QString getTypedName() const;

    NodeGuiPtr getNode() const;

private:

    virtual void changeEvent(QEvent* e) OVERRIDE FINAL;
    virtual void keyPressEvent(QKeyEvent* e) OVERRIDE FINAL;
    boost::scoped_ptr<EditNodeNameDialogPrivate> _imp;
};

NATRON_NAMESPACE_EXIT

#endif // Gui_NodeGraph_h
