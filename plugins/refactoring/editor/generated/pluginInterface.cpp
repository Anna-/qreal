#include "pluginInterface.h"

#include "elements.h"


Q_EXPORT_PLUGIN2(qreal_editors, RefactoringEditorPlugin)

RefactoringEditorPlugin::RefactoringEditorPlugin()
{
	initPlugin();
}

void RefactoringEditorPlugin::initPlugin()
{
	initNameMap();
	initMouseGestureMap();
	initPropertyMap();
	initPropertyDefaultsMap();
	initDescriptionMap();
	initParentsMap();
	initPaletteGroupsMap();
	initPaletteGroupsDescriptionMap();
}

void RefactoringEditorPlugin::initNameMap()
{
	diagramNameMap["RefactoringDiagram"] = QString::fromUtf8("Refactoring Diagram");
	diagramNodeNameMap["RefactoringDiagram"] = "refactoringDiagramNode";

	elementsNameMap["RefactoringDiagram"]["AfterBlock"] = QString::fromUtf8("After Block");
	elementsNameMap["RefactoringDiagram"]["BeforeBlock"] = QString::fromUtf8("Before Block");
	elementsNameMap["RefactoringDiagram"]["Element"] = QString::fromUtf8("Element");
	elementsNameMap["RefactoringDiagram"]["FromBeforeToAter"] = QString::fromUtf8("From Before To After");
	elementsNameMap["RefactoringDiagram"]["Link"] = QString::fromUtf8("Link");
	elementsNameMap["RefactoringDiagram"]["RefactoringDiagramNode"] = QString::fromUtf8("Refactoring Diagram");
	elementsNameMap["RefactoringDiagram"]["SelectedSegment"] = QString::fromUtf8("Selected segment");
}

void RefactoringEditorPlugin::initPaletteGroupsMap()
{
	paletteGroupsMap[QString::fromUtf8("RefactoringDiagram")][QString::fromUtf8("Basic Elements")].append(QString::fromUtf8("Element"));
	paletteGroupsMap[QString::fromUtf8("RefactoringDiagram")][QString::fromUtf8("Basic Elements")].append(QString::fromUtf8("Link"));
	paletteGroupsMap[QString::fromUtf8("RefactoringDiagram")][QString::fromUtf8("Basic Elements")].append(QString::fromUtf8("Selected_segment"));
	paletteGroupsMap[QString::fromUtf8("RefactoringDiagram")][QString::fromUtf8("Refactoring Rule Elements")].append(QString::fromUtf8("Refactoring_Diagram"));
	paletteGroupsMap[QString::fromUtf8("RefactoringDiagram")][QString::fromUtf8("Refactoring Rule Elements")].append(QString::fromUtf8("From_Before_To_After"));
	paletteGroupsMap[QString::fromUtf8("RefactoringDiagram")][QString::fromUtf8("Refactoring Rule Elements")].append(QString::fromUtf8("After_Block"));
	paletteGroupsMap[QString::fromUtf8("RefactoringDiagram")][QString::fromUtf8("Refactoring Rule Elements")].append(QString::fromUtf8("Before_Block"));
}

void RefactoringEditorPlugin::initPaletteGroupsDescriptionMap()
{
}

void RefactoringEditorPlugin::initMouseGestureMap()
{
}

void RefactoringEditorPlugin::initPropertyMap()
{
}

void RefactoringEditorPlugin::initPropertyDefaultsMap()
{
}

void RefactoringEditorPlugin::initDescriptionMap()
{
}

void RefactoringEditorPlugin::initParentsMap()
{
}

QStringList RefactoringEditorPlugin::diagrams() const
{
	return diagramNameMap.keys();
}

QStringList RefactoringEditorPlugin::diagramPaletteGroups(QString const &diagram) const
{
	return paletteGroupsMap[diagram].keys();
}

QStringList RefactoringEditorPlugin::diagramPaletteGroupList(QString const &diagram, QString const &group) const
{
	return paletteGroupsMap[diagram][group];
}

QString RefactoringEditorPlugin::diagramPaletteGroupDescription(QString const &diagram, QString const &group) const
{
	return paletteGroupsDescriptionMap[diagram][group];
}

QStringList RefactoringEditorPlugin::elements(QString const &diagram) const
{
	return elementsNameMap[diagram].keys();
}

QStringList RefactoringEditorPlugin::getPropertiesWithDefaultValues(QString const &element) const
{
	return propertyDefault[element].keys();
}

QIcon RefactoringEditorPlugin::getIcon(SdfIconEngineV2Interface *engine) const
{
	return QIcon(engine);
}

QString RefactoringEditorPlugin::editorName() const
{
	 return "RefactoringEditor Editor";
}

QString RefactoringEditorPlugin::diagramName(QString const &diagram) const
{
	return diagramNameMap[diagram];
}

QString RefactoringEditorPlugin::diagramNodeName(QString const &diagram) const
{
	return diagramNodeNameMap[diagram];
}

QString RefactoringEditorPlugin::elementName(QString const &diagram, QString const &element) const
{
	return elementsNameMap[diagram][element];
}

QString RefactoringEditorPlugin::elementDescription(QString const &diagram, QString const &element) const
{
	return elementsDescriptionMap[diagram][element];
}

QString RefactoringEditorPlugin::propertyDescription(QString const &diagram, QString const &element, QString const &property) const
{
	return propertiesDescriptionMap[diagram][element][property];
}

QString RefactoringEditorPlugin::propertyDisplayedName(QString const &diagram, QString const &element, QString const &property) const
{
	return propertiesDisplayedNamesMap[diagram][element][property];
}

QString RefactoringEditorPlugin::elementMouseGesture(QString const &diagram, QString const &element) const
{
	return elementMouseGesturesMap[diagram][element];
}

ElementImpl* RefactoringEditorPlugin::getGraphicalObject(QString const &/*diagram*/, QString const &element) const
{
	if (element == "AfterBlock")
		return new AfterBlock();
	else if (element == "BeforeBlock")
		return new BeforeBlock();
	else if (element == "Element")
		return new Element();
	else if (element == "FromBeforeToAter")
		return new FromBeforeToAter();
	else if (element == "Link")
		return new Link();
	else if (element == "RefactoringDiagramNode")
		return new RefactoringDiagramNode();
	else if (element == "SelectedSegment")
		return new SelectedSegment();
	else {
		Q_ASSERT(!"Request for creation of an element with unknown name");
		return NULL;
	}
}

bool RefactoringEditorPlugin::isParentOf(QString const &parentDiagram, QString const &parentElement, QString const &childDiagram, QString const &childElement) const
{
	if (childDiagram == parentDiagram && childElement == parentElement)
		return true;
	if (parentsMap[childDiagram][childElement].contains(qMakePair(parentDiagram, parentElement)))
		return true;
	typedef QPair<QString, QString> StringPair;
	foreach (StringPair const &pair, parentsMap[childDiagram][childElement])
		if (isParentOf(parentDiagram, parentElement, pair.first, pair.second))
			return true;
	return false;
}
QList<QPair<QString, QString> > RefactoringEditorPlugin::getParentsOf(QString const &diagram, QString const &element) const
{
	return parentsMap[diagram][element];
}
QStringList RefactoringEditorPlugin::getPropertyNames(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "AfterBlock")
;
	else if (element == "BeforeBlock")
;
	else if (element == "Element")
		result  << "ID";
	else if (element == "FromBeforeToAter")
;
	else if (element == "Link")
		result  << "ID";
	else if (element == "RefactoringDiagramNode")
;
	else if (element == "SelectedSegment")
		result  << "ID";
	return result;
}

QStringList RefactoringEditorPlugin::getReferenceProperties(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "AfterBlock")
;
	else if (element == "BeforeBlock")
;
	else if (element == "Element")
;
	else if (element == "FromBeforeToAter")
;
	else if (element == "Link")
;
	else if (element == "RefactoringDiagramNode")
;
	else if (element == "SelectedSegment")
;
	return result;
}

QStringList RefactoringEditorPlugin::getTypesContainedBy(QString const &element) const
{
	QStringList result;
	if (element == "AfterBlock")
		result << "Element" << "Link" << "Subprogram" ;
	else if (element == "BeforeBlock")
		result << "Element" << "SelectedSegment" << "Link" << "Subprogram" ;
	return result;
}

QStringList RefactoringEditorPlugin::getConnectedTypes(QString const &element) const
{
	QStringList result;
	Q_UNUSED(element);
	return result;
}

QStringList RefactoringEditorPlugin::getUsedTypes(QString const &element) const
{
	QStringList result;
	Q_UNUSED(element);
	return result;
}

QList<QPair<QPair<QString,QString>,QPair<bool,QString> > > RefactoringEditorPlugin::getPossibleEdges(QString const &element) const
{
	QList<QPair<QPair<QString,QString>,QPair<bool,QString> > > result;
	Q_UNUSED(element);
	return result;
}

//(-1) means "edge", (+1) means "node"
int RefactoringEditorPlugin::isNodeOrEdge(QString const &element) const
{
	if (element == "AfterBlock")
		return 1;
	else if (element == "BeforeBlock")
		return 1;
	else if (element == "Element")
		return 1;
	else if (element == "FromBeforeToAter")
		return 1;
	else if (element == "Link")
		return -1;
	else if (element == "RefactoringDiagramNode")
		return 1;
	else if (element == "SelectedSegment")
		return 1;
	return 0;
}
QStringList RefactoringEditorPlugin::getEnumValues(QString name) const 
{
	QStringList result;
	Q_UNUSED(name);
	return result;
}

QString RefactoringEditorPlugin::getPropertyType(QString const &element, QString const &property) const
{
	return propertyTypes[element][property];
}

QString RefactoringEditorPlugin::getPropertyDefaultValue(QString const &element, QString const &property) const
{
	return propertyDefault[element][property];
}

QList<qReal::ListenerInterface*> RefactoringEditorPlugin::listeners() const
{
	QList<qReal::ListenerInterface*> result;
	return result;
}
