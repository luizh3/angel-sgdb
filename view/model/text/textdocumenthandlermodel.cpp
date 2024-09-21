#include "textdocumenthandlermodel.h"

TextDocumentHandlerModel::TextDocumentHandlerModel() :
    _document( nullptr ) {}

QQuickTextDocument* TextDocumentHandlerModel::document() const {
    return _document;
}

void TextDocumentHandlerModel::setDocument( QQuickTextDocument* document ) {

    if ( _document == document ) {
        return;
    }

    _sqlSyntaxHighlighter.reset( new SqlSyntaxHighlighter( document->textDocument() ) );

    _document = document;
    emit documentChanged();
}
