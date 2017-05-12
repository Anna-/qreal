#include "generator.h"
#include "../../../qrutils/nameNormalizer.h"
#include <QtCore/QFile>
#include <QtCore/QDebug>
#include <QMessageBox>

using namespace dachass::dachassGenerator;
using namespace qReal;
using namespace utils;

QString const templateDir = "/templates";

/// Generation target file

Generator::Generator(QString const &outputDirPath
		, QString const &programName
		, qReal::LogicalModelAssistInterface const &logicalModel
		, qReal::ErrorReporterInterface &errorReporter
		)
	: AbstractGenerator(templateDir, QString(outputDirPath + "/" + programName).replace("\\", "/"), logicalModel, errorReporter)
	, mProgramName(programName)
{
}

Generator::~Generator()
{
}

bool Generator::isCorrectedName(QString const &name)
{
	QRegExp patten;
	patten.setPattern("[A-Za-z]+([A-Za-z_0-9]*)");
	return patten.exactMatch(name);
}

void Generator::generate()
{
	qDebug() << "Generator::generate()" << mProgramName << " : " << mOutputDirPath;
	QMessageBox msgBox;
	msgBox.setText("Hello Here");
	msgBox.exec();
}


