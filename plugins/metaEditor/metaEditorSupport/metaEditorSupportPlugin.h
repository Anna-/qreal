#pragma once

#include <QtCore/QTranslator>

#include "../../../qrgui/toolPluginInterface/toolPluginInterface.h"
#include "../../../qrgui/toolPluginInterface/pluginConfigurator.h"

namespace metaEditor {

class MetaEditorSupportPlugin : public QObject, public qReal::ToolPluginInterface
{
	Q_OBJECT
	Q_INTERFACES(qReal::ToolPluginInterface)

public:
	MetaEditorSupportPlugin();
	virtual ~MetaEditorSupportPlugin();

	virtual void init(qReal::PluginConfigurator const &configurator);
	virtual QList<qReal::ActionInfo> actions();

private slots:

	void generateEditorForQrxc();

	void generateEditorWithQrmc();

	void parseEditorXml();

private:
	void loadNewEditor(QString const &directoryName
			, QString const &metamodelName
			, QString const &commandFirst
			, QString const &commandSecond
			, QString const &extension
			, QString const &prefix);


	QAction mGenerateEditorForQrxcAction;


	QAction mGenerateEditorWithQrmcAction;


	QAction mParseEditorXmlAction;

	/// Thanslator object for this plugin, provides localisation
	QTranslator mAppTranslator;

	/// Interface of MainWindow, used, for example, to reinit models when finished parsing
	qReal::gui::MainWindowInterpretersInterface *mMainWindowInterface;  // Does not have ownership

	/// API of logical part of a repository, mutable to allow parser build model
	qrRepo::LogicalRepoApi *mLogicalRepoApi;  // Does not have ownership
};

}