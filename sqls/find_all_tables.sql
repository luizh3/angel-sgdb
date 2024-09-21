SELECT
    table_name,
    column_name
FROM
    information_schema.columns
WHERE
    table_catalog = :DATABASE AND
    table_schema = :SCHEMA;
