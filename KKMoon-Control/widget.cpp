#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QNetworkReply>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    netManager = new QNetworkAccessManager(this);
    connect(netManager, &QNetworkAccessManager::finished, this, &Widget::replyFinished);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::replyFinished(QNetworkReply *reply){

    qDebug() << reply->isFinished();
     qDebug() << reply->readAll();

    reply->deleteLater();
}


void Widget::ptzCommand(PTZ_Directions dir){

    QString url = "http://";
    url += ui->ipAddressEdit->text();
    url += "/goform/ptz.cgi?action=";
    url += QString::number(dir);
    url += "&speed=25&ppp=0" ;

    qDebug() << url;
    //netManager->get(QNetworkRequest(QUrl("http://192.168.20.104/goform/ptz.cgi?action=2&speed=25&ppp=0")));
    netManager->get(QNetworkRequest(QUrl(url)));

}

void Widget::presetCommand(Preset_CMD cmd) {

    // /goform/ptz.cgi?action=15&AddrID=0&Speed=32&PresetName=3

    QString url = "http://";
    url += ui->ipAddressEdit->text();
    url += "/goform/ptz.cgi?action=";
    url += QString::number(cmd);
    url += "&AddrID=0&Speed=32&PresetName=" ;
    url += QString::number(getPreset());

    qDebug() << url;
    //netManager->get(QNetworkRequest(QUrl("http://192.168.20.104/goform/ptz.cgi?action=2&speed=25&ppp=0")));
    netManager->get(QNetworkRequest(QUrl(url)));
}

// START PTZ Buttons:
void Widget::on_upButton_pressed()
{
    ptzCommand(PTZ_Up);
}

void Widget::on_upButton_released()
{
    ptzCommand(PTZ_Stop);
}

void Widget::on_stopButton_clicked()
{
    //QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    //connect(manager, &QNetworkAccessManager::finished,           this, &MyClass::replyFinished);

    //manager->get(QNetworkRequest(QUrl("http://192.168.20.104/goform/ptz.cgi?action=0&speed=25&ppp=0")));
    ptzCommand(PTZ_Stop);
}

void Widget::on_downButton_pressed()
{
    ptzCommand(PTZ_Down);
}

void Widget::on_downButton_released()
{
    ptzCommand(PTZ_Stop);
}

void Widget::on_rightButton_pressed()
{
    ptzCommand(PTZ_Right);
}

void Widget::on_rightButton_released()
{
    ptzCommand(PTZ_Stop);
}

void Widget::on_leftButton_pressed()
{
    ptzCommand(PTZ_Left);
}

void Widget::on_leftButton_released()
{
    ptzCommand(PTZ_Stop);
}

// END PTZ Buttons:


void Widget::on_cmosSetButton_clicked()
{


    int mirror=0;
    int whiteBalance=1;
    int flicker=50;
    int exposureTime=0;
    int irCutSetting=3;
    int irCutSensitivity=7;
    int color=0;

    //goform/cmos.cgi?action=set&Mirror=0&WhiteBalance=1&Flicker=50&ExposureTime=0&IrCut=3&IrCutSensitive=7&Color=0


    // Mirror:
    if(ui->mirrorNormal_radioButton->isChecked()) mirror=0;
    if(ui->mirrorUD_radioButton->isChecked()) mirror=1;
    if(ui->mirrorLR_radioButton->isChecked()) mirror=2;
    if(ui->mirrorUDLR_radioButton->isChecked()) mirror=3;

    // white balance:
    if(ui->wbIndoor_radioButton->isChecked() ) whiteBalance=0;
    if(ui->wbOutdoor_radioButton->isChecked() ) whiteBalance=1;

    // flicker:
    if(ui->flicker50_radioButton->isChecked() ) flicker=50;
    if(ui->flicker60_radioButton->isChecked() ) flicker=60;

    // exposureTime
    if (ui->exposureTime_comboBox->currentText() == "Auto") exposureTime=0;
    if (ui->exposureTime_comboBox->currentText() == "1/30") exposureTime=30;
    if (ui->exposureTime_comboBox->currentText() == "1/60") exposureTime=60;
    if (ui->exposureTime_comboBox->currentText() == "1/125") exposureTime=125;
    if (ui->exposureTime_comboBox->currentText() == "1/250") exposureTime=250;
    if (ui->exposureTime_comboBox->currentText() == "1/500") exposureTime=500;
    if (ui->exposureTime_comboBox->currentText() == "1/1000") exposureTime=1000;
    if (ui->exposureTime_comboBox->currentText() == "1/2000") exposureTime=2000;
    if (ui->exposureTime_comboBox->currentText() == "1/5000") exposureTime=5000;
    if (ui->exposureTime_comboBox->currentText() == "1/10000") exposureTime=10000;

    // irCutSetting
    irCutSetting = ui->irCutSetting_comboBox->currentIndex();

    // irCut sens:
    irCutSensitivity = ui->irCutSensitvity_spinBox->value();

    // color:
    if(ui->colorAuto_radioButton->isChecked() ) color=0;
    if(ui->colorColor_radioButton->isChecked() ) color=1;
    if(ui->colorBW_radioButton->isChecked() ) color=2;

    QString url = "http://";
    url += ui->ipAddressEdit->text();
    url += "/goform/cmos.cgi?action=set&Mirror=";
    url += QString::number(mirror);
    url += "&WhiteBalance=" ;
    url += QString::number(whiteBalance);
    url += "&Flicker=" ;
    url += QString::number(flicker);
    url += "&ExposureTime=" ;
    url += QString::number(exposureTime);
    url += "&IrCut=" ;
    url += QString::number(irCutSetting);
    url += "&IrCutSensitive=" ;
    url += QString::number(irCutSensitivity);
    url += "&Color=" ;
    url += QString::number(color);

    qDebug() << url;
    //netManager->get(QNetworkRequest(QUrl("http://192.168.20.104/goform/ptz.cgi?action=2&speed=25&ppp=0")));

    // request with basic auth!!

    QString concatenated = "admin:admin"; //username:password
    QByteArray data = concatenated.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;

    QNetworkRequest request=QNetworkRequest(QUrl(url));
    request.setRawHeader("Authorization", headerData.toLocal8Bit());

    netManager->get(request);

    // without auth
    //netManager->get(QNetworkRequest(QUrl(url)));

}


// Preset things:
int Widget::getPreset()
{
    int preset=0;
    if (ui->p0_radioButton->isChecked()) preset=0;
    if (ui->p1_radioButton->isChecked()) preset=1;
    if (ui->p2_radioButton->isChecked()) preset=2;
    if (ui->p3_radioButton->isChecked()) preset=3;
    if (ui->p4_radioButton->isChecked()) preset=4;
    if (ui->p5_radioButton->isChecked()) preset=5;
    if (ui->p6_radioButton->isChecked()) preset=6;
    if (ui->p7_radioButton->isChecked()) preset=7;
    if (ui->p8_radioButton->isChecked()) preset=8;
    if (ui->p9_radioButton->isChecked()) preset=9;
    if (ui->p10_radioButton->isChecked()) preset=10;
    if (ui->p11_radioButton->isChecked()) preset=11;
    if (ui->p12_radioButton->isChecked()) preset=12;
    if (ui->p13_radioButton->isChecked()) preset=13;
    if (ui->p14_radioButton->isChecked()) preset=14;
    if (ui->p15_radioButton->isChecked()) preset=15;

    return preset;

}

void Widget::on_presetGotoButton_clicked()
{
    presetCommand(PS_GOTO);

}

void Widget::on_presetDeleteButton_clicked()
{
    presetCommand(PS_DEL);

}

void Widget::on_presetSetButton_clicked()
{
    presetCommand(PS_SET);

}
