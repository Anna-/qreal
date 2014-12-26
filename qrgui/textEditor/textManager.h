#pragma once

#include <QtCore/QObject>
#include <QtCore/QMap>
#include <QtCore/QMultiHash>

#include "qrgui/textEditor/textEditorDeclSpec.h"
#include "qrgui/textEditor/textManagerInterface.h"

namespace qReal {

namespace gui {
class MainWindowInterpretersInterface;
}

namespace text {

class QRGUI_TEXT_EDITOR_EXPORT TextManager : public TextManagerInterface
{
	Q_OBJECT

public:
	TextManager(SystemEvents &systemEvents, gui::MainWindowInterpretersInterface &mainWindow);

	/// Reads code source file and create new QScintillaTextEdit associated with this file (rather with filepath)
	bool openFile(QString const &filePath, QString const &genName, LanguageInfo const &language);

	/// Remove all info about filePath (including QScintillaTextEdit associated with it)
	bool closeFile(QString const &filePath);

	void changeFilePath(QString const &from, QString const &to);

	/// Binds diagram with another code source file.
	bool bindCode(Id const &diagram, QString const &filePath);

	bool unbindCode(QString const &filePath);
	bool unbindCode(text::QScintillaTextEdit *code);
	text::QScintillaTextEdit *code(QString const &filePath) const;
	QList<text::QScintillaTextEdit *> code(Id const &diagram) const;
	bool contains(QString const &filePath) const;
	bool removeDiagram(Id const &diagram);
	Id diagram(text::QScintillaTextEdit *code) const;
	QString path(text::QScintillaTextEdit *code) const;
	bool isDefaultPath(QString const &path) const;
	bool isModified(QString const &path) const;
	bool isModifiedEver(QString const &path) const;

	/// Opens new tab with file created by some generator in text editor and shows a text in it
	/// @param fileInfo A filepath to file with text
	/// @param genName A name of generator which created this file
	void showInTextEditor(QFileInfo const &fileInfo, QString const &genName, LanguageInfo const &language);

	/// Opens new tab with file
	/// @param fileInfo A filepath to file with text
	void showInTextEditor(QFileInfo const &fileInfo, LanguageInfo const &language);

	/// Saves text from tab to another or same file
	/// @param saveAs Defines what to do: save to the same file or in another
	bool saveText(bool saveAs);

	QString generatorName(QString const &filepath) const;

private slots:
	void setModified(text::QScintillaTextEdit *code, bool modified = true);
	void onTabClosed(QFileInfo const &file);

private:
	QMap<QString, text::QScintillaTextEdit *> mText;
	QMap<text::QScintillaTextEdit *, QString> mPath;

	/// If default path - true.
	QMap<QString, bool> mPathType;

	/// Contains names of generator, which generate each сщfile
	QMap<QString, QString> mGeneratorName;

	/// First - was modified once and more (with save), second - was modified recently and not saved
	QMap<QString, QPair<bool, bool> > mModified;

	/// mCodeTabManager - Map that keeps pairs of opened tabs and their code areas.
	QMultiHash<Id, QString> mDiagramCodeManager;

	gui::MainWindowInterpretersInterface &mMainWindow;
	SystemEvents &mSystemEvents;
};

}
}
