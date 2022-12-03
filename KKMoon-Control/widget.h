#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


/*
 * var PTZ_STOP = 0, TILT_UP = 1, TILT_DOWN = 2, PAN_LEFT = 3, PAN_RIGHT = 4;
 * var PT_LEFT_UP	= 5, PT_LEFT_UP	=6, PT_RIGHT_DOWN = 7, PT_RIGHT_DOWN = 8;
 * var Z_ZOOM_IN = 9, Z_ZOOM_OUT	= 10, FOCUS_NEAR = 11, FOCUS_FAR = 12, IRIS_OPEN = 13, IRIS_CLOSE = 14;
 * var PRE_SET = 17, PRE_DEL = 16, PRE_GO = 15;
 * var PAN_AUTO = 18, PAN_AUTO_STOP = 19;
*/

typedef enum {
    PTZ_Stop = 0,
    PTZ_Down = 1,
    PTZ_Up = 2,
    PTZ_Right = 3,
    PTZ_Left = 4
}  PTZ_Directions;

typedef enum {
    PS_GOTO = 15,
    PS_DEL = 16,
    PS_SET = 17
}  Preset_CMD;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();    

private slots:
    void replyFinished(QNetworkReply *reply);

    void on_upButton_pressed();

    void on_stopButton_clicked();

    void on_upButton_released();



    void on_downButton_pressed();

    void on_downButton_released();

    void on_rightButton_pressed();

    void on_rightButton_released();

    void on_leftButton_pressed();

    void on_leftButton_released();

    void on_cmosSetButton_clicked();

    void on_presetGotoButton_clicked();

    void on_presetDeleteButton_clicked();

    void on_presetSetButton_clicked();

private:
    Ui::Widget *ui;

    QNetworkAccessManager *netManager;
    void ptzCommand(PTZ_Directions);
    void presetCommand(Preset_CMD);

    int getPreset();
};
#endif // WIDGET_H
