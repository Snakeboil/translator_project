#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->logo->move(-900,0);
    ui->logo = new QLabel(this);
    animation=new QPropertyAnimation(ui->logo, "pos");
    animation->setDuration(250);
    animation->setStartValue(QPoint(0,0));
    animation->setEndValue(QPoint(0,20));
    //animation->setLoopCount(0);
    animation->setDirection(QAbstractAnimation::Forward);
    //animation->start();
    animation2=new QPropertyAnimation(ui->logo, "pos");
    animation2->setDuration(250);
    animation2->setStartValue(QPoint(0,20));
    animation2->setEndValue(QPoint(0,0));
    //animation->setLoopCount(0);
    animation2->setDirection(QAbstractAnimation::Forward);
    //animation2->start();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::onTimeout);
    timer2 = new QTimer(this);
    connect(timer2, &QTimer::timeout, this, &MainWindow::onTimeout2);
    //timer->start(250);
    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(100);
    player->setSource(QUrl("qrc:/images/sample-3s.mp3"));
}


void MainWindow::onTimeout()
{
    timer->stop();
    animation->start();
    timer2->start(250);
}

void MainWindow::onTimeout2()
{
    timer2->stop();
    animation2->start();
    timer->start(250);
}

void MainWindow::onTimeout3()
{

    if(iteration>message_length)
    {
        timer3->stop();
        timer2->stop();
        timer->stop();

    }
    else
    {
        message_to_print+=response[iteration];
        ui->result_box->setText(message_to_print);
        timer->start();
        player->play();
    }
    iteration++;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    request.setUrl(QUrl("https://generativelanguage.googleapis.com/v1beta/models/gemini-2.0-flash:generateContent?key=AIzaSyAaRSl34n-aVT5hQqoGJiSVO7OtlGwjDrc"));
    request.setHeader(QNetworkRequest::ContentTypeHeader,
                      "application/json");
    QJsonObject textPart;
    textPart["text"] = QString("Please translate this text:%1 into %2. Do not say anything other than the translated text.")
                           .arg(ui->textEdit->toPlainText())
                           .arg(ui->comboBox->currentText());


    QJsonObject contentObject;
    contentObject["parts"] = QJsonArray{ textPart };

    QJsonObject root;
    root["contents"] = QJsonArray{ contentObject };


    QJsonDocument jsonDoc(root);
    QByteArray jsonData_tosend = jsonDoc.toJson();
    QJsonObject jsonObj=jsonDoc.object();



    reply = manager->post(request, jsonData_tosend);
connect(reply,&QNetworkReply::finished,this,&MainWindow::onmessageDataRecieved);

}

void MainWindow::onmessageDataRecieved()
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc_received=QJsonDocument::fromJson(responseData);
        QJsonObject jsonObj_received=jsonDoc_received.object();
        response =jsonObj_received["candidates"].toArray()[0].toObject()["content"].toObject()["parts"].toArray()[0].toObject()["text"].toString();
        qDebug() << "Response:" << responseData;
       // ui->result_box->setText(response);
      //  for (auto character: response)
       // {  ui->result_box->setText(response[0]); }
        timer3 = new QTimer(this);
        connect(timer3, &QTimer::timeout, this, &MainWindow::onTimeout3);
        iteration=0;
        message_length=response.length();
        timer3->start(1000);




    } else {
        qDebug() << "Error:" << reply->errorString();
    }
    reply->deleteLater();

    QString Again = ("Enter another phrase...");
    ui->AgainBox->setText(Again);

    QString Again2 = ("...ooooor swap the translator!");
    ui->AgainBox2->setText(Again2);
}




void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}




void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{


    if (ui->comboBox->currentText()== "Medieval")
    {
        ui->result_box->clear();
    ui->pushButton->setText("Send-eth it!");
        ui->pushButton_2->setText("Quit-eth.");
      ui->funLabel->setText("Fun Fact!(?)");
      ui->logo->setFixedSize(300, 300);
      ui->logo->move(150,25);
      QString imagename;
    imagename = "CrusaderSmall.png";
    ui->logo->setPixmap(":/images/"+imagename);

    int FunFact = (std::rand()%3) +1;
    switch(FunFact){
    case 1:
        ui->FFLabel->setText("'Mensur' was a medieval fencing practice where nobles swung blades at each other's faces, because they really really wanted scars for some reason.");
        break;
    case 2:
        ui->FFLabel->setText("There are 3 main schools of fencing: Foil, Epee, and Saber. Foil is, historically, the best one. Ask any historian, they'll tell you.");
        break;
    case 3:
         ui->FFLabel->setText("The airspeed velocity of an unladen swallow is approximately 20.1 miles per hour.");
        break;
    }
    QFont font1("Script", 20, QFont::Bold);
    ui->result_box->setFont(font1);
    }
    else if (ui->comboBox->currentText()== "French")
    {
        ui->result_box->clear();
        ui->pushButton->setText("Envoie!");
             ui->pushButton_2->setText("Desmissionne.");
        ui->funLabel->setText("Fun Fact!(?)");
             ui->logo->setFixedSize(300, 300);
             ui->logo->move(150,25);
             QString imagename;
             imagename = "pngtree-a-capwearing-frenchman-holding-a-fresh-baguette-comical-photo-png-image_13686654.png";
             ui->logo->setPixmap(":/images/"+imagename);
             int FunFact = (std::rand()%3) +1;
        switch(FunFact){
        case 1:
        ui->FFLabel->setText("French is the only dead language still spoken by an entire country!");
            break;
        case 2:
        ui->FFLabel->setText("It is always morally right to make fun of the French.");
            break;
        case 3:
        ui->FFLabel->setText("I really considered writing these facts in French for the meme. But then they'd be unreadable for any non-French speaker. Not all too fun.");
        break;
             }
        QFont font2("Algerian", 12, QFont::Bold);
        ui->result_box->setFont(font2);
    }
    else if (ui->comboBox->currentText()== "Pirate")
    {
         ui->result_box->clear();
        ui->pushButton->setText("Heave ho!");
          ui->pushButton_2->setText("Abandon ship!");
        ui->funLabel->setText("Fun Fact!(?)");
          ui->logo->setFixedSize(300, 300);
          ui->logo->move(150,25);
          QString imagename;
          imagename = "JackSmall.png";
          ui->logo->setPixmap(":/images/"+imagename);

          int FunFact = (std::rand()%3) +1;
        switch(FunFact){
        case 1:
            ui->FFLabel->setText("The pirate accent being used right now was actually popularized by Disney, not pirates! They'd be pissed if they knew the truth!");
            break;
        case 2:
            ui->FFLabel->setText("Most pirates had a sophisticated retirment plan. That makes them more financially prepared than a majority of the U.S. workforce!");
            break;
        case 3:
            ui->FFLabel->setText("Modern pirating mostly takes place at sea in Somalia, or in the home, when someone wants to watch Stranger Things without a Netflix subscription.");
            break;
        }
        QFont font3("Gigi", 20, QFont::Bold);
        ui->result_box->setFont(font3);
    }
    else if (ui->comboBox->currentText()== "Backwards")
    {
         ui->result_box->clear();
        ui->pushButton->setText("!ti dneS");
          ui->pushButton_2->setText(".tiuQ");
        ui->funLabel->setText("Fun Fact!(?)");
          ui->logo->setFixedSize(300, 300);
          ui->logo->move(150,35);
          QString imagename;
          imagename = "UpsideSmall.png";
          ui->logo->setPixmap(":/images/"+imagename);
        int FunFact = (std::rand()%3) +1;
        switch(FunFact){
        case 1:
        ui->FFLabel->setText("A 'palindrome' is a word that is spelled the same way forwards and backwards, such as rotor, or kayak! Or boob!");
            break;
        case 2:
            ui->FFLabel->setText("National backwards day is celebrated on January 31st. This is different from Opposite Day, on the 25th. What's the difference? I dunno.");
            break;
        case 3:
            ui->FFLabel->setText("Have you ever accidently put on clothes backwards? Yeah... I bet you have. Loser.");
            break;
        }
        QFont font4("Bodoni 93", 12, QFont::Bold);
        ui->result_box->setFont(font4);
    }
    else if (ui->comboBox->currentText()== "Spoiled Victorian Child")
    {
         ui->result_box->clear();
        ui->pushButton->setText("Now, I say!");
          ui->pushButton_2->setText("Stop at once!");
        ui->funLabel->setText("Fun Fact!(?)");
          ui->logo->setFixedSize(300, 300);
          ui->logo->move(150,25);
          QString imagename;
          imagename = "RanniSmall.png";
          ui->logo->setPixmap(":/images/"+imagename);
        int FunFact = (std::rand()%3) +1;
        switch(FunFact){
        case 1:
          ui->FFLabel->setText("Victorian England is often portrayed in media as being very dreary and/or cloudy. This is because modern day England is also dreary and cloudy!");
            break;
        case 2:
            ui->FFLabel->setText("Rich people in this time would rent real mummies from Egypt, which they would unwrap live at 'mummy parties!' This is considered 'gross.'");
            break;
        case 3:
            ui->FFLabel->setText("Children as young as five years old could be found in Victorian coal mines! Mining and crafting is a timeless experience.");
            break;
        }
        QFont font5("Blackadder ITC", 20, QFont::Bold);
        ui->result_box->setFont(font5);
    }
    else if (ui->comboBox->currentText()== "Binary")
    {
         ui->result_box->clear();
        ui->pushButton->setText("0x6, 1x10!");
          ui->pushButton_2->setText("0x6, 1x10.");
        ui->funLabel->setText("Fun Fact!(?)");
          ui->logo->setFixedSize(300, 300);
          ui->logo->move(150,25);
          QString imagename;
          imagename = "AimSmall.png";
          ui->logo->setPixmap(":/images/"+imagename);
        int FunFact = (std::rand()%3) +1;
        switch(FunFact){
        case 1:
        ui->FFLabel->setText("'01110000 01101111 01101111' spells 'Poo' in binary code. Don't believe me? Try it out!");
            break;
        case 2:
            ui->FFLabel->setText("While 'bit', 'nibble,' and 'byte' are terms used for processing storage, 'chomp' is not. This is considered a 'missed oppritunity.'");
            break;
        case 3:
            ui->FFLabel->setText("Binary was invented in the 17th century by Gottfried Wilhelm Leibniz, who also happened to have the coolest name of all time.");
            break;
        }
        QFont font6("Bauhaus 93", 12, QFont::Bold);
        ui->result_box->setFont(font6);
    }
    else if (ui->comboBox->currentText()== "Brainrot")
    {
         ui->result_box->clear();
        ui->pushButton->setText("Send ts!");
          ui->pushButton_2->setText("86, blud.");
        ui->funLabel->setText("Fun Fact!(?)");
          ui->logo->setFixedSize(300, 300);
          ui->logo->move(150,25);
          QString imagename;
          imagename = "SpeedSmall.png";
          ui->logo->setPixmap(":/images/"+imagename);
        int FunFact = (std::rand()%3) +1;
        switch(FunFact){
        case 1:
         ui->FFLabel->setText("Whenever you use this specific accent, somewhere in the world, a baby seal is clubbed to death. You're responsible.");
            break;
        case 2:
            ui->FFLabel->setText("'Rizz' was popularized by streamer Kai Cenat, who, immediatly after uttering it, died for the 415th time to the same Elden Ring boss.");
            break;
        case 3:
         ui->FFLabel->setText("If there was a social credit score here, using this would make yours decrease.");
            break;
        }
        QFont font7("Forte", 20, QFont::Bold);
        ui->result_box->setFont(font7);
    }

}





void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}







