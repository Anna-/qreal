#pragma once

#include <QtCore/QString>

namespace editorPluginTestingFramework {

/// Class for generating results and names for methods of one interface.
class AbstractStringGenerator
{
public:
	/// clones StringGenerator and inits cloned generator
	virtual AbstractStringGenerator* clone() const = 0;

	/// generates string of results for one method of one interface
	virtual QString generateString() const = 0;

	/// generates string of results for one method of one interface
	virtual QString generateStringTime()
	{
		return "";
	}

	/// generates name of tested method
	virtual QString methodName() const = 0;
	virtual ~AbstractStringGenerator() {}
};

}
