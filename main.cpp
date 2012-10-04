#include <QApplication>
#include <QColorDialog>
#include "FenPrincipale.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    FenPrincipale fenetre;

    fenetre.show();
    return app.exec();
}

/*
#include <QtGui>

static const QVector<QRgb> colors = QVector<QRgb>()
        << qRgb(  0,   0,   0)
        << qRgb(255,   0,   0)
        << qRgb(  0, 255,   0)
        << qRgb(255, 255,   0)
        << qRgb(  0,   0, 255)
        << qRgb(255,   0, 255)
        << qRgb(  0, 255, 255)
        << qRgb(255, 255, 255);

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QImage image(320, 240, QImage::Format_Indexed8);
    image.setColorTable(colors);
    image.fill(2);

    QLabel label;
    label.setPixmap(QPixmap::fromImage(image));
    label.show();

    return app.exec();
}
*/
