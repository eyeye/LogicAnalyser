#include "logicchannel.h"
#include <QtQuick/qsgnode.h>
#include <QtQuick/qsgflatcolormaterial.h>


LogicChannel::LogicChannel(QQuickItem *parent) :
    QQuickItem(parent), m_color("red"), m_series(NULL)
{
    //m_color = QColor("red");
    setFlag(ItemHasContents, true);
}

LogicChannel::~LogicChannel()
{
}

QSGNode *LogicChannel::updatePaintNode(QSGNode * oldNode, QQuickItem::UpdatePaintNodeData *)
{
    QSGGeometryNode *node = 0;
    QSGGeometry     *geometry = 0;

    if(m_series == NULL)
    {
        return NULL;
    }

//    qDebug() <<"m_series->count: "<< m_series->count();

    if(oldNode == NULL)
    {
        node = new QSGGeometryNode;
        geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(),
                                   2*(m_series->count()) + 2);

        geometry->setDrawingMode(GL_LINE_STRIP);
        geometry->setLineWidth(4);

        node->setGeometry(geometry);
        node->setFlag(QSGNode::OwnsGeometry);

        QSGFlatColorMaterial *material = new QSGFlatColorMaterial;
        material->setColor(m_color);
        node->setMaterial(material);
        node->setFlag(QSGNode::OwnsMaterial);
    }
    else
    {
        node = static_cast<QSGGeometryNode *>(oldNode);
        geometry = node->geometry();
        geometry->allocate(2*(m_series->count()) + 2);
    }

    //QRectF rect = boundingRect();
    QSGGeometry::Point2D *points = geometry->vertexDataAsPoint2D();
//    qDebug() <<"index_count: "<< geometry->indexCount();


    float xx = boundingRect().x();
    float yy = boundingRect().y();
    float ww = boundingRect().width();
    float hh = boundingRect().height();
    float high = yy+5;
    float low = yy+hh-5;

    int index = 0;
    quint32 i = 0;
    float x;

    if(m_series->level())
    {
        // start
        points[index++].set(xx, high);    // HIGH

        while( true )
        {
            // fall
            x  = m_series->points()[i] + xx;
            points[index++].set(x, high);
            points[index++].set(x, low);
            if( ++i == m_series->count() )
            {
                points[index++].set(ww, low);    // LOW
                break;
            }

            // rise
            x  = m_series->points()[i] + xx;
            points[index++].set(x, low);
            points[index++].set(x, high);
            if( ++i == m_series->count() )
            {
                points[index++].set(xx+ww, high);    // HIGH
                break;
            }
        }

    }
    else
    {
        points[index++].set(xx, low);    // LOW

        while( true )
        {
            // rise
            x  = m_series->points()[i] + xx;
            points[index++].set(x, low);
            points[index++].set(x, high);
            if( ++i == m_series->count() )
            {
                points[index++].set(xx+ww, high);    // HIGH
                break;
            }

            // fall
            x  = m_series->points()[i] + xx;
            points[index++].set(x, high);
            points[index++].set(x, low);
            if( ++i == m_series->count() )
            {
                points[index++].set(xx+ww, low);    // LOW
                break;
            }
        }

    }

    qDebug() <<"*";
    return node;
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
        emit colorChanged(color);
        update();
    }
}

LogicSeries *LogicChannel::series() const
{
    return m_series;
}

void LogicChannel::setSeries(LogicSeries *series)
{
    if(m_series != series)
    {
        qDebug("Set series!");
        m_series = series;
        emit seriesChanged(series);
        update();
    }
}


