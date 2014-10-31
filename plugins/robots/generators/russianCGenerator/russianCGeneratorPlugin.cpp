#include "russianCGeneratorPlugin.h"

#include <QtWidgets/QApplication>
#include <QtCore/QDir>

#include "russianCMasterGenerator.h"

using namespace russianC;
using namespace generatorBase;

RussianCGeneratorPlugin::RussianCGeneratorPlugin()
	: mGenerateCodeAction(nullptr)
{
}

RussianCGeneratorPlugin::~RussianCGeneratorPlugin()
{
}

QString RussianCGeneratorPlugin::kitId() const
{
	return "nxtKit";
}

QString RussianCGeneratorPlugin::defaultFilePath(QString const &projectName) const
{
	return QString::fromUtf8("russianC/%1/%1.си").arg(projectName);
}

QString RussianCGeneratorPlugin::extension() const
{
	return QString::fromUtf8("си");
}

QString RussianCGeneratorPlugin::extensionDescription() const
{
	return tr("RussianC Source File");
}

QString RussianCGeneratorPlugin::generatorName() const
{
	return "RussianC";
}

QList<qReal::ActionInfo> RussianCGeneratorPlugin::actions()
{
	mGenerateCodeAction.setText(tr("Generate to Russian C"));
	mGenerateCodeAction.setIcon(QIcon(":/images/generateRussianCCode.svg"));
	qReal::ActionInfo generateCodeActionInfo(&mGenerateCodeAction, "generators", "tools");
	mGenerateCodeAction.setObjectName("generateRussianC");
	connect(&mGenerateCodeAction, SIGNAL(triggered()), this, SLOT(generateCode()));

	return { generateCodeActionInfo };
}

QList<qReal::HotKeyActionInfo> RussianCGeneratorPlugin::hotKeyActions()
{
	mGenerateCodeAction.setShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_G));

	qReal::HotKeyActionInfo generateActionInfo("Generator.GenerateNxtRussianC"
			, tr("Generate Russian C Code"), &mGenerateCodeAction);

	return { generateActionInfo };
}

MasterGeneratorBase *RussianCGeneratorPlugin::masterGenerator()
{
	return new RussianCMasterGenerator(*mRepo
			, *mMainWindowInterface->errorReporter()
			, *mRobotModelManager
			, *mTextLanguage
			, mMainWindowInterface->activeDiagram());
}


void RussianCGeneratorPlugin::regenerateExtraFiles(QFileInfo const &newFileInfo)
{
	Q_UNUSED(newFileInfo);
}


void RussianCGeneratorPlugin::changeActiveTab(QList<qReal::ActionInfo> const &info, bool trigger)
{
	for (qReal::ActionInfo const &actionInfo : info) {
		actionInfo.action()->setEnabled(trigger);
	}
}
