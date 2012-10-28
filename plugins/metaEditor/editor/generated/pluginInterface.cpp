#include "pluginInterface.h"

#include "elements.h"


Q_EXPORT_PLUGIN2(qreal_editors, MetaEditorPlugin)

MetaEditorPlugin::MetaEditorPlugin()
{
	initPlugin();
}

void MetaEditorPlugin::initPlugin()
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

void MetaEditorPlugin::initNameMap()
{
	diagramNameMap["MetaEditor"] = QString::fromUtf8("Meta Editor");
	diagramNodeNameMap["MetaEditor"] = "MetamodelDiagram";

	elementsNameMap["MetaEditor"]["Container"] = QString::fromUtf8("Container");
	elementsNameMap["MetaEditor"]["Inheritance"] = QString::fromUtf8("Inheritance");
	elementsNameMap["MetaEditor"]["Listener"] = QString::fromUtf8("Listener");
	elementsNameMap["MetaEditor"]["MetaEditorDiagramNode"] = QString::fromUtf8("Meta Editor Diagram");
	elementsNameMap["MetaEditor"]["MetaEntity_Attribute"] = QString::fromUtf8("Property");
	elementsNameMap["MetaEditor"]["MetaEntityAssociation"] = QString::fromUtf8("Assotiation");
	elementsNameMap["MetaEditor"]["MetaEntityConnection"] = QString::fromUtf8("Connection");
	elementsNameMap["MetaEditor"]["MetaEntityContextMenuField"] = QString::fromUtf8("Context Menu Field");
	elementsNameMap["MetaEditor"]["MetaEntityEdge"] = QString::fromUtf8("Edge");
	elementsNameMap["MetaEditor"]["MetaEntityEnum"] = QString::fromUtf8("Enum");
	elementsNameMap["MetaEditor"]["MetaEntityImport"] = QString::fromUtf8("Import");
	elementsNameMap["MetaEditor"]["MetaEntityNode"] = QString::fromUtf8("Node");
	elementsNameMap["MetaEditor"]["MetaEntityPossibleEdge"] = QString::fromUtf8("Possible Edge");
	elementsNameMap["MetaEditor"]["MetaEntityPropertiesAsContainer"] = QString::fromUtf8("Properties as Container");
	elementsNameMap["MetaEditor"]["MetaEntityUsage"] = QString::fromUtf8("Usage");
	elementsNameMap["MetaEditor"]["MetaEntityValue"] = QString::fromUtf8("Value");
	elementsNameMap["MetaEditor"]["MetamodelDiagram"] = QString::fromUtf8("Metamodel Diagram");
	elementsNameMap["MetaEditor"]["PackageDiagram"] = QString::fromUtf8("Package Diagram");
	propertiesDisplayedNamesMap["MetaEditor"]["MetamodelDiagram"]["name of the directory"] = QString::fromUtf8("directory to generated code");
}

void MetaEditorPlugin::initPaletteGroupsMap()
{
	paletteGroupsMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("DSL Elements")].append(QString::fromUtf8("MetaEntityNode"));
	paletteGroupsMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("DSL Elements")].append(QString::fromUtf8("MetaEntityEdge"));
	paletteGroupsMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("DSL Elements")].append(QString::fromUtf8("MetaEntityEnum"));
	paletteGroupsMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("DSL Elements")].append(QString::fromUtf8("MetaEntityImport"));
	paletteGroupsMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Edge Properties")].append(QString::fromUtf8("MetaEntity_Attribute"));
	paletteGroupsMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Edge Properties")].append(QString::fromUtf8("MetaEntityAssociation"));
	paletteGroupsMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Enum Properties")].append(QString::fromUtf8("MetaEntityValue"));
	paletteGroupsMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Node Properties")].append(QString::fromUtf8("MetaEntity_Attribute"));
	paletteGroupsMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Node Properties")].append(QString::fromUtf8("MetaEntityPropertiesAsContainer"));
	paletteGroupsMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Node Properties")].append(QString::fromUtf8("MetaEntityPossibleEdge"));
	paletteGroupsMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Relationship")].append(QString::fromUtf8("Inheritance"));
	paletteGroupsMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Relationship")].append(QString::fromUtf8("Container"));
	paletteGroupsMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Root Diagrams")].append(QString::fromUtf8("MetamodelDiagram"));
	paletteGroupsMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Root Diagrams")].append(QString::fromUtf8("MetaEditorDiagramNode"));
	paletteGroupsMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Root Diagrams")].append(QString::fromUtf8("PackageDiagram"));
}

void MetaEditorPlugin::initPaletteGroupsDescriptionMap()
{
	paletteGroupsDescriptionMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("DSL Elements")] = QString::fromUtf8("Элементы метаязыка для описания узлов и связей создаваемого языка");
	paletteGroupsDescriptionMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Edge Properties")] = QString::fromUtf8("Элементы метаязыка для указания свойств связей создаваемого языка");
	paletteGroupsDescriptionMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Enum Properties")] = QString::fromUtf8("Элементы метаязыка для указания свойств перечисляемого типа создаваемого языка");
	paletteGroupsDescriptionMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Node Properties")] = QString::fromUtf8("Элементы метаязыка для указания свойств узлов создаваемого языка");
	paletteGroupsDescriptionMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Relationship")] = QString::fromUtf8("Связи метаязыка для описания вызимоотношений между элементами создаваемого языка");
	paletteGroupsDescriptionMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Root Diagrams")] = QString::fromUtf8("Корневые элементы");
}

void MetaEditorPlugin::initMouseGestureMap()
{
}

void MetaEditorPlugin::initPropertyMap()
{
	propertyTypes["Container"]["ownedComment"] = "Comment";
	propertyTypes["Inheritance"]["ownedComment"] = "Comment";
	propertyTypes["MetaEditorDiagramNode"]["isView"] = "Bool";
	propertyTypes["MetaEntityAssociation"]["beginType"] = "AssociationTypes";
	propertyTypes["MetaEntityAssociation"]["endType"] = "AssociationTypes";
	propertyTypes["MetaEntityEdge"]["labelType"] = "LabelTypes";
	propertyTypes["MetaEntityEdge"]["lineType"] = "LineTypes";
	propertyTypes["MetaEntityNode"]["isAction"] = "Bool";
	propertyTypes["MetaEntityNode"]["isPin"] = "Bool";
	propertyTypes["MetaEntityNode"]["isResizeable"] = "Bool";
	propertyTypes["MetaEntityNode"]["isView"] = "Bool";
	propertyTypes["MetaEntityPossibleEdge"]["directed"] = "Bool";
	propertyTypes["MetaEntityPropertiesAsContainer"]["banChildrenMove"] = "Bool";
	propertyTypes["MetaEntityPropertiesAsContainer"]["maximizeChildren"] = "Bool";
	propertyTypes["MetaEntityPropertiesAsContainer"]["minimizeToChildren"] = "Bool";
	propertyTypes["MetaEntityPropertiesAsContainer"]["sortContainer"] = "Bool";
	propertyTypes["PackageDiagram"]["isView"] = "Bool";
}

void MetaEditorPlugin::initPropertyDefaultsMap()
{
	propertyDefault["MetaEntityEdge"]["labelType"] = QString::fromUtf8("Dynamic text");
	propertyDefault["MetaEntityEdge"]["lineType"] = QString::fromUtf8("solidLine");
	propertyDefault["MetaEntityNode"]["isAction"] = QString::fromUtf8("false");
	propertyDefault["MetaEntityNode"]["isPin"] = QString::fromUtf8("false");
	propertyDefault["MetaEntityNode"]["isResizeable"] = QString::fromUtf8("true");
	propertyDefault["MetaEntityPossibleEdge"]["directed"] = QString::fromUtf8("false");
	propertyDefault["MetaEntityPropertiesAsContainer"]["banChildrenMove"] = QString::fromUtf8("false");
	propertyDefault["MetaEntityPropertiesAsContainer"]["maximizeChildren"] = QString::fromUtf8("false");
	propertyDefault["MetaEntityPropertiesAsContainer"]["minimizeToChildren"] = QString::fromUtf8("false");
	propertyDefault["MetaEntityPropertiesAsContainer"]["sortContainer"] = QString::fromUtf8("false");
}

void MetaEditorPlugin::initDescriptionMap()
{
	elementsDescriptionMap["MetaEditor"]["Container"] = QString::fromUtf8("Связь, указывающая отношение вложенности между элементами (направления – от вкладываемого элемента к тому, в который вкладывается)");
	elementsDescriptionMap["MetaEditor"]["Inheritance"] = QString::fromUtf8("Связь, указывающая отношение наследования между элементами (направление – от дочернего элемента к предку)");
	elementsDescriptionMap["MetaEditor"]["Listener"] = QString::fromUtf8("Не поддерживается");
	elementsDescriptionMap["MetaEditor"]["MetaEditorDiagramNode"] = QString::fromUtf8("Элемент для описания конкретного редактора создаваемого языка. Должен вкладываться в Metamodel Diagram");
	elementsDescriptionMap["MetaEditor"]["MetaEntity_Attribute"] = QString::fromUtf8("Сущность для описания нового свойства элемента. Вкладывается в соответствующий элемент Node или Edge");
	elementsDescriptionMap["MetaEditor"]["MetaEntityAssociation"] = QString::fromUtf8("Элемент для указания типов и имен начала и конца связи (см. Edge). Вкладывается в соответствующий элемент Edge");
	elementsDescriptionMap["MetaEditor"]["MetaEntityConnection"] = QString::fromUtf8("Не поддерживается");
	elementsDescriptionMap["MetaEditor"]["MetaEntityContextMenuField"] = QString::fromUtf8("Не поддерживается");
	elementsDescriptionMap["MetaEditor"]["MetaEntityEdge"] = QString::fromUtf8("Элемент для описания новой связи на диаграмме создаваемого языка. Должен вкладываться в Meta Editor Diagram");
	elementsDescriptionMap["MetaEditor"]["MetaEntityEnum"] = QString::fromUtf8("Элемент для описания перечисляемого типа данных для создаваемого языка (см. Value). Вкладывается в Meta Editor Diagram");
	elementsDescriptionMap["MetaEditor"]["MetaEntityImport"] = QString::fromUtf8("Сущность для добавления в создаваемый язык элемента из другого визуального языка. Должен вкладываться в Metamodel Diagram.");
	elementsDescriptionMap["MetaEditor"]["MetaEntityNode"] = QString::fromUtf8("Элемент для описания нового узла диаграммы создаваемого языка. Должен вкладываться в Meta Editor Diagram");
	elementsDescriptionMap["MetaEditor"]["MetaEntityPossibleEdge"] = QString::fromUtf8("Сущность для указания элементов, которые можно присоединять к данному с помощью «вытягивания» из него связей. Вкладывается в соответствующий элемент Node");
	elementsDescriptionMap["MetaEditor"]["MetaEntityPropertiesAsContainer"] = QString::fromUtf8("Сущность для указания дополнительной функциональности элемента создаваемого языка, являющегося контейнером (см. Container). Вкладывается в соответствующий элемент типа Node");
	elementsDescriptionMap["MetaEditor"]["MetaEntityUsage"] = QString::fromUtf8("Не поддерживается");
	elementsDescriptionMap["MetaEditor"]["MetaEntityValue"] = QString::fromUtf8("Сущность для описания конкретного значения для создаваемого перечисляемого типа (см. Enum). Должен вкладываться в Enum");
	elementsDescriptionMap["MetaEditor"]["MetamodelDiagram"] = QString::fromUtf8("Корневой элемент метамодели языка. В его свойствах указываются необходимые для сборки параметры");
	elementsDescriptionMap["MetaEditor"]["PackageDiagram"] = QString::fromUtf8("Предназначен для описания связей между метамоделями. Также может быть корневым элементом метамодели");
	propertiesDescriptionMap["MetaEditor"]["MetaEditorDiagramNode"]["nodeName"] = QString::fromUtf8("имя элемента, который будет корневым для диаграмм на создаваемом языке");
	propertiesDescriptionMap["MetaEditor"]["MetaEntityEdge"]["labelType"] = QString::fromUtf8("тип текста(статический, динамический)");
	propertiesDescriptionMap["MetaEditor"]["MetaEntityEdge"]["lineType"] = QString::fromUtf8("тип линии (прямая, пунктирная и т.д.)");
	propertiesDescriptionMap["MetaEditor"]["MetamodelDiagram"]["include"] = QString::fromUtf8("xml-файлы, которые следует подключить к создаваемой метамодели");
	propertiesDescriptionMap["MetaEditor"]["MetamodelDiagram"]["relative path to QReal Source Files"] = QString::fromUtf8("путь до исходных файлов QReal относительно пути до сгенерированного кода");
}

void MetaEditorPlugin::initParentsMap()
{
	parentsMap["MetaEditor"]["Container"]
		<< qMakePair(QString("MetaEditor"), QString("Relationship"))
	;
	parentsMap["MetaEditor"]["Inheritance"]
		<< qMakePair(QString("MetaEditor"), QString("Relationship"))
	;
	parentsMap["MetaEditor"]["MetaEditorDiagramNode"]
		<< qMakePair(QString("MetaEditor"), QString("Diagram"))
	;
	parentsMap["MetaEditor"]["MetaEntityNode"]
		<< qMakePair(QString("MetaEditor"), QString("Diagram"))
	;
	parentsMap["MetaEditor"]["PackageDiagram"]
		<< qMakePair(QString("MetaEditor"), QString("Diagram"))
	;
}

QStringList MetaEditorPlugin::diagrams() const
{
	return diagramNameMap.keys();
}

QStringList MetaEditorPlugin::diagramPaletteGroups(QString const &diagram) const
{
	return paletteGroupsMap[diagram].keys();
}

QStringList MetaEditorPlugin::diagramPaletteGroupList(QString const &diagram, QString const &group) const
{
	return paletteGroupsMap[diagram][group];
}

QString MetaEditorPlugin::diagramPaletteGroupDescription(QString const &diagram, QString const &group) const
{
	return paletteGroupsDescriptionMap[diagram][group];
}

QStringList MetaEditorPlugin::elements(QString const &diagram) const
{
	return elementsNameMap[diagram].keys();
}

QStringList MetaEditorPlugin::getPropertiesWithDefaultValues(QString const &element) const
{
	return propertyDefault[element].keys();
}

QIcon MetaEditorPlugin::getIcon(SdfIconEngineV2Interface *engine) const
{
	return QIcon(engine);
}

QString MetaEditorPlugin::editorName() const
{
	 return "MetaEditor Editor";
}

QString MetaEditorPlugin::diagramName(QString const &diagram) const
{
	return diagramNameMap[diagram];
}

QString MetaEditorPlugin::diagramNodeName(QString const &diagram) const
{
	return diagramNodeNameMap[diagram];
}

QString MetaEditorPlugin::elementName(QString const &diagram, QString const &element) const
{
	return elementsNameMap[diagram][element];
}

QString MetaEditorPlugin::elementDescription(QString const &diagram, QString const &element) const
{
	return elementsDescriptionMap[diagram][element];
}

QString MetaEditorPlugin::propertyDescription(QString const &diagram, QString const &element, QString const &property) const
{
	return propertiesDescriptionMap[diagram][element][property];
}

QString MetaEditorPlugin::propertyDisplayedName(QString const &diagram, QString const &element, QString const &property) const
{
	return propertiesDisplayedNamesMap[diagram][element][property];
}

QString MetaEditorPlugin::elementMouseGesture(QString const &diagram, QString const &element) const
{
	return elementMouseGesturesMap[diagram][element];
}

ElementImpl* MetaEditorPlugin::getGraphicalObject(QString const &/*diagram*/, QString const &element) const
{
	if (element == "Container")
		return new Container();
	else if (element == "Inheritance")
		return new Inheritance();
	else if (element == "Listener")
		return new Listener();
	else if (element == "MetaEditorDiagramNode")
		return new MetaEditorDiagramNode();
	else if (element == "MetaEntity_Attribute")
		return new MetaEntity_Attribute();
	else if (element == "MetaEntityAssociation")
		return new MetaEntityAssociation();
	else if (element == "MetaEntityConnection")
		return new MetaEntityConnection();
	else if (element == "MetaEntityContextMenuField")
		return new MetaEntityContextMenuField();
	else if (element == "MetaEntityEdge")
		return new MetaEntityEdge();
	else if (element == "MetaEntityEnum")
		return new MetaEntityEnum();
	else if (element == "MetaEntityImport")
		return new MetaEntityImport();
	else if (element == "MetaEntityNode")
		return new MetaEntityNode();
	else if (element == "MetaEntityPossibleEdge")
		return new MetaEntityPossibleEdge();
	else if (element == "MetaEntityPropertiesAsContainer")
		return new MetaEntityPropertiesAsContainer();
	else if (element == "MetaEntityUsage")
		return new MetaEntityUsage();
	else if (element == "MetaEntityValue")
		return new MetaEntityValue();
	else if (element == "MetamodelDiagram")
		return new MetamodelDiagram();
	else if (element == "PackageDiagram")
		return new PackageDiagram();
	else {
		Q_ASSERT(!"Request for creation of an element with unknown name");
		return NULL;
	}
}

bool MetaEditorPlugin::isParentOf(QString const &parentDiagram, QString const &parentElement, QString const &childDiagram, QString const &childElement) const
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
QList<QPair<QString, QString> > MetaEditorPlugin::getParentsOf(QString const &diagram, QString const &element) const
{
	return parentsMap[diagram][element];
}
QStringList MetaEditorPlugin::getPropertyNames(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "Container")
		result  << "ownedComment";
	else if (element == "Inheritance")
		result  << "ownedComment";
	else if (element == "Listener")
		result  << "class" << "file";
	else if (element == "MetaEditorDiagramNode")
		result  << "displayedName" << "isView" << "language" << "nodeName";
	else if (element == "MetaEntity_Attribute")
		result  << "attributeType" << "defaultValue" << "displayedName";
	else if (element == "MetaEntityAssociation")
		result  << "beginName" << "beginType" << "endName" << "endType";
	else if (element == "MetaEntityConnection")
		result  << "type";
	else if (element == "MetaEntityContextMenuField")
;
	else if (element == "MetaEntityEdge")
		result  << "displayedName" << "labelText" << "labelType" << "lineType";
	else if (element == "MetaEntityEnum")
		result  << "displayedName";
	else if (element == "MetaEntityImport")
		result  << "as" << "displayedName" << "importedFrom";
	else if (element == "MetaEntityNode")
		result  << "description" << "displayedName" << "isAction" << "isPin" << "isResizeable" << "isView"
		 << "language" << "path" << "shape";
	else if (element == "MetaEntityPossibleEdge")
		result  << "beginName" << "directed" << "endName";
	else if (element == "MetaEntityPropertiesAsContainer")
		result  << "banChildrenMove" << "childrenForestallingSize" << "forestallingSize" << "maximizeChildren"
		 << "minimizeToChildren" << "sortContainer";
	else if (element == "MetaEntityUsage")
		result  << "type";
	else if (element == "MetaEntityValue")
		result  << "valueName";
	else if (element == "MetamodelDiagram")
		result  << "displayedName" << "include" << "name of the directory" << "relative path to QReal Source Files";
	else if (element == "PackageDiagram")
		result  << "isView" << "language";
	return result;
}

QStringList MetaEditorPlugin::getReferenceProperties(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "Container")
;
	else if (element == "Inheritance")
;
	else if (element == "Listener")
;
	else if (element == "MetaEditorDiagramNode")
;
	else if (element == "MetaEntity_Attribute")
;
	else if (element == "MetaEntityAssociation")
;
	else if (element == "MetaEntityConnection")
;
	else if (element == "MetaEntityContextMenuField")
;
	else if (element == "MetaEntityEdge")
;
	else if (element == "MetaEntityEnum")
;
	else if (element == "MetaEntityImport")
;
	else if (element == "MetaEntityNode")
;
	else if (element == "MetaEntityPossibleEdge")
;
	else if (element == "MetaEntityPropertiesAsContainer")
;
	else if (element == "MetaEntityUsage")
;
	else if (element == "MetaEntityValue")
;
	else if (element == "MetamodelDiagram")
;
	else if (element == "PackageDiagram")
;
	return result;
}

QStringList MetaEditorPlugin::getTypesContainedBy(QString const &element) const
{
	QStringList result;
	if (element == "MetaEditorDiagramNode")
		result << "MetaEntityNode" << "MetaEntityEdge" << "MetaEntityEnum" << "MetaEntityImport" << "Inheritance" ;
	else if (element == "MetaEntityEdge")
		result << "MetaEntity_Attribute" << "MetaEntityAssociation" << "Inheritance" << "Importation" ;
	else if (element == "MetaEntityEnum")
		result << "MetaEntityValue" ;
	else if (element == "MetaEntityNode")
		result << "MetaEntity_Attribute" << "MetaEntityConnection" << "MetaEntityUsage" << "Inheritance" << "MetaEntityPossibleEdge" << "MetaEntityPropertiesAsContainer" ;
	return result;
}

QStringList MetaEditorPlugin::getConnectedTypes(QString const &element) const
{
	QStringList result;
	if (element == "MetamodelDiagram")
		result << "MetamodelDiagram" ;
	return result;
}

QStringList MetaEditorPlugin::getUsedTypes(QString const &element) const
{
	QStringList result;
	Q_UNUSED(element);
	return result;
}

QList<QPair<QPair<QString,QString>,QPair<bool,QString> > > MetaEditorPlugin::getPossibleEdges(QString const &element) const
{
	QList<QPair<QPair<QString,QString>,QPair<bool,QString> > > result;
	Q_UNUSED(element);
	return result;
}

//(-1) means "edge", (+1) means "node"
int MetaEditorPlugin::isNodeOrEdge(QString const &element) const
{
	if (element == "Container")
		return -1;
	else if (element == "Inheritance")
		return -1;
	else if (element == "Listener")
		return 1;
	else if (element == "MetaEditorDiagramNode")
		return 1;
	else if (element == "MetaEntity_Attribute")
		return 1;
	else if (element == "MetaEntityAssociation")
		return 1;
	else if (element == "MetaEntityConnection")
		return 1;
	else if (element == "MetaEntityContextMenuField")
		return 1;
	else if (element == "MetaEntityEdge")
		return 1;
	else if (element == "MetaEntityEnum")
		return 1;
	else if (element == "MetaEntityImport")
		return 1;
	else if (element == "MetaEntityNode")
		return 1;
	else if (element == "MetaEntityPossibleEdge")
		return 1;
	else if (element == "MetaEntityPropertiesAsContainer")
		return 1;
	else if (element == "MetaEntityUsage")
		return 1;
	else if (element == "MetaEntityValue")
		return 1;
	else if (element == "MetamodelDiagram")
		return 1;
	else if (element == "PackageDiagram")
		return 1;
	else if (element == "AssociationTypes")
		return 0;
	else if (element == "LabelTypes")
		return 0;
	else if (element == "LineTypes")
		return 0;
	return 0;
}
QStringList MetaEditorPlugin::getEnumValues(QString name) const 
{
	QStringList result;
	if (name == "AggregationKind")
		result << QString::fromUtf8("none") << QString::fromUtf8("shared") << QString::fromUtf8("composite");
	else if (name == "AssociationTypes")
		result << QString::fromUtf8("no_arrow") << QString::fromUtf8("open_arrow") << QString::fromUtf8("empty_arrow") << QString::fromUtf8("filled_arrow") << QString::fromUtf8("empty_rhomb") << QString::fromUtf8("filled_rhomb");
	else if (name == "LineTypes")
		result << QString::fromUtf8("solidLine") << QString::fromUtf8("dashLine") << QString::fromUtf8("dotLine");
	else if (name == "Bool")
		result << QString::fromUtf8("false") << QString::fromUtf8("true");
	else if (name == "LabelTypes")
		result << QString::fromUtf8("Static text") << QString::fromUtf8("Dynamic text");
	else if (name == "ParameterDirectionKind")
		result << QString::fromUtf8("in") << QString::fromUtf8("inout") << QString::fromUtf8("out") << QString::fromUtf8("return");
	else if (name == "VisibilityKind")
		result << QString::fromUtf8("private") << QString::fromUtf8("protected") << QString::fromUtf8("public") << QString::fromUtf8("package");
	return result;
}

QString MetaEditorPlugin::getPropertyType(QString const &element, QString const &property) const
{
	return propertyTypes[element][property];
}

QString MetaEditorPlugin::getPropertyDefaultValue(QString const &element, QString const &property) const
{
	return propertyDefault[element][property];
}

QList<qReal::ListenerInterface*> MetaEditorPlugin::listeners() const
{
	QList<qReal::ListenerInterface*> result;
	return result;
}
