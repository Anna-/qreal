#include "systemCommandBlock.h"

using namespace trikKitInterpreter::blocks::details;
using namespace interpreterBase::robotModel;

SystemCommandBlock::SystemCommandBlock(RobotModelInterface &robotModel)
	: interpreterBase::blocksBase::common::DeviceBlock<robotModel::parts::TrikShell>(robotModel)
{
}

void SystemCommandBlock::doJob(robotModel::parts::TrikShell &shell)
{
	const QString command = stringProperty("Command").replace("\"", "\\\"");
	shell.runCommand(command);

	emit done(mNextBlockId);
}
