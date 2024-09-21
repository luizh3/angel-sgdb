#include "sqlsyntaxhighlighter.h"

#include <QRegularExpressionMatchIterator>

SqlSyntaxHighlighter::SqlSyntaxHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent),
    _keywords( {} ) {

    // TODO Override this when have more database options
    setKeywords();
}

void SqlSyntaxHighlighter::highlightBlock( const QString& text ) {

    QTextCharFormat myClassFormat;
    myClassFormat.setForeground(QColor(QStringLiteral("#ffc300")));

    // TODO dont work, why ?
    myClassFormat.setFontCapitalization( QFont::Capitalization::AllUppercase );

    QRegularExpression expression("\\b[A-Za-z]+\\b");
    QRegularExpressionMatchIterator current = expression.globalMatch(text.toUpper());
    while ( current.hasNext()) {
        QRegularExpressionMatch match = current.next();

        if( _keywords.contains(match.captured(0) ) ){
             setFormat(match.capturedStart(), match.capturedLength(), myClassFormat);
        }

    }
}

void SqlSyntaxHighlighter::setKeywords() {

    _keywords << "ABORT" << "ABSOLUTE" << "ACCESS" << "ACTION" <<
        "ADD" << "ADMIN" << "AFTER" <<
        "AGGREGATE" << "ALL" << "ALSO" << "ALTER" <<
        "ALWAYS" << "ANALYSE" << "ANALYZE" << "AND" <<
        "ANY" << "ARRAY" << "AS" << "ASC" <<
        "ASSERTION" << "ASSIGNMENT" << "ASYMMETRIC" << "AT" <<
        "ATTACH" << "ATTRIBUTE" << "AUTHORIZATION" << "BACKWARD" <<
        "BEFORE" << "BEGIN" << "BETWEEN" << "BIGINT" <<
        "BINARY" << "BIT" << "BOOLEAN" << "BOTH" <<
        "BY" << "CACHE" << "CALL" << "CALLED" <<
        "CASCADE" << "CASCADED" << "CASE" << "CAST" <<
        "CATALOG" << "CHAIN" << "CHAR" << "CHARACTER" <<
        "CHARACTERISTICS" << "CHECK" << "CHECKPOINT" << "CLASS" <<
        "CLOSE" << "CLUSTER" << "COALESCE" << "COLLATE" <<
        "COLLATION" << "COLUMN" << "COMMENT" << "COMMENTS" <<
        "COMMIT" << "COMMITTED" << "CONCURRENTLY" << "CONFIGURATION" <<
        "CONFLICT" << "CONNECTION" << "CONSTRAINT" << "CONSTRAINTS" <<
        "CONTENT" << "CONTINUE" << "CONVERSION" << "COPY" <<
        "COST" << "CREATE" << "CROSS" << "CSV" << "CUBE" <<
        "CURRENT" << "CURRENT_CATALOG" << "CURRENT_DATE" <<
        "CURRENT_ROLE" << "CURRENT_SCHEMA" << "CURRENT_TIME" <<
        "CURRENT_TIMESTAMP" << "CURRENT_USER" << "CURSOR" <<
        "CYCLE" << "DATA" << "DATABASE" << "DAY" <<
        "DEALLOCATE" << "DEC" << "DECIMAL" << "DECLARE" <<
        "DEFAULT" << "DEFAULTS" << "DEFERRABLE" << "DEFERRED" <<
        "DEFINER" << "DELETE" << "DELIMITER" << "DELIMITERS" <<
        "DEPENDS" << "DESC" << "DETACH" << "DICTIONARY" <<
        "DISABLE" << "DISCARD" << "DISTINCT" << "DO" <<
        "DOCUMENT" << "DOMAIN" << "DOUBLE" << "DROP" <<
        "EACH" << "ELSE" << "ENABLE" << "ENCODING" <<
        "ENCRYPTED" << "END" << "ENUM" << "ESCAPE" << "EVENT" <<
        "EXCEPT" << "EXCLUDE" << "EXCLUDING" << "EXCLUSIVE" <<
        "EXECUTE" << "EXISTS" << "EXPLAIN" << "EXTENSION" <<
        "EXTERNAL" << "EXTRACT" << "FALSE" << "FAMILY" << "FETCH" <<
        "FILTER" << "FINALIZE" << "FIRST" << "FLOAT" << "FOLLOWING" <<
        "FOR" << "FORCE" << "FOREIGN" << "FORWARD" <<
        "FREEZE" << "FROM" << "FULL" << "FUNCTION" <<
        "FUNCTIONS" << "GENERATED" << "GLOBAL" << "GRANT" <<
        "GRANTED" << "GREATEST" << "GROUP" << "GROUPING" <<
        "HANDLER" << "HAVING" << "HEADER" << "HOLD" << "HOUR" <<
        "IDENTITY" << "IF" << "ILIKE" << "IMMEDIATE" <<
        "IMMUTABLE" << "IMPLICIT" << "IMPORT" << "IN" <<
        "INCLUDING" << "INCREMENT" << "INDEX" << "INDEXES" <<
        "INHERIT" << "INHERITS" << "INITIALLY" << "INLINE" <<
        "INNER" << "INOUT" << "INPUT" << "INSENSITIVE" << "INSERT" <<
        "INSTEAD" << "INT" << "INTEGER" << "INTERSECT" << "INTERVAL" <<
        "INTO" << "INVOKER" << "IS" << "ISNULL" << "ISOLATION" <<
        "JOIN" << "KEY" << "LABEL" << "LANGUAGE" << "LARGE" <<
        "LAST" << "LATERAL" << "LEADING" << "LEAKPROOF" << "LEAST" <<
        "LEFT" << "LEVEL" << "LIKE" << "LIMIT" << "LISTEN" << "LOAD" <<
        "LOCAL" << "LOCALTIME" << "LOCALTIMESTAMP" << "LOCATION" << "LOCK" <<
        "LOCKED" << "LOGGED" << "MAPPING" << "MATCH" << "MATERIALIZED" <<
        "MAXVALUE" << "METHOD" << "MINUTE" << "MINVALUE" << "MODE" <<
        "MONTH" << "MOVE" << "NAME" << "NAMES" << "NATIONAL" << "NATURAL" <<
        "NCHAR" << "NEW" << "NEXT" << "NO" << "NONE" << "NOT" << "NOTHING" <<
        "NOTIFY" << "NOTNULL" << "NOWAIT" << "NULL" << "NULLIF" << "NULLS" <<
        "NUMERIC" << "OBJECT" << "OF" << "OFF" << "OFFSET" << "OIDS" <<
        "OLD" << "ON" << "ONLY" << "OPERATOR" << "OPTION" << "OPTIONS" << "OR" <<
        "ORDER" << "ORDINALITY" << "OUT" << "OUTER" << "OVER" <<
        "OVERLAPS" << "OVERLAY" << "OVERRIDING" << "OWNED" << "OWNER" <<
        "PARALLEL" << "PARSER" << "PARTIAL" << "PARTITION" << "PASSING" << "PASSWORD" <<
        "PLACING" << "PLANS" << "POLICY" << "POSITION" << "PRECEDING" <<
        "PRECISION" << "PREPARE" << "PREPARED" << "PRESERVE" <<
        "PRIMARY" << "PRIOR" << "PRIVILEGES" << "PROCEDURAL" <<
        "PROCEDURE" << "PROGRAM" << "PUBLICATION" << "QUOTE" << "RANGE" <<
        "READ" << "REAL" << "REASSIGN" << "RECHECK" << "RECURSIVE" << "REF" <<
        "REFERENCES" << "REFERENCING" << "REFRESH" << "REINDEX" <<
        "RELATIVE" << "RELEASE" << "RENAME" << "REPEATABLE" <<
        "REPLACE" << "REPLICA" << "RESET" << "RESTART" << "RESTRICT" <<
        "RETURNING" << "RETURNS" << "REVOKE" << "RIGHT" << "ROLE" <<
        "ROLLBACK" << "ROLLUP" << "ROW" << "ROWS" << "RULE" <<
        "SAVEPOINT" << "SCHEMA" << "SCHEMAS" << "SCROLL" <<
        "SEARCH" << "SECOND" << "SECURITY" << "SELECT" <<
        "SEQUENCE" << "SEQUENCES" << "SERIALIZABLE" << "SERVER" <<
        "SESSION" << "SESSION_USER" << "SET" << "SETS" << "SHARE" <<
        "SHOW" << "SIMILAR" << "SIMPLE" << "SKIP" << "SMALLINT" <<
        "SNAPSHOT" << "SOME" << "SQL" << "STABLE" << "STANDALONE" <<
        "START" << "STATEMENT" << "STATISTICS" << "STDIN" << "STDOUT" <<
        "STORAGE" << "STRICT" << "STRIP" << "SUBSCRIPTION" << "SUBSTRING" <<
        "SYMMETRIC" << "SYSID" << "SYSTEM" << "TABLE" << "TABLES" <<
        "TABLESPACE" << "TEMP" << "TEMPLATE" << "TEMPORARY" << "TEXT" <<
        "THEN" << "TIME" << "TIMESTAMP" << "TO" << "TRAILING" <<
        "TRANSACTION" << "TRANSFORM" << "TREAT" << "TRIGGER" <<
        "TRIM" << "TRUE" << "TRUNCATE" << "TRUSTED" << "TYPE" <<
        "TYPES" << "UNBOUNDED" << "UNCOMMITTED" << "UNENCRYPTED" <<
        "UNION" << "UNIQUE" << "UNKNOWN" << "UNLISTEN" << "UNLOGGED" <<
        "UNTIL" << "UPDATE" << "USER" << "USING" << "VACUUM" << "VALID" <<
        "VALIDATE" << "VALIDATOR" << "VALUE" << "VALUES" << "VARCHAR" <<
        "VARIADIC" << "VARYING" << "VERBOSE" << "VERSION" << "VIEW" <<
        "VIEWS" << "VOLATILE" << "WHEN" << "WHERE" << "WHITESPACE" <<
        "WINDOW" << "WITH" << "WITHIN" << "WITHOUT" << "WORK" <<
        "WRAPPER" << "WRITE" << "XML" << "YEAR" << "YES" << "ZONE";
}
