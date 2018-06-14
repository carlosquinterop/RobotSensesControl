#ifndef RobotSensesControl_H
#define RobotSensesControl_H

#include <QMainWindow>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QString>
#include <QPushButton>
#include <QObject>
#include <QSignalMapper>
#include <QGridLayout>
#include <QProcess>
#include <QLabel>
#include <QPlainTextEdit>
#include <QDesktopWidget>
#include <iostream>
#include <QStringList>
#include "WorkerThread.h"
#include <QComboBox>
#include <QDirIterator>
#include <QtSerialPort/QSerialPort>
#include <QMessageBox>
#include <QTimer>

#define NUMBER_OF_BUTTONS 12

using namespace std;

class RobotSensesControl : public QMainWindow
{
    Q_OBJECT

public:
    RobotSensesControl();
    virtual ~RobotSensesControl();
    void openSerialPort();
    void sendSerialMessage(char instruction);
    
private:
    QString buttonTexts[NUMBER_OF_BUTTONS], speechProcessName;
    QSignalMapper *signalMapper;
    QPushButton *shortcutButtons[NUMBER_OF_BUTTONS], *playButton;
    QGridLayout *mainLayout, *buttonsLayout, *textLayout, *speechLayout, *visionLayout, *moveLayout, *moveTalkLayout;
    QProcess *speakProcess;
    QLabel *speechName, *visionName, *moveName, *moveTalkName;
    QPlainTextEdit *textEntry;
    
    QComboBox *camId;
    WorkerThread *visionThread;
    QLabel *captureImageLabel;
    QPushButton *captureButton;
    QPushButton *stopCaptureButton;
    QPushButton *startSerialConnection;
    QPushButton *stopSerialConnection;
    
    QPushButton *leftTurnButton, *rightTurnButton, *upTurnButton, *downTurnButton;
    QSerialPort *serialPort;
    QTimer *yesTimer, *noTimer;
    
    int yesCount, noCount;
    QPushButton *yesButton, *noButton;
    
private slots:
  void playStandardMessages(QString message);
  void processEnded(int exitCode, QProcess::ExitStatus existStatus);
  void playButtonSlot();
  void captureImage();
  void stopCapturingImage();
  void leftTurnButtonSlot();
  void rightTurnButtonSlot();
  void upTurnButtonSlot();
  void downTurnButtonSlot();
  void yesSlot();
  void noSlot();
  void yesButtonSlot();
  void noButtonSlot();
};

#endif //