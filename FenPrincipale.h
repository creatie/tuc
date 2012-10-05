#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QImage>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QSlider>
#include <QDebug>
#include <QToolButton>
#include <QColorDialog>

class FenPrincipale : public QWidget
{
    Q_OBJECT
public:
    FenPrincipale();

private slots:
    void redChanged(int);
    void greenChanged(int);
    void blueChanged(int);
    void resultLineChanged();
    void pickColor();

private:
    void paintCanvas(int r =0, int g =0, int b =0);   // default = black
    void buildSliders();
    void buildResultSide();
    void buildButtons();        // build actions and buttons
    void buildLayout();
    void makeConnections();

    QGridLayout* layoutPrincipale;
    QLabel* paneau;
    QSlider* redSlider;
    QSlider* greenSlider;
    QSlider* blueSlider;
    QLineEdit* resultLine;

    QToolButton* buttonColorPicker;
    QPixmap* pixmapToPaint;
};

#endif // FENPRINCIPALE_H
