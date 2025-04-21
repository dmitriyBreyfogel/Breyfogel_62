#ifndef ERROR_H
#define ERROR_H

#include <QString>

class Error {
public:
    // Перечисление типа ошибок
    enum Type {
        inputFileWay,           // Указанный входной файл не существует, нет доступа к указанному файлу
        outputFileWay,          // Невозможно создать указанный выходной файл
        countStrings,           // Во входном файле больше одной строки
        unknownSymbolsSequence, // Неизвестная последовательность символов
        divisionByZero,         // Деление на ноль в выражении
        noLeftOperand,          // Отсутствие левого операнда в определённой операции вычисления
        noRightOperand,         // Отсутствие правого операнда в определённой операции вычисления
        noBothOperands,         // Отсутствие обоих операндов у определённой операции вычисления
        noClosingParenthesis,   // Отсутствует закрывающая скобка
        noOpeningParenthesis,   // Отсутствует открывающая скобка
        noCalcOperation,        // Отсутствует оператор вычисления
        incorrectRoot,          // Извлечение корня, являющегося правильной дробью, из отрицательного числа
        operandOutOfRange       // Один из операндов выходит за пределы обрабатываемых чисел
    };

    // Методы установки параметров ошибки
    void setType(Type type);
    void setSymbolsSequence(const QString &symbolsSequence);
    void setExpression(const QString &expression);
    void setLeftOperand(const QString &leftOperand);
    void setRightOperand(const QString &rightOperand);
    void setSymbolIndex(int symbolIndex);
    void setOperation(const QString &operation);

    // Генерация текстового описания ошибки
    QString message() const;

private:
    Type type;
    QString symbolsSequence;
    QString expression;
    QString leftOperand;
    QString rightOperand;
    int symbolIndex;
    QString operation;
};

#endif // ERROR_H
