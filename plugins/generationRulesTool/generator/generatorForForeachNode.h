#pragma once

#include <qrgui/plugins/interpretedPluginInterface/interpretedPluginInterface.h>

#include <QtCore/QSharedPointer>
#include <QtCore/QString>

#include "ast/foreach.h"

#include "variablesTable.h"

namespace generationRules {
namespace generator {

class GeneratorForForeachNode
{
public:
	static QString generatedResult(QSharedPointer<simpleParser::ast::Foreach> foreachNode
			, qReal::LogicalModelAssistInterface *logicalModelInterface
			, VariablesTable tableOfVariables
			, qReal::EditorManagerInterface *editorManagerInterface
			, const QString &generatorName = ""
			, const qReal::Id elementId = qReal::Id::rootId()
			, const QString &basicElementType = ""
			, const QString &basicElementName = ""
			);
};

}
}
