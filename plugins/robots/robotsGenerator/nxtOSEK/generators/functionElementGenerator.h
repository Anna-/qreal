#pragma once

#include "../../../../../qrkernel/ids.h"
#include "../smartLine.h"
#include "../nxtOSEKRobotGenerator.h"
#include "simpleElementGenerator.h"

namespace robots {
namespace generator {

/// Realization of AbstractElementGenerator for Function.
class FunctionElementGenerator: public SimpleElementGenerator {
public:
	explicit FunctionElementGenerator(NxtOSEKRobotGenerator *generator, qReal::Id elementId, bool generateToInit);

protected:
	virtual QList<SmartLine> simpleCode();
	void variableAnalysis(QByteArray const &code);

private:
	bool mGenerateToInit;
	QByteArray replaceSensorVariables(QByteArray portValue);
};

}
}
