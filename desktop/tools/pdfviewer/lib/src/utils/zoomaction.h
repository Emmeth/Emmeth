/***************************************************************************
 *   Copyright (C) 2009, 2011, 2012 by Glad Deschrijver                    *
 *     <glad.deschrijver@gmail.com>                                        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>.  *
 ***************************************************************************/

#ifndef ZOOMACTION_H
#define ZOOMACTION_H

#include "selectaction.h"

class QIcon;

class ZoomAction : public SelectAction
{
	Q_OBJECT

public:
	explicit ZoomAction(QObject *parent, const QString &name = 0);
	ZoomAction(const QString &text, QObject *parent, const QString &name = 0);
	ZoomAction(const QIcon &icon, const QString &text, QObject *parent, const QString &name = 0);
	~ZoomAction();

	void setMinZoomFactor(qreal zoomFactor);
	void setMaxZoomFactor(qreal zoomFactor);
	qreal minZoomFactor() const;
	qreal maxZoomFactor() const;
	void setZoomFactor(qreal zoomFactor);

Q_SIGNALS:
	void zoomFactorAdded(qreal zoomFactor);

private Q_SLOTS:
	void setZoomFactor(const QString &zoomFactorText);

private:
	void init();
	void setCurrentZoomFactor(qreal newZoomFactor = 1);

	qreal m_minZoomFactor;
	qreal m_maxZoomFactor;
};

#endif // ZOOMACTION_H
