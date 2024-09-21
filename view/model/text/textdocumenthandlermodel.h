#ifndef TEXTDOCUMENTHANDLERMODEL_H
#define TEXTDOCUMENTHANDLERMODEL_H

#include <memory>

#include <QObject>
#include <QQuickTextDocument>

#include "sqlsyntaxhighlighter.h"

class TextDocumentHandlerModel : public QObject {
    Q_OBJECT
    Q_PROPERTY( QQuickTextDocument* document READ document WRITE setDocument NOTIFY documentChanged FINAL )
public:
    TextDocumentHandlerModel();

    QQuickTextDocument* document() const;
    void setDocument( QQuickTextDocument * document );

signals:
    void documentChanged();

private:
    QQuickTextDocument* _document;
    std::unique_ptr<SqlSyntaxHighlighter> _sqlSyntaxHighlighter;

};

#endif // TEXTDOCUMENTHANDLERMODEL_H
