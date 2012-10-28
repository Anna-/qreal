#include "pluginInterface.h"

#include "elements.h"


Q_EXPORT_PLUGIN2(qreal_editors, ConstraintsMetamodelPlugin)

ConstraintsMetamodelPlugin::ConstraintsMetamodelPlugin()
{
	initPlugin();
}

void ConstraintsMetamodelPlugin::initPlugin()
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

void ConstraintsMetamodelPlugin::initNameMap()
{
	diagramNameMap["ConstraintsEditor"] = QString::fromUtf8("Constraints Editor");
	diagramNodeNameMap["ConstraintsEditor"] = "metamodelConstraints";

	elementsNameMap["ConstraintsEditor"]["MultiOrEdge"] = QString::fromUtf8("Multi Or Edge");
	elementsNameMap["ConstraintsEditor"]["MultiOrNode"] = QString::fromUtf8("Multi Or Node");
	elementsNameMap["ConstraintsEditor"]["BeginNode"] = QString::fromUtf8("Begin Node");
	elementsNameMap["ConstraintsEditor"]["Childrens"] = QString::fromUtf8("Childrens");
	elementsNameMap["ConstraintsEditor"]["ConstraintsDiagram"] = QString::fromUtf8("Constraints Diagram");
	elementsNameMap["ConstraintsEditor"]["EdgeConstraint"] = QString::fromUtf8("Edge Constraint");
	elementsNameMap["ConstraintsEditor"]["EdgesConstraint"] = QString::fromUtf8("Edges Constraint");
	elementsNameMap["ConstraintsEditor"]["EndNode"] = QString::fromUtf8("End Node");
	elementsNameMap["ConstraintsEditor"]["IncomingLinks"] = QString::fromUtf8("Incoming Links");
	elementsNameMap["ConstraintsEditor"]["IncomingNodes"] = QString::fromUtf8("Incoming Nodes");
	elementsNameMap["ConstraintsEditor"]["MetamodelConstraints"] = QString::fromUtf8("Metamodel Constraints");
	elementsNameMap["ConstraintsEditor"]["NodeConstraint"] = QString::fromUtf8("Node Constraint");
	elementsNameMap["ConstraintsEditor"]["NodesConstraint"] = QString::fromUtf8("Nodes Constraint");
	elementsNameMap["ConstraintsEditor"]["Or"] = QString::fromUtf8("Or");
	elementsNameMap["ConstraintsEditor"]["OutgoingLinks"] = QString::fromUtf8("Outgoing Links");
	elementsNameMap["ConstraintsEditor"]["OutgoingNodes"] = QString::fromUtf8("Outgoing Nodes");
	elementsNameMap["ConstraintsEditor"]["Parent"] = QString::fromUtf8("Parent");
	elementsNameMap["ConstraintsEditor"]["PropertyNode"] = QString::fromUtf8("Property");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["BeginNode"]["exists"] = QString::fromUtf8("Exists");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["Childrens"]["count"] = QString::fromUtf8("Count");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["Childrens"]["selection"] = QString::fromUtf8("Selection");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["ConstraintsDiagram"]["languageName"] = QString::fromUtf8("Language Name");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["EdgeConstraint"]["errorText"] = QString::fromUtf8("Text of error");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["EdgeConstraint"]["errorType"] = QString::fromUtf8("Error Type");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["EdgesConstraint"]["errorText"] = QString::fromUtf8("Text of error");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["EdgesConstraint"]["errorType"] = QString::fromUtf8("Error Type");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["EdgesConstraint"]["selection"] = QString::fromUtf8("Selection");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["EndNode"]["exists"] = QString::fromUtf8("Exists");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["IncomingLinks"]["count"] = QString::fromUtf8("Count");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["IncomingLinks"]["selection"] = QString::fromUtf8("Selection");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["IncomingNodes"]["count"] = QString::fromUtf8("Count");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["IncomingNodes"]["selection"] = QString::fromUtf8("Selection");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["MetamodelConstraints"]["metamodelName"] = QString::fromUtf8("Metamodel Name");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["MetamodelConstraints"]["outputDirPath"] = QString::fromUtf8("Output Dir Path");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["MetamodelConstraints"]["pathToQReal"] = QString::fromUtf8("Dir Path to QReal");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["NodeConstraint"]["errorText"] = QString::fromUtf8("Text of error");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["NodeConstraint"]["errorType"] = QString::fromUtf8("Error Type");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["NodesConstraint"]["errorText"] = QString::fromUtf8("Text of error");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["NodesConstraint"]["errorType"] = QString::fromUtf8("Error Type");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["NodesConstraint"]["selection"] = QString::fromUtf8("Selection");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["OutgoingLinks"]["count"] = QString::fromUtf8("Count");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["OutgoingLinks"]["selection"] = QString::fromUtf8("Selection");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["OutgoingNodes"]["count"] = QString::fromUtf8("Count");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["OutgoingNodes"]["selection"] = QString::fromUtf8("Selection");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["Parent"]["exists"] = QString::fromUtf8("Exists");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["PropertyNode"]["property"] = QString::fromUtf8("Property");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["PropertyNode"]["sign"] = QString::fromUtf8("Sign");
	propertiesDisplayedNamesMap["ConstraintsEditor"]["PropertyNode"]["value"] = QString::fromUtf8("Value");
}

void ConstraintsMetamodelPlugin::initPaletteGroupsMap()
{
	paletteGroupsMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("DSL Constraints Elements")].append(QString::fromUtf8("Node_Constraint"));
	paletteGroupsMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("DSL Constraints Elements")].append(QString::fromUtf8("Edge_Constraint"));
	paletteGroupsMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("DSL Constraints Elements")].append(QString::fromUtf8("Nodes_Constraint"));
	paletteGroupsMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("DSL Constraints Elements")].append(QString::fromUtf8("Edges_Constraint"));
	paletteGroupsMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("Edge Constraints Properties")].append(QString::fromUtf8("Property"));
	paletteGroupsMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("Edge Constraints Properties")].append(QString::fromUtf8("Begin_Node"));
	paletteGroupsMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("Edge Constraints Properties")].append(QString::fromUtf8("End_Node"));
	paletteGroupsMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("Node Constraints Properties")].append(QString::fromUtf8("Property"));
	paletteGroupsMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("Node Constraints Properties")].append(QString::fromUtf8("Parent"));
	paletteGroupsMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("Node Constraints Properties")].append(QString::fromUtf8("Childrens"));
	paletteGroupsMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("Node Constraints Properties")].append(QString::fromUtf8("Incoming_Nodes"));
	paletteGroupsMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("Node Constraints Properties")].append(QString::fromUtf8("Outgoing_Nodes"));
	paletteGroupsMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("Node Constraints Properties")].append(QString::fromUtf8("Incoming_Links"));
	paletteGroupsMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("Node Constraints Properties")].append(QString::fromUtf8("Outgoing_Links"));
	paletteGroupsMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("Relationship")].append(QString::fromUtf8("Or"));
	paletteGroupsMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("Relationship")].append(QString::fromUtf8("Multi_Or_Edge"));
	paletteGroupsMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("Relationship")].append(QString::fromUtf8("Multi_Or_Node"));
	paletteGroupsMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("Root Diagrams")].append(QString::fromUtf8("Metamodel_Constraints"));
	paletteGroupsMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("Root Diagrams")].append(QString::fromUtf8("Constraints_Diagram"));
}

void ConstraintsMetamodelPlugin::initPaletteGroupsDescriptionMap()
{
	paletteGroupsDescriptionMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("DSL Constraints Elements")] = QString::fromUtf8("Базовые элементы задания ограничений на узлы и связи рассматриваемого языка");
	paletteGroupsDescriptionMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("Edge Constraints Properties")] = QString::fromUtf8("Сущности для задания элементарных ограничений на связи рассматриваемого языка");
	paletteGroupsDescriptionMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("Node Constraints Properties")] = QString::fromUtf8("Сущности для задания элементарных ограничений на узлы рассматриваемого языка");
	paletteGroupsDescriptionMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("Relationship")] = QString::fromUtf8("Связи для описания взаимоотношений между элементарными ограничениями");
	paletteGroupsDescriptionMap[QString::fromUtf8("ConstraintsEditor")][QString::fromUtf8("Root Diagrams")] = QString::fromUtf8("Корневые элементы");
}

void ConstraintsMetamodelPlugin::initMouseGestureMap()
{
}

void ConstraintsMetamodelPlugin::initPropertyMap()
{
	propertyTypes["BeginNode"]["exists"] = "ExistsType";
	propertyTypes["EdgeConstraint"]["errorType"] = "ErrorTypeType";
	propertyTypes["EdgesConstraint"]["errorType"] = "ErrorTypeType";
	propertyTypes["EndNode"]["exists"] = "ExistsType";
	propertyTypes["NodeConstraint"]["errorType"] = "ErrorTypeType";
	propertyTypes["NodesConstraint"]["errorType"] = "ErrorTypeType";
	propertyTypes["Parent"]["exists"] = "ExistsType";
}

void ConstraintsMetamodelPlugin::initPropertyDefaultsMap()
{
	propertyDefault["BeginNode"]["exists"] = QString::fromUtf8("true");
	propertyDefault["Childrens"]["selection"] = QString::fromUtf8("all");
	propertyDefault["EdgeConstraint"]["errorText"] = QString::fromUtf8("fail_text");
	propertyDefault["EdgeConstraint"]["errorType"] = QString::fromUtf8("warning");
	propertyDefault["EdgesConstraint"]["errorText"] = QString::fromUtf8("fail_text");
	propertyDefault["EdgesConstraint"]["errorType"] = QString::fromUtf8("warning");
	propertyDefault["EdgesConstraint"]["selection"] = QString::fromUtf8("all");
	propertyDefault["EndNode"]["exists"] = QString::fromUtf8("true");
	propertyDefault["IncomingLinks"]["selection"] = QString::fromUtf8("all");
	propertyDefault["IncomingNodes"]["selection"] = QString::fromUtf8("all");
	propertyDefault["NodeConstraint"]["errorText"] = QString::fromUtf8("fail_text");
	propertyDefault["NodeConstraint"]["errorType"] = QString::fromUtf8("warning");
	propertyDefault["NodesConstraint"]["errorText"] = QString::fromUtf8("fail_text");
	propertyDefault["NodesConstraint"]["errorType"] = QString::fromUtf8("warning");
	propertyDefault["NodesConstraint"]["selection"] = QString::fromUtf8("all");
	propertyDefault["OutgoingLinks"]["selection"] = QString::fromUtf8("all");
	propertyDefault["OutgoingNodes"]["selection"] = QString::fromUtf8("all");
	propertyDefault["Parent"]["exists"] = QString::fromUtf8("true");
}

void ConstraintsMetamodelPlugin::initDescriptionMap()
{
	elementsDescriptionMap["ConstraintsEditor"]["MultiOrEdge"] = QString::fromUtf8("Связь, позволяющий задавать логическое ИЛИ между группой элементарных ограничений через узел 'Multi Or Node'. Должен вкладываться в элементы задания ограничений на узлы или связи");
	elementsDescriptionMap["ConstraintsEditor"]["MultiOrNode"] = QString::fromUtf8("Элемент, позволяющий задавать логическое ИЛИ между группой элементарных ограничений при помощи связи 'Multi Or Edge'. Должен вкладываться в элементы задания ограничений на узлы или связи");
	elementsDescriptionMap["ConstraintsEditor"]["BeginNode"] = QString::fromUtf8("Сущность для задания ограничения на узел, находящийся в начале некоторой связи. Должен вкладываться в элементы задания ограничений на связи");
	elementsDescriptionMap["ConstraintsEditor"]["Childrens"] = QString::fromUtf8("Сущность для задания ограничения на детей (в смысле контейнеров) некоторого элемента рассматриваемого языка. Должен вкладываться в элементы задания ограничений на узлы");
	elementsDescriptionMap["ConstraintsEditor"]["ConstraintsDiagram"] = QString::fromUtf8("Элемент для описания ограничений на конкретный язык. В его свойствах указывается имя соответсвующего языка. Должен вкладываться в Metamodel Constraints");
	elementsDescriptionMap["ConstraintsEditor"]["EdgeConstraint"] = QString::fromUtf8("Элемент для задания ограничения на одну конкретную связь рассматриваемого языка. Должен вкладываться в Constraints Diagram");
	elementsDescriptionMap["ConstraintsEditor"]["EdgesConstraint"] = QString::fromUtf8("Элемент для задания ограничения на некоторый набор связей рассматриваемого языка. Должен вкладываться в Constraints Diagram");
	elementsDescriptionMap["ConstraintsEditor"]["EndNode"] = QString::fromUtf8("Сущность для задания ограничения на узел, находящийся в конце некоторой связи. Должен вкладываться в элементы задания ограничений на связи");
	elementsDescriptionMap["ConstraintsEditor"]["IncomingLinks"] = QString::fromUtf8("Сущность для задания ограничения на набор связей рассматриваемого языка, входящих в некоторый элемент. Должен вкладываться в элементы задания ограничений на узлы");
	elementsDescriptionMap["ConstraintsEditor"]["IncomingNodes"] = QString::fromUtf8("Сущность для задания ограничения на набор узлов рассматриваемого языка, находящихся на других концах входящих в некоторый элемент связей. Должен вкладываться в элементы задания ограничений на узлы");
	elementsDescriptionMap["ConstraintsEditor"]["MetamodelConstraints"] = QString::fromUtf8("Корневой элемент модели ограничений на метамодель. В его свойствах указываются имя метамодели, на которые накладываются ограничения, и необходимые для сборки параметры");
	elementsDescriptionMap["ConstraintsEditor"]["NodeConstraint"] = QString::fromUtf8("Элемент для задания ограничения на один конкретный узел рассматриваемого языка. Должен вкладываться в Constraints Diagram");
	elementsDescriptionMap["ConstraintsEditor"]["NodesConstraint"] = QString::fromUtf8("Элемент для задания ограничения на некоторый набор узлов рассматриваемого языка. Должен вкладываться в Constraints Diagram");
	elementsDescriptionMap["ConstraintsEditor"]["Or"] = QString::fromUtf8("Связь, означающая логическое ИЛИ между двумя элементарными ограничениями. Должен вкладываться в элементы задания ограничений на узлы или связи");
	elementsDescriptionMap["ConstraintsEditor"]["OutgoingLinks"] = QString::fromUtf8("Сущность для задания ограничения на набор связей рассматриваемого языка, исходящих из некоторого элемента. Должен вкладываться в элементы задания ограничений на узлы");
	elementsDescriptionMap["ConstraintsEditor"]["OutgoingNodes"] = QString::fromUtf8("Сущность для задания ограничения на набор узлов рассматриваемого языка, находящихся на других концах исходящих из некоторого элемента связей. Должен вкладываться в элементы задания ограничений на узлы");
	elementsDescriptionMap["ConstraintsEditor"]["Parent"] = QString::fromUtf8("Сущность для задания ограничения на родителя (в смысле контейнеров) некоторого элемента рассматриваемого языка. Должен вкладываться в элементы задания ограничений на узлы");
	elementsDescriptionMap["ConstraintsEditor"]["PropertyNode"] = QString::fromUtf8("Сущность для задания ограничения на некоторое свойство узла или связи рассматриваемого языка. Должен вкладываться в элементы задания ограничений на узлы или связи");
}

void ConstraintsMetamodelPlugin::initParentsMap()
{
	parentsMap["ConstraintsEditor"]["AbstractListOfElementsNode"]
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractSelectionNode"))
	;
	parentsMap["ConstraintsEditor"]["BeginNode"]
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractExistsNode"))
	;
	parentsMap["ConstraintsEditor"]["Childrens"]
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractNodeForNodeConstraint"))
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractListOfElementsNode"))
	;
	parentsMap["ConstraintsEditor"]["EdgeConstraint"]
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractErrorTypeNode"))
	;
	parentsMap["ConstraintsEditor"]["EdgesConstraint"]
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractSelectionNode"))
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractErrorTypeNode"))
	;
	parentsMap["ConstraintsEditor"]["EndNode"]
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractExistsNode"))
	;
	parentsMap["ConstraintsEditor"]["IncomingLinks"]
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractNodeForNodeConstraint"))
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractListOfElementsNode"))
	;
	parentsMap["ConstraintsEditor"]["IncomingNodes"]
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractNodeForNodeConstraint"))
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractListOfElementsNode"))
	;
	parentsMap["ConstraintsEditor"]["NodeConstraint"]
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractErrorTypeNode"))
	;
	parentsMap["ConstraintsEditor"]["NodesConstraint"]
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractSelectionNode"))
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractErrorTypeNode"))
	;
	parentsMap["ConstraintsEditor"]["OutgoingLinks"]
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractNodeForNodeConstraint"))
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractListOfElementsNode"))
	;
	parentsMap["ConstraintsEditor"]["OutgoingNodes"]
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractNodeForNodeConstraint"))
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractListOfElementsNode"))
	;
	parentsMap["ConstraintsEditor"]["Parent"]
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractNodeForNodeConstraint"))
		<< qMakePair(QString("ConstraintsEditor"), QString("AbstractExistsNode"))
	;
}

QStringList ConstraintsMetamodelPlugin::diagrams() const
{
	return diagramNameMap.keys();
}

QStringList ConstraintsMetamodelPlugin::diagramPaletteGroups(QString const &diagram) const
{
	return paletteGroupsMap[diagram].keys();
}

QStringList ConstraintsMetamodelPlugin::diagramPaletteGroupList(QString const &diagram, QString const &group) const
{
	return paletteGroupsMap[diagram][group];
}

QString ConstraintsMetamodelPlugin::diagramPaletteGroupDescription(QString const &diagram, QString const &group) const
{
	return paletteGroupsDescriptionMap[diagram][group];
}

QStringList ConstraintsMetamodelPlugin::elements(QString const &diagram) const
{
	return elementsNameMap[diagram].keys();
}

QStringList ConstraintsMetamodelPlugin::getPropertiesWithDefaultValues(QString const &element) const
{
	return propertyDefault[element].keys();
}

QIcon ConstraintsMetamodelPlugin::getIcon(SdfIconEngineV2Interface *engine) const
{
	return QIcon(engine);
}

QString ConstraintsMetamodelPlugin::editorName() const
{
	 return "ConstraintsMetamodel Editor";
}

QString ConstraintsMetamodelPlugin::diagramName(QString const &diagram) const
{
	return diagramNameMap[diagram];
}

QString ConstraintsMetamodelPlugin::diagramNodeName(QString const &diagram) const
{
	return diagramNodeNameMap[diagram];
}

QString ConstraintsMetamodelPlugin::elementName(QString const &diagram, QString const &element) const
{
	return elementsNameMap[diagram][element];
}

QString ConstraintsMetamodelPlugin::elementDescription(QString const &diagram, QString const &element) const
{
	return elementsDescriptionMap[diagram][element];
}

QString ConstraintsMetamodelPlugin::propertyDescription(QString const &diagram, QString const &element, QString const &property) const
{
	return propertiesDescriptionMap[diagram][element][property];
}

QString ConstraintsMetamodelPlugin::propertyDisplayedName(QString const &diagram, QString const &element, QString const &property) const
{
	return propertiesDisplayedNamesMap[diagram][element][property];
}

QString ConstraintsMetamodelPlugin::elementMouseGesture(QString const &diagram, QString const &element) const
{
	return elementMouseGesturesMap[diagram][element];
}

ElementImpl* ConstraintsMetamodelPlugin::getGraphicalObject(QString const &/*diagram*/, QString const &element) const
{
	if (element == "MultiOrEdge")
		return new MultiOrEdge();
	else if (element == "MultiOrNode")
		return new MultiOrNode();
	else if (element == "BeginNode")
		return new BeginNode();
	else if (element == "Childrens")
		return new Childrens();
	else if (element == "ConstraintsDiagram")
		return new ConstraintsDiagram();
	else if (element == "EdgeConstraint")
		return new EdgeConstraint();
	else if (element == "EdgesConstraint")
		return new EdgesConstraint();
	else if (element == "EndNode")
		return new EndNode();
	else if (element == "IncomingLinks")
		return new IncomingLinks();
	else if (element == "IncomingNodes")
		return new IncomingNodes();
	else if (element == "MetamodelConstraints")
		return new MetamodelConstraints();
	else if (element == "NodeConstraint")
		return new NodeConstraint();
	else if (element == "NodesConstraint")
		return new NodesConstraint();
	else if (element == "Or")
		return new Or();
	else if (element == "OutgoingLinks")
		return new OutgoingLinks();
	else if (element == "OutgoingNodes")
		return new OutgoingNodes();
	else if (element == "Parent")
		return new Parent();
	else if (element == "PropertyNode")
		return new PropertyNode();
	else {
		Q_ASSERT(!"Request for creation of an element with unknown name");
		return NULL;
	}
}

bool ConstraintsMetamodelPlugin::isParentOf(QString const &parentDiagram, QString const &parentElement, QString const &childDiagram, QString const &childElement) const
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
QList<QPair<QString, QString> > ConstraintsMetamodelPlugin::getParentsOf(QString const &diagram, QString const &element) const
{
	return parentsMap[diagram][element];
}
QStringList ConstraintsMetamodelPlugin::getPropertyNames(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "MultiOrEdge")
;
	else if (element == "MultiOrNode")
;
	else if (element == "BeginNode")
		result  << "exists";
	else if (element == "Childrens")
		result  << "count" << "selection";
	else if (element == "ConstraintsDiagram")
		result  << "languageName";
	else if (element == "EdgeConstraint")
		result  << "errorText" << "errorType";
	else if (element == "EdgesConstraint")
		result  << "errorText" << "errorType" << "selection";
	else if (element == "EndNode")
		result  << "exists";
	else if (element == "IncomingLinks")
		result  << "count" << "selection";
	else if (element == "IncomingNodes")
		result  << "count" << "selection";
	else if (element == "MetamodelConstraints")
		result  << "metamodelName" << "outputDirPath" << "pathToQReal";
	else if (element == "NodeConstraint")
		result  << "errorText" << "errorType";
	else if (element == "NodesConstraint")
		result  << "errorText" << "errorType" << "selection";
	else if (element == "Or")
;
	else if (element == "OutgoingLinks")
		result  << "count" << "selection";
	else if (element == "OutgoingNodes")
		result  << "count" << "selection";
	else if (element == "Parent")
		result  << "exists";
	else if (element == "PropertyNode")
		result  << "property" << "sign" << "value";
	return result;
}

QStringList ConstraintsMetamodelPlugin::getReferenceProperties(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "MultiOrEdge")
;
	else if (element == "MultiOrNode")
;
	else if (element == "BeginNode")
;
	else if (element == "Childrens")
;
	else if (element == "ConstraintsDiagram")
;
	else if (element == "EdgeConstraint")
;
	else if (element == "EdgesConstraint")
;
	else if (element == "EndNode")
;
	else if (element == "IncomingLinks")
;
	else if (element == "IncomingNodes")
;
	else if (element == "MetamodelConstraints")
;
	else if (element == "NodeConstraint")
;
	else if (element == "NodesConstraint")
;
	else if (element == "Or")
;
	else if (element == "OutgoingLinks")
;
	else if (element == "OutgoingNodes")
;
	else if (element == "Parent")
;
	else if (element == "PropertyNode")
;
	return result;
}

QStringList ConstraintsMetamodelPlugin::getTypesContainedBy(QString const &element) const
{
	QStringList result;
	if (element == "BeginNode")
		result << "PropertyNode" << "AbstractNodeForNodeConstraint" << "MultiOrNode" ;
	else if (element == "Childrens")
		result << "AbstractNodeForNodeConstraint" << "PropertyNode" << "MultiOrNode" ;
	else if (element == "ConstraintsDiagram")
		result << "AbstractErrorTypeNode" ;
	else if (element == "EdgeConstraint")
		result << "PropertyNode" << "AbstractExistsNode" << "MultiOrNode" ;
	else if (element == "EdgesConstraint")
		result << "PropertyNode" << "AbstractExistsNode" << "MultiOrNode" ;
	else if (element == "EndNode")
		result << "PropertyNode" << "AbstractNodeForNodeConstraint" << "MultiOrNode" ;
	else if (element == "IncomingLinks")
		result << "PropertyNode" << "AbstractExistsNode" << "MultiOrNode" ;
	else if (element == "IncomingNodes")
		result << "PropertyNode" << "AbstractNodeForNodeConstraint" << "MultiOrNode" ;
	else if (element == "MetamodelConstraints")
		result << "ConstraintsDiagram" ;
	else if (element == "NodeConstraint")
		result << "PropertyNode" << "AbstractNodeForNodeConstraint" << "MultiOrNode" ;
	else if (element == "NodesConstraint")
		result << "AbstractNodeForNodeConstraint" << "MultiOrNode" << "PropertyNode" ;
	else if (element == "OutgoingLinks")
		result << "PropertyNode" << "AbstractExistsNode" << "MultiOrNode" ;
	else if (element == "OutgoingNodes")
		result << "PropertyNode" << "AbstractNodeForNodeConstraint" << "MultiOrNode" ;
	else if (element == "Parent")
		result << "AbstractNodeForNodeConstraint" << "PropertyNode" << "MultiOrNode" ;
	return result;
}

QStringList ConstraintsMetamodelPlugin::getConnectedTypes(QString const &element) const
{
	QStringList result;
	Q_UNUSED(element);
	return result;
}

QStringList ConstraintsMetamodelPlugin::getUsedTypes(QString const &element) const
{
	QStringList result;
	Q_UNUSED(element);
	return result;
}

QList<QPair<QPair<QString,QString>,QPair<bool,QString> > > ConstraintsMetamodelPlugin::getPossibleEdges(QString const &element) const
{
	QList<QPair<QPair<QString,QString>,QPair<bool,QString> > > result;
	Q_UNUSED(element);
	return result;
}

//(-1) means "edge", (+1) means "node"
int ConstraintsMetamodelPlugin::isNodeOrEdge(QString const &element) const
{
	if (element == "MultiOrEdge")
		return -1;
	else if (element == "MultiOrNode")
		return 1;
	else if (element == "AbstractErrorTypeNode")
		return 1;
	else if (element == "AbstractExistsNode")
		return 1;
	else if (element == "AbstractListOfElementsNode")
		return 1;
	else if (element == "AbstractNodeForNodeConstraint")
		return 1;
	else if (element == "AbstractSelectionNode")
		return 1;
	else if (element == "BeginNode")
		return 1;
	else if (element == "Childrens")
		return 1;
	else if (element == "ConstraintsDiagram")
		return 1;
	else if (element == "EdgeConstraint")
		return 1;
	else if (element == "EdgesConstraint")
		return 1;
	else if (element == "EndNode")
		return 1;
	else if (element == "ErrorTypeType")
		return 0;
	else if (element == "ExistsType")
		return 0;
	else if (element == "IncomingLinks")
		return 1;
	else if (element == "IncomingNodes")
		return 1;
	else if (element == "MetamodelConstraints")
		return 1;
	else if (element == "NodeConstraint")
		return 1;
	else if (element == "NodesConstraint")
		return 1;
	else if (element == "Or")
		return -1;
	else if (element == "OutgoingLinks")
		return 1;
	else if (element == "OutgoingNodes")
		return 1;
	else if (element == "Parent")
		return 1;
	else if (element == "PropertyNode")
		return 1;
	return 0;
}
QStringList ConstraintsMetamodelPlugin::getEnumValues(QString name) const 
{
	QStringList result;
	if (name == "ExistsType")
		result << QString::fromUtf8("false") << QString::fromUtf8("true") << QString::fromUtf8("doesn't matter");
	else if (name == "ErrorTypeType")
		result << QString::fromUtf8("warning") << QString::fromUtf8("critical") << QString::fromUtf8("verification");
	return result;
}

QString ConstraintsMetamodelPlugin::getPropertyType(QString const &element, QString const &property) const
{
	return propertyTypes[element][property];
}

QString ConstraintsMetamodelPlugin::getPropertyDefaultValue(QString const &element, QString const &property) const
{
	return propertyDefault[element][property];
}

QList<qReal::ListenerInterface*> ConstraintsMetamodelPlugin::listeners() const
{
	QList<qReal::ListenerInterface*> result;
	return result;
}
