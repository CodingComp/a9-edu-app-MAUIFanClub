#ifndef NODEINPUTSLOT_H
#define NODEINPUTSLOT_H

#include <QWidget>

class CircuitNode;
class NodeOutputSlot;

class NodeInputSlot : public QWidget
{
public:
    NodeInputSlot(QWidget *parent = nullptr);
    ~NodeInputSlot();

    CircuitNode *node;

    bool clicked = false;
    int size = 20;

    NodeOutputSlot *connection = nullptr;

    void disconnect();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // NODEINPUTSLOT_H
