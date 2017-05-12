#pragma once

#include "../../../qrutils/generator/abstractGenerator.h"

namespace dachass {
namespace dachassGenerator {

class Generator : public utils::AbstractGenerator
{
public:
	/** Constructor.
	  @param templateDirPath Path to a directory with generation template.
	  @param outputDirPath Path to a directory.
	  @param logicalModel Logical model reference.
	  @param errorReporter Object to return errors to.
	  */
	Generator(QString const &outputDirPath
			, QString const &programName
			, qReal::LogicalModelAssistInterface const &logicalModel
			, qReal::ErrorReporterInterface &errorReporter
			);

	virtual ~Generator();

	/// Starts generation.
	void generate();

private:
	bool isCorrectedName(QString const &name);

	QString mProgramName;
	QVector<QString> mCompileIncludeFiles;

	QString mResultForms;
	QString mResultVariables;
};

}
}

