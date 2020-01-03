#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChartView>//显示图表
#include <QtCharts/QLineSeries>//线系列
#include <QDoubleSpinBox>
#include <QGridLayout>
#include <QTimer>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>



QT_CHARTS_USE_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void RealtimeDataSlot();

private:
    Ui::MainWindow *ui;
    QTimer m_timer;
    QChart chart;
    QSplineSeries m_series;
    QStringList m_titles;
    QValueAxis m_axis;
    qreal m_step;
    qreal m_x;
    qreal m_y;
};

#endif // MAINWINDOW_H
