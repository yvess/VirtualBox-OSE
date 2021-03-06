/** @file
 *
 * VBox frontends: Qt GUI ("VirtualBox"):
 * UIPopupPane class declaration
 */

/*
 * Copyright (C) 2013 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 */

#ifndef __UIPopupPane_h__
#define __UIPopupPane_h__

/* Qt includes: */
#include <QWidget>
#include <QMap>

/* GUI includes: */
#include "QIWithRetranslateUI.h"

/* Forward declaration: */
class UIPopupPaneTextPane;
class UIPopupPaneButtonPane;
class UIAnimation;

/* Popup-pane prototype: */
class UIPopupPane : public QIWithRetranslateUI<QWidget>
{
    Q_OBJECT;
    Q_PROPERTY(QSize hiddenSizeHint READ hiddenSizeHint);
    Q_PROPERTY(QSize shownSizeHint READ shownSizeHint);
    Q_PROPERTY(QSize minimumSizeHint READ minimumSizeHint WRITE setMinimumSizeHint);
    Q_PROPERTY(int defaultOpacity READ defaultOpacity);
    Q_PROPERTY(int hoveredOpacity READ hoveredOpacity);
    Q_PROPERTY(int opacity READ opacity WRITE setOpacity);

signals:

    /* Notifiers: Show/hide stuff: */
    void sigToShow();
    void sigToHide();
    void sigShow();
    void sigHide();

    /* Notifiers: Hover stuff: */
    void sigHoverEnter();
    void sigHoverLeave();

    /* Notifiers: Focus stuff: */
    void sigFocusEnter();
    void sigFocusLeave();

    /* Notifiers: Layout stuff: */
    void sigProposeTextPaneWidth(int iWidth);
    void sigSizeHintChanged();

    /* Notifier: Complete stuff: */
    void sigDone(int iResultCode) const;

public:

    /* Constructor: */
    UIPopupPane(QWidget *pParent,
                const QString &strMessage, const QString &strDetails,
                const QMap<int, QString> &buttonDescriptions,
                bool fProposeAutoConfirmation);

    /* API: Recall stuff: */
    void recall();

    /* API: Text stuff: */
    void setMessage(const QString &strMessage);
    void setDetails(const QString &strDetails);

    /* API: Auto-confirmation stuff: */
    void setProposeAutoConfirmation(bool fPropose);

    /* API: Layout stuff: */
    QSize minimumSizeHint() const { return m_minimumSizeHint; }
    void setMinimumSizeHint(const QSize &minimumSizeHint);
    void layoutContent();

private slots:

    /* Handler: Show/hide stuff: */
    void sltMarkAsShown();

    /* Handlers: Layout stuff: */
    void sltHandleProposalForWidth(int iWidth);
    void sltUpdateSizeHint();

    /* Handler: Button stuff: */
    void sltButtonClicked(int iButtonID);

private:

    /* Helpers: Prepare stuff: */
    void prepare();
    void prepareBackground();
    void prepareContent();
    void prepareAnimation();

    /* Helpers: Translate stuff: */
    void retranslateUi();
    void retranslateToolTips();

    /* Handler: Event-filter stuff: */
    bool eventFilter(QObject *pWatched, QEvent *pEvent);

    /* Handlers: Event stuff: */
    void showEvent(QShowEvent *pEvent);
    void polishEvent(QShowEvent *pEvent);
    void paintEvent(QPaintEvent *pEvent);

    /* Helpers: Paint stuff: */
    void configureClipping(const QRect &rect, QPainter &painter);
    void paintBackground(const QRect &rect, QPainter &painter);
    void paintFrame(QPainter &painter);

    /* Helper: Complete stuff: */
    void done(int iResultCode);

    /* Property: Show/hide stuff: */
    QSize hiddenSizeHint() const { return m_hiddenSizeHint; }
    QSize shownSizeHint() const { return m_shownSizeHint; }

    /* Property: Hover stuff: */
    int defaultOpacity() const { return m_iDefaultOpacity; }
    int hoveredOpacity() const { return m_iHoveredOpacity; }
    int opacity() const { return m_iOpacity; }
    void setOpacity(int iOpacity) { m_iOpacity = iOpacity; update(); }

    /* Variables: General stuff: */
    bool m_fPolished;
    const QString m_strId;
    const int m_iLayoutMargin;
    const int m_iLayoutSpacing;
    QSize m_minimumSizeHint;

    /* Variables: Text stuff: */
    QString m_strMessage, m_strDetails;

    /* Variables: Auto-confirmation stuff: */
    bool m_fProposeAutoConfirmation;

    /* Variables: Button stuff: */
    QMap<int, QString> m_buttonDescriptions;

    /* Variables: Show/hide stuff: */
    bool m_fShown;
    UIAnimation *m_pShowAnimation;
    QSize m_hiddenSizeHint;
    QSize m_shownSizeHint;

    /* Variables: Focus stuff: */
    bool m_fCanLooseFocus;
    bool m_fFocused;

    /* Variables: Hover stuff: */
    bool m_fHovered;
    const int m_iDefaultOpacity;
    const int m_iHoveredOpacity;
    int m_iOpacity;

    /* Widgets: */
    UIPopupPaneTextPane *m_pTextPane;
    UIPopupPaneButtonPane *m_pButtonPane;
};

#endif /* __UIPopupPane_h__ */
