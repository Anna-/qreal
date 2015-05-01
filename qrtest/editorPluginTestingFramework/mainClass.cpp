#include "mainClass.h"
#include "defs.h"
#include "methodsTesterForQrxcAndQrmc.h"
#include "methodsTesterForQrxcAndInterpreter.h"
#include "methodsCheckerForTravis.h"

#include "qrgui/plugins/pluginManager/interpreterEditorManager.h"
#include "qrgui/plugins/pluginManager/editorManagerInterface.h"
#include "qrgui/plugins/pluginManager/editorManager.h"
#include "qrutils/xmlUtils.h"

#include <QtCore/QDir>
#include <QtCore/QFileInfo>

using namespace qReal;
using namespace editorPluginTestingFramework;
using namespace qrRepo;

MainClass::MainClass(
		QString const &fileName
		, QString const &pathToQrmc
		, QString const &applicationPath
		, QString const &configurationFileName)
		: mTempOldValue(SettingsManager::value("temp").toString())
		, mApplicationPath(applicationPath)
{
	setTempValueInSettingsManager();

	qDebug() << "configuration file: " << configurationFileName;
	parseConfigurationFile(configurationFileName);

	//deleteOldBinaries(mGeneratedCodeDirQrxc);
	//deleteOldBinaries(mGeneratedCodeDirQrmc);

	createNewFolders();
	QString const normalizedFileName = normalizedName(fileName);

	copyTestMetamodel(fileName);

	launchQrxc(normalizedFileName);
	compilePlugin(mGeneratedCodeDirQrxc + pathToQrxcGeneratedCode, normalizedFileName);
	EditorInterface* const qrxcGeneratedPlugin = loadedPlugin(normalizedFileName, mGeneratedCodeDirQrxc + pathToQrxcGeneratedPlugin);
	appendPluginNames();

	launchQrmc(fileName, pathToQrmc);
	compilePlugin(mGeneratedCodeDirQrmc + pathToQrmcGeneratedCode, normalizedFileName);
	EditorInterface* const qrmcGeneratedPlugin = loadedPlugin(normalizedFileName, mGeneratedCodeDirQrmc + pathToQrmcGeneratedPlugin);

	InterpreterEditorManager interpreterEditorManager(fileName, nullptr);
	EditorManager qrxcEditorManager("plugins/editors/qrxc/plugins");
	// we cast qrxc plugin to Editor Manager "plugins/editors/qrxc/plugin

	MethodsTesterForQrxcAndInterpreter* const interpreterMethodsTester = new MethodsTesterForQrxcAndInterpreter(
			&qrxcEditorManager
			,&interpreterEditorManager);

	QList<QPair<QString, QPair<QString, QString> > > interpreterMethodsTesterOutput =
			interpreterMethodsTester->generatedResult();
	QList<QPair<QString, QPair<QString, QString> > > methodsTimeOutputInterpreter = interpreterMethodsTester->generateTimeResult();


	if ((qrxcGeneratedPlugin != NULL) && (qrmcGeneratedPlugin != NULL)) {
		MethodsTesterForQrxcAndQrmc* const methodsTester = new MethodsTesterForQrxcAndQrmc(
				qrmcGeneratedPlugin, qrxcGeneratedPlugin);

		QList<QPair<QString, QPair<QString, QString> > > methodsTesterOutput = methodsTester->generatedOutput();
		QList<QPair<QString, QPair<QString, QString> > > methodsTimeOutput = methodsTester->generateTimeResult();

		if (mGenerateHtml == "yes") {
			createHtml(methodsTesterOutput, interpreterMethodsTesterOutput, methodsTimeOutput, methodsTimeOutputInterpreter);
		}
		mResultOfTesting = MethodsCheckerForTravis::calculateResult(methodsTesterOutput
				, interpreterMethodsTesterOutput);
	} else {
		qDebug() << "Generation of plugins failed";
	}

	returnOldValueOfTemp();
}

int MainClass::travisTestResult() const
{
	return mResultOfTesting;
}

void MainClass::createFolder(QString const &path)
{
	QDir dir;
	if (!dir.exists(path)) {
		dir.mkdir(path);
	}
}

void MainClass::createNewFolders()
{
	createFolder(mGeneratedCodeDirQrxc);
	createFolder(mGeneratedCodeDirQrxc + pluginsDir);
	createFolder(mGeneratedCodeDirQrxc + sourcesDir);
	createFolder(mGeneratedCodeDirQrmc + pathToQrmcGeneratedPlugin);
	createFolder(mGeneratedCodeDirQrxc + pathToQrxcGeneratedPlugin);
}

QString MainClass::normalizedName(QString const &fileName)
{
	QString normalizedName = fileName;
	if (fileName.contains("/")) {
		QStringList splittedName = normalizedName.split("/");
		normalizedName = splittedName.last();
	}
	if (normalizedName.contains(".qrs")) {
		normalizedName.chop(4);
	}
	return normalizedName;
}

void MainClass::deleteOldBinaries(QString const &directory)
{
	QDir dir(directory);
	if (!dir.exists()) {
		return;
	}

	foreach (QFileInfo const &fileInfo, dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot)) {
		if (fileInfo.isDir()) {
			deleteOldBinaries(fileInfo.filePath());
			dir.rmdir(fileInfo.fileName());
		} else {
			dir.remove(fileInfo.fileName());
		}
	}
}

void MainClass::copyTestMetamodel(QString const &fileName)
{
	QString const workingDirName = pathToTestMetamodel;
	QDir sourceDir(workingDirName);

	QFileInfo const destDirInfo;
	QDir destDir = destDirInfo.dir();

	QFile::copy(sourceDir.absolutePath() + "/" + fileName, destDir.absolutePath() + "/" + fileName);
}

void MainClass::setTempValueInSettingsManager()
{
//	mApplicationPath.chop(4);
	SettingsManager::setValue("temp", mApplicationPath + tempValueForSettingsManager);
}

void MainClass::returnOldValueOfTemp() const
{
	SettingsManager::setValue("temp", mTempOldValue);
}

void MainClass::launchQrmc(QString const &fileName, QString const &pathToQrmc)
{
	mQrmcLauncher.launchQrmc(fileName, pathToQrmc, mGeneratedCodeDirQrmc);
}

void MainClass::compilePlugin(QString const &directoryToCodeToCompile, const QString &fileName)
{
	mPluginCompiler.compilePlugin(
			fileName
			, directoryToCodeToCompile
			, mQmakeParameter
			, mMakeParameter
			, mConfigurationParameter
	);
}

void MainClass::launchQrxc(QString const &fileName)
{
	QString tempPath = "plugins/editors/qrtest/qrxc";
	mQrxcLauncher.launchQrxc(fileName, mQRealRootPath, tempPath);
}

EditorInterface* MainClass::loadedPlugin(QString const &fileName, QString const &pathToFile)
{
	return mPluginLoader.loadedPlugin(fileName, pathToFile, mPluginExtension, mPrefix);
}

void MainClass::createHtml(QList<QPair<QString, QPair<QString, QString> > > qrxcAndQrmcResult
		, QList<QPair<QString, QPair<QString, QString> > > qrxcAndInterpreterResult
		, QList<QPair<QString, QPair<QString, QString> > > timeResult
		, QList<QPair<QString, QPair<QString, QString> > > timeResultInterpter)
{
	mHtmlMaker.makeHtml(qrxcAndQrmcResult, qrxcAndInterpreterResult, timeResult, timeResultInterpter, mGeneratedDirHtml);
}

void MainClass::appendPluginNames()
{
	mQrxcGeneratedPluginsList.append(mPluginLoader.pluginNames());
}

void MainClass::parseConfigurationFile(QString const &fileName)
{
	mConfigurationFileParser.parseConfigurationFile(fileName);

	mQmakeParameter = mConfigurationFileParser.qmakeParameter();
	mMakeParameter = mConfigurationFileParser.makeParameter();
	mConfigurationParameter = mConfigurationFileParser.configurationParameter();
	mPluginExtension = mConfigurationFileParser.pluginExtension();
	mPrefix = mConfigurationFileParser.prefix();
	mQRealRootPath = mConfigurationFileParser.qRealRootPath();
	mGenerateHtml = mConfigurationFileParser.htmlGenerationParameter();
	mGeneratedCodeDirQrxc = mConfigurationFileParser.generatedCodeDirQrxc();
	mGeneratedCodeDirQrmc = mConfigurationFileParser.generatedCodeDirQrmc();
	mGeneratedDirHtml = mConfigurationFileParser.generatedDirHtml();
}

