#ifndef TIMESCALE_H
#define TIMESCALE_H

#include <QQuickItem>

class Timescale : public QQuickItem
{
    Q_OBJECT

//    Q_PROPERTY(quint64 pixelLength READ pixelLength WRITE setPixelLength)

public:
    explicit Timescale(QQuickItem *parent = 0);

    /**
     * @brief zoom 简单的固定中心点缩放
     * @todo 后期添加中心点参数
     * @param ratio ratio > 0: zoom in  放大
     *              ratio < 0: zoom out 缩小
     */
    Q_INVOKABLE void zoomAtCenter(qreal ratio);
    Q_INVOKABLE void zoomAtPosition(qreal ratio, qreal position);

    /**
     * @brief move
     * @param pixel pixel > 0: move right
     *              pixel < 0: move left
     */
//    Q_INVOKABLE void moveToPosition(qreal position);
    Q_INVOKABLE void movePixel(qint64 pixel);
    Q_INVOKABLE void moveTime(qint64 time);

    /**
     * @brief resize
     * @param pixel
     */
    Q_INVOKABLE void resizePixel(quint64 pixel);
//    Q_INVOKABLE void resizeTime(quint64 time);



signals:
    void scaleChanged();

public slots:

private:
    qreal   m_position;             /// 显示全局位置
    qreal   m_positionStart;        /// 全局起始显示位置
    qreal   m_positionEnd;          /// 全局终止显示位置

    qreal   m_pixelRatio;           /// 像素时间系数
    qreal   m_scale;                /// 显示比率

    quint64 m_pixelLength;          /// 像素总长度
    quint64 m_pixelViewLength;      /// 像素显示长度
    quint64 m_pixelViewStart;       /// 起始显示像素
    quint64 m_pixelViewEnd;         /// 终止显示像素

    quint64 m_timeLength;           /// 时间总长度
    quint64 m_timeViewLength;       /// 显示时间长度
    quint64 m_timeStart;            /// 起始显示时间
    quint64 m_timeEnd;              /// 终止显示时间

    void setPositionRange(qreal positionStart, qreal positionEnd);
};

#endif // TIMESCALE_H


