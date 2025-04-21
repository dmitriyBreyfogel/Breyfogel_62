#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include <QMap>
#include <QSet>
#include "error.h"

enum NodeType {
    Plus,
    Multiplication,
    Division,
    Exponentiation,
    BinaryMinus,
    UnaryMinus,
    Operand
};

class ExpressionTree {
private:
    ExpressionTree* left;
    ExpressionTree* right;
    NodeType nodeType;
    double value;

    bool isValidNumber(double number) const;
    static NodeType determineNodeType(const QString& value);

public:
    ExpressionTree(const QString& operation, ExpressionTree* left, ExpressionTree* right);
    ~ExpressionTree();

    static const QMap<QString, int> operatorsPrecedence;

    double getValue() const;
    NodeType getNodeType() const;

    static int countOperands(NodeType type);
    static ExpressionTree* build(const QStringList& tokens);
    double calculate(QSet<Error>& errors) const;
};

#endif // EXPRESSIONTREE_H
