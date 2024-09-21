#ifndef SQLSYNTAXHIGHLIGHTER_H
#define SQLSYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>

class SqlSyntaxHighlighter : public QSyntaxHighlighter {
    Q_OBJECT
public:
    explicit SqlSyntaxHighlighter( QTextDocument* parent = 0 );
protected:
    void highlightBlock( const QString& text );
private:
    QSet<QString> _keywords;

    void setKeywords();
};

#endif // SQLSYNTAXHIGHLIGHTER_H
