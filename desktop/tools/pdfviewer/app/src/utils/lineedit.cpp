/****************************************************************************
**
** Copyright (c) 2007 Trolltech ASA <info@trolltech.com>
** Modified (c) 2009, 2011 by Glad Deschrijver <glad.deschrijver@gmail.com>
**
** Use, modification and distribution is allowed without limitation,
** warranty, liability or support of any kind.
**
****************************************************************************/

#include "lineedit.h"

#include <QtGui/QToolButton>
#include <QtGui/QStyle>

LineEdit::LineEdit(const QString &text, QWidget *parent)
	: QLineEdit(parent)
{
	init();
	setText(text);
}

LineEdit::LineEdit(QWidget *parent)
	: QLineEdit(parent)
{
	init();
}

void LineEdit::init()
{
	m_clearButton = new QToolButton(this);
	const QPixmap pixmap(":/icons/edit-clear-locationbar-rtl.png");
	m_clearButton->setIcon(QIcon(pixmap));
	m_clearButton->setIconSize(pixmap.size());
#ifndef QT_NO_CURSOR
	m_clearButton->setCursor(Qt::ArrowCursor);
#endif // QT_NO_CURSOR
	m_clearButton->setStyleSheet("QToolButton { border: none; padding: 0px; }");
#ifndef QT_NO_TOOLTIP
	m_clearButton->setToolTip(tr("Clear input field"));
#endif // QT_NO_TOOLTIP
	m_clearButton->hide();
	connect(m_clearButton, SIGNAL(clicked()), this, SLOT(clear()));
	connect(this, SIGNAL(textChanged(QString)), this, SLOT(updateClearButton(QString)));
//	const int frameWidth = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
//	setStyleSheet(QString("QLineEdit { padding-right: %1px; width: %2px; height: %3px; }")
//	              .arg(m_clearButton->sizeHint().width() + frameWidth + 1)
//	              .arg(sizeHint().width())
//	              .arg(sizeHint().height()));
	setStyleSheet(QString("QLineEdit { padding-right: %1px; }")
	              .arg(m_clearButton->sizeHint().width() + style()->pixelMetric(QStyle::PM_DefaultFrameWidth) + 1));
}

QSize LineEdit::sizeHint() const
{
	const QSize msz = QLineEdit::sizeHint();
	const int minimumHeight = m_clearButton->sizeHint().height() + style()->pixelMetric(QStyle::PM_DefaultFrameWidth) * 2;
	return QSize(qMax(msz.width(), minimumHeight + 2), qMax(msz.height(), minimumHeight));
}

void LineEdit::resizeEvent(QResizeEvent *event)
{
	const QSize sz = m_clearButton->sizeHint();
	m_clearButton->move(rect().right() - style()->pixelMetric(QStyle::PM_DefaultFrameWidth) - sz.width(),
	                    (rect().bottom() + 1 - sz.height()) / 2);
	QLineEdit::resizeEvent(event);
}

void LineEdit::updateClearButton(const QString &text)
{
	m_clearButton->setVisible(!text.isEmpty());
}
