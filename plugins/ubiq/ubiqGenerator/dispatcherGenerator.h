#pragma once

#include "abstractGenerator.h"

namespace ubiq {
namespace generator {

class DispatcherGenerator : public AbstractGenerator
{
public:
	DispatcherGenerator(QString const &templateDirPath
			, QString const &outputDirPath
			, qReal::LogicalModelAssistInterface const &logicalModel
			, qReal::ErrorReporterInterface &errorReporter
			);

	virtual ~DispatcherGenerator();

	void generate();

private:
	QString generateEventHandlers(qReal::Id const &diagram);
	QString generateEventHandler(QString const handlerName);
};

}
}
