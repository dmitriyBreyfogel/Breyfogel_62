#include "expressiontree.h"

ExpressionTree::ExpressionTree(const QString& value, ExpressionTree* left, ExpressionTree* right) {
    nodeType = determineNodeType(value);
    if (nodeType == NodeType::Operand && isValidNumber(value.toDouble())) {
        this->value = value.toDouble();
    }

    this->left = left;
    this->right = right;
}

ExpressionTree::~ExpressionTree() {
    delete left;
    delete right;
}

const QMap<QString, int> operatorsPrecedence = {
    {"+", 1},
    {"-", 1},
    {"*", 2},
    {"/", 2},
    {"^", 3},
    {"-u", 4},
    {"(", 5},
    {")", 5}
};

bool ExpressionTree::isValidNumber(double number) const {
    return number >= -1.7E308 && number <= 1.7E308;
}

NodeType ExpressionTree::determineNodeType(const QString& value) {
    if (value == "+") return NodeType::Plus;
    else if (value == "-") return NodeType::BinaryMinus;
    else if (value == "*") return NodeType::Multiplication;
    else if (value == "/") return NodeType::Division;
    else if (value == "-u") return NodeType::UnaryMinus;
    else return NodeType::Operand;
}

double ExpressionTree::getValue() const { return value; }
NodeType ExpressionTree::getNodeType() const { return nodeType; }

ExpressionTree* ExpressionTree::build(const QStringList& tokens) {
    return NULL;
}

double ExpressionTree::calculate(QSet<Error>& errors) const {
    return 0;
}

int ExpressionTree::countOperands(NodeType type) {
    return 0;
}




