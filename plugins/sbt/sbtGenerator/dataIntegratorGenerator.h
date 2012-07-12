#pragma once
#include "QString"
#include "QList"

#include "../../../qrgui/toolPluginInterface/usedInterfaces/logicalModelAssistInterface.h"
#include "../../../qrgui/toolPluginInterface/usedInterfaces/errorReporterInterface.h"
#include "../../../qrutils/generator/abstractGenerator.h"

using namespace qReal;
using namespace utils;

class DataIntegratorGenerator : public AbstractGenerator
{
public:
  DataIntegratorGenerator(QString const &templateDirPath
					, QString const &outputDirPath
					, qReal::LogicalModelAssistInterface const &logicalModel
					, qReal::ErrorReporterInterface &errorReporter
					);
	QList<QString> getFiles();
	void generate();
private:
QList<QString> mFiles;
};

