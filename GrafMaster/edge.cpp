#include "vertex.h"
#include "edge.h"
#include "graph.h"

#include <QtMath>


#define M_PI 3.1415926



Edge::Edge(Vertex *source, Vertex *dest, double weight) {
    this->source = source;//начало дуги
    this->dest = dest;//конец дуги
    setAcceptedMouseButtons(Qt::NoButton);
    source->addEdge(this);//добавление дуги
    this->weight = weight;//устанавливаем вес
    color = "white";
}

Edge::~Edge(){

}

Vertex *Edge::sourceVertex() const{
    return source;//начало
}

Vertex *Edge::destVertex() const{
    return dest;//конец
}

void Edge::adjust() {//регулировка параметров для дуги
    if(!source || !dest) {
        return;
    }
    QLineF line(mapFromItem(source, 0, 0), mapFromItem(dest, 0, 0));//задание объекта для дуги
    qreal length = line.length();//длина
    prepareGeometryChange();
    //установка нужных размеров для линии
    if (length > qreal(20.)) {
        QPointF edgeOffset((line.dx() * 10) / length, (line.dy() * 10) / length);
        sourcePoint = line.p1() + edgeOffset;
        destPoint = line.p2() - edgeOffset;
    }
    else {
        sourcePoint = destPoint = line.p1();
    }
}

QRectF Edge::boundingRect() const {
    if(!source || !dest){
        return QRectF();//хз
    }
    qreal penWidth = 1;
    qreal extra = (penWidth + arrowSize) / 2.0;
    return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(), destPoint.y() - sourcePoint.y())).normalized().adjusted(-extra, -extra, extra, extra);
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    if(!source || !dest){
        return;
    }
    QLineF line(sourcePoint, destPoint);
    if(qFuzzyCompare(line.length(), qreal(0.))){//хз
        return;
    }

    double angle = std::atan2(-line.dy(), line.dx());
    QPointF destArrowP1 = destPoint + QPointF(sin(angle - M_PI / 3) * arrowSize, cos(angle - M_PI / 3) * arrowSize);
    QPointF destArrowP2 = destPoint + QPointF(sin(angle - M_PI + M_PI / 3) * arrowSize, cos(angle - M_PI + M_PI / 3) * arrowSize);


    if (color == "white") {
        painter->setBrush(Qt::black);
        painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    }
    else if (color == "black") {
        painter->setBrush(Qt::red);
        painter->setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    }
    painter->drawLine(line);//рисование линии
    painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);//рисование стрелок
    painter->setBrush(Qt::red);
    painter->setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawText(QRectF(QPointF(sourcePoint.x() - 15, sourcePoint.y() - 15), QPointF(destPoint.x() + 15, destPoint.y() + 15)), Qt::AlignCenter, QString::number(weight));//вывод веса
}

double Edge::getWeight(){
    return weight;
}

void Edge::setWeight(double weight){
    this->weight = weight;
}

QString Edge::getColor(){
    return color;
}

void Edge::setColor(QString color){
    this -> color = color;
    qApp->processEvents();
    update();
}
