#include "logicchannel.h"
#include <QtQuick/qsgnode.h>
#include <QtQuick/qsgflatcolormaterial.h>


LogicChannel::LogicChannel(QQuickItem *parent) :
    QQuickItem(parent), m_color("red")
{
    //m_color = QColor("red");
    setFlag(ItemHasContents, true);

    m_nSecPerPixel = 1;
    m_points = new QVector<quint64>(1024);
    m_count = 0;

    m_node = new QSGGeometryNode;
    m_geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(),
                                 2*(m_count) );

    m_geometry->setDrawingMode(GL_LINE_STRIP);
    m_geometry->setLineWidth(4);

    m_node->setGeometry(m_geometry);
    m_node->setFlag(QSGNode::OwnsGeometry);

    QSGFlatColorMaterial *material = new QSGFlatColorMaterial;
    material->setColor(m_color);
    m_node->setMaterial(material);
    m_node->setFlag(QSGNode::OwnsMaterial);

//    QTimer::singleShot(200, this, SLOT(autoAddPoint()));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(autoAddPoint()));
    timer->start(200);
}

LogicChannel::~LogicChannel()
{
}

QSGNode *LogicChannel::updatePaintNode(QSGNode * oldNode, QQuickItem::UpdatePaintNodeData *)
{
    m_geometry->allocate(2*m_count);
    QSGGeometry::Point2D *points = m_geometry->vertexDataAsPoint2D();

    float xx = boundingRect().x();
    float yy = boundingRect().y();
    float ww = boundingRect().width();
    float hh = boundingRect().height();
    float high = yy+5;
    float low = yy+hh-5;

    float x;

    for(qint32 index = 0; index < m_count; index ++)
    {
        x = ( m_points->at(index) & ~(quint64)((quint64)3<<62) ) + xx;

        if(m_points->at(index) & (quint64)((quint64)1<<62))
        {
            points[2*index].set(x, high);
            points[2*index + 1].set(x, low);
        }
        else if(m_points->at(index) & (quint64)((quint64)2<<62))
        {
            points[2*index].set(x, low);
            points[2*index + 1].set(x, high);
        }
    }

    return m_node;
}



QColor LogicChannel::color() const
{
    return m_color;
}



void LogicChannel::setColor(const QColor &color)
{
    if(m_color != color)
    {
        m_color = color;
        QSGFlatColorMaterial *material = dynamic_cast<QSGFlatColorMaterial*>(m_node->material());
        material->setColor(color);
        emit colorChanged(color);
        update();
    }
}


qint32 LogicChannel::nSecPerPixel() const
{
    return this->m_nSecPerPixel;
}


void LogicChannel::setNSecPerPixel(qint32 nSecPerPixel)
{
    if( nSecPerPixel > 0 )
    {
        m_nSecPerPixel = nSecPerPixel;
        emit nSecPerPixelChanged(m_nSecPerPixel);
        update();
    }
}



void LogicChannel::autoAddPoint()
{
    quint64 point;
    static quint64 time = 0;

    if( m_count < m_points->count())
    {
        if(m_count & 1)
        {
            point = time | ((quint64)1<<62);
        }
        else
        {
            point = time | ((quint64)2<<62);
        }

        time += 4;
        (*m_points)[m_count++] = point;

        updatePoints();

        setWidth(point + 200);
    }

//    qDebug() << "autoAddPoint: " << m_count << point;

}


void LogicChannel::updatePoints()
{
    this->update();
}



