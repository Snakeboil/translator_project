#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QPropertyAnimation>
#include <QMediaPlayer>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkReply *reply;
    void onmessageDataRecieved();
    QTimer *timer;
    void onTimeout();
    void onTimeout2();
    void onTimeout3();
    QPropertyAnimation* animation;
    QPropertyAnimation* animation2;
    QTimer *timer2;
    QTimer *timer3;
    int iteration=0;
    int message_length;
    QString message_to_print="";
    QString response;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
};
#endif // MAINWINDOW_H
