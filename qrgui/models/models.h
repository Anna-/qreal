#pragma once

#include "details/graphicalModel.h"
#include "details/logicalModel.h"
#include "graphicalModelAssistApi.h"
#include "logicalModelAssistApi.h"
#include "../../qrkernel/ids.h"

namespace qReal {

namespace models {

class Models
{
public:
	explicit Models(QString const &workingCopy, EditorManager const &editorManager, ConstraintsManager const &constraintsManager);//qwerty
	~Models();

	QAbstractItemModel* graphicalModel() const;
	QAbstractItemModel* logicalModel() const;

	GraphicalModelAssistApi &graphicalModelAssistApi() const;
	LogicalModelAssistApi &logicalModelAssistApi() const;

	qrRepo::RepoControlInterface &repoControlApi() const;

	qrRepo::LogicalRepoApi const &logicalRepoApi() const;
	qrRepo::LogicalRepoApi &mutableLogicalRepoApi() const;

	qrRepo::GraphicalRepoApi const &graphicalRepoApi() const;

	Id logicalId(Id const &element) const;//qwerty

	void reinit();

private:
	models::details::GraphicalModel *mGraphicalModel;
	models::details::LogicalModel *mLogicalModel;
	qrRepo::RepoControlInterface *mRepoApi;
};

}

}
