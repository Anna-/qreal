TEMPLATE = subdirs

SUBDIRS = \
	editor \
	robotsInterpreter \
	robotsGenerator \
	qextserialport \
	constraintsRobotsMetamodel/constraintsRobotsMetamodel.pro \

qextserialport.file = thirdparty/qextserialport/qextserialport.pro
robotsInterpreter.depends = qextserialport
