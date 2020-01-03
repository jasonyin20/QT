#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTime"
#include "QDebug"
#include "qmath.h"
#include "QValueAxis"
#include "QDateTimeAxis"
#include "QRandomGenerator"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("动态正弦波形图");
    connect(&m_timer,SIGNAL(timeout()),this,SLOT(RealtimeDataSlot()));
    m_timer.setInterval(1000);
    m_x=0;
    m_y=0;

    chart.setTheme(QChart::ChartThemeBlueCerulean);//设置系统主题
    chart.setTitle("动态正弦波形图");//设置标题
    chart.setTitleFont(QFont("微软雅黑",10));
    chart.legend()->hide();


    QPen green(Qt::yellow);
    green.setWidth(2);
    m_series.setPen(green);
    m_series.append(m_x, m_y);

    chart.addSeries(&m_series);
    chart.createDefaultAxes();
    chart.setAxisX(&m_axis,&m_series);
    m_axis.setTickCount(5);
    chart.axisX()->setRange(0,10);
    chart.axisY()->setRange(-1, 1);



    QChartView *chartView = new QChartView(&chart);
    QGridLayout *baseLayout = new QGridLayout(); //便于显示，创建网格布局

    chartView->setRenderHint(QPainter::Antialiasing);

    baseLayout->addWidget(chartView, 0, 0);
    ui->widgetWaveForm->setLayout(baseLayout); //显示到QWidget控件

    m_timer.start();
}
void MainWindow::RealtimeDataSlot()
{
    qreal x = chart.plotArea().width()/m_axis.tickCount();
    qreal y = 10/m_axis.tickCount();
    m_x += y;
    m_y=sin(m_x);
    m_series.append(m_x, m_y);
    chart.scroll(x/2, 0);
    /*if (m_x == 100)
        m_timer.stop();*/
}
MainWindow::~MainWindow()
{
    delete ui;
}
