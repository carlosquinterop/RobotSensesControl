#include "include/RobotSensesControl.h"

RobotSensesControl::RobotSensesControl()
{
    QDesktopWidget dw;
    int x_window=dw.width()*0.4;
    int y_window=dw.height()*0.7;  
  
    mainLayout = new QGridLayout();
    buttonsLayout = new QGridLayout();    
    speechLayout = new QGridLayout();
    visionLayout = new QGridLayout();
    
    signalMapper = new QSignalMapper();
        
    buttonTexts[0] = "Hola";
    buttonTexts[1] = "Adiós";
    buttonTexts[2] = "Sí";
    buttonTexts[3] = "No";
    buttonTexts[4] = "No sé";
    buttonTexts[5] = "Bienvenidos";
    buttonTexts[6] = "Un placer conocerlos";
    buttonTexts[7] = "No oigo";
    buttonTexts[8] = "¿Cómo están?";
    buttonTexts[9] = "Nos vemos en una \n próxima ocasión";
    buttonTexts[10] = "Soy un robot";
    buttonTexts[11] = "Hagamos silencio \n por favor";
    
    for(int i = 0;i < NUMBER_OF_BUTTONS;i++)
    {
	shortcutButtons[i] = new QPushButton(buttonTexts[i]);
	signalMapper->setMapping(shortcutButtons[i], buttonTexts[i]);
    }
    playButton = new QPushButton("Reproducir");
    speechName = new QLabel("Robot Speech");
    textEntry = new QPlainTextEdit();
    QWidget *window = new QWidget();
    speakProcess = new QProcess();
    
    //Vision
    captureButton = new QPushButton("Capture");
    stopCaptureButton = new QPushButton("Stop");
    startSerialConnection = new QPushButton("Start Connection");
    stopSerialConnection = new QPushButton("Stop Connection");
    stopSerialConnection->setEnabled(false);
    stopCaptureButton->setEnabled(false);
    camId = new QComboBox();
    captureImageLabel = new QLabel("Capture image from camera");
    visionName = new QLabel("Vision Speech");
    visionThread = new WorkerThread();
    
    //Initialization
    mainLayout->addWidget(speechName, 0, 0);
    mainLayout->addLayout(speechLayout, 1, 0);
    mainLayout->addWidget(visionName, 2, 0);
    mainLayout->addLayout(visionLayout, 3, 0);
    
    speechLayout->addLayout(buttonsLayout, 1, 0);
    speechLayout->addWidget(textEntry, 2, 0);
    speechLayout->addWidget(playButton, 3, 0);
        
    int row = 0, col = 0;
    for (int i = 0;i <4;i++)
    {
	for (int j = 0;j < 3;j++)
	    buttonsLayout->addWidget(shortcutButtons[3*i +j], i, j);	    
    }
   
    visionLayout->addWidget(new QLabel("Camera Id"), 0, 0);
    visionLayout->addWidget(camId, 0, 1);
    visionLayout->addWidget(captureImageLabel, 1, 0);
    visionLayout->addWidget(captureButton, 1, 1);
    visionLayout->addWidget(stopCaptureButton, 1, 2);
        
    
    //playButton->setFixedSize(QSize(0.96*x_window, 0.1*y_window));
    
    speechName->setAlignment(Qt::AlignCenter);
    QFont f("Arial",16);
    QFontMetrics fm(f);
    speechName->setFont(f);
    
    visionName->setAlignment(Qt::AlignCenter);
    QFont fv("Arial",16);
    QFontMetrics fmv(fv);
    visionName->setFont(fv);
    
    window->setLayout(mainLayout);
    setCentralWidget(window);
    window->setFixedSize(x_window,y_window);
    setWindowTitle("Robot Senses Control");
    
    speechProcessName = "espeak";
    
    int camCont = 0;
    QDirIterator it("/dev", QDirIterator::NoIteratorFlags);
    QDir dir("/dev");
    bool exists = false;
    do
    {
	QString file = "video" + QString::number(camCont);
	if (dir.exists(file))
	{
	    camCont++;
	    exists = true;
	}
	else
	{
	    exists = false;   
	}
    }
    while(exists);
    for(int i = 0; i < camCont;i++)
	camId->addItem(QString::number(i));
    
    camId->setCurrentIndex(camCont-1);
    
    for (int i = 0;i < NUMBER_OF_BUTTONS;i++)
	connect(shortcutButtons[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(playStandardMessages(QString)));
    connect(speakProcess, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(processEnded(int, QProcess::ExitStatus)));
    connect(playButton, SIGNAL(clicked()), this, SLOT(playButtonSlot()));
    connect(captureButton, SIGNAL(clicked()), this, SLOT(captureImage()));
    connect(stopCaptureButton, SIGNAL(clicked()), this, SLOT(stopCapturingImage()));
}

RobotSensesControl::~RobotSensesControl()
{
  
}

void RobotSensesControl::playStandardMessages(QString message)
{
    QStringList arguments;
    arguments << "-a" << "200" << "-s" << "190" << "-ves-la";
    arguments << message;
    speakProcess->start(speechProcessName, arguments);
    
    for(int i = 0;i < NUMBER_OF_BUTTONS;i++)
	shortcutButtons[i]->setEnabled(false);
    
}

void RobotSensesControl::processEnded(int exitCode, QProcess::ExitStatus existStatus)
{
    for(int i = 0;i < NUMBER_OF_BUTTONS;i++)
	shortcutButtons[i]->setEnabled(true);
    textEntry->setPlainText("");
}

void RobotSensesControl::playButtonSlot()
{
    QStringList arguments;
    arguments << "-a" << "200" << "-s" << "190" << "-ves-la";
    arguments << textEntry->toPlainText();
    speakProcess->start(speechProcessName, arguments);
    
    for(int i = 0;i < NUMBER_OF_BUTTONS;i++)
	shortcutButtons[i]->setEnabled(false);
}

void RobotSensesControl::captureImage()
{
    visionThread->setWorkingThread(true);
    visionThread->setCameraId(camId->currentIndex());
    visionThread->start();
    stopCaptureButton->setEnabled(true);
    captureButton->setEnabled(false);
    namedWindow("Real time video", WINDOW_AUTOSIZE );
    //serialConnectionAllowed = true;
}

void RobotSensesControl::stopCapturingImage()
{
    visionThread->setWorkingThread(false);
    stopCaptureButton->setEnabled(false);
    captureButton->setEnabled(true);
    destroyWindow("Real time video");
    /*serialConnectionAllowed = false;
    if (serialConnected)
	closeSerialPort();*/
}