#pragma once
#include "QtCore/QString"
#include "QtCore/QList"

#include "../../../qrgui/toolPluginInterface/usedInterfaces/logicalModelAssistInterface.h"
#include "../../../qrgui/toolPluginInterface/usedInterfaces/errorReporterInterface.h"
#include "../../../qrutils/generatorsUtils/abstractGenerator.h"

namespace sbt {

class DataObjectGenerator : public generatorsUtils::AbstractGenerator
{
public:
	DataObjectGenerator(QString const &templateDirPath
			, QString const &outputDirPath
			, qReal::LogicalModelAssistInterface const &logicalModel
			, qReal::ErrorReporterInterface &errorReporter
			);

	/// Starts generation process.
	virtual void generate();

	/// Returns list of generated files.
	QList<QString> getFiles();

private:
	QList<QString> mFiles;
};

}
