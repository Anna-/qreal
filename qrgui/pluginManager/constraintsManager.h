#pragma once

#include "../../qrrepo/logicalRepoApi.h"
#include "../constraintsPluginInterface/constraintsPluginInterface.h"

namespace qReal {

class ConstraintsManager
{
public:
	ConstraintsManager();
	CheckStatus check(IdList const &elements, qrRepo::LogicalRepoApi const &logicalApi);

private:
	QList<ConstraintsPluginInterface *> mPlugins;
};

}