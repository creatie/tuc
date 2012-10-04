#include "FenPrincipale.h"

FenPrincipale::FenPrincipale() :
    layoutPrincipale    (new QGridLayout(this)),
    paneau              (new QLabel(this)),
    canvas              (new QImage(320, 240, QImage::Format_Indexed8)),
    redSlider           (new QSlider(Qt::Horizontal, this)),
    greenSlider         (new QSlider(Qt::Horizontal, this)),
    blueSlider          (new QSlider(Qt::Horizontal, this)),
    resultLine          (new QLineEdit(this)),
    colorVector         (1)     // build colour vector with one place
{
    this->setFixedSize(230, 120);

    paintCanvas();      // set canvas
    buildSliders();     // set sliders
    buildResultSide();  // set result
    buildButtons();     // set buttons
    buildLayout();      // set layouts

    // make connections
    connect(redSlider, SIGNAL(valueChanged(int)), this, SLOT(redChanged(int)));
    connect(greenSlider, SIGNAL(valueChanged(int)), this, SLOT(greenChanged(int)));
    connect(blueSlider, SIGNAL(valueChanged(int)), this, SLOT(blueChanged(int)));
    connect(buttonColorPicker, SIGNAL(clicked()), this, SLOT(pickColor())); /// @test
}


void FenPrincipale::paintCanvas(int r, int g, int b)
{
    colorVector[0] = qRgb(r, g, b);

    canvas->setColorTable(colorVector);
    canvas->fill(0);
    paneau->setPixmap(QPixmap::fromImage(*canvas));

    /* very slow but readable
    QString redText = QString( "%1" ).arg( int(r), 2, 16, QChar('0') ).toUpper();
    QString greenText = QString( "%1" ).arg( int(g), 2, 16, QChar('0') ).toUpper();
    QString blueText = QString( "%1" ).arg( int(b), 2, 16, QChar('0') ).toUpper();
    QString totalText = QString( "0x" ) + QString( redText + greenText + blueText ).toUpper();
    this->resultLine->setText( totalText );
    */

    // fast but maniac mode
    this->resultLine->setText(QString("0x") + QString("%1%2%3").arg( int(r), 2, 16, QChar('0') ).arg( int(g), 2, 16, QChar('0') ).arg( int(b), 2, 16, QChar('0') ).toUpper());
}


void FenPrincipale::buildSliders()
{
    redSlider->setFixedWidth(100);
    redSlider->setRange(0, 255);
    redSlider->setStyleSheet("QSlider { background-color: red; }");
    greenSlider->setFixedWidth(100);
    greenSlider->setRange(0, 255);
    greenSlider->setStyleSheet("QSlider { background-color: green; }");
    blueSlider->setFixedWidth(100);
    blueSlider->setRange(0, 255);
    blueSlider->setStyleSheet("QSlider { background-color: blue; }");
}


void FenPrincipale::buildResultSide()
{

    resultLine->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void FenPrincipale::buildButtons()
{
    buttonColorPicker = new QToolButton();
    buttonColorPicker->setIcon(QIcon("images/color-picker.png"));
    buttonColorPicker->setToolTip(tr("Pick a color from palette"));
}


void FenPrincipale::buildLayout()
{
    layoutPrincipale->addWidget(redSlider, 0, 0, 1, 2);
    layoutPrincipale->addWidget(greenSlider, 1, 0, 1, 2);
    layoutPrincipale->addWidget(blueSlider, 2, 0, 1, 2);

    layoutPrincipale->addWidget(paneau, 0, 2, 2, 2);
    layoutPrincipale->addWidget(resultLine, 2, 2, 1, 2, Qt::AlignCenter);

    layoutPrincipale->addWidget(buttonColorPicker, 0, 3);

    //to use this instead when adding more buttons so they fill one column for them
    //layoutPrincipale->addWidget(buttonColorPicker, 0, 4);

    this->setLayout(layoutPrincipale);
}


void FenPrincipale::makeConnections()
{
}


/// [SLOTS] ========================================================


void FenPrincipale::redChanged(int)
{
    int r = redSlider->value(),
            g = greenSlider->value(),
            b = blueSlider->value();
    this->paintCanvas(r, g, b);
}

void FenPrincipale::greenChanged(int)
{
    int r = redSlider->value(),
            g = greenSlider->value(),
            b = blueSlider->value();
    this->paintCanvas(r, g, b);
}

void FenPrincipale::blueChanged(int)
{
    int r = redSlider->value(),
            g = greenSlider->value(),
            b = blueSlider->value();
    this->paintCanvas(r, g, b);
}

void FenPrincipale::resultLineChanged()
{
}

void FenPrincipale::pickColor()
{
    QColor choice = QColorDialog().getColor();

    redSlider->setValue(choice.red());
    greenSlider->setValue(choice.green());
    blueSlider->setValue(choice.blue());

    paintCanvas(choice.red(), choice.green(), choice.blue());
}
