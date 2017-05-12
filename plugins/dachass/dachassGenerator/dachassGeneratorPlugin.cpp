#include "dachassGeneratorPlugin.h"
#include <QMessageBox>
#include <QProgressBar>
#include <QtCore/QProcess>
#include <QFileDialog>
#include <QApplication>
#include <QDesktopWidget>

#include "../../../qrkernel/settingsManager.h"

using namespace dachass::dachassGenerator;
using namespace qReal;

DachassGeneratorPlugin::DachassGeneratorPlugin()
{
}

DachassGeneratorPlugin::~DachassGeneratorPlugin()
{
}

void DachassGeneratorPlugin::init(PluginConfigurator const &configurator)
{
	mMainWindowInterface = &configurator.mainWindowInterpretersInterface();
	mLogicalModel = &configurator.logicalModelApi();
	mErrorReporter = configurator.mainWindowInterpretersInterface().errorReporter();
}

QList<ActionInfo> DachassGeneratorPlugin::actions()
{
	QAction * const generateAction = new QAction(QObject::tr("Generate DACHaSS program"), NULL);
	ActionInfo generateActionInfo(generateAction, "interpreters", "tools");
	QObject::connect(generateAction, SIGNAL(triggered()), this, SLOT(generate()));

	return QList<ActionInfo>() << generateActionInfo;
}

void DachassGeneratorPlugin::generate()
{
	qDebug() << "DachassGeneratorPlugin::generate()";
	foreach (qReal::Id const &diagram, mLogicalModel->logicalRepoApi().elementsByType("newDachassModel")) {
		if (!mLogicalModel->logicalRepoApi().isLogicalElement(diagram)) {
			continue;
		}

		QString programName = mLogicalModel->logicalRepoApi().property(diagram, "programName").toString();
		QString pathToGenerate = mLogicalModel->logicalRepoApi().property(diagram, "pathToGenerate").toString();

		mGenerator = new Generator(pathToGenerate, programName, *mLogicalModel, *mErrorReporter);
		mGenerator->generate();
	}
}
