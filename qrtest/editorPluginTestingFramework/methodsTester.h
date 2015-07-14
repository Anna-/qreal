#pragma once

#include "qrgui/plugins/pluginManager/editorManagerInterface.h"
#include "qrgui/plugins/pluginManager/interpreterEditorManager.h"
#include "qrgui/plugins/pluginManager/editorManager.h"
#include "qrgui/plugins/editorPluginInterface/editorInterface.h"

#include "abstractStringGenerator.h"

namespace editorPluginTestingFramework {

class MethodsTester
{
public:

	QList<QPair<QString, QPair<QString, QString>>> generateTimeResult();
	virtual ~MethodsTester() {}

protected:

	virtual AbstractStringGenerator * initGeneratorWithFirstInterface(const AbstractStringGenerator &generator) const = 0;
	virtual AbstractStringGenerator * initGeneratorWithSecondInterface(const AbstractStringGenerator &generator) const = 0;

	/// tests given method if it exists in list of methods to be tested
	QPair<QString, QPair<QString, QString>> testMethodIfExistsInList(
			const AbstractStringGenerator &stringGenerator
			, const QString &method
			);

	/// fills list of methods to test with methods from given .txt-file
	void fillMethodsToTestList(const QString &fileName);

private:

	void generateOutputTimeForOneMethod(const AbstractStringGenerator &stringGenerator);

	/// generated method name and results for two interfaces, returns triplet of strings
	QPair<QString, QPair<QString, QString> > generateOutputForOneMethod(AbstractStringGenerator const &stringGenerator);

	/// list of methods to be tested, is filled from files
	QStringList mMethodsToTest;
	QList<QPair<QString, QPair<QString, QString>>> mTimeResult;

};

}
