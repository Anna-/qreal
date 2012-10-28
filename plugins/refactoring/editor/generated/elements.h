#pragma once

#include <QBrush>
#include <QPainter>

#include "../../../../qrgui/editorPluginInterface/elementImpl.h"
#include "../../../../qrgui/editorPluginInterface/elementRepoInterface.h"
#include "../../../../qrgui/editorPluginInterface/elementTitleHelpers.h"

	class AfterBlock : public ElementImpl
	{
	public:
		void init(ElementTitleFactoryInterface &, QList<ElementTitleInterface*> &) {}

		void init(QRectF &contents, QList<StatPoint> &pointPorts,
							QList<StatLine> &linePorts, ElementTitleFactoryInterface &factory,
							QList<ElementTitleInterface*> &titles, SdfRendererInterface *renderer,
							SdfRendererInterface *portRenderer)
		{
			Q_UNUSED(linePorts);
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/AfterBlockClass.sdf"));
			portRenderer->load(QString(":/generated/shapes/AfterBlockPorts.sdf"));
			contents.setWidth(200);
			contents.setHeight(200);
			{
				StatPoint pt;
				pt.point = QPointF(0, 0.5);
				pt.prop_x = false;
				pt.prop_y = false; 
				pt.initWidth = 200;
				pt.initHeight = 200;
				pointPorts << pt;
			};
			{
				StatPoint pt;
				pt.point = QPointF(0.5, 0);
				pt.prop_x = false;
				pt.prop_y = false; 
				pt.initWidth = 200;
				pt.initHeight = 200;
				pointPorts << pt;
			};
			{
				StatPoint pt;
				pt.point = QPointF(1, 0.5);
				pt.prop_x = false;
				pt.prop_y = false; 
				pt.initWidth = 200;
				pt.initHeight = 200;
				pointPorts << pt;
			};
			{
				StatPoint pt;
				pt.point = QPointF(0.5, 1);
				pt.prop_x = false;
				pt.prop_y = false; 
				pt.initWidth = 200;
				pt.initHeight = 200;
				pointPorts << pt;
			};
			title_1 = factory.createTitle(0.025, 0.025, QString::fromUtf8("<b>AFTER</b>"));
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setFlags(0);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 ElementImpl *clone() { return NULL; }
		~AfterBlock() {}

		void paint(QPainter *painter, QRectF &contents)
		{
			mRenderer->render(painter, contents);
		}

		Qt::PenStyle getPenStyle() const { return Qt::SolidLine; }

		int getPenWidth() const { return 0; }

		QColor getPenColor() const { return QColor(); }

		void drawStartArrow(QPainter *) const {}
		void drawEndArrow(QPainter *) const {}
		bool hasPorts() const
		{
			return true;
		}

		void updateData(ElementRepoInterface *repo) const
		{
			Q_UNUSED(repo);
		}

		bool isNode() const
		{
			return true;
		}

		bool isResizeable() const
		{
			return true;
		}

		bool isContainer() const
		{
			return true;
		}

		bool isSortingContainer() const
		{
			return false;
		}

		int sizeOfForestalling() const
		{
			return 0;
		}

		int sizeOfChildrenForestalling() const
		{
			return 0;
		}

		bool hasMovableChildren() const
		{
			return true;
		}

		bool minimizesToChildren() const
		{
			return false;
		}

		bool maximizesChildren() const
		{
			return false;
		}

		bool isDividable() const
		{
			return false;
		}

		bool isPort() const
		{
			return false;
		}

		bool hasPin() const
		{
			return false;
		}

		QList<double> border() const
		{
			QList<double> list;
			list << 0 << 0 << 0 << 0;
			return list;
		}

		QStringList bonusContextMenuFields() const
		{
			return QStringList();
		}

	private:
		SdfRendererInterface *mRenderer;
		ElementTitleInterface *title_1;
	};

	class BeforeBlock : public ElementImpl
	{
	public:
		void init(ElementTitleFactoryInterface &, QList<ElementTitleInterface*> &) {}

		void init(QRectF &contents, QList<StatPoint> &pointPorts,
							QList<StatLine> &linePorts, ElementTitleFactoryInterface &factory,
							QList<ElementTitleInterface*> &titles, SdfRendererInterface *renderer,
							SdfRendererInterface *portRenderer)
		{
			Q_UNUSED(linePorts);
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/BeforeBlockClass.sdf"));
			portRenderer->load(QString(":/generated/shapes/BeforeBlockPorts.sdf"));
			contents.setWidth(200);
			contents.setHeight(200);
			{
				StatPoint pt;
				pt.point = QPointF(0, 0.5);
				pt.prop_x = false;
				pt.prop_y = false; 
				pt.initWidth = 200;
				pt.initHeight = 200;
				pointPorts << pt;
			};
			{
				StatPoint pt;
				pt.point = QPointF(0.5, 0);
				pt.prop_x = false;
				pt.prop_y = false; 
				pt.initWidth = 200;
				pt.initHeight = 200;
				pointPorts << pt;
			};
			{
				StatPoint pt;
				pt.point = QPointF(1, 0.5);
				pt.prop_x = false;
				pt.prop_y = false; 
				pt.initWidth = 200;
				pt.initHeight = 200;
				pointPorts << pt;
			};
			{
				StatPoint pt;
				pt.point = QPointF(0.5, 1);
				pt.prop_x = false;
				pt.prop_y = false; 
				pt.initWidth = 200;
				pt.initHeight = 200;
				pointPorts << pt;
			};
			title_1 = factory.createTitle(0.025, 0.025, QString::fromUtf8("<b>BEFORE</b>"));
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setFlags(0);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 ElementImpl *clone() { return NULL; }
		~BeforeBlock() {}

		void paint(QPainter *painter, QRectF &contents)
		{
			mRenderer->render(painter, contents);
		}

		Qt::PenStyle getPenStyle() const { return Qt::SolidLine; }

		int getPenWidth() const { return 0; }

		QColor getPenColor() const { return QColor(); }

		void drawStartArrow(QPainter *) const {}
		void drawEndArrow(QPainter *) const {}
		bool hasPorts() const
		{
			return true;
		}

		void updateData(ElementRepoInterface *repo) const
		{
			Q_UNUSED(repo);
		}

		bool isNode() const
		{
			return true;
		}

		bool isResizeable() const
		{
			return true;
		}

		bool isContainer() const
		{
			return true;
		}

		bool isSortingContainer() const
		{
			return false;
		}

		int sizeOfForestalling() const
		{
			return 0;
		}

		int sizeOfChildrenForestalling() const
		{
			return 0;
		}

		bool hasMovableChildren() const
		{
			return true;
		}

		bool minimizesToChildren() const
		{
			return false;
		}

		bool maximizesChildren() const
		{
			return false;
		}

		bool isDividable() const
		{
			return false;
		}

		bool isPort() const
		{
			return false;
		}

		bool hasPin() const
		{
			return false;
		}

		QList<double> border() const
		{
			QList<double> list;
			list << 0 << 0 << 0 << 0;
			return list;
		}

		QStringList bonusContextMenuFields() const
		{
			return QStringList();
		}

	private:
		SdfRendererInterface *mRenderer;
		ElementTitleInterface *title_1;
	};

	class Element : public ElementImpl
	{
	public:
		void init(ElementTitleFactoryInterface &, QList<ElementTitleInterface*> &) {}

		void init(QRectF &contents, QList<StatPoint> &pointPorts,
							QList<StatLine> &linePorts, ElementTitleFactoryInterface &factory,
							QList<ElementTitleInterface*> &titles, SdfRendererInterface *renderer,
							SdfRendererInterface *portRenderer)
		{
			Q_UNUSED(pointPorts);
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/ElementClass.sdf"));
			portRenderer->load(QString(":/generated/shapes/ElementPorts.sdf"));
			contents.setWidth(80);
			contents.setHeight(80);
			{
				StatLine ln;
				ln.line = QLineF(0, 0.125, 0, 0.875);
				ln.prop_x1 = false;
				ln.prop_y1 = false; 
				ln.prop_x2 = false; 
				ln.prop_y2 = false; 
				ln.initWidth = 80;
				ln.initHeight = 80;
				linePorts << ln;
			};
			{
				StatLine ln;
				ln.line = QLineF(0.125, 0, 0.875, 0);
				ln.prop_x1 = false;
				ln.prop_y1 = false; 
				ln.prop_x2 = false; 
				ln.prop_y2 = false; 
				ln.initWidth = 80;
				ln.initHeight = 80;
				linePorts << ln;
			};
			{
				StatLine ln;
				ln.line = QLineF(1, 0.125, 1, 0.875);
				ln.prop_x1 = false;
				ln.prop_y1 = false; 
				ln.prop_x2 = false; 
				ln.prop_y2 = false; 
				ln.initWidth = 80;
				ln.initHeight = 80;
				linePorts << ln;
			};
			{
				StatLine ln;
				ln.line = QLineF(0.125, 1, 0.875, 1);
				ln.prop_x1 = false;
				ln.prop_y1 = false; 
				ln.prop_x2 = false; 
				ln.prop_y2 = false; 
				ln.initWidth = 80;
				ln.initHeight = 80;
				linePorts << ln;
			};
			title_1 = factory.createTitle(1, 0, "ID", false);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setFlags(0);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
			title_2 = factory.createTitle(0.0625, 0.0625, "name", false);
			title_2->setBackground(Qt::transparent);
			title_2->setScaling(false, false);
			title_2->setFlags(0);
			title_2->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_2);
		}

		 ElementImpl *clone() { return NULL; }
		~Element() {}

		void paint(QPainter *painter, QRectF &contents)
		{
			mRenderer->render(painter, contents);
		}

		Qt::PenStyle getPenStyle() const { return Qt::SolidLine; }

		int getPenWidth() const { return 0; }

		QColor getPenColor() const { return QColor(); }

		void drawStartArrow(QPainter *) const {}
		void drawEndArrow(QPainter *) const {}
		bool hasPorts() const
		{
			return true;
		}

		void updateData(ElementRepoInterface *repo) const
		{
			title_1->setHtml(QString("<b>%1</b>").arg(repo->logicalProperty("ID")).replace("\n", "<br>"));
			title_2->setHtml(QString("<b>%1</b>").arg(repo->name()).replace("\n", "<br>"));
		}

		bool isNode() const
		{
			return true;
		}

		bool isResizeable() const
		{
			return true;
		}

		bool isContainer() const
		{
			return false;
		}

		bool isSortingContainer() const
		{
			return false;
		}

		int sizeOfForestalling() const
		{
			return 0;
		}

		int sizeOfChildrenForestalling() const
		{
			return 0;
		}

		bool hasMovableChildren() const
		{
			return true;
		}

		bool minimizesToChildren() const
		{
			return false;
		}

		bool maximizesChildren() const
		{
			return false;
		}

		bool isDividable() const
		{
			return false;
		}

		bool isPort() const
		{
			return false;
		}

		bool hasPin() const
		{
			return false;
		}

		QList<double> border() const
		{
			QList<double> list;
			list << 0 << 0 << 0 << 0;
			return list;
		}

		QStringList bonusContextMenuFields() const
		{
			return QStringList();
		}

	private:
		SdfRendererInterface *mRenderer;
		ElementTitleInterface *title_1;
		ElementTitleInterface *title_2;
	};

	class FromBeforeToAter : public ElementImpl
	{
	public:
		void init(ElementTitleFactoryInterface &, QList<ElementTitleInterface*> &) {}

		void init(QRectF &contents, QList<StatPoint> &pointPorts,
							QList<StatLine> &linePorts, ElementTitleFactoryInterface &factory,
							QList<ElementTitleInterface*> &titles, SdfRendererInterface *renderer,
							SdfRendererInterface *portRenderer)
		{
			Q_UNUSED(pointPorts);
			Q_UNUSED(titles);
			Q_UNUSED(factory);
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/FromBeforeToAterClass.sdf"));
			portRenderer->load(QString(":/generated/shapes/FromBeforeToAterPorts.sdf"));
			contents.setWidth(100);
			contents.setHeight(100);
			{
				StatLine ln;
				ln.line = QLineF(0.3, 0, 0.7, 0);
				ln.prop_x1 = false;
				ln.prop_y1 = false; 
				ln.prop_x2 = false; 
				ln.prop_y2 = false; 
				ln.initWidth = 100;
				ln.initHeight = 100;
				linePorts << ln;
			};
			{
				StatLine ln;
				ln.line = QLineF(0, 0.3, 0, 0.7);
				ln.prop_x1 = false;
				ln.prop_y1 = false; 
				ln.prop_x2 = false; 
				ln.prop_y2 = false; 
				ln.initWidth = 100;
				ln.initHeight = 100;
				linePorts << ln;
			};
			{
				StatLine ln;
				ln.line = QLineF(1, 0.3, 1, 0.7);
				ln.prop_x1 = false;
				ln.prop_y1 = false; 
				ln.prop_x2 = false; 
				ln.prop_y2 = false; 
				ln.initWidth = 100;
				ln.initHeight = 100;
				linePorts << ln;
			};
			{
				StatLine ln;
				ln.line = QLineF(0.3, 1, 0.7, 1);
				ln.prop_x1 = false;
				ln.prop_y1 = false; 
				ln.prop_x2 = false; 
				ln.prop_y2 = false; 
				ln.initWidth = 100;
				ln.initHeight = 100;
				linePorts << ln;
			};
		}

		 ElementImpl *clone() { return NULL; }
		~FromBeforeToAter() {}

		void paint(QPainter *painter, QRectF &contents)
		{
			mRenderer->render(painter, contents);
		}

		Qt::PenStyle getPenStyle() const { return Qt::SolidLine; }

		int getPenWidth() const { return 0; }

		QColor getPenColor() const { return QColor(); }

		void drawStartArrow(QPainter *) const {}
		void drawEndArrow(QPainter *) const {}
		bool hasPorts() const
		{
			return true;
		}

		void updateData(ElementRepoInterface *repo) const
		{
			Q_UNUSED(repo);
		}

		bool isNode() const
		{
			return true;
		}

		bool isResizeable() const
		{
			return false;
		}

		bool isContainer() const
		{
			return false;
		}

		bool isSortingContainer() const
		{
			return false;
		}

		int sizeOfForestalling() const
		{
			return 0;
		}

		int sizeOfChildrenForestalling() const
		{
			return 0;
		}

		bool hasMovableChildren() const
		{
			return true;
		}

		bool minimizesToChildren() const
		{
			return false;
		}

		bool maximizesChildren() const
		{
			return false;
		}

		bool isDividable() const
		{
			return false;
		}

		bool isPort() const
		{
			return false;
		}

		bool hasPin() const
		{
			return false;
		}

		QList<double> border() const
		{
			QList<double> list;
			list << 0 << 0 << 0 << 0;
			return list;
		}

		QStringList bonusContextMenuFields() const
		{
			return QStringList();
		}

	private:
		SdfRendererInterface *mRenderer;
	};

	class Link : public ElementImpl {
	public:
		void init(QRectF &, QList<StatPoint> &, QList<StatLine> &,
											ElementTitleFactoryInterface &, QList<ElementTitleInterface*> &,
											SdfRendererInterface *, SdfRendererInterface *) {}

		void init(ElementTitleFactoryInterface &factory, QList<ElementTitleInterface*> &titles)
		{
			title_1 = factory.createTitle(0, 0, "ID", false);
			title_1->setBackground(Qt::white);
			title_1->setScaling(false, false);
			title_1->setFlags(0);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		virtual ~Link() {}

		ElementImpl *clone() { return NULL; }
		void paint(QPainter *, QRectF &){}
		bool isNode() const { return false; }
		bool isResizeable() const { return true; }
		bool isContainer() const { return false; }
		bool isDividable() const { return false; }
		bool isSortingContainer() const { return false; }
		int sizeOfForestalling() const { return 0; }
		int sizeOfChildrenForestalling() const { return 0; }
		bool hasMovableChildren() const { return false; }
		bool minimizesToChildren() const { return false; }
		bool maximizesChildren() const { return false; }
		bool isPort() const { return false; }
		bool hasPin() const { return false; }
		QList<double> border() const
		{
			QList<double> list;
			list << 0 << 0 << 0 << 0;
			return list;
		}
		bool hasPorts() const { return false; }
		int getPenWidth() const { return 1; }
		QColor getPenColor() const { return QColor(0,0,0); }
		Qt::PenStyle getPenStyle() const { return Qt::SolidLine; }
		QStringList bonusContextMenuFields() const
		{
			return QStringList();
		}

	protected:
		virtual void drawStartArrow(QPainter * painter) const
		{
			QBrush old = painter->brush();
			QBrush brush;
			brush.setStyle(Qt::SolidPattern);
			painter->setBrush(brush);
			painter->setBrush(old);
		}

		virtual void drawEndArrow(QPainter * painter) const
		{
			QBrush old = painter->brush();
			QBrush brush;
			brush.setStyle(Qt::SolidPattern);
			painter->setBrush(brush);
			static const QPointF points[] = {
				QPointF(-5,10),
				QPointF(0,0),
				QPointF(5,10)
			};
			painter->drawPolyline(points, 3);
			painter->setBrush(old);
		}

		void updateData(ElementRepoInterface *repo) const
		{
			title_1->setHtml(QString("<b>%1</b>").arg(repo->logicalProperty("ID")).replace("\n", "<br>"));
		}

	private:
		ElementTitleInterface *title_1;
	};

	class RefactoringDiagramNode : public ElementImpl
	{
	public:
		void init(ElementTitleFactoryInterface &, QList<ElementTitleInterface*> &) {}

		void init(QRectF &contents, QList<StatPoint> &pointPorts,
							QList<StatLine> &linePorts, ElementTitleFactoryInterface &factory,
							QList<ElementTitleInterface*> &titles, SdfRendererInterface *renderer,
							SdfRendererInterface *portRenderer)
		{
			Q_UNUSED(pointPorts);
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/RefactoringDiagramNodeClass.sdf"));
			portRenderer->load(QString(":/generated/shapes/RefactoringDiagramNodePorts.sdf"));
			contents.setWidth(100);
			contents.setHeight(100);
			{
				StatLine ln;
				ln.line = QLineF(0.3, 0, 0.7, 0);
				ln.prop_x1 = false;
				ln.prop_y1 = false; 
				ln.prop_x2 = false; 
				ln.prop_y2 = false; 
				ln.initWidth = 100;
				ln.initHeight = 100;
				linePorts << ln;
			};
			{
				StatLine ln;
				ln.line = QLineF(0, 0.3, 0, 0.7);
				ln.prop_x1 = false;
				ln.prop_y1 = false; 
				ln.prop_x2 = false; 
				ln.prop_y2 = false; 
				ln.initWidth = 100;
				ln.initHeight = 100;
				linePorts << ln;
			};
			{
				StatLine ln;
				ln.line = QLineF(1, 0.3, 1, 0.7);
				ln.prop_x1 = false;
				ln.prop_y1 = false; 
				ln.prop_x2 = false; 
				ln.prop_y2 = false; 
				ln.initWidth = 100;
				ln.initHeight = 100;
				linePorts << ln;
			};
			{
				StatLine ln;
				ln.line = QLineF(0.3, 1, 0.7, 1);
				ln.prop_x1 = false;
				ln.prop_y1 = false; 
				ln.prop_x2 = false; 
				ln.prop_y2 = false; 
				ln.initWidth = 100;
				ln.initHeight = 100;
				linePorts << ln;
			};
			title_1 = factory.createTitle(0.05, 0.95, "name", false);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setFlags(0);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 ElementImpl *clone() { return NULL; }
		~RefactoringDiagramNode() {}

		void paint(QPainter *painter, QRectF &contents)
		{
			mRenderer->render(painter, contents);
		}

		Qt::PenStyle getPenStyle() const { return Qt::SolidLine; }

		int getPenWidth() const { return 0; }

		QColor getPenColor() const { return QColor(); }

		void drawStartArrow(QPainter *) const {}
		void drawEndArrow(QPainter *) const {}
		bool hasPorts() const
		{
			return true;
		}

		void updateData(ElementRepoInterface *repo) const
		{
			title_1->setHtml(QString("<b>%1</b>").arg(repo->name()).replace("\n", "<br>"));
		}

		bool isNode() const
		{
			return true;
		}

		bool isResizeable() const
		{
			return true;
		}

		bool isContainer() const
		{
			return false;
		}

		bool isSortingContainer() const
		{
			return false;
		}

		int sizeOfForestalling() const
		{
			return 0;
		}

		int sizeOfChildrenForestalling() const
		{
			return 0;
		}

		bool hasMovableChildren() const
		{
			return true;
		}

		bool minimizesToChildren() const
		{
			return false;
		}

		bool maximizesChildren() const
		{
			return false;
		}

		bool isDividable() const
		{
			return false;
		}

		bool isPort() const
		{
			return false;
		}

		bool hasPin() const
		{
			return false;
		}

		QList<double> border() const
		{
			QList<double> list;
			list << 0 << 0 << 0 << 0;
			return list;
		}

		QStringList bonusContextMenuFields() const
		{
			return QStringList();
		}

	private:
		SdfRendererInterface *mRenderer;
		ElementTitleInterface *title_1;
	};

	class SelectedSegment : public ElementImpl
	{
	public:
		void init(ElementTitleFactoryInterface &, QList<ElementTitleInterface*> &) {}

		void init(QRectF &contents, QList<StatPoint> &pointPorts,
							QList<StatLine> &linePorts, ElementTitleFactoryInterface &factory,
							QList<ElementTitleInterface*> &titles, SdfRendererInterface *renderer,
							SdfRendererInterface *portRenderer)
		{
			Q_UNUSED(pointPorts);
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/SelectedSegmentClass.sdf"));
			portRenderer->load(QString(":/generated/shapes/SelectedSegmentPorts.sdf"));
			contents.setWidth(80);
			contents.setHeight(80);
			{
				StatLine ln;
				ln.line = QLineF(0, 0.125, 0, 0.875);
				ln.prop_x1 = false;
				ln.prop_y1 = false; 
				ln.prop_x2 = false; 
				ln.prop_y2 = false; 
				ln.initWidth = 80;
				ln.initHeight = 80;
				linePorts << ln;
			};
			{
				StatLine ln;
				ln.line = QLineF(0.125, 0, 0.875, 0);
				ln.prop_x1 = false;
				ln.prop_y1 = false; 
				ln.prop_x2 = false; 
				ln.prop_y2 = false; 
				ln.initWidth = 80;
				ln.initHeight = 80;
				linePorts << ln;
			};
			{
				StatLine ln;
				ln.line = QLineF(1, 0.125, 1, 0.875);
				ln.prop_x1 = false;
				ln.prop_y1 = false; 
				ln.prop_x2 = false; 
				ln.prop_y2 = false; 
				ln.initWidth = 80;
				ln.initHeight = 80;
				linePorts << ln;
			};
			{
				StatLine ln;
				ln.line = QLineF(0.125, 1, 0.875, 1);
				ln.prop_x1 = false;
				ln.prop_y1 = false; 
				ln.prop_x2 = false; 
				ln.prop_y2 = false; 
				ln.initWidth = 80;
				ln.initHeight = 80;
				linePorts << ln;
			};
			title_1 = factory.createTitle(1, 0, "ID", false);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setFlags(0);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
			title_2 = factory.createTitle(0.0625, 0.0625, QString::fromUtf8("<b>SELECTED</b>"));
			title_2->setBackground(Qt::transparent);
			title_2->setScaling(false, false);
			title_2->setFlags(0);
			title_2->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_2);
		}

		 ElementImpl *clone() { return NULL; }
		~SelectedSegment() {}

		void paint(QPainter *painter, QRectF &contents)
		{
			mRenderer->render(painter, contents);
		}

		Qt::PenStyle getPenStyle() const { return Qt::SolidLine; }

		int getPenWidth() const { return 0; }

		QColor getPenColor() const { return QColor(); }

		void drawStartArrow(QPainter *) const {}
		void drawEndArrow(QPainter *) const {}
		bool hasPorts() const
		{
			return true;
		}

		void updateData(ElementRepoInterface *repo) const
		{
			title_1->setHtml(QString("<b>%1</b>").arg(repo->logicalProperty("ID")).replace("\n", "<br>"));
			Q_UNUSED(repo);
		}

		bool isNode() const
		{
			return true;
		}

		bool isResizeable() const
		{
			return true;
		}

		bool isContainer() const
		{
			return false;
		}

		bool isSortingContainer() const
		{
			return false;
		}

		int sizeOfForestalling() const
		{
			return 0;
		}

		int sizeOfChildrenForestalling() const
		{
			return 0;
		}

		bool hasMovableChildren() const
		{
			return true;
		}

		bool minimizesToChildren() const
		{
			return false;
		}

		bool maximizesChildren() const
		{
			return false;
		}

		bool isDividable() const
		{
			return false;
		}

		bool isPort() const
		{
			return false;
		}

		bool hasPin() const
		{
			return false;
		}

		QList<double> border() const
		{
			QList<double> list;
			list << 0 << 0 << 0 << 0;
			return list;
		}

		QStringList bonusContextMenuFields() const
		{
			return QStringList();
		}

	private:
		SdfRendererInterface *mRenderer;
		ElementTitleInterface *title_1;
		ElementTitleInterface *title_2;
	};

