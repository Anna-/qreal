#pragma once

#include <ev3GeneratorBase/ev3MasterGeneratorBase.h>

namespace ev3 {
namespace rbf {

class Ev3RbfMasterGenerator : public Ev3MasterGeneratorBase
{
public:
	Ev3RbfMasterGenerator(qrRepo::RepoApi const &repo
			, qReal::ErrorReporterInterface &errorReporter
			, interpreterBase::robotModel::RobotModelManagerInterface const &robotModelManager
			, qrtext::LanguageToolboxInterface &textLanguage
			, qReal::Id const &diagramId
			, QString const &generatorName);

	/// Starts code generation process. Returns path to file with generated code
	/// if it was successfull and an empty string otherwise.
	QString generate() override;

protected:
	QString targetPath() override;
	bool supportsGotoGeneration() const override;
};

}
}

