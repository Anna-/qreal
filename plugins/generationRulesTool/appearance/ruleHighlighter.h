#pragma once

#include <QtGui/QSyntaxHighlighter>

namespace generationRules {

/// Class for highlighting generation rules.
class RuleHighlighter : public QSyntaxHighlighter
{
	Q_OBJECT

public:
	/// Constructor.
	RuleHighlighter(QTextDocument *parent = 0);

protected:
	void highlightBlock(const QString &text);

private:
	struct HighlightingRule
	{
		QRegExp pattern;
		QTextCharFormat format;
	};

	QVector<HighlightingRule> mHighlightingRules;

	QTextCharFormat mKeywordFormat;
	QTextCharFormat mConstantTextFormat;
};

}
