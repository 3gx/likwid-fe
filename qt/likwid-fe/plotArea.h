#ifndef PLOTAREA_H
#define PLOTAREA_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>l
namespace Ui
{
  class PlotArea
  {
    public:

      enum Shape { Line, Points, Polyline, Polygon, Rect, RoundedRect, Ellipse, Arc,
               Chord, Pie, Path, Text, Pixmap };
      QSize minimumSizeHint() const;
      QSize sizeHint() const;

      PlotArea();
      ~PlotArea();

    public slots:
        void setShape(Shape shape);
        void setPen(const QPen &pen);
        void setBrush(const QBrush &brush);
        void setAntialiased(bool antialiased);
        void setTransformed(bool transformed);

    protected:
        void paintEvent(QPaintEvent *event);
        Shape shape;
        QPen pen;
        QBrush brush;
        bool antialiased;
        bool transformed;
        QPixmap pixmap;
  };
}
#endif // PLOTAREA_H
