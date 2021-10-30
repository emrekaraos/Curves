#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>

class renderArea : public QWidget
{
    Q_OBJECT
public:
    explicit renderArea(QWidget *parent = nullptr);
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum ShapeType{
        Astroid,
        Cycloid,
        HuygensCycloid,
        HypoCycloid,
        line
    };

    void setBackgroundColor(QColor color) { mBackgroundColor = color; } // SETTER
    QColor backgroundColor() const { return mBackgroundColor; }  //GETTER


    void setSahpe(ShapeType shape) { mShape = shape; on_shape_changed();} //SETTER
    ShapeType shape() const { return  mShape;} //GETTER

    void setScale(float scale){ mScale = scale; repaint();}
    float scale() const{return mScale;}

    void setLenght(float intervalLength){ mIntervalLength = intervalLength; repaint();}
    float length() const{return mIntervalLength;}

    void setStepCount(int count){ mStepCount = count; repaint();}
    float stepCount() const{return mStepCount;}

    void setShapeColor(QColor color){ mShapeColor = color;}
    QColor shapeColor() const {return  mShapeColor;}


protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:


private:
    void  on_shape_changed();
    QPointF compute(float t);
    QPointF compute_astroid(float t);
    QPointF compute_cycloid(float t);
    QPointF compute_huygens(float t);
    QPointF compute_hypo(float t);
    QPointF compute_line(float t);




private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;

    float mIntervalLength;
    float mScale;
    int mStepCount;

};

#endif // RENDERAREA_H
