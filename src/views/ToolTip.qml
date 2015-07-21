/****************************************************************************
**
**  Copyright (C) 2011~2014 Deepin, Inc.
**                2011~2014 Kaisheng Ye
**
**  Author:     Kaisheng Ye <kaisheng.ye@gmail.com>
**  Maintainer: Kaisheng Ye <kaisheng.ye@gmail.com>
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

import QtQuick 2.1
import QtQuick.Window 2.1

Window {
    id: toolTip
    width: background.width
    height: background.height
    flags: Qt.Popup | Qt.WindowStaysOnTopHint
    color: Qt.rgba(0, 0, 0, 0)

    function showTip(s){
        tipText.text = s
        tipText.width = 280     // reset tooltip width to max size
        tipText.width = (tipText.contentWidth <= 280) ? tipText.contentWidth : 280 // fix tooltip width
        tipText.height = tipText.contentHeight

        timeoutShow.restart()
        freshBackground.restart()
    }

    function hideTip(){
        timeoutShow.stop()
        toolTip.hide()
        toolTip.visible = false
    }

    Timer{
        id: freshBackground
        interval: 200
        repeat: true
        property int repeatTime: 0

        onTriggered: {
            if(repeatTime > 10){
                freshBackground.stop()
                freshBackground.repeat = false
            }
            else{
                repeatTime += 1
                if (background.color == Qt.rgba(0, 0, 0, 0.9)){
                    background.color = Qt.rgba(0, 0, 0, 0.91)
                }
                else{
                    background.color = Qt.rgba(0, 0, 0, 0.9)
                }
            }
        }
    }

    Timer {
        id: timeoutShow
        interval: 500
        running: false
        repeat: false
        onTriggered: {
            toolTip.x = cursorPosition.x + 10
            toolTip.y = cursorPosition.y + 10
            if (toolTip.x + toolTip.width > screenSize.width + screenSize.x){
                toolTip.x = screenSize.width + screenSize.x - toolTip.width
            }
            if (toolTip.y + toolTip.height > screenSize.height + screenSize.y){
                toolTip.y = screenSize.height + screenSize.y -toolTip.height - 10
            }
            toolTip.show()
            toolTip.visible = true
            toolTip.raise()
            timeoutHide.restart()
        }
    }

    Timer {
        id: timeoutHide
        interval: 3000
        running: false
        repeat: false
        onTriggered: {
            toolTip.hideTip()
        }
    }

    Rectangle {
        id: background
        width: tipText.width + 10
        height: tipText.height + 10
        color: Qt.rgba(0, 0, 0, 0.9)
        radius: 4

        Text {
            id: tipText
            wrapMode: Text.Wrap
            anchors.centerIn: parent
            font.pixelSize: 12
            color: "#faca57"
        }
    }
}