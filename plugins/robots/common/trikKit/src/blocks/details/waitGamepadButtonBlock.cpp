#include "waitGamepadButtonBlock.h"

#include <kitBase/robotModel/robotModelInterface.h>
#include <kitBase/robotModel/robotModelUtils.h>

#include "trikKit/robotModel/parts/trikGamepadButton.h"

using namespace trik::blocks::details;
using namespace kitBase::robotModel;

WaitGamepadButtonBlock::WaitGamepadButtonBlock(kitBase::robotModel::RobotModelInterface &robotModel)
	: WaitBlock(robotModel)
{
	mActiveWaitingTimer.setInterval(200);
}

void WaitGamepadButtonBlock::run()
{
	const QString port = eval<QString>("Button");
	const QString portName = QString("GamepadButton%1Port").arg(port);

	mButton = RobotModelUtils::findDevice<robotModel::parts::TrikGamepadButton>(mRobotModel, portName);

	if (!mButton) {
		mActiveWaitingTimer.stop();
		error(tr("Incorrect port for gamepad button %1").arg(port));
		return;
	}

	connect(mButton, &robotModel::parts::TrikGamepadButton::newData, this, &WaitGamepadButtonBlock::responseSlot);

	mButton->read();
	mActiveWaitingTimer.start();
}

void WaitGamepadButtonBlock::timerTimeout()
{
	mButton->read();
}

void WaitGamepadButtonBlock::responseSlot(int isPressed)
{
	if (isPressed) {
		stop();
	}
}

DeviceInfo WaitGamepadButtonBlock::device() const
{
	return DeviceInfo::create<robotModel::parts::TrikGamepadButton>();
}
