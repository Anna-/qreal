#pragma once

#include <QtCore/QTranslator>
#include <qrgui/plugins/toolPluginInterface/toolPluginInterface.h>
#include "generator.h"

namespace dachass {
namespace dachassGenerator {

class DachassGeneratorPlugin : public QObject, public qReal::ToolPluginInterface
{
	Q_OBJECT
	Q_INTERFACES(qReal::ToolPluginInterface)
	Q_PLUGIN_METADATA(IID "dachass.DachassGeneratorPlugin")

public:
	DachassGeneratorPlugin();
	virtual ~DachassGeneratorPlugin();

	/// Initializes generator with ref to logical model.
	virtual void init(qReal::PluginConfigurator const &configurator);

	/// Returns list containing "generate" action, which runs a generator.
	virtual QList<qReal::ActionInfo> actions();

private slots:
	void generate();
private:
	Generator *mGenerator;

	/// Interface of MainWindow, used, for example, to reinit models when finished parsing
	qReal::gui::MainWindowInterpretersInterface *mMainWindowInterface;  // Does not have ownership

	/// Logical model, from which generator takes all information.
	qReal::LogicalModelAssistInterface const *mLogicalModel;

	/// Error reporter object, used to show generation errors in output window.
	qReal::ErrorReporterInterface *mErrorReporter;

	/// Thanslator object for this plugin, provides localisation
	QTranslator mAppTranslator;
};

}
}
