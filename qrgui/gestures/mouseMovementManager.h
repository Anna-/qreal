#pragma once

#include <qrkernel/ids.h>

#include <QtCore/QMap>
#include <QtWidgets/QWidget>

#include "gesturesPainterInterface.h"
#include "private/geometricForms.h"

#include "pluginManager/editorManagerInterface.h"

namespace qReal {
namespace gestures {

class KeyManager;
class GesturesManager;

class MouseMovementManager
{
public:
	/// Specifies the type of the result of the gesture made by user: regular element creation or some metagesture
	/// (e.g. element deletion).
	enum GestureResultType
	{
		invalidGesture
		, createElementGesture
		, deleteGesture
	};

	/// Specifies the result of the gesture made.
	struct GestureResult
	{
	public:
		GestureResult();
		explicit GestureResult(GestureResultType type, Id const &id = Id());

		/// Returns the resulting type of the gesture.
		GestureResultType type() const;

		/// Returns the type of the element requested by the gesture.
		Id elementType() const;

		/// Returns the resulting type of the gesture.
		void setType(GestureResultType type);

		/// Sets the type of the element requested by the gesture.
		void setElementType(Id const &id);

	private:
		GestureResultType mType;
		Id mId;
	};

	MouseMovementManager(Id const &diagram
			, EditorManagerInterface const &editorManagerInterface
			, GesturesPainterInterface *gesturesPaintManager);

	~MouseMovementManager();

	void initializeGestures();
	void mousePress(QPointF const &point);
	void mouseMove(QPointF const &point);
	void clear();
	void setGesturesPainter(GesturesPainterInterface *gesturesPainter);
	GestureResult result();
	static PathVector stringToPath(QString const &str);
	QPointF pos();
	QPointF firstPoint();
	QPointF lastPoint();
	QLineF newLine();
	void printElements();
	void drawIdealPath();
	bool wasMoving();
	bool isEdgeCandidate();
	bool pathIsEmpty();

private:
	static QPoint parsePoint(QString const &str);
	void recountCentre();

	Id const mDiagram;
	EditorManagerInterface const &mEditorManagerInterface;
	GesturesPainterInterface *mGesturesPaintMan;  // Does not take ownership
	PathVector mPath;
	QPointF mCenter;
	QSet<Id> mInitializedGestures;
	QScopedPointer<KeyManager> mKeyStringManager;
	QScopedPointer<GesturesManager> mGesturesManager;
};

}
}
