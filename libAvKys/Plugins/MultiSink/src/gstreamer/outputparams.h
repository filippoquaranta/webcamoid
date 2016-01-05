/* Webcamoid, webcam capture application.
 * Copyright (C) 2011-2016  Gonzalo Exequiel Pedone
 *
 * Webcamoid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Webcamoid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Webcamoid. If not, see <http://www.gnu.org/licenses/>.
 *
 * Email   : hipersayan DOT x AT gmail DOT com
 * Web-Site: http://github.com/hipersayanX/webcamoid
 */

#ifndef OUTPUTPARAMS_H
#define OUTPUTPARAMS_H

#include <ak.h>
#include <gst/gst.h>
#include <gst/app/gstappsrc.h>
#include <gst/pbutils/encoding-profile.h>

class OutputParams: public QObject
{
    Q_OBJECT
    Q_PROPERTY(int inputIndex
               READ inputIndex
               WRITE setInputIndex
               RESET resetInputIndex
               NOTIFY inputIndexChanged)

    public:
        explicit OutputParams(int inputIndex=0, QObject *parent=NULL);
        OutputParams(const OutputParams &other);
        ~OutputParams();

        OutputParams &operator =(const OutputParams &other);

        Q_INVOKABLE int inputIndex() const;
        Q_INVOKABLE int &inputIndex();

    private:
        int m_inputIndex;

    signals:
        void inputIndexChanged(int inputIndex);

    public slots:
        void setInputIndex(int inputIndex);
        void resetInputIndex();
};

Q_DECLARE_METATYPE(OutputParams)

#endif // OUTPUTPARAMS_H
