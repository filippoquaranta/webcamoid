/* Webcamoid, webcam capture application.
 * Copyright (C) 2011-2014  Gonzalo Exequiel Pedone
 *
 * Webcamod is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Webcamod is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Webcamod. If not, see <http://www.gnu.org/licenses/>.
 *
 * Email     : hipersayan DOT x AT gmail DOT com
 * Web-Site 1: http://github.com/hipersayanX/Webcamoid
 * Web-Site 2: http://opendesktop.org/content/show.php/Webcamoid?content=144796
 */

#ifndef DESKTOPCAPTUREELEMENT_H
#define DESKTOPCAPTUREELEMENT_H

#include <QTimer>
#include <QThread>
#include <QDesktopWidget>

#include <qbmultimediasourceelement.h>

typedef QSharedPointer<QThread> ThreadPtr;

class DesktopCaptureElement: public QbMultimediaSourceElement
{
    Q_OBJECT

    public:
        explicit DesktopCaptureElement();

        Q_INVOKABLE QStringList medias() const;
        Q_INVOKABLE QString media() const;
        Q_INVOKABLE QList<int> streams() const;

        Q_INVOKABLE int defaultStream(const QString &mimeType) const;
        Q_INVOKABLE QString description(const QString &media) const;
        Q_INVOKABLE QbCaps caps(int stream) const;

    private:
        QString m_curScreen;
        int m_curScreenNumber;
        ThreadPtr m_thread;
        QTimer m_timer;
        QDesktopWidget *m_desktopWidget;

        static void deleteThread(QThread *thread);

    protected:
        void stateChange(QbElement::ElementState from, QbElement::ElementState to);

    signals:
        void sizeChanged(const QString &media, const QSize &size) const;

    public slots:
        void setMedia(const QString &media);
        void resetMedia();

    private slots:
        void readFrame();
        void screenCountChanged(int count);
        void srceenResized(int screen);
};

#endif // DESKTOPCAPTUREELEMENT_H