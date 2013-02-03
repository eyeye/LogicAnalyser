#include "logicchannel.h"
#include <QtQuick/qsgnode.h>
#include <QtQuick/qsgflatcolormaterial.h>


LogicChannel::LogicChannel(QQuickItem *parent) :
    QQuickItem(parent), m_color("red")
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

    const int count = 128;

    if(oldNode == NULL)
    {
        node = new QSGGeometryNode;
        geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), count);

        geometry->setDrawingMode(GL_LINES);
        geometry->setLineWidth(2);

        node->setGeometry(geometry);
        node->setFlag(QSGNode::OwnsGeometry);

        QSGFlatColorMaterial *material = new QSGFlatColorMaterial;
        //material->setColor(m_color);
        material->setColor(m_color);
        node->setMaterial(material);
        node->setFlag(QSGNode::OwnsMaterial);
    }
    else
    {
        node = static_cast<QSGGeometryNode *>(oldNode);
        geometry = node->geometry();
        geometry->allocate(count);
    }

    QRectF rect = boundingRect();
    QSGGeometry::Point2D *points = geometry->vertexDataAsPoint2D();


    for( int i = 0; i < (count/2); i++)
    {
        float x = (rect.width() * i)/(count/2);
        float y0 = 5;
        float y1 = rect.height()-5;

        points[2*i + 0].set(rect.x()+x, rect.y()+y0);
        points[2*i + 1].set(rect.x()+x, rect.y()+y1);
    }

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


